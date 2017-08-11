//+------------------------------------------------------------------------------------------------+
//| ARM Cortex-M0+ core configuration header for the Kinetis MKL26 MCU.                            |
//|                                                                                                |
//| This header defines vector number enumerations and core configuration options required by      |
//| the CMSIS in order to provide core support.                                                    |
//|                                                                                                |
//| Author: Joksan Alvarado.                                                                       |
//+------------------------------------------------------------------------------------------------+

#ifndef MKL26_H_
#define MKL26_H_

//Interrupt vector number enumerations.
typedef enum IRQn
{
  //Generic cortex M0+ interrupt request vector numbers.
  NonMaskableInt_IRQn     = -14,
  HardFault_IRQn          = -13,
  SVCall_IRQn             = -5,
  PendSV_IRQn             = -2,
  SysTick_IRQn            = -1,
  //MKL26 specific interrupt request vector numbers.
  DmaChannel_0_IRQn       = 0,
  DmaChannel_1_IRQn       = 1,
  DmaChannel_2_IRQn       = 2,
  DmaChannel_3_IRQn       = 3,
  FlashMemoryModule_IRQn  = 5,
  LowVoltage_IRQn         = 6,
  LowLeakageWakeup_IRQn   = 7,
  I2C_0_IRQn              = 8,
  I2C_1_IRQn              = 9,
  SPI_0_IRQn              = 10,
  SPI_1_IRQn              = 11,
  UART_0_IRQn             = 12,
  UART_1_IRQn             = 13,
  UART_2_IRQn             = 14,
  ADC_0_IRQn              = 15,
  CMP_0_IRQn              = 16,
  TPM_0_IRQn              = 17,
  TPM_1_IRQn              = 18,
  TPM_2_IRQn              = 19,
  RTC_Alarm_IRQn          = 20,
  RTC_Seconds_IRQn        = 21,
  PIT_IRQn                = 22,
  I2S_0_IRQn              = 23,
  USB_OTG_IRQn            = 24,
  DAC_0_IRQn              = 25,
  TSI_0_IRQn              = 26,
  MCG_IRQn                = 27,
  LPTMR_0_IRQn            = 28,
  Port_A_IRQn             = 30,
  Port_C_D_IRQn           = 31,
} IRQn_Type;

//ARM Cortex-M0+ core configurations.
#define __FPU_PRESENT           0
#define __MPU_PRESENT           0
#define __NVIC_PRIO_BITS        2
#define __Vendor_SysTickConfig  0

//Include the CMSIS header.
#include "core_cm0plus.h"

#endif //MKL26_H_
