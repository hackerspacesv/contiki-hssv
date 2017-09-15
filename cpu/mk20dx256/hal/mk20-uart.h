//+------------------------------------------------------------------------------------------------+
//| UART peripheral registers for Kinetis MK20 MCU.                                                |
//|                                                                                                |
//| Author: Joksan Alvarado.                                                                       |
//+------------------------------------------------------------------------------------------------+

#ifndef MK20_UART_H_
#define MK20_UART_H_

#include <stdint.h>

struct UART_type {
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
  uint8_t ED;             //Extended data register
  uint8_t MODEM;          //Modem register
  uint8_t IR;             //Infrared register
  uint8_t reserved0;
  uint8_t PFIFO;          //FIFO parameters
  uint8_t CFIFO;          //FIFO control register
  uint8_t SFIFO;          //FIFO status register
  uint8_t TWFIFO;         //FIFO transmit watermark
  uint8_t TCFIFO;         //FIFO transmit count
  uint8_t RWFIFO;         //FIFO receive watermark
  uint8_t RCFIFO;         //FIFO receive count
  uint8_t reserved1;
  uint8_t C7816;          //7816 control register
  uint8_t IE7816;         //7816 interrupt enable register
  uint8_t IS7816;         //7816 interrupt status register
  uint8_t WP7816;         //7816 wait parameter register
  uint8_t WN7816;         //7816 wait N register
  uint8_t WF7816;         //7816 wait FD register
  uint8_t ET7816;         //7816 error threshold register
  uint8_t TL7816;         //7816 transmit length register
  uint8_t reserved2;
  uint8_t C6;             //CEA709.1-B control register 6
  uint8_t PCTH;           //CEA709.1-B packet cycle time counter high
  uint8_t PCTL;           //CEA709.1-B packet cycle time counter low
  uint8_t B1T;            //CEA709.1-B Beta1 timer
  uint8_t SDTH;           //CEA709.1-B secondary delay timer high
  uint8_t SDTL;           //CEA709.1-B secondary delay timer low
  uint8_t PRE;            //CEA709.1-B preamble
  uint8_t TPL;            //CEA709.1-B transmit packet length
  uint8_t IE;             //CEA709.1-B interrupt enable register
  uint8_t WB;             //CEA709.1-B WBASE
  uint8_t S3;             //CEA709.1-B status register 3
  uint8_t S4;             //CEA709.1-B status register 4
  uint8_t RPL;            //CEA709.1-B received packet length
  uint8_t RPREL;          //CEA709.1-B received preamble length
  uint8_t CPW;            //CEA709.1-B collision pulse width
  uint8_t RIDT;           //CEA709.1-B receive indeterminate time
  uint8_t TIDT;           //CEA709.1-B transmit indeterminate time
};

#define UART0 ((volatile struct UART_type *) 0x4006A000)
#define UART1 ((volatile struct UART_type *) 0x4006B000)
#define UART2 ((volatile struct UART_type *) 0x4006C000)
#define UART4 ((volatile struct UART_type *) 0x400EA000)

//Baud rate register high bitfields
#define UART_BDH_SBR_Msk            0x1F      //UART baud rate bits (high)
#define UART_BDH_SBR_Pos            0
#define UART_BDH_SBNS_1             (0 << 5)  //Stop bit number select
#define UART_BDH_SBNS_2             (1 << 5)
#define UART_BDH_RXEDGIE_Disabled   (0 << 6)  //RxD input active edge interrupt enable
#define UART_BDH_RXEDGIE_Enabled    (1 << 6)
#define UART_BDH_LBKDIE_Disabled    (0 << 7)  //LIN break detect interrupt enable
#define UART_BDH_LBKDIE_Enabled     (1 << 7)

//Baud rate register low bitfields
#define UART_BDL_SBR_Msk  0xFF  //UART baud rate bits (low)
#define UART_BDL_SBR_Pos  0

