#+-------------------------------------------------------------------------------------------------+
#| Project makefile for the low power blink example.                                               |
#|                                                                                                 |
#| Author: Joksan Alvarado.                                                                        |
#+-------------------------------------------------------------------------------------------------+

#Set the main target.
CONTIKI_PROJECT = low-power-blink
all: $(CONTIKI_PROJECT)

#Select the power profile
MKL26_POWER_PROFILE = LOWPOWER_4MHZ_INTREF

#Since this project targets the teensy-lc only, keep the project .co file (avoid recompiling).
.SECONDARY: $(CONTIKI_PROJECT).co

#Configure contiki for out of tree compilation and include its main makefile.
CONTIKI = ../../../contiki
TARGETDIRS += ../../../platform
include $(CONTIKI)/Makefile.include
