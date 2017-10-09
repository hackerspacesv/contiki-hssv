//+------------------------------------------------------------------------------------------------+
//| DMAMUX peripheral registers for Kinetis MKL26 MCU.                                             |
//|                                                                                                |
//| Author: Joksan Alvarado.                                                                       |
//+------------------------------------------------------------------------------------------------+

#ifndef MKL26_DMAMUX_H_
#define MKL26_DMAMUX_H_

#include <stdint.h>

struct DMAMUX_type {
  uint8_t CHCFG[4];  //Channel configuration register
};

#define DMAMUX0 ((volatile struct DMAMUX_type *) 0x40021000)

//Channel configuration register bitfields
#define DMAMUX_CHCFG_SOURCE_Disabled        (0 << 0)  //DMA channel source (slot)
#define DMAMUX_CHCFG_SOURCE_UART0_Receive   (2 << 0)
#define DMAMUX_CHCFG_SOURCE_UART0_Transmit  (3 << 0)
#define DMAMUX_CHCFG_SOURCE_UART1_Receive   (4 << 0)
#define DMAMUX_CHCFG_SOURCE_UART1_Transmit  (5 << 0)
#define DMAMUX_CHCFG_SOURCE_UART2_Receive   (6 << 0)
#define DMAMUX_CHCFG_SOURCE_UART2_Transmit  (7 << 0)
#define DMAMUX_CHCFG_SOURCE_I2S0_Receive    (14 << 0)
#define DMAMUX_CHCFG_SOURCE_I2S0_Transmit   (15 << 0)
#define DMAMUX_CHCFG_SOURCE_SPI0_Receive    (16 << 0)
#define DMAMUX_CHCFG_SOURCE_SPI0_Transmit   (17 << 0)
#define DMAMUX_CHCFG_SOURCE_SPI1_Receive    (18 << 0)
#define DMAMUX_CHCFG_SOURCE_SPI1_Transmit   (19 << 0)
#define DMAMUX_CHCFG_SOURCE_I2C0            (22 << 0)
#define DMAMUX_CHCFG_SOURCE_I2C1            (23 << 0)
#define DMAMUX_CHCFG_SOURCE_TPM0_Channel_0  (24 << 0)
#define DMAMUX_CHCFG_SOURCE_TPM0_Channel_1  (25 << 0)
#define DMAMUX_CHCFG_SOURCE_TPM0_Channel_2  (26 << 0)
#define DMAMUX_CHCFG_SOURCE_TPM0_Channel_3  (27 << 0)
#define DMAMUX_CHCFG_SOURCE_TPM0_Channel_4  (28 << 0)
#define DMAMUX_CHCFG_SOURCE_TPM0_Channel_5  (29 << 0)
#define DMAMUX_CHCFG_SOURCE_TPM1_Channel_0  (32 << 0)
#define DMAMUX_CHCFG_SOURCE_TPM1_Channel_1  (33 << 0)
#define DMAMUX_CHCFG_SOURCE_TPM2_Channel_0  (34 << 0)
#define DMAMUX_CHCFG_SOURCE_TPM2_Channel_1  (35 << 0)
#define DMAMUX_CHCFG_SOURCE_ADC0            (40 << 0)
#define DMAMUX_CHCFG_SOURCE_CMP0            (42 << 0)
#define DMAMUX_CHCFG_SOURCE_DAC0            (45 << 0)
#define DMAMUX_CHCFG_SOURCE_PORT_A          (49 << 0)
#define DMAMUX_CHCFG_SOURCE_PORT_C          (51 << 0)
#define DMAMUX_CHCFG_SOURCE_PORT_D          (52 << 0)
#define DMAMUX_CHCFG_SOURCE_TPM0_Overflow   (54 << 0)
#define DMAMUX_CHCFG_SOURCE_TPM1_Overflow   (55 << 0)
#define DMAMUX_CHCFG_SOURCE_TPM2_Overflow   (56 << 0)
#define DMAMUX_CHCFG_SOURCE_TSI             (57 << 0)
#define DMAMUX_CHCFG_TRIG_Disabled          (0 << 6)  //DMA channel trigger enable
#define DMAMUX_CHCFG_TRIG_Enabled           (1 << 6)
#define DMAMUX_CHCFG_ENBL_Disabled          (0 << 7)  //DMA channel enable
#define DMAMUX_CHCFG_ENBL_Enabled           (1 << 7)

#endif //MKL26_DMAMUX_H_
