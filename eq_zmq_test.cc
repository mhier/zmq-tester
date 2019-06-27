
#include <stdio.h>
#include "eq_zmq_test.h"
#include "eq_errors.h"
#include "eq_sts_codes.h"
#include "eq_fct_errors.h"
#include "printtostderr.h"
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
  prop_histogram.set_ro_access();
  for(size_t i = 0; i < NBINS; ++i) {
    prop_histogram.fill_spectrum(i, histogram[i]);
  }
  prop_histogram.spectrum_parameter(0, -1, 1, 0);
  prop_histogram.xegu(0, -100, NBINS - 2 + 100, "ms");

  prop_histogram2.set_ro_access();
  for(size_t i = 0; i < NBINS; ++i) {
    prop_histogram2.fill_spectrum(i, histogram2[i]);
  }
  prop_histogram2.spectrum_parameter(0, -int(NBINS) / 2., 1, 0);
  prop_histogram2.xegu(0, -int(NBINS) / 2. - 100, NBINS / 2. + 100, "ms");
}

void EqFctZmqTest::zmq_callback(void* self_, EqData* data, dmsg_info_t* info) {
  auto* subscription = static_cast<EqFctZmqTest::Subscription*>(self_);
  auto* eqfct = subscription->eqfct;
  eqfct->lock();

  int64_t usecs = info->sec * 1000000 + info->usec;
  /*int dsecs, dusecs;
  data->time(&dsecs,&dusecs);
  if(dsecs != info->sec || dusecs != info->usec) {
  }*/

  try {
    if(subscription->isMPSnumber) {
      eqfct->mpsReceivedMap[info->ident] = std::chrono::steady_clock::now();
      eqfct->mpsReceivedMap2[info->ident] = usecs;
      for(auto& sub : eqfct->subscriptionMap) {
        if(sub.second.isMPSnumber) continue;
        if(!sub.second.receivedSinceLastTrigger) {
          std::cout << "Missing in last event: " << sub.second.name << std::endl;
        }
        sub.second.receivedSinceLastTrigger = false;
      }
    }
    else {
      subscription->receivedSinceLastTrigger = true;
      auto found = eqfct->mpsReceivedMap.find(info->ident);
      int64_t bin = 0; // bin 0 -> MPS number not yet received
      int64_t bin2 = 0;
      if(found != eqfct->mpsReceivedMap.end()) {
        auto dt = std::chrono::steady_clock::now() - found->second;
        bin = std::chrono::duration_cast<std::chrono::milliseconds>(dt).count() + 1;
        bin2 = (usecs - eqfct->mpsReceivedMap2[info->ident]) / 1000 + NBINS / 2;
        if((usecs - eqfct->mpsReceivedMap2[info->ident]) != 0) {
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
      eqfct->histogram[bin]++;
      eqfct->histogram2[bin2]++;
    }
  }
  catch(...) {
    eqfct->unlock();
    throw;
  }

  eqfct->unlock();
}
