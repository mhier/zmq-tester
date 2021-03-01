#ifndef eq_vs_stat_h
#define eq_vs_stat_h

#include <vector>
#include <time.h>
#include "d_fct.h"
#include "eq_fct.h"
#include "eq_client.h"
#include <pthread.h>
#include <stdio.h>
#include <iostream>

#define ZmqTest_stat 10
constexpr size_t NBINS = 222;

class EqFctZmqTest : public EqFct {
 public:
  EqFctZmqTest();

  void interrupt_usr1(int sig_no);
  void update();
  void init();
  void post_init();
  int fct_code() { return ZmqTest_stat; }

  static int64_t usecs_last_mpn;
  static int64_t last_mpn;


  /** static flag if dmsg_start() has been called already, with mutex for thread safety */
  bool dmsgStartCalled{false};
  std::mutex dmsgStartCalled_mutex;


  /// Structure describing a single subscription
  struct Subscription {
    Subscription()  {}
    std::string path;
    bool isMpn{false};

    /// Mutex for zmq_callback_extra_listeners
    std::mutex listeners_mutex;

    /// Flag whether the subscription is currently active, i.e. whether the actual DOOCS subscription has been made.
    /// This is used to implement activateAsyncRead() properly. listeners_mutex must be held while accessing this
    /// variable.
    bool active{false};

    /// Flag whether the callback function has already been called for this subscription, with a condition variable
    /// for the notification when the callback is called for the first time.
    bool started{false};
    std::condition_variable startedCv{};

    /// Flag whether an exception has been reported to the listeners since the last activation. Used to prevent
    /// duplicate exceptions in setException(). Will be cleared during activation. Access requires listeners_mutex.
    bool hasException{false};
  };



  /// map of subscriptions
  std::map<std::string, Subscription> subscriptionMap;

  /// mutex for subscriptionMap
  std::mutex subscriptionMap_mutex;


  static void zmq_callback(void* self_, EqData* data, dmsg_info_t*);



  /******************************************************************************************************************/

  void subscribe(const std::string& path, bool isMpn=false);


};

#endif
