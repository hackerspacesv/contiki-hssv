//+------------------------------------------------------------------------------------------------+
//| UART peripheral driver for Kinetis MK66 MCU.                                                   |
//|                                                                                                |
//| Author: Joksan Alvarado.                                                                       |
//+------------------------------------------------------------------------------------------------+

#include "mk66-sim.h"
#include "mk66-uart.h"

//This function initializes the selected UART peripheral for use at 115200 bps, 8 bits, no partity
//and no stop bits. Note that pin multiplexing is not done here, as this is expected be done by the
//application itself.
void uart_init(volatile struct UART_type *UART) {
  //Enable the corresponding peripheral clock.
  if (UART == UART0)
    SIM->SCGC4 |= SIM_SCGC4_UART0_Enabled;
  else if (UART == UART1)
    SIM->SCGC4 |= SIM_SCGC4_UART1_Enabled;
  else if (UART == UART2)
    SIM->SCGC4 |= SIM_SCGC4_UART2_Enabled;
  else if (UART == UART3)
    SIM->SCGC4 |= SIM_SCGC4_UART3_Enabled;
  else if (UART == UART4)
    SIM->SCGC1 |= SIM_SCGC1_UART4_Enabled;

  //Set the baud rate to 115200 bps (MSB) and use a single stop bit.
  UART->BDH = (((97>>8) & UART_BDH_SBR_Msk) << UART_BDH_SBR_Pos) | UART_BDH_SBNS_1;

  //Set the baud rate to 115200 bps (LSB).
  UART->BDL = (97 & UART_BDL_SBR_Msk) << UART_BDL_SBR_Pos;

  //Configure the module to perform 8-bit transmissions and disable parity.
  UART->C1 = UART_C1_PE_Disabled | UART_C1_M_8Bit;

  //Enable transmission and reception.
  UART->C2 = UART_C2_RE_Enable | UART_C2_TE_Enable;
}

//This function transmits a single character through the selected UART peripheral.
void uart_tx(volatile struct UART_type *UART, uint8_t c) {
  //Wait until the transmit buffer is clear.
  while (UART->TCFIFO > 0);

  //Place the character in the transmit buffer.
  UART->D = c;
}
