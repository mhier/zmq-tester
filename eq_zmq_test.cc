
#include <stdio.h>
#include "eq_zmq_test.h"
#include "eq_errors.h"
#include "eq_fct_errors.h"
#include <assert.h>
#include <sys/resource.h>

using namespace std;

EqFctZmqTest::EqFctZmqTest() : EqFct("LOCATION") {
  for(size_t i = 0; i < 250; ++i) {
    addresses.emplace_back(this, "LISTENER_" + std::to_string(i));
  }
}

void EqFctZmqTest::interrupt_usr1(int) {}
void EqFctZmqTest::init() {}
void EqFctZmqTest::post_init() {
  std::cout << "Subscribing MPS number '" << mpsZmqName.value() << "'..." << std::endl;
  dmsg_start();

  EqData dst;
  EqAdr ea;
  int err;

  ea.adr(mpsZmqName.value());
  subscriptionMap[mpsZmqName.value()].isMPSnumber = true;
  subscriptionMap[mpsZmqName.value()].eqfct = this;
  subscriptionMap[mpsZmqName.value()].name = mpsZmqName.value();
  err = dmsg_attach(&ea, &dst, (void*)&(subscriptionMap[mpsZmqName.value()]), &zmq_callback,
      &subscriptionMap[mpsZmqName.value()].tag);
  if(err) {
    std::cout << "Cannot subscribe to MPS number property '" << mpsZmqName.value()
              << "' via ZeroMQ: " << dst.get_string() << std::endl;
    exit(1);
  }
  std::cout << "done." << std::endl;

  for(auto& addListener : addresses) {
    if(strcmp(addListener.value(), "") != 0) {
      std::cout << "Adding new listener '" << addListener.value() << "'..." << std::endl;
      ea.adr(addListener.value());
      subscriptionMap[addListener.value()].eqfct = this;
      subscriptionMap[addListener.value()].name = addListener.value();
      err = dmsg_attach(&ea, &dst, (void*)&(subscriptionMap[addListener.value()]), &zmq_callback,
          &subscriptionMap[addListener.value()].tag);
      if(err) {
        std::cout << "Cannot subscribe to DOOCS property '" << addListener.value()
                  << "' via ZeroMQ: " << dst.get_string() << std::endl;
      }
      else {
        std::cout << "done." << std::endl;
      }
    }
  }
}

void EqFctZmqTest::update() {
  prop_delayStamp.set_ro_access();
  for(size_t i = 0; i < NBINS; ++i) {
    prop_delayStamp.fill_spectrum(i, hist_delayStamp[i]);
  }
  prop_delayStamp.spectrum_parameter(0, -1, 1, 0);
  prop_delayStamp.xegu(0, -int(NBINS) / 2. - 10, NBINS - 2 + 10, "ms");

  prop_delayClock.set_ro_access();
  for(size_t i = 0; i < NBINS; ++i) {
    prop_delayClock.fill_spectrum(i, hist_delayClock[i]);
  }
  prop_delayClock.spectrum_parameter(0, -int(NBINS) / 2., 1, 0);
  prop_delayClock.xegu(0, -int(NBINS) / 2. - 10, NBINS / 2. + 10, "ms");

  prop_deltaXtimer.set_ro_access();
  for(size_t i = 0; i < NBINS; ++i) {
    prop_deltaXtimer.fill_spectrum(i, hist_deltaXtimer[i]);
  }
  prop_deltaXtimer.spectrum_parameter(0, -int(NBINS) / 2., 1, 0);
  prop_deltaXtimer.xegu(0, -int(NBINS) / 2. - 10, NBINS / 2. + 10, "ms");
}

void EqFctZmqTest::zmq_callback(void* self_, EqData* data, dmsg_info_t* info) {
  auto* subscription = static_cast<EqFctZmqTest::Subscription*>(self_);
  auto* eqfct = subscription->eqfct;
  eqfct->lock();

  time_t s;
  uint32_t us;
  data->time(&s, &us);
  int64_t usecs = s * 1000000 + us;
  //int64_t usecs = info->sec * 1000000 + info->usec;


  try {
    if(subscription->isMPSnumber) {
      eqfct->mpsReceivedMap[info->ident] = std::chrono::steady_clock::now();
      eqfct->mpsReceivedMap2[info->ident] = usecs;
      bool hasMissedData=false;
      for(auto& sub : eqfct->subscriptionMap) {
        if(sub.second.isMPSnumber) continue;
        if(!sub.second.receivedSinceLastTrigger) {
          if(!hasMissedData) {
            std::cout << "Event " << info->ident << " [" << std::put_time(std::localtime(&s), "%c %Z") << "] has missing data" << std::endl;
            hasMissedData = true;
          }
          std::cout << "Missing in last event: " << sub.second.name << std::endl;
        }
        sub.second.receivedSinceLastTrigger = false;
      }
      if(eqfct->usecs_last_mpn) {
        int64_t bin = (usecs - eqfct->usecs_last_mpn) / 1000 + NBINS / 2;
        if(bin > signed(NBINS - 1)) {
          std::cout << "overrun: " << bin << " " << subscription->name << std::endl;
          bin = NBINS - 1;
        }
        if(bin < 0) bin = 0;
        eqfct->hist_deltaXtimer[bin]++;

        if(info->ident != eqfct->last_mpn + 1) {
          std::cout << "MPN jumped: " << info->ident << " follows " << eqfct->last_mpn << std::endl;
        }
      }
      eqfct->usecs_last_mpn = usecs;
      eqfct->last_mpn = info->ident;
    }
    else {
      subscription->receivedSinceLastTrigger = true;
      auto found = eqfct->mpsReceivedMap.find(info->ident);
      int64_t bin = 0; // bin 0 -> MPS number not yet received
      int64_t bin2 = 0;
      if(eqfct->last_mpn > info->ident) {
        std::cout << subscription->name << " has arrived late for event " << info->ident << " [" << std::put_time(std::localtime(&s), "%c %Z") << "]." << std::endl;
      }
      if(found != eqfct->mpsReceivedMap.end()) {
        auto dt = std::chrono::steady_clock::now() - found->second;
        bin = std::chrono::duration_cast<std::chrono::milliseconds>(dt).count() + 1;
        bin2 = (usecs - eqfct->mpsReceivedMap2[info->ident]) / 1000 + NBINS / 2;
        if(std::abs(usecs - eqfct->mpsReceivedMap2[info->ident]) > 100000) {  // 100ms tolerance
          std::cout << "attached timestamp does not match: "
                    << std::round((usecs - eqfct->mpsReceivedMap2[info->ident]) / 1000.) << " " << subscription->name
                    << std::endl;
        }
        if(bin > signed(NBINS - 1)) {
          std::cout << "overrun: " << bin << " " << subscription->name << std::endl;
          bin = NBINS - 1;
        }
        if(bin2 > signed(NBINS - 1)) {
          std::cout << "overrun2: " << bin2 << " " << subscription->name << std::endl;
          bin2 = NBINS - 1;
        }
        if(bin < 0) bin = 0;
        if(bin2 < 0) bin2 = 0;
      }
      else {
        std::cout << "notfound: " << subscription->name << std::endl;
      }
      eqfct->hist_delayStamp[bin]++;
      eqfct->hist_delayClock[bin2]++;
    }
  }
  catch(...) {
    eqfct->unlock();
    throw;
  }

  eqfct->unlock();
}
