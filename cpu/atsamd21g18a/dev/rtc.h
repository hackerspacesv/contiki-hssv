//+------------------------------------------------------------------------------------------------+
//| RTC peripheral driver for ATSAMD21G18A MCU.                                                    |
//|                                                                                                |
//| This driver provides hardware interrupt services for Contiki's clock and rtimer libraries.     |
//|                                                                                                |
//| Author: Joksan Alvarado.                                                                       |
//+------------------------------------------------------------------------------------------------+

#ifndef RTC_H_
#define RTC_H_

#include "contiki-conf.h"

void rtc_init();
rtimer_clock_t rtc_get_count();
void rtc_rtimer_schedule(rtimer_clock_t time);

#endif //RTC_H_
