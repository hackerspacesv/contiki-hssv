//+------------------------------------------------------------------------------------------------+
//| PORT peripheral registers for Kinetis MK20 MCU.                                                |
//|                                                                                                |
//| Author: Joksan Alvarado.                                                                       |
//+------------------------------------------------------------------------------------------------+

#ifndef MK20_PORT_H_
#define MK20_PORT_H_

#include <stdint.h>

struct PORT_type {
  uint32_t PCR[32];       //Pin control registers
  uint32_t GPCLR;         //Global pin control low register
  uint32_t GPCHR;         //Global pin control high register
  uint32_t reserved0[6];
  uint32_t ISFR;          //Interrupt status flag register
};

#define PORTA ((volatile struct PORT_type *) 0x40049000)
#define PORTB ((volatile struct PORT_type *) 0x4004A000)
#define PORTC ((volatile struct PORT_type *) 0x4004B000)
#define PORTD ((volatile struct PORT_type *) 0x4004C000)
#define PORTE ((volatile struct PORT_type *) 0x4004D000)

//Pin control register bitfields
#define PORT_PCR_PS_Pulldown    (0 << 0)    //Select internal pull-up or pull-down
#define PORT_PCR_PS_Pullup      (1 << 0)
#define PORT_PCR_PE_Disabled    (0 << 1)    //Control internal pull-up/down resistor
#define PORT_PCR_PE_Enabled     (1 << 1)
#define PORT_PCR_SRE_Fast       (0 << 2)    //Select fast/slow output slew rate
#define PORT_PCR_SRE_Slow       (1 << 2)
#define PORT_PCR_PFE_Disabled   (0 << 4)    //Control passive input filter
#define PORT_PCR_PFE_Enabled    (1 << 4)
#define PORT_PCR_ODE_Disabled   (0 << 5)    //Control open drain output
#define PORT_PCR_ODE_Enabled    (1 << 5)
#define PORT_PCR_DSE_Low        (0 << 6)    //Select high/low output drive strength
#define PORT_PCR_DSE_High       (1 << 6)
#define PORT_PCR_MUX_Analog     (0 << 8)    //Pin mux control
#define PORT_PCR_MUX_Gpio       (1 << 8)
#define PORT_PCR_MUX_Alt2       (2 << 8)
#define PORT_PCR_MUX_Alt3       (3 << 8)
#define PORT_PCR_MUX_Alt4       (4 << 8)
#define PORT_PCR_MUX_Alt5       (5 << 8)
#define PORT_PCR_MUX_Alt6       (6 << 8)
#define PORT_PCR_MUX_Alt7       (7 << 8)
#define PORT_PCR_LK_Unlocked    (0 << 15)   //Control configuration locking
#define PORT_PCR_LK_Locked      (1 << 15)
#define PORT_PCR_IRQC_Disabled  (0 << 16)   //Interrupt configuration
#define PORT_PCR_IRQC_Dma_Rise  (1 << 16)
#define PORT_PCR_IRQC_Dma_Fall  (2 << 16)
#define PORT_PCR_IRQC_Dma_Both  (3 << 16)
#define PORT_PCR_IRQC_Int_Low   (8 << 16)
#define PORT_PCR_IRQC_Int_Rise  (9 << 16)
#define PORT_PCR_IRQC_Int_Fall  (10 << 16)
#define PORT_PCR_IRQC_Int_Both  (11 << 16)
#define PORT_PCR_IRQC_Int_High  (12 << 16)
#define PORT_PCR_ISF_Msk        0x01000000  //Interrupt status flag
#define PORT_PCR_ISF_Clear      (0 << 24)
#define PORT_PCR_ISF_Set        (1 << 24)

//Global pin control low and high register bitfields
#define PORT_GPCxR_GPWD_Msk   0x0000FFFF  //Global pin write data
#define PORT_GPCxR_GPWD_Pos   0
#define PORT_GPCxR_GPWE_Msk   0xFFFF0000  //Global pin write enable
#define PORT_GPCxR_GPWE_Pos   16

#endif //MK20_PORT_H_
