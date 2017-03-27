//+------------------------------------------------------------------------------------------------+
//| OSC peripheral registers for Kinetis MK66 MCU.                                                 |
//|                                                                                                |
//| Author: Joksan Alvarado.                                                                       |
//+------------------------------------------------------------------------------------------------+

#ifndef MK66_OSC_H_
#define MK66_OSC_H_

#include <stdint.h>

struct OSC_type {
  uint8_t CR;         //Control register
  uint8_t reserved0;
  uint8_t OSC_DIV;    //OSC clock divider register
};

#define OSC ((volatile struct OSC_type *) 0x40065000)

//Control register bitfields
#define OSC_CR_SC16P_Disabled     (0 << 0)  //Oscillator 16 pF load configure
#define OSC_CR_SC16P_Enabled      (1 << 0)
#define OSC_CR_SC8P_Disabled      (0 << 1)  //Oscillator 8 pF load configure
#define OSC_CR_SC8P_Enabled       (1 << 1)
#define OSC_CR_SC4P_Disabled      (0 << 2)  //Oscillator 4 pF load configure
#define OSC_CR_SC4P_Enabled       (1 << 2)
#define OSC_CR_SC2P_Disabled      (0 << 3)  //Oscillator 2 pF load configure
#define OSC_CR_SC2P_Enabled       (1 << 3)
#define OSC_CR_EREFSTEN_Disabled  (0 << 5)  //External reference stop enable
#define OSC_CR_EREFSTEN_Enabled   (1 << 5)
#define OSC_CR_ERCLKEN_Disabled   (0 << 7)  //External reference enable
#define OSC_CR_ERCLKEN_Enabled    (1 << 7)

//OSC clock divider register bitfields
#define OSC_OSC_DIV_ERPS_Div_1  (0 << 6)  //ERCLK prescaler
#define OSC_OSC_DIV_ERPS_Div_2  (1 << 6)
#define OSC_OSC_DIV_ERPS_Div_4  (2 << 6)
#define OSC_OSC_DIV_ERPS_Div_8  (3 << 6)

#endif //MK66_OSC_H_
