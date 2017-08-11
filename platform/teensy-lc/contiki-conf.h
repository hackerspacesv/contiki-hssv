//+------------------------------------------------------------------------------------------------+
//| Contiki configuration header for the Teensy LC platform.                                       |
//|                                                                                                |
//| Author: Joksan Alvarado.                                                                       |
//+------------------------------------------------------------------------------------------------+

#ifndef CONTIKI_CONF_H_
#define CONTIKI_CONF_H_
 
#include <stdint.h>

#define CLOCK_CONF_SECOND 128

typedef uint32_t clock_time_t;
typedef uint16_t uip_stats_t;

#define CCIF
#define CLIF

#endif //CONTIKI_CONF_H_
