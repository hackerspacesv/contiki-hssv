//+------------------------------------------------------------------------------------------------+
//| PIT peripheral registers for Kinetis MKL26 MCU.                                                |
//|                                                                                                |
//| Author: Joksan Alvarado.                                                                       |
//+------------------------------------------------------------------------------------------------+

#ifndef MKL26_PIT_H_
#define MKL26_PIT_H_

#include <stdint.h>

struct PIT_type {
  uint32_t MCR;           //Module control register
  uint32_t reserved0[55];
  uint32_t LTMR64H;       //Upper lifetime timer register
  uint32_t LTMR64L;       //Lower lifetime timer register
  uint32_t reserved1[6];
  uint32_t LDVAL0;        //Timer load value register
  uint32_t CVAL0;         //Current timer value register
  uint32_t TCTRL0;        //Timer control register
  uint32_t TFLG0;         //Timer flag register
  uint32_t LDVAL1;        //Timer load value register
  uint32_t CVAL1;         //Current timer value register
  uint32_t TCTRL1;        //Timer control register
  uint32_t TFLG1;         //Timer flag register
};

#define PIT ((volatile struct PIT_type *) 0x40037000)

//Module control register bitfields
#define PIT_MCR_FRZ_DbgRun      (0 << 0)  //Freeze
#define PIT_MCR_FRZ_DbgStop     (1 << 0)
#define PIT_MCR_MDIS_Enabled    (0 << 1)  //Module disable
#define PIT_MCR_MDIS_Disabled   (1 << 1)

//Timer control register bitfields
#define PIT_TCTRL_TEN_Disabled    (0 << 0)  //Timer enable
#define PIT_TCTRL_TEN_Enabled     (1 << 0)
#define PIT_TCTRL_TIE_Disabled    (0 << 1)  //Timer interrupt enable
#define PIT_TCTRL_TIE_Enabled     (1 << 1)
#define PIT_TCTRL_CHN_NotChained  (0 << 2)  //Chain mode
#define PIT_TCTRL_CHN_Chained     (1 << 2)

//Timer flag register bitfields
#define PIT_TFLG_TIF_Msk    0x01      //Timer interrupt flag
#define PIT_TFLG_TIF_Clear  (0 << 0)
#define PIT_TFLG_TIF_Set    (1 << 0)

#endif //MKL26_PIT_H_
