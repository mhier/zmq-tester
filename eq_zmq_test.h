#ifndef eq_vs_stat_h
#define eq_vs_stat_h

#include <vector>
#include "D_DOOCSdzmq.h"
#include <time.h>
#include "d_fct.h"
#include "eq_fct.h"
#include "eq_client.h"
#include <pthread.h>
#include <stdio.h>
#include <iostream>

#define ZmqTest_stat 10
constexpr size_t NBINS = 10002;

class EqFctZmqTest : public EqFct {
 public:
  EqFctZmqTest();

  void interrupt_usr1(int sig_no);
  void update();
  void init();
  void post_init();
  int fct_code() { return ZmqTest_stat; }

  D_spectrum prop_histogram{"HISTOGRAM", NBINS, this};
  D_spectrum prop_histogram2{"HISTOGRAM2", NBINS, this};

  D_string mpsZmqName{this, "MPS_ZMQNAME"};
  std::vector<D_string> addresses;

  std::map<int64_t, std::chrono::steady_clock::time_point> mpsReceivedMap;
  std::map<int64_t, int64_t> mpsReceivedMap2;

  /// Structure describing a single subscription
  struct Subscription {
    /// cached dmsg tag needed for cleanup
    dmsg_t tag;

    bool isMPSnumber{false};

    std::string name;

    EqFctZmqTest* eqfct;

    bool receivedSinceLastTrigger{true};
  };

  /// map of subscriptions
  std::map<std::string, Subscription> subscriptionMap;

  std::map<size_t, size_t> histogram, histogram2;

  static void zmq_callback(void* self_, EqData* data, dmsg_info_t*);
};

#endif
