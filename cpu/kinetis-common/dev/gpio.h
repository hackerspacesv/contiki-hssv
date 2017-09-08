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

//Include the respective HAL header, according to the MCU contained in the selected platform.
#if defined(MKL26Z64)
  #include "mkl26-gpio.h"
  #include "mkl26-port.h"
#elif defined(MK20DX256)
  #include "mk20-gpio.h"
  #include "mk20-port.h"
#elif defined(MK66FX1M0)
  #include "mk66-gpio.h"
  #include "mk66-port.h"
#else
  #error "Unsupported CPU"
#endif

//Include the board pinout definition for the selected platform.
#include "board-pinout.h"

//Macros intended for internal use (not part of the API)
//--------------------------------------------------------------------------------------------------

//Macro used to concatenate macros. A typical two level expansion strategy is used because of the
//way that the C preprocessor works. This allows joining 2 tokens that can form a new macro which is
//then expanded.
#define GPIO_CONCAT_(A, B) A ## B
#define GPIO_CONCAT(A, B) GPIO_CONCAT_(A, B)

//Macros used to concatenate the pin number with a prefix which maps to a macro defined in the board
//pinout header, allowing to obtain the PORT/GPIO peripheral instance (A, B, C, etc.) and the bit
//position (0..31).
#define GPIO_PER_INS(PIN) GPIO_CONCAT(BOARD_PER_INS_PIN_, PIN)
#define GPIO_BIT_POS(PIN) GPIO_CONCAT(BOARD_BIT_POS_PIN_, PIN)

//These macros allow to obtain the PORT and GPIO peripheral instances that are associated to an
//especific pin number.
#define GPIO_PORT(PIN) GPIO_CONCAT(PORT, GPIO_PER_INS(PIN))
#define GPIO_GPIO(PIN) GPIO_CONCAT(GPIO, GPIO_PER_INS(PIN))

//These macros allow to obtain specific registers asociated with a pin number.
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
