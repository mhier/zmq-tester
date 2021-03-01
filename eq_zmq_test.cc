
#include <stdio.h>
#include "eq_zmq_test.h"
#include "eq_errors.h"
#include "eq_fct_errors.h"
#include <assert.h>
#include <sys/resource.h>

using namespace std;


int64_t EqFctZmqTest::usecs_last_mpn{0};
int64_t EqFctZmqTest::last_mpn{0};

EqFctZmqTest::EqFctZmqTest() : EqFct("LOCATION") {
}


void EqFctZmqTest::subscribe(const std::string& path, bool isMpn) {

  std::unique_lock<std::mutex> lock(subscriptionMap_mutex);

  assert(subscriptionMap.find(path) == subscriptionMap.end());

  // gain lock for listener, to exclude concurrent access with the zmq_callback()
  std::unique_lock<std::mutex> listeners_lock(subscriptionMap[path].listeners_mutex);


  // subscriptionMap is no longer used below this point
  lock.unlock();

  subscriptionMap[path].path = path;
  subscriptionMap[path].isMpn=isMpn;

  assert(!subscriptionMap[path].active);

  // subscribe to property
  EqData dst;
  EqAdr ea;
  ea.adr(path);
  dmsg_t tag;
  int err = dmsg_attach(&ea, &dst, (void*)&(subscriptionMap[path]), &zmq_callback, &tag);
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

void EqFctZmqTest::interrupt_usr1(int) {}
void EqFctZmqTest::init() {}
void EqFctZmqTest::post_init() {
  subscribe("XFEL.RF/TIMER/LLA2SPS/MACRO_PULSE_NUMBER",true);
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
}

void EqFctZmqTest::update() {

}

void EqFctZmqTest::zmq_callback(void* self_, EqData* data, dmsg_info_t* info) {
    // obtain pointer to subscription object
    auto* subscription = static_cast<Subscription*>(self_);

    // Make sure the stamp is used from the ZeroMQ header. TODO: Is this really wanted?
    data->time(info->sec, info->usec);
    data->mpnum(info->ident);

    std::unique_lock<std::mutex> lock(subscription->listeners_mutex);

    // As long as we get a callback from ZMQ, we consider it started
    if(not subscription->started) {
      subscription->started = true;
      subscription->startedCv.notify_all();
    }

    // check for error
    if(data->error() != no_connection) {
      // no error: push the data
      subscription->hasException = false;

      if(subscription->isMpn) {
        int64_t mpn = data->get_long();
        if(last_mpn != 0) {
           if(mpn != last_mpn+1) {
             std::cout << "GAP! " <<mpn-last_mpn+1<< " MPN missing" << std::endl;
           }
        }
        last_mpn = mpn;
        std::cout << mpn << std::endl;
      }
    }
    else {
      std::cout << "Error: " << subscription->path << std::endl;
    }

}
