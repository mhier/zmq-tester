#include "doocs/printtostderr.h"
#include <stdio.h>
#include "eq_zmq_test.h"
#include "eq_errors.h"
#include "eq_fct_errors.h"
#include <assert.h>
#include <sys/resource.h>
#include <boost/make_shared.hpp>

using namespace std;

pthread_t EqFctZmqTest::pthread_t_invalid;

int64_t EqFctZmqTest::usecs_last_mpn{0};
int64_t EqFctZmqTest::last_mpn{0};
std::vector<uint64_t> EqFctZmqTest::histogram;
std::mutex EqFctZmqTest::mx_hist;

/******************************************************************************************************************/

EqFctZmqTest::EqFctZmqTest() : EqFct("LOCATION") {
  pthread_t_invalid = pthread_self();
  histogram.resize(20001);
}

/******************************************************************************************************************/

void EqFctZmqTest::subscribe(const std::string& path, bool isMpn) {
  listenerHolder.push_back(boost::make_shared<Listener>(path, isMpn));

  std::unique_lock<std::mutex> lock(subscriptionMap_mutex);

  assert(subscriptionMap.find(path) == subscriptionMap.end());

  // gain lock for listener, to exclude concurrent access with the zmq_callback()
  std::unique_lock<std::mutex> listeners_lock(subscriptionMap[path].listeners_mutex);

  subscriptionMap[path].listeners.push_back(listenerHolder.back().get());

  // subscriptionMap is no longer used below this point
  lock.unlock();

  // from here, this is like ZMQSubscriptionManager::activate(path)
  assert(!subscriptionMap[path].active);

  names.push_back(path);

  // subscribe to property
  EqData dst;
  EqAdr ea;
  ea.adr(path);
  dmsg_t tag;
  int err = dmsg_attach(&ea, &dst, (void*)names.back().c_str(), &zmq_callback, &tag);
  if(err) {
    /// FIXME put error into queue of all accessors!
    throw std::runtime_error(
        std::string("Cannot subscribe to DOOCS property '" + path + "' via ZeroMQ: ") + dst.get_string());
  }

  // run dmsg_start() once
  std::unique_lock<std::mutex> lck(dmsgStartCalled_mutex);
  if(!dmsgStartCalled) {
    dmsg_start();
    dmsgStartCalled = true;
  }

  // set active flag, reset hasException flag
  subscriptionMap[path].active = true;
  subscriptionMap[path].hasException = false;
}

/******************************************************************************************************************/

void EqFctZmqTest::theThread() {
  std::vector<cppext::future_queue<EqData>> qothers;
  cppext::future_queue<EqData> qmpn;

  {
    std::unique_lock<std::mutex> lk(subscriptionMap_mutex);

    for(auto& sub : subscriptionMap) {
      if(sub.second.listeners.front()->isMpn) {
        qmpn = sub.second.listeners.front()->notifications;
      }
      else {
        qothers.push_back(sub.second.listeners.front()->notifications);
      }
    }
  }

  while(true) {
    try {
      EqData data;
      qmpn.pop_wait(data);

      int64_t mpn = data.get_long();
      if(last_mpn != 0) {
        if(mpn != last_mpn + 1) {
          printftostderr("zmq_test", "GAP! %ld events missing! %ld -> %ld", mpn - last_mpn - 1, last_mpn, mpn);
        }
      }
      last_mpn = mpn;

      for(auto& q : qothers) {
        while(q.pop()) continue;
      }
    }
    catch(std::runtime_error& e) {
      printftostderr("zmq_test", "ERROR! %s", e.what());
    }
  }
}

/******************************************************************************************************************/

void EqFctZmqTest::update() {
    std::unique_lock<std::mutex> lk(mx_hist);

    spec_hist.spectrum_parameter(spec_hist.spec_time(), -10000., 1, spec_hist.spec_status());
    for(size_t i=0; i<20001; ++i) {
      spec_hist.fill_spectrum(i, histogram[i]);
    }
    spec_hist.egu(1, 1., 100000., "counts");
    spec_hist.xegu(0,-10000., 10000., "ms");


    // clear histogram after 3 seconds to get rid of startup garbage
    ++updateCounter;
    if(updateCounter == 3) {
        printtostderr("update","Reset histogram after startup");
        for(size_t i=0; i<20001; ++i) {
            histogram[i] = 0;
        }
    }
}

/******************************************************************************************************************/

void EqFctZmqTest::post_init() {
  subscribe("XFEL.RF/TIMER/LLA2SPS/MACRO_PULSE_NUMBER", true);
  subscribe("XFEL.RF/TIMER/LLA2SPS/BUNCH_POSITION.1");
  subscribe("XFEL.RF/TIMER/LLA2SPS/BUNCH_POSITION.2");
  subscribe("XFEL.RF/TIMER/LLA2SPS/BUNCH_POSITION.3");
  subscribe("XFEL.RF/LLRF.CONTROLLER/MAIN.M12.A2SP.L1/GLOBAL_SAMPLING.OFFSET.1");
  subscribe("XFEL.RF/LLRF.CONTROLLER/MAIN.M12.A2SP.L1/GLOBAL_SAMPLING.OFFSET.2");
  subscribe("XFEL.RF/LLRF.CONTROLLER/MAIN.M12.A2SP.L1/GLOBAL_SAMPLING.OFFSET.3");
  subscribe("XFEL.RF/LLRF.CONTROLLER/MAIN.M12.A2SP.L1/PULSE_DELAY");
  subscribe("XFEL.RF/LLRF.CONTROLLER/MAIN.M12.A2SP.L1/PULSE_FILLING");
  subscribe("XFEL.RF/LLRF.CONTROLLER/MAIN.M12.A2SP.L1/PULSE_FLATTOP");
  subscribe("XFEL.RF/LLRF.CONTROLLER/MAIN.M12.A2SP.L1/REFERENCE_PHASES.LOCAL_AVERAGE");

  hThread = std::thread([this] { this->theThread(); });
}

/******************************************************************************************************************/

void EqFctZmqTest::zmq_callback(void* name_, EqData* data, dmsg_info_t* info) {
  char* name = static_cast<char*>(name_);

  // Make sure the stamp is used from the ZeroMQ header. TODO: Is this really wanted?
  data->time(info->sec, info->usec);
  data->mpnum(info->ident);

  auto now = doocs::Timestamp::now();
  auto ts = data->get_timestamp();
  int diff = (now-ts).count()/1e6;
  {
    std::unique_lock<std::mutex> lk(mx_hist);
    ++histogram[std::max(std::min(diff,10000),-10000)+10000];
  }

  if(diff > 90) {
    printftostderr("zmq_callback", "Long delay detected: %d ms for %s", diff, name);
  }

}

/******************************************************************************************************************/