//Control register 1 bitfields
#define UART_C1_PT_Even           (0 << 0)  //Parity type
#define UART_C1_PT_Odd            (1 << 0)
#define UART_C1_PE_Disabled       (0 << 1)  //Parity enable
#define UART_C1_PE_Enabled        (1 << 1)
#define UART_C1_ILT_Start         (0 << 2)  //Idle line type select
#define UART_C1_ILT_Stop          (1 << 2)
#define UART_C1_WAKE_Idle         (0 << 3)  //Receiver wakeup method select
#define UART_C1_WAKE_AddrMark     (1 << 3)
#define UART_C1_M_8Bit            (0 << 4)  //9 bit or 8 bit mode select
#define UART_C1_M_9Bit            (1 << 4)
#define UART_C1_RSRC_Loopback     (0 << 5)  //Receiver source select
#define UART_C1_RSRC_Single       (1 << 5)
#define UART_C1_UARTSWAI_EnWait   (0 << 6)  //UART stops in wait mode
#define UART_C1_UARTSWAI_DisWait  (1 << 6)
#define UART_C1_LOOPS_Normal      (0 << 7)  //Loop mode select
#define UART_C1_LOOPS_Loop        (1 << 7)

//Control register 2 bitfields
#define UART_C2_SBK_Clear       (0 << 0)  //Send break
#define UART_C2_SBK_Set         (1 << 0)
#define UART_C2_RWU_Clear       (0 << 1)  //Receiver wakeup control
#define UART_C2_RWU_Set         (1 << 1)
#define UART_C2_RE_Disable      (0 << 2)  //Receiver enable
#define UART_C2_RE_Enable       (1 << 2)
#define UART_C2_TE_Disable      (0 << 3)  //Transmitter enable
#define UART_C2_TE_Enable       (1 << 3)
#define UART_C2_ILIE_Disabled   (0 << 4)  //Idle line interrupt enable
#define UART_C2_ILIE_Enabled    (1 << 4)
#define UART_C2_RIE_Disabled    (0 << 5)  //Receiver full interrupt or DMA transfer enable
#define UART_C2_RIE_Enabled     (1 << 5)
#define UART_C2_TCIE_Disabled   (0 << 6)  //Transmission complete interrupt enable
#define UART_C2_TCIE_Enabled    (1 << 6)
#define UART_C2_TIE_Disabled    (0 << 7)  //Transmitter interrupt or DMA transfer enable
#define UART_C2_TIE_Enabled     (1 << 7)

//Status register 1 bitfields
#define UART_S1_PF_Msk      0x01      //Parity error flag
#define UART_S1_PF_Clear    (0 << 0)
#define UART_S1_PF_Set      (1 << 0)
#define UART_S1_FE_Msk      0x02      //Framing error flag
#define UART_S1_FE_Clear    (0 << 1)
#define UART_S1_FE_Set      (1 << 1)
#define UART_S1_NF_Msk      0x04      //Noise flag
#define UART_S1_NF_Clear    (0 << 2)
#define UART_S1_NF_Set      (1 << 2)
#define UART_S1_OR_Msk      0x08      //Receiver overrun flag
#define UART_S1_OR_Clear    (0 << 3)
#define UART_S1_OR_Set      (1 << 3)
#define UART_S1_IDLE_Msk    0x10      //Idle line flag
#define UART_S1_IDLE_Clear  (0 << 4)
#define UART_S1_IDLE_Set    (1 << 4)
#define UART_S1_RDRF_Msk    0x20      //Receive data register full flag
#define UART_S1_RDRF_Clear  (0 << 5)
#define UART_S1_RDRF_Set    (1 << 5)
#define UART_S1_TC_Msk      0x40      //Transmit complete flag
#define UART_S1_TC_Clear    (0 << 6)
#define UART_S1_TC_Set      (1 << 6)
#define UART_S1_TDRE_Msk    0x80      //Transmit data register empty flag
#define UART_S1_TDRE_Clear  (0 << 7)
#define UART_S1_TDRE_Set    (1 << 7)

