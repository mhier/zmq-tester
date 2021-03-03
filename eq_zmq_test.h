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

  std::vector<std::string> names;

  static void zmq_callback(void* self_, EqData* data, dmsg_info_t*);

  void subscribe(const std::string& pathe);


  static std::vector<uint64_t> histogram;
  static std::mutex mx_hist;

  uint64_t updateCounter{0};
};

#endif
