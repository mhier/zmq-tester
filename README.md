Example output for a single incident:

```
2021-03-04T11:31:46 Server-20.10.1-fo... ****************************************
2021-03-04T11:31:46 Server-20.10.1-fo... System restart
2021-03-04T11:31:46 Server-20.10.1-fo... Working directory: /home/mhier/zmq_tester/build/A2SPS
2021-03-04T11:31:46 zmq_tester_server... No hard error
2021-03-04T11:31:46 Server-20.10.1-fo... Messaging inactive, base port not set
2021-03-04T11:31:46 Server-20.10.1-fo... Init phase completed
2021-03-04T11:31:46 Server-20.10.1-fo... Customer uid/gid are missing
2021-03-04T11:31:46 Server-20.10.1-fo... DOOCS server:    TEST.DOOCS/XFELCPULLA25S_610498010/LOCALHOST._SVR - programmer: wilksen
2021-03-04T11:31:46 Server-20.10.1-fo... DOOCS serverlib: Built on host xfelvdev20 by wilksen on Oct 28 2020 at 14:34:22
2021-03-04T11:31:46 Server-20.10.1-fo... Archiver runs in advanced mode
2021-03-04T11:31:46 Server-20.10.1-fo... Archiver does not use HIST_DIR
2021-03-04T11:31:46 Server-20.10.1-fo... Started with 2 locations on xfelcpulla2sps - DOOCSARCH = Ubuntu-20.04-x86_64
2021-03-04T11:31:46 dmsg_open            libzmq version: 4.3.2
Subscribing: XFEL.RF/TIMER/LLA2SPS/MACRO_PULSE_NUMBER
Subscribing: XFEL.RF/TIMER/LLA2SPS/BUNCH_POSITION.1
Subscribing: XFEL.RF/TIMER/LLA2SPS/BUNCH_POSITION.2
Subscribing: XFEL.RF/TIMER/LLA2SPS/BUNCH_POSITION.3
Subscribing: XFEL.RF/LLRF.CONTROLLER/MAIN.M12.A2SP.L1/GLOBAL_SAMPLING.OFFSET.1
Subscribing: XFEL.RF/LLRF.CONTROLLER/MAIN.M12.A2SP.L1/GLOBAL_SAMPLING.OFFSET.2
Subscribing: XFEL.RF/LLRF.CONTROLLER/MAIN.M12.A2SP.L1/GLOBAL_SAMPLING.OFFSET.3
Subscribing: XFEL.RF/LLRF.CONTROLLER/MAIN.M12.A2SP.L1/PULSE_DELAY
Subscribing: XFEL.RF/LLRF.CONTROLLER/MAIN.M12.A2SP.L1/PULSE_FILLING
Subscribing: XFEL.RF/LLRF.CONTROLLER/MAIN.M12.A2SP.L1/PULSE_FLATTOP
Subscribing: XFEL.RF/LLRF.CONTROLLER/MAIN.M12.A2SP.L1/REFERENCE_PHASES.LOCAL_AVERAGE
2021-03-04T11:31:46 Server-20.10.1-fo... Post-init phase completed
2021-03-04T11:31:49 update               Reset histogram after startup
2021-03-04T11:42:39 zmq_callback         Long delay detected: 5028 ms for XFEL.RF/TIMER/LLA2SPS/MACRO_PULSE_NUMBER
2021-03-04T11:42:39 zmq_callback         Long delay detected: 5028 ms for XFEL.RF/TIMER/LLA2SPS/BUNCH_POSITION.1
2021-03-04T11:42:39 zmq_callback         Long delay detected: 4928 ms for XFEL.RF/TIMER/LLA2SPS/MACRO_PULSE_NUMBER
2021-03-04T11:42:39 zmq_callback         Long delay detected: 4928 ms for XFEL.RF/TIMER/LLA2SPS/BUNCH_POSITION.1
2021-03-04T11:42:39 zmq_callback         Long delay detected: 4828 ms for XFEL.RF/TIMER/LLA2SPS/MACRO_PULSE_NUMBER
2021-03-04T11:42:39 zmq_callback         Long delay detected: 4828 ms for XFEL.RF/TIMER/LLA2SPS/BUNCH_POSITION.1
2021-03-04T11:42:39 zmq_callback         Long delay detected: 5028 ms for XFEL.RF/TIMER/LLA2SPS/BUNCH_POSITION.2
2021-03-04T11:42:39 zmq_callback         Long delay detected: 4928 ms for XFEL.RF/TIMER/LLA2SPS/BUNCH_POSITION.2
2021-03-04T11:42:39 zmq_callback         Long delay detected: 4728 ms for XFEL.RF/TIMER/LLA2SPS/BUNCH_POSITION.1
2021-03-04T11:42:39 zmq_callback         Long delay detected: 5028 ms for XFEL.RF/TIMER/LLA2SPS/BUNCH_POSITION.3
2021-03-04T11:42:39 zmq_callback         Long delay detected: 4728 ms for XFEL.RF/TIMER/LLA2SPS/MACRO_PULSE_NUMBER
2021-03-04T11:42:39 zmq_callback         Long delay detected: 4828 ms for XFEL.RF/TIMER/LLA2SPS/BUNCH_POSITION.2
2021-03-04T11:42:39 zmq_callback         Long delay detected: 4928 ms for XFEL.RF/TIMER/LLA2SPS/BUNCH_POSITION.3
2021-03-04T11:42:39 zmq_callback         Long delay detected: 4628 ms for XFEL.RF/TIMER/LLA2SPS/BUNCH_POSITION.1
2021-03-04T11:42:39 zmq_callback         Long delay detected: 4828 ms for XFEL.RF/TIMER/LLA2SPS/BUNCH_POSITION.3
2021-03-04T11:42:39 zmq_callback         Long delay detected: 4728 ms for XFEL.RF/TIMER/LLA2SPS/BUNCH_POSITION.2
2021-03-04T11:42:39 zmq_callback         Long delay detected: 4628 ms for XFEL.RF/TIMER/LLA2SPS/MACRO_PULSE_NUMBER
2021-03-04T11:42:39 zmq_callback         Long delay detected: 4628 ms for XFEL.RF/TIMER/LLA2SPS/BUNCH_POSITION.2
2021-03-04T11:42:39 zmq_callback         Long delay detected: 4528 ms for XFEL.RF/TIMER/LLA2SPS/MACRO_PULSE_NUMBER
2021-03-04T11:42:39 zmq_callback         Long delay detected: 4728 ms for XFEL.RF/TIMER/LLA2SPS/BUNCH_POSITION.3
2021-03-04T11:42:39 zmq_callback         Long delay detected: 4428 ms for XFEL.RF/TIMER/LLA2SPS/MACRO_PULSE_NUMBER
2021-03-04T11:42:39 zmq_callback         Long delay detected: 4628 ms for XFEL.RF/TIMER/LLA2SPS/BUNCH_POSITION.3
2021-03-04T11:42:39 zmq_callback         Long delay detected: 4328 ms for XFEL.RF/TIMER/LLA2SPS/MACRO_PULSE_NUMBER
2021-03-04T11:42:39 zmq_callback         Long delay detected: 4528 ms for XFEL.RF/TIMER/LLA2SPS/BUNCH_POSITION.3
2021-03-04T11:42:39 zmq_callback         Long delay detected: 4228 ms for XFEL.RF/TIMER/LLA2SPS/MACRO_PULSE_NUMBER
2021-03-04T11:42:39 zmq_callback         Long delay detected: 4428 ms for XFEL.RF/TIMER/LLA2SPS/BUNCH_POSITION.3
2021-03-04T11:42:39 zmq_callback         Long delay detected: 4528 ms for XFEL.RF/TIMER/LLA2SPS/BUNCH_POSITION.1
2021-03-04T11:42:39 zmq_callback         Long delay detected: 4328 ms for XFEL.RF/TIMER/LLA2SPS/BUNCH_POSITION.3
2021-03-04T11:42:39 zmq_callback         Long delay detected: 4128 ms for XFEL.RF/TIMER/LLA2SPS/MACRO_PULSE_NUMBER
2021-03-04T11:42:39 zmq_callback         Long delay detected: 4228 ms for XFEL.RF/TIMER/LLA2SPS/BUNCH_POSITION.3
2021-03-04T11:42:39 zmq_callback         Long delay detected: 4528 ms for XFEL.RF/TIMER/LLA2SPS/BUNCH_POSITION.2
2021-03-04T11:42:39 zmq_callback         Long delay detected: 4128 ms for XFEL.RF/TIMER/LLA2SPS/BUNCH_POSITION.3
2021-03-04T11:42:39 zmq_callback         Long delay detected: 4028 ms for XFEL.RF/TIMER/LLA2SPS/MACRO_PULSE_NUMBER
2021-03-04T11:42:39 zmq_callback         Long delay detected: 4028 ms for XFEL.RF/TIMER/LLA2SPS/BUNCH_POSITION.3
2021-03-04T11:42:39 zmq_callback         Long delay detected: 4428 ms for XFEL.RF/TIMER/LLA2SPS/BUNCH_POSITION.2
2021-03-04T11:42:39 zmq_callback         Long delay detected: 4428 ms for XFEL.RF/TIMER/LLA2SPS/BUNCH_POSITION.1
2021-03-04T11:42:39 zmq_callback         Long delay detected: 3928 ms for XFEL.RF/TIMER/LLA2SPS/MACRO_PULSE_NUMBER
2021-03-04T11:42:39 zmq_callback         Long delay detected: 3928 ms for XFEL.RF/TIMER/LLA2SPS/BUNCH_POSITION.3
2021-03-04T11:42:39 zmq_callback         Long delay detected: 4328 ms for XFEL.RF/TIMER/LLA2SPS/BUNCH_POSITION.1
2021-03-04T11:42:39 zmq_callback         Long delay detected: 3828 ms for XFEL.RF/TIMER/LLA2SPS/BUNCH_POSITION.3
2021-03-04T11:42:39 zmq_callback         Long delay detected: 4328 ms for XFEL.RF/TIMER/LLA2SPS/BUNCH_POSITION.2
2021-03-04T11:42:39 zmq_callback         Long delay detected: 3728 ms for XFEL.RF/TIMER/LLA2SPS/BUNCH_POSITION.3
2021-03-04T11:42:39 zmq_callback         Long delay detected: 4228 ms for XFEL.RF/TIMER/LLA2SPS/BUNCH_POSITION.1
2021-03-04T11:42:39 zmq_callback         Long delay detected: 3628 ms for XFEL.RF/TIMER/LLA2SPS/BUNCH_POSITION.3
2021-03-04T11:42:39 zmq_callback         Long delay detected: 3828 ms for XFEL.RF/TIMER/LLA2SPS/MACRO_PULSE_NUMBER
2021-03-04T11:42:39 zmq_callback         Long delay detected: 3528 ms for XFEL.RF/TIMER/LLA2SPS/BUNCH_POSITION.3
2021-03-04T11:42:39 zmq_callback         Long delay detected: 4128 ms for XFEL.RF/TIMER/LLA2SPS/BUNCH_POSITION.1
2021-03-04T11:42:39 zmq_callback         Long delay detected: 3428 ms for XFEL.RF/TIMER/LLA2SPS/BUNCH_POSITION.3
2021-03-04T11:42:39 zmq_callback         Long delay detected: 4028 ms for XFEL.RF/TIMER/LLA2SPS/BUNCH_POSITION.1
2021-03-04T11:42:39 zmq_callback         Long delay detected: 4228 ms for XFEL.RF/TIMER/LLA2SPS/BUNCH_POSITION.2
2021-03-04T11:42:39 zmq_callback         Long delay detected: 3728 ms for XFEL.RF/TIMER/LLA2SPS/MACRO_PULSE_NUMBER
2021-03-04T11:42:39 zmq_callback         Long delay detected: 4128 ms for XFEL.RF/TIMER/LLA2SPS/BUNCH_POSITION.2
2021-03-04T11:42:39 zmq_callback         Long delay detected: 3928 ms for XFEL.RF/TIMER/LLA2SPS/BUNCH_POSITION.1
2021-03-04T11:42:39 zmq_callback         Long delay detected: 4028 ms for XFEL.RF/TIMER/LLA2SPS/BUNCH_POSITION.2
2021-03-04T11:42:39 zmq_callback         Long delay detected: 3828 ms for XFEL.RF/TIMER/LLA2SPS/BUNCH_POSITION.1
2021-03-04T11:42:39 zmq_callback         Long delay detected: 3628 ms for XFEL.RF/TIMER/LLA2SPS/MACRO_PULSE_NUMBER
2021-03-04T11:42:39 zmq_callback         Long delay detected: 3728 ms for XFEL.RF/TIMER/LLA2SPS/BUNCH_POSITION.1
2021-03-04T11:42:39 zmq_callback         Long delay detected: 3328 ms for XFEL.RF/TIMER/LLA2SPS/BUNCH_POSITION.3
2021-03-04T11:42:39 zmq_callback         Long delay detected: 3528 ms for XFEL.RF/TIMER/LLA2SPS/MACRO_PULSE_NUMBER
2021-03-04T11:42:39 zmq_callback         Long delay detected: 3228 ms for XFEL.RF/TIMER/LLA2SPS/BUNCH_POSITION.3
2021-03-04T11:42:39 zmq_callback         Long delay detected: 3928 ms for XFEL.RF/TIMER/LLA2SPS/BUNCH_POSITION.2
2021-03-04T11:42:39 zmq_callback         Long delay detected: 3628 ms for XFEL.RF/TIMER/LLA2SPS/BUNCH_POSITION.1
2021-03-04T11:42:39 zmq_callback         Long delay detected: 3128 ms for XFEL.RF/TIMER/LLA2SPS/BUNCH_POSITION.3
2021-03-04T11:42:39 zmq_callback         Long delay detected: 3528 ms for XFEL.RF/TIMER/LLA2SPS/BUNCH_POSITION.1
2021-03-04T11:42:39 zmq_callback         Long delay detected: 3829 ms for XFEL.RF/TIMER/LLA2SPS/BUNCH_POSITION.2
2021-03-04T11:42:39 zmq_callback         Long delay detected: 3028 ms for XFEL.RF/TIMER/LLA2SPS/BUNCH_POSITION.3
2021-03-04T11:42:39 zmq_callback         Long delay detected: 3428 ms for XFEL.RF/TIMER/LLA2SPS/MACRO_PULSE_NUMBER
2021-03-04T11:42:39 zmq_callback         Long delay detected: 3729 ms for XFEL.RF/TIMER/LLA2SPS/BUNCH_POSITION.2
2021-03-04T11:42:39 zmq_callback         Long delay detected: 3428 ms for XFEL.RF/TIMER/LLA2SPS/BUNCH_POSITION.1
2021-03-04T11:42:39 zmq_callback         Long delay detected: 2928 ms for XFEL.RF/TIMER/LLA2SPS/BUNCH_POSITION.3
2021-03-04T11:42:39 zmq_callback         Long delay detected: 3629 ms for XFEL.RF/TIMER/LLA2SPS/BUNCH_POSITION.2
2021-03-04T11:42:39 zmq_callback         Long delay detected: 3328 ms for XFEL.RF/TIMER/LLA2SPS/MACRO_PULSE_NUMBER
2021-03-04T11:42:39 zmq_callback         Long delay detected: 3328 ms for XFEL.RF/TIMER/LLA2SPS/BUNCH_POSITION.1
2021-03-04T11:42:39 zmq_callback         Long delay detected: 3529 ms for XFEL.RF/TIMER/LLA2SPS/BUNCH_POSITION.2
2021-03-04T11:42:39 zmq_callback         Long delay detected: 3229 ms for XFEL.RF/TIMER/LLA2SPS/BUNCH_POSITION.1
2021-03-04T11:42:39 zmq_callback         Long delay detected: 3229 ms for XFEL.RF/TIMER/LLA2SPS/MACRO_PULSE_NUMBER
2021-03-04T11:42:39 zmq_callback         Long delay detected: 3129 ms for XFEL.RF/TIMER/LLA2SPS/BUNCH_POSITION.1
2021-03-04T11:42:39 zmq_callback         Long delay detected: 3129 ms for XFEL.RF/TIMER/LLA2SPS/MACRO_PULSE_NUMBER
2021-03-04T11:42:39 zmq_callback         Long delay detected: 2828 ms for XFEL.RF/TIMER/LLA2SPS/BUNCH_POSITION.3
2021-03-04T11:42:39 zmq_callback         Long delay detected: 3429 ms for XFEL.RF/TIMER/LLA2SPS/BUNCH_POSITION.2
2021-03-04T11:42:39 zmq_callback         Long delay detected: 2729 ms for XFEL.RF/TIMER/LLA2SPS/BUNCH_POSITION.3
2021-03-04T11:42:39 zmq_callback         Long delay detected: 3029 ms for XFEL.RF/TIMER/LLA2SPS/MACRO_PULSE_NUMBER
2021-03-04T11:42:39 zmq_callback         Long delay detected: 3029 ms for XFEL.RF/TIMER/LLA2SPS/BUNCH_POSITION.1
2021-03-04T11:42:39 zmq_callback         Long delay detected: 3329 ms for XFEL.RF/TIMER/LLA2SPS/BUNCH_POSITION.2
2021-03-04T11:42:39 zmq_callback         Long delay detected: 2629 ms for XFEL.RF/TIMER/LLA2SPS/BUNCH_POSITION.3
2021-03-04T11:42:39 zmq_callback         Long delay detected: 2929 ms for XFEL.RF/TIMER/LLA2SPS/BUNCH_POSITION.1
2021-03-04T11:42:39 zmq_callback         Long delay detected: 3229 ms for XFEL.RF/TIMER/LLA2SPS/BUNCH_POSITION.2
2021-03-04T11:42:39 zmq_callback         Long delay detected: 2829 ms for XFEL.RF/TIMER/LLA2SPS/BUNCH_POSITION.1
2021-03-04T11:42:39 zmq_callback         Long delay detected: 2929 ms for XFEL.RF/TIMER/LLA2SPS/MACRO_PULSE_NUMBER
2021-03-04T11:42:39 zmq_callback         Long delay detected: 2729 ms for XFEL.RF/TIMER/LLA2SPS/BUNCH_POSITION.1
2021-03-04T11:42:39 zmq_callback         Long delay detected: 3129 ms for XFEL.RF/TIMER/LLA2SPS/BUNCH_POSITION.2
2021-03-04T11:42:39 zmq_callback         Long delay detected: 2529 ms for XFEL.RF/TIMER/LLA2SPS/BUNCH_POSITION.3
2021-03-04T11:42:39 zmq_callback         Long delay detected: 3029 ms for XFEL.RF/TIMER/LLA2SPS/BUNCH_POSITION.2
2021-03-04T11:42:39 zmq_callback         Long delay detected: 2629 ms for XFEL.RF/TIMER/LLA2SPS/BUNCH_POSITION.1
2021-03-04T11:42:39 zmq_callback         Long delay detected: 2929 ms for XFEL.RF/TIMER/LLA2SPS/BUNCH_POSITION.2
2021-03-04T11:42:39 zmq_callback         Long delay detected: 2829 ms for XFEL.RF/TIMER/LLA2SPS/MACRO_PULSE_NUMBER
2021-03-04T11:42:39 zmq_callback         Long delay detected: 2429 ms for XFEL.RF/TIMER/LLA2SPS/BUNCH_POSITION.3
2021-03-04T11:42:39 zmq_callback         Long delay detected: 2829 ms for XFEL.RF/TIMER/LLA2SPS/BUNCH_POSITION.2
2021-03-04T11:42:39 zmq_callback         Long delay detected: 2729 ms for XFEL.RF/TIMER/LLA2SPS/BUNCH_POSITION.2
2021-03-04T11:42:39 zmq_callback         Long delay detected: 2729 ms for XFEL.RF/TIMER/LLA2SPS/MACRO_PULSE_NUMBER
2021-03-04T11:42:39 zmq_callback         Long delay detected: 2529 ms for XFEL.RF/TIMER/LLA2SPS/BUNCH_POSITION.1
2021-03-04T11:42:39 zmq_callback         Long delay detected: 2629 ms for XFEL.RF/TIMER/LLA2SPS/BUNCH_POSITION.2
2021-03-04T11:42:39 zmq_callback         Long delay detected: 2429 ms for XFEL.RF/TIMER/LLA2SPS/BUNCH_POSITION.1
2021-03-04T11:42:39 zmq_callback         Long delay detected: 2629 ms for XFEL.RF/TIMER/LLA2SPS/MACRO_PULSE_NUMBER
2021-03-04T11:42:39 zmq_callback         Long delay detected: 2329 ms for XFEL.RF/TIMER/LLA2SPS/BUNCH_POSITION.1
2021-03-04T11:42:39 zmq_callback         Long delay detected: 2529 ms for XFEL.RF/TIMER/LLA2SPS/BUNCH_POSITION.2
2021-03-04T11:42:39 zmq_callback         Long delay detected: 2229 ms for XFEL.RF/TIMER/LLA2SPS/BUNCH_POSITION.1
2021-03-04T11:42:39 zmq_callback         Long delay detected: 2329 ms for XFEL.RF/TIMER/LLA2SPS/BUNCH_POSITION.3
2021-03-04T11:42:39 zmq_callback         Long delay detected: 2529 ms for XFEL.RF/TIMER/LLA2SPS/MACRO_PULSE_NUMBER
2021-03-04T11:42:39 zmq_callback         Long delay detected: 2229 ms for XFEL.RF/TIMER/LLA2SPS/BUNCH_POSITION.3
2021-03-04T11:42:39 zmq_callback         Long delay detected: 2429 ms for XFEL.RF/TIMER/LLA2SPS/BUNCH_POSITION.2
2021-03-04T11:42:39 zmq_callback         Long delay detected: 2429 ms for XFEL.RF/TIMER/LLA2SPS/MACRO_PULSE_NUMBER
2021-03-04T11:42:39 zmq_callback         Long delay detected: 2129 ms for XFEL.RF/TIMER/LLA2SPS/BUNCH_POSITION.1
2021-03-04T11:42:39 zmq_callback         Long delay detected: 2329 ms for XFEL.RF/TIMER/LLA2SPS/MACRO_PULSE_NUMBER
2021-03-04T11:42:39 zmq_callback         Long delay detected: 2329 ms for XFEL.RF/TIMER/LLA2SPS/BUNCH_POSITION.2
2021-03-04T11:42:39 zmq_callback         Long delay detected: 2029 ms for XFEL.RF/TIMER/LLA2SPS/BUNCH_POSITION.1
2021-03-04T11:42:39 zmq_callback         Long delay detected: 2229 ms for XFEL.RF/TIMER/LLA2SPS/BUNCH_POSITION.2
2021-03-04T11:42:39 zmq_callback         Long delay detected: 2129 ms for XFEL.RF/TIMER/LLA2SPS/BUNCH_POSITION.3
2021-03-04T11:42:39 zmq_callback         Long delay detected: 2129 ms for XFEL.RF/TIMER/LLA2SPS/BUNCH_POSITION.2
2021-03-04T11:42:39 zmq_callback         Long delay detected: 1929 ms for XFEL.RF/TIMER/LLA2SPS/BUNCH_POSITION.1
2021-03-04T11:42:39 zmq_callback         Long delay detected: 2229 ms for XFEL.RF/TIMER/LLA2SPS/MACRO_PULSE_NUMBER
2021-03-04T11:42:39 zmq_callback         Long delay detected: 2029 ms for XFEL.RF/TIMER/LLA2SPS/BUNCH_POSITION.3
2021-03-04T11:42:39 zmq_callback         Long delay detected: 1929 ms for XFEL.RF/TIMER/LLA2SPS/BUNCH_POSITION.3
2021-03-04T11:42:39 zmq_callback         Long delay detected: 2129 ms for XFEL.RF/TIMER/LLA2SPS/MACRO_PULSE_NUMBER
2021-03-04T11:42:39 zmq_callback         Long delay detected: 2029 ms for XFEL.RF/TIMER/LLA2SPS/BUNCH_POSITION.2
2021-03-04T11:42:39 zmq_callback         Long delay detected: 1829 ms for XFEL.RF/TIMER/LLA2SPS/BUNCH_POSITION.1
2021-03-04T11:42:39 zmq_callback         Long delay detected: 1929 ms for XFEL.RF/TIMER/LLA2SPS/BUNCH_POSITION.2
2021-03-04T11:42:39 zmq_callback         Long delay detected: 2029 ms for XFEL.RF/TIMER/LLA2SPS/MACRO_PULSE_NUMBER
2021-03-04T11:42:39 zmq_callback         Long delay detected: 1729 ms for XFEL.RF/TIMER/LLA2SPS/BUNCH_POSITION.1
2021-03-04T11:42:39 zmq_callback         Long delay detected: 1829 ms for XFEL.RF/TIMER/LLA2SPS/BUNCH_POSITION.2
2021-03-04T11:42:39 zmq_callback         Long delay detected: 1629 ms for XFEL.RF/TIMER/LLA2SPS/BUNCH_POSITION.1
2021-03-04T11:42:39 zmq_callback         Long delay detected: 1729 ms for XFEL.RF/TIMER/LLA2SPS/BUNCH_POSITION.2
2021-03-04T11:42:39 zmq_callback         Long delay detected: 1829 ms for XFEL.RF/TIMER/LLA2SPS/BUNCH_POSITION.3
2021-03-04T11:42:39 zmq_callback         Long delay detected: 1629 ms for XFEL.RF/TIMER/LLA2SPS/BUNCH_POSITION.2
2021-03-04T11:42:39 zmq_callback         Long delay detected: 1529 ms for XFEL.RF/TIMER/LLA2SPS/BUNCH_POSITION.1
2021-03-04T11:42:39 zmq_callback         Long delay detected: 1729 ms for XFEL.RF/TIMER/LLA2SPS/BUNCH_POSITION.3
2021-03-04T11:42:39 zmq_callback         Long delay detected: 1929 ms for XFEL.RF/TIMER/LLA2SPS/MACRO_PULSE_NUMBER
2021-03-04T11:42:39 zmq_callback         Long delay detected: 1529 ms for XFEL.RF/TIMER/LLA2SPS/BUNCH_POSITION.2
2021-03-04T11:42:39 zmq_callback         Long delay detected: 1429 ms for XFEL.RF/TIMER/LLA2SPS/BUNCH_POSITION.1
2021-03-04T11:42:39 zmq_callback         Long delay detected: 1629 ms for XFEL.RF/TIMER/LLA2SPS/BUNCH_POSITION.3
2021-03-04T11:42:39 zmq_callback         Long delay detected: 1329 ms for XFEL.RF/TIMER/LLA2SPS/BUNCH_POSITION.1
2021-03-04T11:42:39 zmq_callback         Long delay detected: 1829 ms for XFEL.RF/TIMER/LLA2SPS/MACRO_PULSE_NUMBER
2021-03-04T11:42:39 zmq_callback         Long delay detected: 1229 ms for XFEL.RF/TIMER/LLA2SPS/BUNCH_POSITION.1
2021-03-04T11:42:39 zmq_callback         Long delay detected: 1129 ms for XFEL.RF/TIMER/LLA2SPS/BUNCH_POSITION.1
2021-03-04T11:42:39 zmq_callback         Long delay detected: 1429 ms for XFEL.RF/TIMER/LLA2SPS/BUNCH_POSITION.2
2021-03-04T11:42:39 zmq_callback         Long delay detected: 1729 ms for XFEL.RF/TIMER/LLA2SPS/MACRO_PULSE_NUMBER
2021-03-04T11:42:39 zmq_callback         Long delay detected: 1329 ms for XFEL.RF/TIMER/LLA2SPS/BUNCH_POSITION.2
2021-03-04T11:42:39 zmq_callback         Long delay detected: 1529 ms for XFEL.RF/TIMER/LLA2SPS/BUNCH_POSITION.3
2021-03-04T11:42:39 zmq_callback         Long delay detected: 1229 ms for XFEL.RF/TIMER/LLA2SPS/BUNCH_POSITION.2
2021-03-04T11:42:39 zmq_callback         Long delay detected: 1029 ms for XFEL.RF/TIMER/LLA2SPS/BUNCH_POSITION.1
2021-03-04T11:42:39 zmq_callback         Long delay detected: 1429 ms for XFEL.RF/TIMER/LLA2SPS/BUNCH_POSITION.3
2021-03-04T11:42:39 zmq_callback         Long delay detected: 929 ms for XFEL.RF/TIMER/LLA2SPS/BUNCH_POSITION.1
2021-03-04T11:42:39 zmq_callback         Long delay detected: 1129 ms for XFEL.RF/TIMER/LLA2SPS/BUNCH_POSITION.2
2021-03-04T11:42:39 zmq_callback         Long delay detected: 829 ms for XFEL.RF/TIMER/LLA2SPS/BUNCH_POSITION.1
2021-03-04T11:42:39 zmq_callback         Long delay detected: 1629 ms for XFEL.RF/TIMER/LLA2SPS/MACRO_PULSE_NUMBER
2021-03-04T11:42:39 zmq_callback         Long delay detected: 1329 ms for XFEL.RF/TIMER/LLA2SPS/BUNCH_POSITION.3
2021-03-04T11:42:39 zmq_callback         Long delay detected: 729 ms for XFEL.RF/TIMER/LLA2SPS/BUNCH_POSITION.1
2021-03-04T11:42:39 zmq_callback         Long delay detected: 1029 ms for XFEL.RF/TIMER/LLA2SPS/BUNCH_POSITION.2
2021-03-04T11:42:39 zmq_callback         Long delay detected: 1529 ms for XFEL.RF/TIMER/LLA2SPS/MACRO_PULSE_NUMBER
2021-03-04T11:42:39 zmq_callback         Long delay detected: 629 ms for XFEL.RF/TIMER/LLA2SPS/BUNCH_POSITION.1
2021-03-04T11:42:39 zmq_callback         Long delay detected: 929 ms for XFEL.RF/TIMER/LLA2SPS/BUNCH_POSITION.2
2021-03-04T11:42:39 zmq_callback         Long delay detected: 1229 ms for XFEL.RF/TIMER/LLA2SPS/BUNCH_POSITION.3
2021-03-04T11:42:39 zmq_callback         Long delay detected: 829 ms for XFEL.RF/TIMER/LLA2SPS/BUNCH_POSITION.2
2021-03-04T11:42:39 zmq_callback         Long delay detected: 529 ms for XFEL.RF/TIMER/LLA2SPS/BUNCH_POSITION.1
2021-03-04T11:42:39 zmq_callback         Long delay detected: 729 ms for XFEL.RF/TIMER/LLA2SPS/BUNCH_POSITION.2
2021-03-04T11:42:39 zmq_callback         Long delay detected: 1129 ms for XFEL.RF/TIMER/LLA2SPS/BUNCH_POSITION.3
2021-03-04T11:42:39 zmq_callback         Long delay detected: 629 ms for XFEL.RF/TIMER/LLA2SPS/BUNCH_POSITION.2
2021-03-04T11:42:39 zmq_callback         Long delay detected: 1429 ms for XFEL.RF/TIMER/LLA2SPS/MACRO_PULSE_NUMBER
2021-03-04T11:42:39 zmq_callback         Long delay detected: 1029 ms for XFEL.RF/TIMER/LLA2SPS/BUNCH_POSITION.3
2021-03-04T11:42:39 zmq_callback         Long delay detected: 529 ms for XFEL.RF/TIMER/LLA2SPS/BUNCH_POSITION.2
2021-03-04T11:42:39 zmq_callback         Long delay detected: 1329 ms for XFEL.RF/TIMER/LLA2SPS/MACRO_PULSE_NUMBER
2021-03-04T11:42:39 zmq_callback         Long delay detected: 929 ms for XFEL.RF/TIMER/LLA2SPS/BUNCH_POSITION.3
2021-03-04T11:42:39 zmq_callback         Long delay detected: 829 ms for XFEL.RF/TIMER/LLA2SPS/BUNCH_POSITION.3
2021-03-04T11:42:39 zmq_callback         Long delay detected: 1229 ms for XFEL.RF/TIMER/LLA2SPS/MACRO_PULSE_NUMBER
2021-03-04T11:42:39 zmq_callback         Long delay detected: 729 ms for XFEL.RF/TIMER/LLA2SPS/BUNCH_POSITION.3
2021-03-04T11:42:39 zmq_callback         Long delay detected: 1129 ms for XFEL.RF/TIMER/LLA2SPS/MACRO_PULSE_NUMBER
2021-03-04T11:42:39 zmq_callback         Long delay detected: 629 ms for XFEL.RF/TIMER/LLA2SPS/BUNCH_POSITION.3
2021-03-04T11:42:39 zmq_callback         Long delay detected: 1029 ms for XFEL.RF/TIMER/LLA2SPS/MACRO_PULSE_NUMBER
2021-03-04T11:42:39 zmq_callback         Long delay detected: 529 ms for XFEL.RF/TIMER/LLA2SPS/BUNCH_POSITION.3
2021-03-04T11:42:39 zmq_callback         Long delay detected: 929 ms for XFEL.RF/TIMER/LLA2SPS/MACRO_PULSE_NUMBER
2021-03-04T11:42:39 zmq_callback         Long delay detected: 829 ms for XFEL.RF/TIMER/LLA2SPS/MACRO_PULSE_NUMBER
2021-03-04T11:42:39 zmq_callback         Long delay detected: 729 ms for XFEL.RF/TIMER/LLA2SPS/MACRO_PULSE_NUMBER
2021-03-04T11:42:39 zmq_callback         Long delay detected: 629 ms for XFEL.RF/TIMER/LLA2SPS/MACRO_PULSE_NUMBER
2021-03-04T11:42:39 zmq_callback         Long delay detected: 529 ms for XFEL.RF/TIMER/LLA2SPS/MACRO_PULSE_NUMBER
```
