//+------------------------------------------------------------------------------------------------+
//| Board pin definitions for the Sparkfun SAMD21G Mini Breakout platform.                         |
//|                                                                                                |
//| Author: Joksan Alvarado.                                                                       |
//+------------------------------------------------------------------------------------------------+

#ifndef BOARD_PINOUT_H_
#define BOARD_PINOUT_H_

//Board pin aliases.
#define BOARD_PIN_RX          BOARD_PIN_0
#define BOARD_PIN_TX          BOARD_PIN_1
#define BOARD_PIN_SS          BOARD_PIN_10
#define BOARD_PIN_MOSI        BOARD_PIN_11
#define BOARD_PIN_MISO        BOARD_PIN_12
#define BOARD_PIN_SCK         BOARD_PIN_13
#define BOARD_PIN_LED         BOARD_PIN_13
#define BOARD_PIN_LED_BLUE    BOARD_PIN_13
#define BOARD_PIN_LED_GREEN   BOARD_PIN_TX_LED
#define BOARD_PIN_LED_YELLOW  BOARD_PIN_RX_LED

//Board pin configuration.
#define BOARD_PIN_0         PA11
#define BOARD_PIN_1         PA10
#define BOARD_PIN_2         PA14
#define BOARD_PIN_3         PA09
#define BOARD_PIN_4         PA08
#define BOARD_PIN_5         PA15
#define BOARD_PIN_6         PA20
#define BOARD_PIN_7         PA21
#define BOARD_PIN_8         PA06
#define BOARD_PIN_9         PA07
#define BOARD_PIN_10        PA18
#define BOARD_PIN_11        PA16
#define BOARD_PIN_12        PA19
#define BOARD_PIN_13        PA17
#define BOARD_PIN_A0        PA02
#define BOARD_PIN_A1        PB08
#define BOARD_PIN_A2        PB09
#define BOARD_PIN_A3        PA04
#define BOARD_PIN_AREF      PA03
#define BOARD_PIN_TX_LED    PA27
#define BOARD_PIN_RX_LED    PB03
#define BOARD_PIN_SCL       PA23
#define BOARD_PIN_SDA       PA22
#define BOARD_PIN_USB_DP    PA25
#define BOARD_PIN_USB_DM    PA24
#define BOARD_PIN_USB_HOST  PA28
#define BOARD_PIN_SWCLK     PA30
#define BOARD_PIN_SWDIO     PA31

#endif //BOARD_PINOUT_H_