//Status register 2 bitfields
#define UART_S2_RAF_Msk         0x01      //Receiver active flag
#define UART_S2_RAF_Idle        (0 << 0)
#define UART_S2_RAF_Active      (1 << 0)
#define UART_S2_LBKDE_Clear     (0 << 1)  //LIN break detection enable
#define UART_S2_LBKDE_Set       (1 << 1)
#define UART_S2_BRK13_Short     (0 << 2)  //Break transmit character length
#define UART_S2_BRK13_Long      (1 << 2)
#define UART_S2_RWUID_Disabled  (0 << 3)  //Receive wakeup idle detect
#define UART_S2_RWUID_Enabled   (1 << 3)
#define UART_S2_RXINV_Normal    (0 << 4)  //Receive data inversion
#define UART_S2_RXINV_Inverted  (1 << 4)
#define UART_S2_MSBF_LSB        (0 << 5)  //Most significant bit first
#define UART_S2_MSBF_MSB        (1 << 5)
#define UART_S2_RXEDGIF_Msk     0x40      //RxD pin active edge interrupt flag
#define UART_S2_RXEDGIF_Clear   (0 << 6)
#define UART_S2_RXEDGIF_Set     (1 << 6)
#define UART_S2_LBKDIF_Msk      0x80      //LIN break detect interrupt flag
#define UART_S2_LBKDIF_Clear    (0 << 7)
#define UART_S2_LBKDIF_Set      (1 << 7)

//Control register 3 bitfields
#define UART_C3_PEIE_Disabled   (0 << 0)  //Parity error interrupt enable
#define UART_C3_PEIE_Enabled    (1 << 0)
#define UART_C3_FEIE_Disabled   (0 << 1)  //Framing error interrupt enable
#define UART_C3_FEIE_Enabled    (1 << 1)
#define UART_C3_NEIE_Disabled   (0 << 2)  //Noise error interrupt enable
#define UART_C3_NEIE_Enabled    (1 << 2)
#define UART_C3_ORIE_Disabled   (0 << 3)  //Overrun error interrupt enable
#define UART_C3_ORIE_Enabled    (1 << 3)
#define UART_C3_TXINV_Normal    (0 << 4)  //Transmit data inversion
#define UART_C3_TXINV_Inverted  (1 << 4)
#define UART_C3_TXDIR_Input     (0 << 5)  //Transmitter pin data direction in single wire mode
#define UART_C3_TXDIR_Output    (1 << 5)
#define UART_C3_T8_Msk          0x40      //Transmit bit 8
#define UART_C3_T8_Pos          6
#define UART_C3_R8_Msk          0x80      //Received bit 8
#define UART_C3_R8_Pos          7

//Control register 4 bitfields
#define UART_C4_BRFA_Msk        0x1F      //Baud rate fine adjust
#define UART_C4_BRFA_Pos        0
#define UART_C4_M10_P9          (0 << 5)  //10-bit mode select
#define UART_C4_M10_P10         (1 << 5)
#define UART_C4_MAEN2_Disabled  (0 << 6)  //Match address mode enable 2
#define UART_C4_MAEN2_Enabled   (1 << 6)
#define UART_C4_MAEN1_Disabled  (0 << 7)  //Match address mode enable 1
#define UART_C4_MAEN1_Enabled   (1 << 7)

//Control register 5 bitfields
#define UART_C5_RDMAS_IRQ   (0 << 5)  //Receiver full DMA select
#define UART_C5_RDMAS_DMA   (1 << 5)
#define UART_C5_TDMAS_IRQ   (0 << 7)  //Transmitter DMA select
#define UART_C5_TDMAS_DMA   (1 << 7)

//Extended data register bitfields
#define UART_ED_PARITYE_Msk     0x40      //Indicates parity error in the current received dataword
#define UART_ED_PARITYE_OK      (0 << 6)
#define UART_ED_PARITYE_ERROR   (1 << 6)
#define UART_ED_NOISY_Msk       0x80      //Indicates noisy reception for current received dataword
#define UART_ED_NOISY_OK        (0 << 7)
#define UART_ED_NOISY_Noisy     (1 << 7)

//Modem register bitfields
#define UART_MODEM_TXCTSE_Disabled  (0 << 0)  //Transmitter clear to send enable
#define UART_MODEM_TXCTSE_Enabled   (1 << 0)
#define UART_MODEM_TXRTSE_Disabled  (0 << 1)  //Transmitter request to send enable
#define UART_MODEM_TXRTSE_Enabled   (1 << 1)
#define UART_MODEM_TXRTSPOL_Low     (0 << 2)  //Transmitter request to send polarity
#define UART_MODEM_TXRTSPOL_High    (1 << 2)
#define UART_MODEM_RXRTSE_Disabled  (0 << 3)  //Receiver request to send enable
#define UART_MODEM_RXRTSE_Enabled   (1 << 3)

