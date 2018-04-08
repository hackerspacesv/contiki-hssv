//+------------------------------------------------------------------------------------------------+
//| Project configuration header for the low power LED blink example.                              |
//|                                                                                                |
//| Author: Joksan Alvarado.                                                                       |
//+------------------------------------------------------------------------------------------------+

#ifndef PROJECT_CONF_H_
#define PROJECT_CONF_H_

//Select a low power profile according to selected target
#if CONTIKI_TARGET_TEENSY_LC
#define MKL26_CONF_POWER_PROFILE MKL26_POWER_PROFILE_LOWPOWER_4MHZ_INTREF
#elif CONTIKI_TARGET_SAMD21_MINI_BREAKOUT
#define SAMD21_CONF_POWER_PROFILE SAMD21_POWER_PROFILE_LOWPOWER_4MHZ
#else
#error "Unsupported target for this example"
#pragma message "Supported targets: teensy-lc samd21-mini-breakout"
#endif

#endif //PROJECT_CONF_H_
