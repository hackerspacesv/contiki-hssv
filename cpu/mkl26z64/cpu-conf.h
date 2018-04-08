//+------------------------------------------------------------------------------------------------+
//| Kinetis MKL26Z64 cpu configuration header.                                                     |
//|                                                                                                |
//| Author: Joksan Alvarado.                                                                       |
//+------------------------------------------------------------------------------------------------+

#ifndef CPU_CONF_H_
#define CPU_CONF_H_

//Available power profiles for the CPU.
// * Performance 48MHZ PLL mode:
//   - PLL is used to run the system from 16MHz external oscillator. CPU runs at 48MHz, bus runs
//     at 24MHz.
//   - LPTMR0 runs at 31.250kHz from 16 MHz external oscillator divided by 512.
//   - Normal stop via WFI is used during sleep. System stays clocked and ready.
// * Low power 4MHZ internal reference mode:
//   - 4MHz internal reference clock is used to run the system. CPU runs at 4MHz, bus at 2MHz.
//   - LPTMR0 runs at 31.250kHz from 4MHz internal reference clock divided by 128.
//   - Very low power stop (VLPS) via WFI is used during sleep. 4MHz internal reference stays on.
// * Low power 4MHZ external reference mode:
//   - 4MHz internal reference clock is used to run the system. CPU runs at 4MHz, bus at 2MHz.
//   - LPTMR0 runs from external 32.768kHz signal - REQUIRES EXTERNAL OSCILLATOR on Pin 22/A8
//     (PTC1).
//   - Very low power stop (VLPS) via WFI is used during sleep. Internal clocks are stopped.
#define MKL26_POWER_PROFILE_PERFORMANCE_48MHZ_PLL   0
#define MKL26_POWER_PROFILE_LOWPOWER_4MHZ_INTREF    1
#define MKL26_POWER_PROFILE_LOWPOWER_4MHZ_EXTREF    2

//Set a default power profile if none is selected.
#ifdef MKL26_CONF_POWER_PROFILE
#define MKL26_POWER_PROFILE MKL26_CONF_POWER_PROFILE
#else
#define MKL26_POWER_PROFILE MKL26_POWER_PROFILE_PERFORMANCE_48MHZ_PLL
#endif

//Configure other parameters that depend on the selected power profile.
#if MKL26_POWER_PROFILE == MKL26_POWER_PROFILE_PERFORMANCE_48MHZ_PLL
#define F_CPU 48000000
#define F_BUS 24000000
#define F_LPT 31250
#elif MKL26_POWER_PROFILE == MKL26_POWER_PROFILE_LOWPOWER_4MHZ_INTREF
#define F_CPU 4000000
#define F_BUS 2000000
#define F_LPT 31250
#elif MKL26_POWER_PROFILE == MKL26_POWER_PROFILE_LOWPOWER_4MHZ_EXTREF
#define F_CPU 4000000
#define F_BUS 2000000
#define F_LPT 32768
#else
#error "Unsupported power profile for MKL26 cpu"
#endif

#endif //CPU_CONF_H_
