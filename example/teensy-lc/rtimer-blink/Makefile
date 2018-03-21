#+-------------------------------------------------------------------------------------------------+
#| Project makefile for the rtimer blink example.                                                  |
#|                                                                                                 |
#| Author: Joksan Alvarado.                                                                        |
#+-------------------------------------------------------------------------------------------------+

#Set the main target.
CONTIKI_PROJECT = rtimer-blink
all: $(CONTIKI_PROJECT)

#Since this project targets the teensy-lc only, keep the project .co file (avoid recompiling).
.SECONDARY: $(CONTIKI_PROJECT).co

#Configure contiki for out of tree compilation and include its main makefile.
CONTIKI = ../../../contiki
TARGETDIRS += ../../../platform
include $(CONTIKI)/Makefile.include
