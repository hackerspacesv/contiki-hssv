//+------------------------------------------------------------------------------------------------+
//| ARM Cortex m4f core configuration header for the Kinetis MK66 MCU.                             |
//|                                                                                                |
//| This header defines vector number enumerations and core configuration options required by      |
//| the CMSIS in order to provide core support.                                                    |
//|                                                                                                |
//| Author: Joksan Alvarado.                                                                       |
//+------------------------------------------------------------------------------------------------+

#ifndef MK66_H_
#define MK66_H_

//Interrupt vector number enumerations.
typedef enum IRQn
{
  //Generic cortex M4 interrupt request vector numbers.
  NonMaskableInt_IRQn     = -14,
  HardFault_IRQn          = -13,
  MemoryManagement_IRQn   = -12,
  BusFault_IRQn           = -11,
  UsageFault_IRQn         = -10,
  SVCall_IRQn             = -5,
  DebugMonitor_IRQn       = -4,
  PendSV_IRQn             = -2,
  SysTick_IRQn            = -1,
  //MK66 specific interrupt request vector numbers.
  DmaChannel_0_16_IRQn        = 0,
  DmaChannel_1_17_IRQn        = 1,
  DmaChannel_2_18_IRQn        = 2,
  DmaChannel_3_19_IRQn        = 4,
  DmaChannel_4_20_IRQn        = 3,
  DmaChannel_5_21_IRQn        = 5,
  DmaChannel_6_22_IRQn        = 6,
  DmaChannel_7_23_IRQn        = 7,
  DmaChannel_8_24_IRQn        = 8,
  DmaChannel_9_25_IRQn        = 9,
  DmaChannel_10_26_IRQn       = 10,
  DmaChannel_11_27_IRQn       = 11,
  DmaChannel_12_28_IRQn       = 12,
  DmaChannel_13_29_IRQn       = 13,
  DmaChannel_14_30_IRQn       = 14,
  DmaChannel_15_31_IRQn       = 15,
  DmaError_IRQn               = 16,
  MCM_IRQn                    = 17,
  FlashCommandComplete_IRQn   = 18,
  FlashReadCollision_IRQn     = 19,
  LowVoltage_IRQn             = 20,
  LowLeakageWakeup_IRQn       = 21,
  WDOG_EWM_IRQn               = 22,
  RNG_IRQn                    = 23,
  I2C_0_IRQn                  = 24,
  I2C_1_IRQn                  = 25,
  SPI_0_IRQn                  = 26,
  SPI_1_IRQn                  = 27,
  I2S_0_Transmit_IRQn         = 28,
  I2S_0_Receive_IRQn          = 29,
  UART_0_Status_IRQn          = 31,
  UART_0_Error_IRQn           = 32,
  UART_1_Status_IRQn          = 33,
  UART_1_Error_IRQn           = 34,
  UART_2_Status_IRQn          = 35,
  UART_2_Error_IRQn           = 36,
  UART_3_Status_IRQn          = 37,
  UART_3_Error_IRQn           = 38,
  ADC_0_IRQn                  = 39,
  CMP_0_IRQn                  = 40,
  CMP_1_IRQn                  = 41,
  FTM_0_IRQn                  = 42,
  FTM_1_IRQn                  = 43,
  FTM_2_IRQn                  = 44,
  CMT_IRQn                    = 45,
  RTC_Alarm_IRQn              = 46,
  RTC_Seconds_IRQn            = 47,
  PIT_0_IRQn                  = 48,
  PIT_1_IRQn                  = 49,
  PIT_2_IRQn                  = 50,
  PIT_3_IRQn                  = 51,
  PDB_IRQn                    = 52,
  USBFS_OTG_IRQn              = 53,
  USBFS_ChargerDetect_IRQn    = 54,
  DAC_0_IRQn                  = 56,
  MCG_IRQn                    = 57,
  LowPowerTimer_IRQn          = 58,
  PORT_A_IRQn                 = 59,
  PORT_B_IRQn                 = 60,
  PORT_C_IRQn                 = 61,
  PORT_D_IRQn                 = 62,
  PORT_E_IRQn                 = 63,
  SoftwareInterrupt_IRQn      = 64,
  SPI_2_IRQn                  = 65,
  UART_4_Status_IRQn          = 66,
  UART_4_Error_IRQn           = 67,
  CMP_2_IRQn                  = 70,
  FTM_3_IRQn                  = 71,
  DAC_1_IRQn                  = 72,
  ADC_1_IRQn                  = 73,
  I2C_2_IRQn                  = 74,
  CAN_0_Message_IRQn          = 75,
  CAN_0_BusOff_IRQn           = 76,
  CAN_0_Error_IRQn            = 77,
  CAN_0_TransmitWarning_IRQn  = 78,
  CAN_0_ReceiveWarning_IRQn   = 79,
  CAN_0_WakeUp_IRQn           = 80,
  SDHC_IRQn                   = 81,
  ENET_Timer_IRQn             = 82,
  ENET_Transmit_IRQn          = 83,
  ENET_Receive_IRQn           = 84,
  ENET_ErrorMisc_IRQn         = 85,
  LPUART_0_IRQn               = 86,
  TSI_0_IRQn                  = 87,
  TPM_1_IRQn                  = 88,
  TPM_2_IRQn                  = 89,
  USBHS_DCD_Phy               = 90,
  i2c_3                       = 91,
  cmp_3                       = 92,
  usbhs_otg                   = 93,
  CAN_1_Message_IRQn          = 94,
  CAN_1_BusOff_IRQn           = 95,
  CAN_1_Error_IRQn            = 96,
  CAN_1_TransmitWarning_IRQn  = 97,
  CAN_1_ReceiveWarning_IRQn   = 98,
  CAN_1_WakeUp_IRQn           = 99,
} IRQn_Type;

//ARM Cortex m4f core configurations.
#define __FPU_PRESENT           1
#define __MPU_PRESENT           0
#define __NVIC_PRIO_BITS        4
#define __Vendor_SysTickConfig  0

//Include the CMSIS header.
#include "core_cm4.h"

#endif //MK66_H_
