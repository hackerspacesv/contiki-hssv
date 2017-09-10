//+------------------------------------------------------------------------------------------------+
//| Contiki configuration header for the Teensy LC platform.                                       |
//|                                                                                                |
//| Author: Joksan Alvarado.                                                                       |
//+------------------------------------------------------------------------------------------------+

#ifndef CONTIKI_CONF_H_
#define CONTIKI_CONF_H_

#include <stdint.h>

//Clock library configuration
//--------------------------------------------------------------------------------------------------

//The CLOCK_CONF_SECOND value is adjusted according to the LPTMR frequency so it can be divided
//evenly and its frequency is generated accurately.
#if F_LPT == 31250
  #define CLOCK_CONF_SECOND 125
#elif F_LPT == 32768
  #define CLOCK_CONF_SECOND 128
#else
  #error "Low power timer frequency is undefined or not supported"
#endif

typedef uint32_t clock_time_t;

//Rtimer library configuration
//--------------------------------------------------------------------------------------------------

#define RTIMER_ARCH_SECOND F_LPT

typedef uint32_t rtimer_clock_t;

#define RTIMER_CLOCK_DIFF(a,b) ((int32_t)((a)-(b)))

//Unused configurations
//--------------------------------------------------------------------------------------------------

typedef uint16_t uip_stats_t;

#define CCIF
#define CLIF

#endif //CONTIKI_CONF_H_
