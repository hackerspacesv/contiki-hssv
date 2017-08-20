//+------------------------------------------------------------------------------------------------+
//| UART peripheral driver for Kinetis MKL26 MCU.                                                  |
//|                                                                                                |
//| Author: Joksan Alvarado.                                                                       |
//+------------------------------------------------------------------------------------------------+

#include "mkl26-sim.h"
#include "mkl26-uart0.h"

//This function initializes the selected UART peripheral for use at 115200 bps, 8 bits, no partity
//and no stop bits. Note that pin multiplexing is not done here, as this is expected be done by the
//application itself.
void uart_init(volatile struct UART0_type *UART) {
  //Enable the corresponding peripheral clock.
  if (UART == UART0) {
    SIM->SOPT2 |= SIM_SOPT2_UART0SRC_FLL_PLL_Div2;
    SIM->SCGC4 |= SIM_SCGC4_UART0_Enabled;
  }

  //Set the baud rate to 115200 bps (MSB) and use a single stop bit.
  UART->BDH = (((26 >> 8) & UART0_BDH_SBR_Msk) << UART0_BDH_SBR_Pos) | UART0_BDH_SBNS_1;

  //Set the baud rate to 115200 bps (LSB).
  UART->BDL = (26 & UART0_BDL_SBR_Msk) << UART0_BDL_SBR_Pos;

  //Configure the module to perform 8-bit transmissions and disable parity.
  UART->C1 = UART0_C1_PE_Disabled | UART0_C1_M_8Bit;

  //Enable transmission and reception.
  UART->C2 = UART0_C2_RE_Enable | UART0_C2_TE_Enable;
}

//This function transmits a single character through the selected UART peripheral.
void uart_tx(volatile struct UART0_type *UART, uint8_t c) {
  //Wait until the transmit buffer is clear.
  while ((UART->S1 & UART0_S1_TDRE_Msk) == UART0_S1_TDRE_Clear);

  //Place the character in the transmit buffer.
  UART->D = c;
}
