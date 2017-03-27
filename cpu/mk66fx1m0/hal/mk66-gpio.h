//+------------------------------------------------------------------------------------------------+
//| GPIO peripheral registers for Kinetis MK66 MCU.                                                |
//|                                                                                                |
//| Author: Joksan Alvarado.                                                                       |
//+------------------------------------------------------------------------------------------------+

#ifndef MK66_GPIO_H_
#define MK66_GPIO_H_

#include <stdint.h>

struct GPIO_type {
  uint32_t PDOR;  //Port data output register
  uint32_t PSOR;  //Port set output register
  uint32_t PCOR;  //Port clear output register
  uint32_t PTOR;  //Port toggle output register
  uint32_t PDIR;  //Port data input register
  uint32_t PDDR;  //Port data direction register
};

#define GPIOA ((volatile struct GPIO_type *) 0x400FF000)
#define GPIOB ((volatile struct GPIO_type *) 0x400FF040)
#define GPIOC ((volatile struct GPIO_type *) 0x400FF080)
#define GPIOD ((volatile struct GPIO_type *) 0x400FF0C0)
#define GPIOE ((volatile struct GPIO_type *) 0x400FF100)

//Port data direction register constants
#define GPIO_PDDR_Input   0
#define GPIO_PDDR_Output  1

#endif //MK66_GPIO_H_
