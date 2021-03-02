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
#include <ChimeraTK/cppext/future_queue.hpp>
#include <boost/shared_ptr.hpp>

/******************************************************************************************************************/

struct Listener {
  explicit Listener(const std::string& path_, bool isMpn_ = false) : path(path_), isMpn(isMpn_) {}
  std::string path;
  bool isMpn;
  cppext::future_queue<EqData> notifications{3};
  bool isActiveZMQ{true};
};

/******************************************************************************************************************/

class EqFctZmqTest : public EqFct {
 public:
  EqFctZmqTest();

  void interrupt_usr1(int){};
  void update();
  void init(){};
  void post_init();
  int fct_code() { return 10; }

  static int64_t usecs_last_mpn;
  static int64_t last_mpn;

  D_spectrum spec_hist{"HIST", 20001, this};

  /** static flag if dmsg_start() has been called already, with mutex for thread safety */
  bool dmsgStartCalled{false};
  std::mutex dmsgStartCalled_mutex;

  /// A "random" value of pthread_t which we consider "invalid" in context of Subscription::zqmThreadId. Technically
  /// we use a valid pthread_t of a thread which cannot be a ZeroMQ subscription thread. All values of
  /// Subscription::zqmThreadId will be initialised with this value.
  static pthread_t pthread_t_invalid;

  std::vector<boost::shared_ptr<Listener>> listenerHolder;

  /// Structure describing a single subscription
  struct Subscription {
    Subscription() : zqmThreadId(EqFctZmqTest::pthread_t_invalid) {}

    /// list of accessors listening to the ZMQ subscription.
    /// Accessing this vector requires holding zmq_callback_extra_listeners_mutex
    /// It's ok to use plain pointers here, since accessors will unsubscribe themselves in their destructor
    std::vector<Listener*> listeners;

    /// Mutex for zmq_callback_extra_listeners
    std::mutex listeners_mutex;

    /// Thread ID of the ZeroMQ subscription thread which calls zmq_callback. This is a DOOCS thread and hence
    /// outside our control. We store the ID inside zmq_callback so we can check whether the thread has been
    /// properly terminated in the cleanup phase. listeners_mutex must be held while accessing this variable.
    pthread_t zqmThreadId;

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

  void theThread();
  std::thread hThread;

  void subscribe(const std::string& path, bool isMpn = false);


  static std::vector<uint64_t> histogram;
  static std::mutex mx_hist;

  uint64_t updateCounter{0};
};

#endif
