//+------------------------------------------------------------------------------------------------+
//| EVSYS peripheral driver for ATSAMD21G18A MCU.                                                  |
//|                                                                                                |
//| This driver provides event detection interrupt services for the RTC peripheral driver.         |
//|                                                                                                |
//| The RTC peripheral is configured by its driver to generate periodic events, which this driver  |
//| is configure to detect, forwarding the interrupts to the rtc_event_callback function. This     |
//| driver needs to be initialized before the RTC driver.                                          |
//|                                                                                                |
//| Author: Joksan Alvarado.                                                                       |
//+------------------------------------------------------------------------------------------------+

#include "samd21.h"
#include "evsys.h"

//External callback functions called by this module.
extern void rtc_event_callback();

//This function initializes the EVSYS module.
void evsys_init() {
  //Initialize the EVSYS peripheral.
  //--------------------------------

  //Set the EVSYS generic clock to use the generic clock generator 1.
  GCLK->CLKCTRL.reg = GCLK_CLKCTRL_CLKEN | GCLK_CLKCTRL_ID_EVSYS_0 | GCLK_CLKCTRL_GEN_GCLK1;

  //Enable the APBC clock for the EVSYS peripheral.
  PM->APBCMASK.reg |= PM_APBCMASK_EVSYS;

  //Restart the EVSYS to make sure it's in a known state.
  EVSYS->CTRL.bit.SWRST = 1;

  //Configure the event channel 0 for event detection on the rising edge, using a synchronous path
  //with RTC periodic event 5 as its event generator source.
  EVSYS->CHANNEL.reg = EVSYS_CHANNEL_EDGSEL_RISING_EDGE | EVSYS_CHANNEL_PATH_SYNCHRONOUS |
                       EVSYS_CHANNEL_EVGEN(0x09) | EVSYS_CHANNEL_CHANNEL(0);

  //Enable the event detection interrupt for channel 0.
  EVSYS->INTENSET.reg = EVSYS_INTENSET_EVD0;

  //Configure the interrupt in the NVIC.
  //------------------------------------
  NVIC_SetPriority(EVSYS_IRQn, 2);  //Set a middle priority level
  NVIC_EnableIRQ(EVSYS_IRQn);       //Enable the interrupt
}

//Interrupt handler for EVSYS peripheral.
void evsys_handler() {
  //Determine the event channel that caused the interrupt.
  if (EVSYS->INTFLAG.reg | EVSYS_INTFLAG_EVD0) {
    //Event channel 0 caused an event detection interrupt. Clear its interrupt flag.
    EVSYS->INTFLAG.reg = EVSYS_INTFLAG_EVD0;

    //Call the RTC event callback function in response to the event.
    rtc_event_callback();
  }
}