//Infrared register bitfields
#define UART_IR_TNP_3_16        (0 << 0)  //Transmitter narrow pulse
#define UART_IR_TNP_1_16        (1 << 0)
#define UART_IR_TNP_1_32        (2 << 0)
#define UART_IR_TNP_1_4         (3 << 0)
#define UART_IR_IREN_Disabled   (0 << 2)  //Infrared enable
#define UART_IR_IREN_Enabled    (1 << 2)

//FIFO parameters bitfields
#define UART_PFIFO_RXFIFOSIZE_1     (0 << 0)  //Receive FIFO buffer depth
#define UART_PFIFO_RXFIFOSIZE_4     (1 << 0)
#define UART_PFIFO_RXFIFOSIZE_8     (2 << 0)
#define UART_PFIFO_RXFIFOSIZE_16    (3 << 0)
#define UART_PFIFO_RXFIFOSIZE_32    (4 << 0)
#define UART_PFIFO_RXFIFOSIZE_64    (5 << 0)
#define UART_PFIFO_RXFIFOSIZE_128   (6 << 0)
#define UART_PFIFO_RXFE_Disabled    (0 << 3)  //Receive FIFO enable
#define UART_PFIFO_RXFE_Enabled     (1 << 3)
#define UART_PFIFO_TXFIFOSIZE_1     (0 << 4)  //Transmit FIFO buffer depth
#define UART_PFIFO_TXFIFOSIZE_4     (1 << 4)
#define UART_PFIFO_TXFIFOSIZE_8     (2 << 4)
#define UART_PFIFO_TXFIFOSIZE_16    (3 << 4)
#define UART_PFIFO_TXFIFOSIZE_32    (4 << 4)
#define UART_PFIFO_TXFIFOSIZE_64    (5 << 4)
#define UART_PFIFO_TXFIFOSIZE_128   (6 << 4)
#define UART_PFIFO_TXFE_Disabled    (0 << 7)  //Transmit FIFO enable
#define UART_PFIFO_TXFE_Enabled     (1 << 7)

//FIFO control register bitfields
#define UART_CFIFO_RXUFE_Disabled   (0 << 0)  //Receive FIFO underflow interrupt enable
#define UART_CFIFO_RXUFE_Enabled    (1 << 0)
#define UART_CFIFO_TXOFE_Disabled   (0 << 1)  //Transmit FIFO overflow interrupt enable
#define UART_CFIFO_TXOFE_Enabled    (1 << 1)
#define UART_CFIFO_RXOFE_Disabled   (0 << 2)  //Receive FIFO overflow interrupt enable
#define UART_CFIFO_RXOFE_Enabled    (1 << 2)
#define UART_CFIFO_RXFLUSH_Nop      (0 << 6)  //Receive FIFO/buffer flush
#define UART_CFIFO_RXFLUSH_Flush    (1 << 6)
#define UART_CFIFO_TXFLUSH_Nop      (0 << 7)  //Transmit FIFO/buffer flush
#define UART_CFIFO_TXFLUSH_Flush    (1 << 7)

//FIFO status register bitfields
#define UART_SFIFO_RXUF_Msk         0x01      //Receiver buffer underflow flag
#define UART_SFIFO_RXUF_Clear       (0 << 0)
#define UART_SFIFO_RXUF_Set         (1 << 0)
#define UART_SFIFO_TXOF_Msk         0x02      //Transmitter buffer overflow flag
#define UART_SFIFO_TXOF_Clear       (0 << 1)
#define UART_SFIFO_TXOF_Set         (1 << 1)
#define UART_SFIFO_RXOF_Msk         0x04      //Receiver buffer overflow flag
#define UART_SFIFO_RXOF_Clear       (0 << 2)
#define UART_SFIFO_RXOF_Set         (1 << 2)
#define UART_SFIFO_RXEMPT_Msk       0x40      //Receive buffer/FIFO empty
#define UART_SFIFO_RXEMPT_HasData   (0 << 6)
#define UART_SFIFO_RXEMPT_Empty     (1 << 6)
#define UART_SFIFO_TXEMPT_Msk       0x80      //Transmit buffer/FIFO empty
#define UART_SFIFO_TXEMPT_HasData   (0 << 7)
#define UART_SFIFO_TXEMPT_Empty     (1 << 7)

