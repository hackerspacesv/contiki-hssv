//+------------------------------------------------------------------------------------------------+
//| Platform implementation for contiki's rtimer library.                                          |
//|                                                                                                |
//| This module depends on the RTC peripheral driver, which provides the actual implementation.    |
//| See the header in contiki/core/sys/rtimer.h for details on the exposed interface.              |
//|                                                                                                |
//| Author: Joksan Alvarado.                                                                       |
//+------------------------------------------------------------------------------------------------+

#include "rtimer.h"

#include "rtc.h"

void rtimer_arch_init(void) {
  //This function does nothing. This module depends on the RTC driver to be initialized.
}

void rtimer_arch_schedule(rtimer_clock_t t) {
  rtc_rtimer_schedule(t);
}

rtimer_clock_t rtimer_arch_now(void) {
  return rtc_get_count();
}

void rtimer_arch_callback() {
  rtimer_run_next();
}
