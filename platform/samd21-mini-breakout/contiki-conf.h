//+------------------------------------------------------------------------------------------------+
//| Contiki configuration header for the Sparkfun SAMD21G Mini Breakout platform.                  |
//|                                                                                                |
//| Author: Joksan Alvarado.                                                                       |
//+------------------------------------------------------------------------------------------------+

#ifndef CONTIKI_CONF_H_
#define CONTIKI_CONF_H_

//Include the project configuration header first (if defined).
#ifdef PROJECT_CONF_H
#include PROJECT_CONF_H
#endif //PROJECT_CONF_H

//Now include the platform configuration header.
#include "platform-conf.h"

#include <stdint.h>

//Clock library configuration
//--------------------------------------------------------------------------------------------------

typedef uint32_t clock_time_t;

//Unused configurations
//--------------------------------------------------------------------------------------------------

typedef uint16_t uip_stats_t;

#define CCIF
#define CLIF

#endif //CONTIKI_CONF_H_
