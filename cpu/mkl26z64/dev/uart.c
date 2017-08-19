//+------------------------------------------------------------------------------------------------+
//| UART peripheral driver for Kinetis MKL26 MCU.                                                  |
//|                                                                                                |
//| Author: Joksan Alvarado.                                                                       |
//+------------------------------------------------------------------------------------------------+

#include "mkl26-sim.h"
#include "mkl26-uart0.h"

#if defined(MKL26_POWER_PROFILE_PERFORMANCE_48MHZ_PLL)
  //Performance profile configuration
  #define UART0_CLOCK_SOURCE SIM_SOPT2_UART0SRC_FLL_PLL_Div2  //Use PLL clock divided by 2
  #define UART0_C5_VAL UART0_C5_BOTHEDGE_Rising               //Use single edge sampling
  #define UART0_OSR 15                                        //Use an oversampling ratio of 16
  #define UART0_SBR 26                                        //(96MHz / 2) / 16 / 26 = 115.384kbps
#elif defined(MKL26_POWER_PROFILE_LOWPOWER_4MHZ_INTREF) ||\
      defined(MKL26_POWER_PROFILE_LOWPOWER_4MHZ_EXTREF)
  //Low power profile configuration
  #define UART0_CLOCK_SOURCE SIM_SOPT2_UART0SRC_MCGIRCLK      //Use 4MHz internal reference clock
  #define UART0_C5_VAL UART0_C5_BOTHEDGE_Both                 //Use both edge sampling
  #define UART0_OSR 6                                         //Use an oversampling ratio of 7
  #define UART0_SBR 5                                         //(4MHz) / 7 / 5 = 114.285kbps
#else
  #error "Unsupported power profile"
#endif

//This function initializes the selected UART peripheral for use at 115200 bps, 8 bits, no partity
//and no stop bits. Note that pin multiplexing is not done here, as this is expected be done by the
//application itself.
void uart_init(volatile struct UART0_type *UART) {
  if (UART == UART0) {
    //Enable the corresponding peripheral clock.
    SIM->SOPT2 |= UART0_CLOCK_SOURCE;
    SIM->SCGC4 |= SIM_SCGC4_UART0_Enabled;

    //Set the edge sampling configuration for the baud rate clock.
    UART->C5 = UART0_C5_VAL;

    //Set the oversampling ratio, disable 10 bit mode.
    UART->C4 = (UART0_OSR << UART0_C4_OSR_Pos) & UART0_C4_OSR_Msk | UART0_C4_M10_8_9Bit;

    //Set the baud rate divider (MSB) and use a single stop bit.
    UART->BDH = (((UART0_SBR >> 8) << UART0_BDH_SBR_Pos) & UART0_BDH_SBR_Msk) | UART0_BDH_SBNS_1;

    //Set the baud rate divider (LSB).
    UART->BDL = (UART0_SBR << UART0_BDL_SBR_Pos) & UART0_BDL_SBR_Msk;

    //Configure the module to perform 8-bit transmissions and disable parity.
    UART->C1 = UART0_C1_PE_Disabled | UART0_C1_M_8Bit;

    //Enable transmission and reception.
    UART->C2 = UART0_C2_RE_Enable | UART0_C2_TE_Enable;
  }
}

//This function transmits a single character through the selected UART peripheral.
void uart_tx(volatile struct UART0_type *UART, uint8_t c) {
  //Wait until the transmit buffer is clear.
  while ((UART->S1 & UART0_S1_TDRE_Msk) == UART0_S1_TDRE_Clear);

  //Place the character in the transmit buffer.
  UART->D = c;
}