//7816 control register bitfields
#define UART_C7816_ISO_7816E_Disabled   (0 << 0)  //ISO-7816 functionality enabled
#define UART_C7816_ISO_7816E_Enabled    (1 << 0)
#define UART_C7816_TTYPE_T0             (0 << 1)  //Transfer type
#define UART_C7816_TTYPE_T1             (1 << 1)
#define UART_C7816_INIT_Normal          (0 << 2)  //Detect initial character
#define UART_C7816_INIT_WaitInit        (1 << 2)
#define UART_C7816_ANACK_Disabled       (0 << 3)  //Generate NACK on error
#define UART_C7816_ANACK_Enabled        (1 << 3)
#define UART_C7816_ONACK_Disabled       (0 << 4)  //Generate NACK on overflow
#define UART_C7816_ONACK_Enabled        (1 << 4)

//7816 interrupt enable register bitfields
#define UART_IE7816_RXTE_Disabled     (0 << 0)  //Receive threshold exceeded interrupt enable
#define UART_IE7816_RXTE_Enabled      (1 << 0)
#define UART_IE7816_TXTE_Disabled     (0 << 1)  //Transmit threshold exceeded interrupt enable
#define UART_IE7816_TXTE_Enabled      (1 << 1)
#define UART_IE7816_GTVE_Disabled     (0 << 2)  //Guard timer violated interrupt enable
#define UART_IE7816_GTVE_Enabled      (1 << 2)
#define UART_IE7816_INITDE_disabled   (0 << 4)  //Initial character detected interrupt enable
#define UART_IE7816_INITDE_Enaabled   (1 << 4)
#define UART_IE7816_BWTE_Disabled     (0 << 5)  //Block wait timer interrupt enable
#define UART_IE7816_BWTE_Enabled      (1 << 5)
#define UART_IE7816_CWTE_Disabled     (0 << 6)  //Character wait timer interrupt enable
#define UART_IE7816_CWTE_Enabled      (1 << 6)
#define UART_IE7816_WTE_Disabled      (0 << 7)  //Wait timer interrupt enable
#define UART_IE7816_WTE_Enabled       (1 << 7)

//7816 interrupt status register bitfields
#define UART_IS7816_RXT_Msk       0x01      //Receive threshold exceeded interrupt
#define UART_IS7816_RXT_Clear     (0 << 0)
#define UART_IS7816_RXT_Set       (1 << 0)
#define UART_IS7816_TXT_Msk       0x02      //Transmit threshold exceeded interrupt
#define UART_IS7816_TXT_Clear     (0 << 1)
#define UART_IS7816_TXT_Set       (1 << 1)
#define UART_IS7816_GTV_Msk       0x04      //Guard timer violated interrupt
#define UART_IS7816_GTV_Clear     (0 << 2)
#define UART_IS7816_GTV_Set       (1 << 2)
#define UART_IS7816_INITD_Msk     0x10      //Initial character detected interrupt
#define UART_IS7816_INITD_Clear   (0 << 4)
#define UART_IS7816_INITD_Set     (1 << 4)
#define UART_IS7816_BWT_Msk       0x20      //Block wait timer interrupt
#define UART_IS7816_BWT_Clear     (0 << 5)
#define UART_IS7816_BWT_Set       (1 << 5)
#define UART_IS7816_CWT_Msk       0x40      //Character wait timer interrupt
#define UART_IS7816_CWT_Clear     (0 << 6)
#define UART_IS7816_CWT_Set       (1 << 6)
#define UART_IS7816_WT_Msk        0x80      //Wait timer interrupt
#define UART_IS7816_WT_Clear      (0 << 7)
#define UART_IS7816_WT_Set        (1 << 7)

//7816 error threshold register bitfields
#define UART_ET7816_RXTHRESHOLD_Msk   0x0F  //Receive NACK threshold
#define UART_ET7816_RXTHRESHOLD_Pos   0
#define UART_ET7816_TXTHRESHOLD_Msk   0xF0  //Transmit NACK threshold
#define UART_ET7816_TXTHRESHOLD_Pos   4

