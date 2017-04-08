//+------------------------------------------------------------------------------------------------+
//| Architecture implementation header for contiki's preemptive multithreading library.            |
//|                                                                                                |
//| Author: Joksan Alvarado.                                                                       |
//+------------------------------------------------------------------------------------------------+

#ifndef MTARCH_H_
#define MTARCH_H_

//Contiki's preemptive multithreading library isn't implemented on this platform. This is just an
//stub to cause the code to compile cleanly.

struct mtarch_thread {
  unsigned char *sp;
};

#endif //MTARCH_H_
