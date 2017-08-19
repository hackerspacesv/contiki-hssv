//+------------------------------------------------------------------------------------------------+
//| LPTMR peripheral registers for Kinetis MKL26 MCU.                                              |
//|                                                                                                |
//| Author: Joksan Alvarado.                                                                       |
//+------------------------------------------------------------------------------------------------+

#ifndef MKL26_LPTMR_H_
#define MKL26_LPTMR_H_

#include <stdint.h>

struct LPTMR_type {
  uint32_t CSR;   //Control status register
  uint32_t PSR;   //Prescale register
  uint32_t CMR;   //Compare register
  uint32_t CNR;   //Counter register
};

#define LPTMR0 ((volatile struct LPTMR_type *) 0x40040000)

//Control status register bitfields
#define LPTMR_CSR_TEN_Disabled                  (0 << 0)  //Timer enable
#define LPTMR_CSR_TEN_Enabled                   (1 << 0)
#define LPTMR_CSR_TMS_Time_Counter              (0 << 1)  //Timer mode select
#define LPTMR_CSR_TMS_Pulse_Counter             (1 << 1)
#define LPTMR_CSR_TFC_Reset_On_TCF              (0 << 2)  //Timer free running counter
#define LPTMR_CSR_TFC_Reset_Overflow            (1 << 2)
#define LPTMR_CSR_TPP_Active_High_Rising_Edge   (0 << 3)  //Timer pin polarity
#define LPTMR_CSR_TPP_Active_Low_Falling_Edge   (1 << 3)
#define LPTMR_CSR_TPS_CMP0                      (0 << 4)  //Timer pin select
#define LPTMR_CSR_TPS_ALT1                      (1 << 4)
#define LPTMR_CSR_TPS_ALT2                      (2 << 4)
#define LPTMR_CSR_TPS_ALT3                      (3 << 4)
#define LPTMR_CSR_TIE_Disabled                  (0 << 6)  //Timer interrupt enable
#define LPTMR_CSR_TIE_Enabled                   (1 << 6)
#define LPTMR_CSR_TCF_Msk                       0x80      //Timer compare flag
#define LPTMR_CSR_TCF_Clear                     (0 << 7)
#define LPTMR_CSR_TCF_Set                       (1 << 7)

//Prescale register
#define LPTMR_PSR_PCS_MCGIRCLK        (0 << 0)    //Prescaler clock select
#define LPTMR_PSR_PCS_LPO             (1 << 0)
#define LPTMR_PSR_PCS_ERCLK32K        (2 << 0)
#define LPTMR_PSR_PCS_OSCERCLK        (3 << 0)
#define LPTMR_PSR_PBYP_Enabled        (0 << 2)    //Prescaler bypass
#define LPTMR_PSR_PBYP_Bypassed       (1 << 2)
#define LPTMR_PSR_PRESCALE_Div2       (0 << 3)    //Prescale value
#define LPTMR_PSR_PRESCALE_Div4       (1 << 3)
#define LPTMR_PSR_PRESCALE_Div8       (2 << 3)
#define LPTMR_PSR_PRESCALE_Div16      (3 << 3)
#define LPTMR_PSR_PRESCALE_Div32      (4 << 3)
#define LPTMR_PSR_PRESCALE_Div64      (5 << 3)
#define LPTMR_PSR_PRESCALE_Div128     (6 << 3)
#define LPTMR_PSR_PRESCALE_Div256     (7 << 3)
#define LPTMR_PSR_PRESCALE_Div512     (8 << 3)
#define LPTMR_PSR_PRESCALE_Div1024    (9 << 3)
#define LPTMR_PSR_PRESCALE_Div2048    (10 << 3)
#define LPTMR_PSR_PRESCALE_Div4096    (11 << 3)
#define LPTMR_PSR_PRESCALE_Div8192    (12 << 3)
#define LPTMR_PSR_PRESCALE_Div16384   (13 << 3)
#define LPTMR_PSR_PRESCALE_Div32768   (14 << 3)
#define LPTMR_PSR_PRESCALE_Div65536   (15 << 3)

#endif //MKL26_LPTMR_H_
