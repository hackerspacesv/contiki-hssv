//+------------------------------------------------------------------------------------------------+
//| UART0 peripheral registers for Kinetis MKL26 MCU.                                              |
//|                                                                                                |
//| Author: Joksan Alvarado.                                                                       |
//+------------------------------------------------------------------------------------------------+

#ifndef MKL26_UART0_H_
#define MKL26_UART0_H_

#include <stdint.h>

struct UART0_type {
  uint8_t BDH;            //Baud rate register high
  uint8_t BDL;            //Baud rate register low
  uint8_t C1;             //Control register 1
  uint8_t C2;             //Control register 2
  uint8_t S1;             //Status register 1
  uint8_t S2;             //Status register 2
  uint8_t C3;             //Control register 3
  uint8_t D;              //Data register
  uint8_t MA1;            //Match address register 1
  uint8_t MA2;            //Match address register 2
  uint8_t C4;             //Control register 4
  uint8_t C5;             //Control register 5
};

#define UART0 ((volatile struct UART0_type *) 0x4006A000)

//Baud rate register high bitfields
#define UART0_BDH_SBR_Msk            0x1F      //Baud rate modulo divisor (MSB)
#define UART0_BDH_SBR_Pos            0
#define UART0_BDH_SBNS_1             (0 << 5)  //Stop bit number select
#define UART0_BDH_SBNS_2             (1 << 5)
#define UART0_BDH_RXEDGIE_Disabled   (0 << 6)  //RX input active edge interrupt enable
#define UART0_BDH_RXEDGIE_Enabled    (1 << 6)
#define UART0_BDH_LBKDIE_Disabled    (0 << 7)  //LIN break detect interrupt enable
#define UART0_BDH_LBKDIE_Enabled     (1 << 7)

//Baud rate register low bitfields
#define UART0_BDL_SBR_Msk  0xFF  //Baud rate modulo divisor (LSB)
#define UART0_BDL_SBR_Pos  0

//Control register 1 bitfields
#define UART0_C1_PT_Even         (0 << 0)  //Parity type
#define UART0_C1_PT_Odd          (1 << 0)
#define UART0_C1_PE_Disabled     (0 << 1)  //Parity enable
#define UART0_C1_PE_Enabled      (1 << 1)
#define UART0_C1_ILT_Start       (0 << 2)  //Idle line type select
#define UART0_C1_ILT_Stop        (1 << 2)
#define UART0_C1_WAKE_Idle       (0 << 3)  //Receiver wakeup method select
#define UART0_C1_WAKE_AddrMark   (1 << 3)
#define UART0_C1_M_8Bit          (0 << 4)  //9 bit or 8 bit mode select
#define UART0_C1_M_9Bit          (1 << 4)
#define UART0_C1_RSRC_Loopback   (0 << 5)  //Receiver source select
#define UART0_C1_RSRC_Single     (1 << 5)
#define UART0_C1_DOZEEN_EnWait   (0 << 6)  //Doze enable
#define UART0_C1_DOZEEN_DisWait  (1 << 6)
#define UART0_C1_LOOPS_Normal    (0 << 7)  //Loop mode select
#define UART0_C1_LOOPS_Loop      (1 << 7)

//Control register 2 bitfields
#define UART0_C2_SBK_Clear       (0 << 0)  //Send break
#define UART0_C2_SBK_Set         (1 << 0)
#define UART0_C2_RWU_Clear       (0 << 1)  //Receiver wakeup control
#define UART0_C2_RWU_Set         (1 << 1)
#define UART0_C2_RE_Disable      (0 << 2)  //Receiver enable
#define UART0_C2_RE_Enable       (1 << 2)
#define UART0_C2_TE_Disable      (0 << 3)  //Transmitter enable
#define UART0_C2_TE_Enable       (1 << 3)
#define UART0_C2_ILIE_Disabled   (0 << 4)  //Idle line interrupt enable for IDLE
#define UART0_C2_ILIE_Enabled    (1 << 4)
#define UART0_C2_RIE_Disabled    (0 << 5)  //Receiver interrupt enable for RDRF
#define UART0_C2_RIE_Enabled     (1 << 5)
#define UART0_C2_TCIE_Disabled   (0 << 6)  //Transmission complete interrupt enable for TC
#define UART0_C2_TCIE_Enabled    (1 << 6)
#define UART0_C2_TIE_Disabled    (0 << 7)  //Transmit interrupt enable for TDRE
#define UART0_C2_TIE_Enabled     (1 << 7)

