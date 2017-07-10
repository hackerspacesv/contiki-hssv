//+------------------------------------------------------------------------------------------------+
//| OSC peripheral registers for Kinetis MKL26 MCU.                                                |
//|                                                                                                |
//| Author: Joksan Alvarado.                                                                       |
//+------------------------------------------------------------------------------------------------+

#ifndef MKL26_OSC_H_
#define MKL26_OSC_H_

#include <stdint.h>

struct OSC_type {
  uint8_t CR;         //Control register
};

#define OSC ((volatile struct OSC_type *) 0x40065000)

//Control register bitfields
#define OSC_CR_SC16P_Disabled     (0 << 0)  //Oscillator 16 pF capacitor load configure
#define OSC_CR_SC16P_Enabled      (1 << 0)
#define OSC_CR_SC8P_Disabled      (0 << 1)  //Oscillator 8 pF capacitor load configure
#define OSC_CR_SC8P_Enabled       (1 << 1)
#define OSC_CR_SC4P_Disabled      (0 << 2)  //Oscillator 4 pF capacitor load configure
#define OSC_CR_SC4P_Enabled       (1 << 2)
#define OSC_CR_SC2P_Disabled      (0 << 3)  //Oscillator 2 pF capacitor load configure
#define OSC_CR_SC2P_Enabled       (1 << 3)
#define OSC_CR_EREFSTEN_Disabled  (0 << 5)  //External reference stop enable
#define OSC_CR_EREFSTEN_Enabled   (1 << 5)
#define OSC_CR_ERCLKEN_Disabled   (0 << 7)  //External reference enable
#define OSC_CR_ERCLKEN_Enabled    (1 << 7)

#endif //MKL26_OSC_H_
