//+------------------------------------------------------------------------------------------------+
//| ATSAMD21G18A cpu configuration header.                                                         |
//|                                                                                                |
//| Author: Joksan Alvarado.                                                                       |
//+------------------------------------------------------------------------------------------------+

#ifndef CPU_CONF_H_
#define CPU_CONF_H_

//Available power profiles for the CPU.
// * Performance 48MHZ mode:
//   - DFLL48M is used to run the system from 32KHz external oscillator. CPU/AHB bus and all APBx
//     busses run at 48MHz.
//   - RTC runs at 32.768kHz from XOSC32K external oscillator.
//   - IDLE mode level 0 via WFI is used during sleep (only the CPU clock is stopped). The rest of
//     the system stays clocked and ready.
// * Low power 4MHZ mode:
//   - OSC8M internal reference clock divided by 2 is used to run the system. CPU/AHB bus and all
//     APBx busses run at 4MHz.
//   - RTC runs at 32.768kHz from XOSC32K external oscillator.
//   - STANDBY mode via WFI is used during sleep. Only XOSC32K and RTC stay on.
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
