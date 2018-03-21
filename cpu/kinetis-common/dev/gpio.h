//+------------------------------------------------------------------------------------------------+
//| GPIO peripheral driver for Kinetis MCUs.                                                       |
//|                                                                                                |
//| This gpio driver is completely based on macros and produces very efficient code. Please keep   |
//| in mind the limitations of macros when using this driver, in particular the constant nature of |
//| the generated code.                                                                            |
//|                                                                                                |
//| Author: Joksan Alvarado.                                                                       |
//+------------------------------------------------------------------------------------------------+

#ifndef GPIO_H_
#define GPIO_H_

#include <stdbool.h>

#include "sys/cc.h"

//Include the respective HAL headers, according to the MCU contained in the selected platform.
#if MKL26Z64
  #include "mkl26-gpio.h"
  #include "mkl26-port.h"
  #include "mkl26-mux-48-qfn.h"
#elif MK20DX256
  #include "mk20-gpio.h"
  #include "mk20-port.h"
  #include "mk20-mux-64-lqfp.h"
#elif MK66FX1M0
  #include "mk66-gpio.h"
  #include "mk66-port.h"
  #include "mk66-mux-144-mapbga.h"
#else
  #error "Unsupported CPU"
#endif

//Include the board pinout definition for the selected platform.
#if CONTIKI_TARGET_TEENSY_LC || CONTIKI_TARGET_TEENSY_32 || CONTIKI_TARGET_TEENSY_36
#include "board-pinout.h"
#endif

//Macros intended for internal use (not part of the API)
//--------------------------------------------------------------------------------------------------

//Macros used to combine the pin number with a suffix which maps to a macro defined in the MUX
//header, allowing to obtain the PORT/GPIO peripheral instance (A, B, C, etc.), the bit position
//(0..31) or the MUX alternate function number.
#define GPIO_PER_INS(PIN) CC_CONCAT_EXT_2(PIN, _PER_INS)
#define GPIO_BIT_POS(PIN) CC_CONCAT_EXT_2(PIN, _BIT_POS)
#define GPIO_MUX_ALT(PIN, MUX_ALT) CC_CONCAT_EXT_3(PIN, _ALT_, MUX_ALT)

//These macros allow to obtain the PORT and GPIO peripheral instances that are associated to an
//specific pin.
#define GPIO_PORT(PIN) CC_CONCAT_EXT_2(PORT, GPIO_PER_INS(PIN))
#define GPIO_GPIO(PIN) CC_CONCAT_EXT_2(GPIO, GPIO_PER_INS(PIN))

//These macros allow to obtain specific registers asociated with a pin.
#define GPIO_PORT_PCR(PIN) GPIO_PORT(PIN)->PCR[GPIO_BIT_POS(PIN)]
#define GPIO_GPIO_PSOR(PIN) GPIO_GPIO(PIN)->PSOR
#define GPIO_GPIO_PCOR(PIN) GPIO_GPIO(PIN)->PCOR
#define GPIO_GPIO_PTOR(PIN) GPIO_GPIO(PIN)->PTOR
#define GPIO_GPIO_PDIR(PIN) GPIO_GPIO(PIN)->PDIR
#define GPIO_GPIO_PDDR(PIN) GPIO_GPIO(PIN)->PDDR

//Macros exposed by this API.
//--------------------------------------------------------------------------------------------------

//Configure pin as an input.
#define GPIO_PIN_MODE_INPUT(PIN) do {\
  GPIO_PORT_PCR(PIN) = PORT_PCR_MUX_Gpio;\
  GPIO_GPIO_PDDR(PIN) &= ~(1 << GPIO_BIT_POS(PIN));\
} while (0)

//Configure pin as an input with pulldown.
#define GPIO_PIN_MODE_INPUT_PULLDOWN(PIN) do {\
  GPIO_PORT_PCR(PIN) = PORT_PCR_MUX_Gpio | PORT_PCR_PE_Enabled | PORT_PCR_PS_Pulldown;\
  GPIO_GPIO_PDDR(PIN) &= ~(1 << GPIO_BIT_POS(PIN));\
} while (0)

//Configure pin as an input with pullup.
#define GPIO_PIN_MODE_INPUT_PULLUP(PIN) do {\
  GPIO_PORT_PCR(PIN) = PORT_PCR_MUX_Gpio | PORT_PCR_PE_Enabled | PORT_PCR_PS_Pullup;\
  GPIO_GPIO_PDDR(PIN) &= ~(1 << GPIO_BIT_POS(PIN));\
} while (0)

//Configure pin as an output.
#define GPIO_PIN_MODE_OUTPUT(PIN) do {\
  GPIO_PORT_PCR(PIN) = PORT_PCR_MUX_Gpio;\
  GPIO_GPIO_PDDR(PIN) |= 1 << GPIO_BIT_POS(PIN);\
} while (0)

//Configure pin as an analog input/output.
#define GPIO_PIN_MODE_ANALOG(PIN) do {\
  GPIO_PORT_PCR(PIN) = PORT_PCR_MUX_Analog;\
} while (0)

//Configure a pin as an alternate function.
#define GPIO_PIN_MODE_ALT(PIN, MUX_ALT) do {\
  GPIO_PORT_PCR(PIN) = GPIO_MUX_ALT(PIN, MUX_ALT);\
} while (0)

//Set pin state to logic high.
#define GPIO_PIN_SET(PIN) do {\
  GPIO_GPIO_PSOR(PIN) = 1 << GPIO_BIT_POS(PIN);\
} while (0)

//Set pin state to logic low.
#define GPIO_PIN_CLEAR(PIN) do {\
  GPIO_GPIO_PCOR(PIN) = 1 << GPIO_BIT_POS(PIN);\
} while (0)

//Toggle pin state between high and low.
#define GPIO_PIN_TOGGLE(PIN) do {\
  GPIO_GPIO_PTOR(PIN) = 1 << GPIO_BIT_POS(PIN);\
} while (0)

//Set pin state to VALUE (high if non zero, low otherwise).
#define GPIO_PIN_WRITE(PIN, VALUE) do {\
  if (VALUE)\
    GPIO_PIN_SET(PIN);\
  else\
    GPIO_PIN_CLEAR(PIN);\
} while (0)

//Read pin state (returns true if high, false if low).
#define GPIO_PIN_READ(PIN) ((GPIO_GPIO_PDIR(PIN) & (1 << GPIO_BIT_POS(PIN)))? true: false)

#endif //GPIO_H_
