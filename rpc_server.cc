
#include "eq_zmq_test.h"
#include "eq_errors.h"
#include "eq_fct_errors.h"
#include "d_fct.h"
#include "eq_fct.h"
#include "eq_client.h"
#include "DOOCSsleep.h"
#include <fstream>
#include <time.h>
#include <assert.h>
#include <stdio.h>

const char* object_name = "zmq_tester";

extern int fct_code;
extern int arch_mode;
// server-wide globals
/*int beam_sts;
int     buff_, last_bunch_ind;
float char_spec[16][2048];
float char_th=0.2;
*/
void eq_init_prolog() {
  set_arch_mode(1);
} // called once before init of all EqFct's

void eq_init_epilog() {} // called once at end of init of all EqFct's

//
// used during startup of the server to create the locations
//
EqFct* eq_create(int eq_code, void*) {
  EqFct* eqn = nullptr;

  switch(eq_code) {
    case 10:
      eqn = new EqFctZmqTest();
      break;
  }
  return eqn;
}

void init() {}
void refresh_prolog() {}

void refresh_epilog() {} // called after "update"

//
// The following methods are provided, when the server needs to use SIGUSR1 or SIGUSR2
// interrupts (from timing system)
//
void interrupt_usr1_prolog(int) {}
void interrupt_usr2_prolog(void) {}
void interrupt_usr1_epilog(int) {}
void interrupt_usr2_epilog(void) {}
void post_init_prolog(void) {}
void post_init_epilog(void) {
  // Setup interrupts to call interrupt_usr1() method,but with an internal call
  int no_interrupt = setup_interrupt_usr1(0); // enable interrupt on SIGUSR1
  if(no_interrupt) {
    printtostderr("post_init_epilog", "Failed to setup interrupt SIGUSR1");
    return;
  }
}
void eq_cancel(void) {}