//Status register 1 bitfields
#define UART0_S1_PF_Msk      0x01      //Parity error flag
#define UART0_S1_PF_Clear    (0 << 0)
#define UART0_S1_PF_Set      (1 << 0)
#define UART0_S1_FE_Msk      0x02      //Framing error flag
#define UART0_S1_FE_Clear    (0 << 1)
#define UART0_S1_FE_Set      (1 << 1)
#define UART0_S1_NF_Msk      0x04      //Noise flag
#define UART0_S1_NF_Clear    (0 << 2)
#define UART0_S1_NF_Set      (1 << 2)
#define UART0_S1_OR_Msk      0x08      //Receiver overrun flag
#define UART0_S1_OR_Clear    (0 << 3)
#define UART0_S1_OR_Set      (1 << 3)
#define UART0_S1_IDLE_Msk    0x10      //Idle line flag
#define UART0_S1_IDLE_Clear  (0 << 4)
#define UART0_S1_IDLE_Set    (1 << 4)
#define UART0_S1_RDRF_Msk    0x20      //Receive data register full flag
#define UART0_S1_RDRF_Clear  (0 << 5)
#define UART0_S1_RDRF_Set    (1 << 5)
#define UART0_S1_TC_Msk      0x40      //Transmission complete flag
#define UART0_S1_TC_Clear    (0 << 6)
#define UART0_S1_TC_Set      (1 << 6)
#define UART0_S1_TDRE_Msk    0x80      //Transmit data register empty flag
#define UART0_S1_TDRE_Clear  (0 << 7)
#define UART0_S1_TDRE_Set    (1 << 7)

//Status register 2 bitfields
#define UART0_S2_RAF_Msk         0x01      //Receiver active flag
#define UART0_S2_RAF_Idle        (0 << 0)
#define UART0_S2_RAF_Active      (1 << 0)
#define UART0_S2_LBKDE_Disabled  (0 << 1)  //LIN break detection enable
#define UART0_S2_LBKDE_Enabled   (1 << 1)
#define UART0_S2_BRK13_Short     (0 << 2)  //Break character generation length
#define UART0_S2_BRK13_Long      (1 << 2)
#define UART0_S2_RWUID_Disabled  (0 << 3)  //Receive wakeup idle detect
#define UART0_S2_RWUID_Enabled   (1 << 3)
#define UART0_S2_RXINV_Normal    (0 << 4)  //Receive data inversion
#define UART0_S2_RXINV_Inverted  (1 << 4)
#define UART0_S2_MSBF_LSB        (0 << 5)  //MSB first
#define UART0_S2_MSBF_MSB        (1 << 5)
#define UART0_S2_RXEDGIF_Msk     0x40      //UART0_RX pin active edge interrupt flag
#define UART0_S2_RXEDGIF_Clear   (0 << 6)
#define UART0_S2_RXEDGIF_Set     (1 << 6)
#define UART0_S2_LBKDIF_Msk      0x80      //LIN break detect interrupt flag
#define UART0_S2_LBKDIF_Clear    (0 << 7)
#define UART0_S2_LBKDIF_Set      (1 << 7)

//Control register 3 bitfields
#define UART0_C3_PEIE_Disabled   (0 << 0)  //Parity error interrupt enable
#define UART0_C3_PEIE_Enabled    (1 << 0)
#define UART0_C3_FEIE_Disabled   (0 << 1)  //Framing error interrupt enable
#define UART0_C3_FEIE_Enabled    (1 << 1)
#define UART0_C3_NEIE_Disabled   (0 << 2)  //Noise error interrupt enable
#define UART0_C3_NEIE_Enabled    (1 << 2)
#define UART0_C3_ORIE_Disabled   (0 << 3)  //Overrun interrupt enable
#define UART0_C3_ORIE_Enabled    (1 << 3)
#define UART0_C3_TXINV_Normal    (0 << 4)  //Transmit data inversion
#define UART0_C3_TXINV_Inverted  (1 << 4)
#define UART0_C3_TXDIR_Input     (0 << 5)  //UART0_TX pin direction in single wire mode
#define UART0_C3_TXDIR_Output    (1 << 5)
#define UART0_C3_R9T8_Msk        0x40      //Receive bit 9 / transmit bit 8
#define UART0_C3_R9T8_Pos        6
#define UART0_C3_R8T9_Msk        0x80      //Receive bit 8 / transmit bit 9
#define UART0_C3_R8T9_Pos        7

//Control register 4 bitfields
#define UART0_C4_OSR_Msk         0x1F      //Over sampling ratio
#define UART0_C4_OSR_Pos         0
#define UART0_C4_M10_8_9Bit      (0 << 5)  //10-bit mode select
#define UART0_C4_M10_10Bit       (1 << 5)
#define UART0_C4_MAEN2_Disabled  (0 << 6)  //Match address mode enable 2
#define UART0_C4_MAEN2_Enabled   (1 << 6)
#define UART0_C4_MAEN1_Disabled  (0 << 7)  //Match address mode enable 1
#define UART0_C4_MAEN1_Enabled   (1 << 7)

//Control register 5 bitfields
#define UART0_C5_RESYNCDIS_Enabled   (0 << 0)  //Resynchronization disable
#define UART0_C5_RESYNCDIS_Disabled  (1 << 0)
#define UART0_C5_BOTHEDGE_Rising     (0 << 1)  //Both edge sampling
#define UART0_C5_BOTHEDGE_Both       (1 << 1)
#define UART0_C5_RDMAE_Disabled      (0 << 5)  //Receiver full DMA enable
#define UART0_C5_RDMAE_Enabled       (1 << 5)
#define UART0_C5_TDMAE_Disabled      (0 << 7)  //Transmitter DMA enable
#define UART0_C5_TDMAE_Enabled       (1 << 7)

#endif //MKL26_UART0_H_
