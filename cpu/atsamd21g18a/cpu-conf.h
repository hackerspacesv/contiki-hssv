//+------------------------------------------------------------------------------------------------+
//| ATSAMD21G18A cpu configuration header.                                                         |
//|                                                                                                |
//| Author: Joksan Alvarado.                                                                       |
//+------------------------------------------------------------------------------------------------+

#ifndef CPU_CONF_H_
#define CPU_CONF_H_

//Available power profiles for the CPU.
#define SAMD21_POWER_PROFILE_PERFORMANCE_48MHZ  0
#define SAMD21_POWER_PROFILE_LOWPOWER_4MHZ      1

//Set a default power profile if none is selected.
#ifdef SAMD21_CONF_POWER_PROFILE
#define SAMD21_POWER_PROFILE SAMD21_CONF_POWER_PROFILE
#else
#define SAMD21_POWER_PROFILE SAMD21_POWER_PROFILE_PERFORMANCE_48MHZ
#endif

//Configure other parameters that depend on the selected power profile.
#if SAMD21_POWER_PROFILE == SAMD21_POWER_PROFILE_PERFORMANCE_48MHZ
#define F_CPU 48000000
#elif SAMD21_POWER_PROFILE == SAMD21_POWER_PROFILE_LOWPOWER_4MHZ
#define F_CPU 4000000
#else
#error "Unsupported power profile for SAMD21 cpu"
#endif

#endif //CPU_CONF_H_
