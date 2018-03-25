//+------------------------------------------------------------------------------------------------+
//| GPIO peripheral driver for SAMD21 MCUs.                                                        |
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

#include "samd21.h"

//Include the board pinout definition for the selected platform.
#if CONTIKI_TARGET_SAMD21_MINI_BREAKOUT
#include "board-pinout.h"
#endif

//Macros intended for internal use (not part of the API)
//--------------------------------------------------------------------------------------------------

//Macros used to combine the pin name with a prefix which which maps to a macro defined in the
//device PIO header, allowing to obtain the pin number (0-31 for port A, 32-63 for port B), the port
//bit mask or the MUX alternate function number.
#define GPIO_PIN_NUMBER(PIN) CC_CONCAT_EXT_2(PIN_, PIN)
#define GPIO_PORT_MASK(PIN) CC_CONCAT_EXT_2(PORT_, PIN)
#define GPIO_MUX_ALT(PIN, MUX_ALT) CC_CONCAT_EXT_3(MUX_, PIN, MUX_ALT)

//This macro allows to obtain the PORT group instance that is associated with an specific pin.
#define GPIO_PORT(PIN) PORT->Group[GPIO_PIN_NUMBER(PIN) >> 5]

//These macros allow to obtain specific registers asociated with a pin.
#define GPIO_PORT_WRCONFIG(PIN) GPIO_PORT(PIN).WRCONFIG.reg
#define GPIO_PORT_DIRCLR(PIN) GPIO_PORT(PIN).DIRCLR.reg
#define GPIO_PORT_DIRSET(PIN) GPIO_PORT(PIN).DIRSET.reg
#define GPIO_PORT_OUTSET(PIN) GPIO_PORT(PIN).OUTSET.reg
#define GPIO_PORT_OUTCLR(PIN) GPIO_PORT(PIN).OUTCLR.reg
#define GPIO_PORT_OUTTGL(PIN) GPIO_PORT(PIN).OUTTGL.reg
#define GPIO_PORT_IN(PIN) GPIO_PORT(PIN).IN.reg

//Macros exposed by this API.
//--------------------------------------------------------------------------------------------------

//Configure pin as an input.
#define GPIO_PIN_MODE_INPUT(PIN) do {\
  GPIO_PORT_WRCONFIG(PIN) = (GPIO_PIN_NUMBER(PIN) & 0x10? PORT_WRCONFIG_HWSEL: 0) |\
                            PORT_WRCONFIG_WRPINCFG | PORT_WRCONFIG_INEN |\
                            PORT_WRCONFIG_PINMASK(1 << (GPIO_PIN_NUMBER(PIN) & 0xF));\
  GPIO_PORT_DIRCLR(PIN) = GPIO_PORT_MASK(PIN);\
} while (0)

//Configure pin as an input with pulldown.
#define GPIO_PIN_MODE_INPUT_PULLDOWN(PIN) do {\
  GPIO_PORT_WRCONFIG(PIN) = (GPIO_PIN_NUMBER(PIN) & 0x10? PORT_WRCONFIG_HWSEL: 0) |\
                            PORT_WRCONFIG_WRPINCFG | PORT_WRCONFIG_INEN | PORT_WRCONFIG_PULLEN |\
                            PORT_WRCONFIG_PINMASK(1 << (GPIO_PIN_NUMBER(PIN) & 0xF));\
  GPIO_PORT_DIRCLR(PIN) = GPIO_PORT_MASK(PIN);\
  GPIO_PIN_CLEAR(PIN);\
} while (0)

//Configure pin as an input with pullup.
#define GPIO_PIN_MODE_INPUT_PULLUP(PIN) do {\
  GPIO_PORT_WRCONFIG(PIN) = (GPIO_PIN_NUMBER(PIN) & 0x10? PORT_WRCONFIG_HWSEL: 0) |\
                            PORT_WRCONFIG_WRPINCFG | PORT_WRCONFIG_INEN | PORT_WRCONFIG_PULLEN |\
                            PORT_WRCONFIG_PINMASK(1 << (GPIO_PIN_NUMBER(PIN) & 0xF));\
  GPIO_PORT_DIRCLR(PIN) = GPIO_PORT_MASK(PIN);\
  GPIO_PIN_SET(PIN);\
} while (0)

//Configure pin as an output.
#define GPIO_PIN_MODE_OUTPUT(PIN) do {\
  GPIO_PORT_WRCONFIG(PIN) = (GPIO_PIN_NUMBER(PIN) & 0x10? PORT_WRCONFIG_HWSEL: 0) |\
                            PORT_WRCONFIG_WRPINCFG |\
                            PORT_WRCONFIG_PINMASK(1 << (GPIO_PIN_NUMBER(PIN) & 0xF));\
  GPIO_PORT_DIRSET(PIN) = GPIO_PORT_MASK(PIN);\
} while (0)

//Configure pin as an analog input/output.
#define GPIO_PIN_MODE_ANALOG(PIN) do {\
  GPIO_PORT_WRCONFIG(PIN) = (GPIO_PIN_NUMBER(PIN) & 0x10? PORT_WRCONFIG_HWSEL: 0) |\
                            PORT_WRCONFIG_WRPINCFG | PORT_WRCONFIG_PMUXEN |\
                            PORT_WRCONFIG_WRPMUX | PORT_WRCONFIG_PMUX(1) |\
                            PORT_WRCONFIG_PINMASK(1 << (GPIO_PIN_NUMBER(PIN) & 0xF));\
} while (0)

//Configure a pin as an alternate function.
#define GPIO_PIN_MODE_ALT(PIN, MUX_ALT) do {\
  GPIO_PORT_WRCONFIG(PIN) = (GPIO_PIN_NUMBER(PIN) & 0x10? PORT_WRCONFIG_HWSEL: 0) |\
                            PORT_WRCONFIG_WRPINCFG | PORT_WRCONFIG_PMUXEN |\
                            PORT_WRCONFIG_WRPMUX | PORT_WRCONFIG_PMUX(GPIO_MUX_ALT(PIN, MUX_ALT)) |\
                            PORT_WRCONFIG_PINMASK(1 << (GPIO_PIN_NUMBER(PIN) & 0xF));\
} while (0)

//Set pin state to logic high.
#define GPIO_PIN_SET(PIN) do {\
  GPIO_PORT_OUTSET(PIN) = GPIO_PORT_MASK(PIN);\
} while (0)

//Set pin state to logic low.
#define GPIO_PIN_CLEAR(PIN) do {\
  GPIO_PORT_OUTCLR(PIN) = GPIO_PORT_MASK(PIN);\
} while (0)

//Toggle pin state between high and low.
#define GPIO_PIN_TOGGLE(PIN) do {\
  GPIO_PORT_OUTTGL(PIN) = GPIO_PORT_MASK(PIN);\
} while (0)

//Set pin state to VALUE (high if non zero, low otherwise).
#define GPIO_PIN_WRITE(PIN, VALUE) do {\
  if (VALUE)\
    GPIO_PIN_SET(PIN);\
  else\
    GPIO_PIN_CLEAR(PIN);\
} while (0)

//Read pin state (returns true if high, false if low).
#define GPIO_PIN_READ(PIN) ((GPIO_PORT_IN(PIN) & GPIO_PORT_MASK(PIN))? true: false)

#endif //GPIO_H_
