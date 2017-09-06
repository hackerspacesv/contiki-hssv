//+------------------------------------------------------------------------------------------------+
//| LPTMR peripheral driver for Kinetis MKL26 MCU.                                                 |
//|                                                                                                |
//| This driver provides hardware interrupt services for Contiki's clock and rtimer libraries.     |
//|                                                                                                |
//| Author: Joksan Alvarado.                                                                       |
//+------------------------------------------------------------------------------------------------+

#ifndef LPTMR_H_
#define LPTMR_H_

#include "contiki-conf.h"

void lptmr_init();
rtimer_clock_t lptmr_get_count();
void lptmr_rtimer_schedule(rtimer_clock_t time);

#endif //LPTMR_H_