//CEA709.1-B control register 6 bitfields
#define UART_C6_CP_Low          (0 << 4)  //Collision signal polarity
#define UART_C6_CP_High         (1 << 4)
#define UART_C6_CE_Disabled     (0 << 5)  //Collision enable
#define UART_C6_CE_Enabled      (1 << 5)
#define UART_C6_TX709_Disabled  (0 << 6)  //CEA709.1-B transmit enable
#define UART_C6_TX709_Enabled   (1 << 6)
#define UART_C6_EN709_Disabled  (0 << 7)  //EN709
#define UART_C6_EN709_Enabled   (1 << 7)

//CEA709.1-B interrupt enable register bitfields
#define UART_IE_TXFIE_Disabled    (0 << 0)  //Transmission fail interrupt enable
#define UART_IE_TXFIE_Enabled     (1 << 0)
#define UART_IE_PSIE_Disabled     (0 << 1)  //Preamble start interrupt enable
#define UART_IE_PSIE_Enabled      (1 << 1)
#define UART_IE_PCTEIE_Disabled   (0 << 2)  //Packet cycle timer interrupt enable
#define UART_IE_PCTEIE_Enabled    (1 << 2)
#define UART_IE_PTXIE_Disabled    (0 << 3)  //Packet transmitted interrupt enable
#define UART_IE_PTXIE_Enabled     (1 << 3)
#define UART_IE_PRXIE_Disabled    (0 << 4)  //Packet received interrupt enable
#define UART_IE_PRXIE_Enabled     (1 << 4)
#define UART_IE_ISDIE_Disabled    (0 << 5)  //Initial sync detection interrupt enable
#define UART_IE_ISDIE_Enabled     (1 << 5)
#define UART_IE_WBEIE_Disabled    (0 << 6)  //WBASE expired interrupt enable
#define UART_IE_WBEIE_Enabled     (1 << 6)

//CEA709.1-B status register 3 bitfields
#define UART_S3_TXFF_Msk      0x01      //Transmission fail flag
#define UART_S3_TXFF_Clear    (0 << 0)
#define UART_S3_TXFF_Set      (1 << 0)
#define UART_S3_PSF_Msk       0x02      //Preamble start flag
#define UART_S3_PSF_Clear     (0 << 1)
#define UART_S3_PSF_Set       (1 << 1)
#define UART_S3_PCTEF_Msk     0x04      //Packet cycle timer expired flag
#define UART_S3_PCTEF_Clear   (0 << 2)
#define UART_S3_PCTEF_Set     (1 << 2)
#define UART_S3_PTXF_Msk      0x08      //Packet transmitted flag
#define UART_S3_PTXF_Clear    (0 << 3)
#define UART_S3_PTXF_Set      (1 << 3)
#define UART_S3_PRXF_Msk      0x10      //Packet received flag
#define UART_S3_PRXF_Clear    (0 << 4)
#define UART_S3_PRXF_Set      (1 << 4)
#define UART_S3_ISD_Msk       0x20      //Initial sync detect
#define UART_S3_ISD_Clear     (0 << 5)
#define UART_S3_ISD_Set       (1 << 5)
#define UART_S3_WBEF_Msk      0x40      //Wbase expired flag
#define UART_S3_WBEF_Clear    (0 << 6)
#define UART_S3_WBEF_Set      (1 << 6)
#define UART_S3_PEF_Msk       0x80      //Preamble error flag
#define UART_S3_PEF_Clear     (0 << 7)
#define UART_S3_PEF_Set       (1 << 7)

//CEA709.1-B status register 4 bitfields
#define UART_S4_FE_Msk        0x01      //Framing error
#define UART_S4_FE_Clear      (0 << 0)
#define UART_S4_FE_Set        (1 << 0)
#define UART_S4_ILCV_Msk      0x02      //Improper line code violation
#define UART_S4_ILCV_Clear    (0 << 1)
#define UART_S4_ILCV_Set      (1 << 1)
#define UART_S4_CDET_Msk      0x0C      //CDET
#define UART_S4_CDET_NoCol    (0 << 2)
#define UART_S4_CDET_ColPre   (1 << 2)
#define UART_S4_CDET_ColDat   (2 << 2)
#define UART_S4_CDET_ColLCV   (3 << 2)
#define UART_S4_INITF_Msk     0x10      //Initial synchronization fail flag
#define UART_S4_INITF_Clear   (0 << 4)
#define UART_S4_INITF_Set     (1 << 4)

#endif //MK20_UART_H_
