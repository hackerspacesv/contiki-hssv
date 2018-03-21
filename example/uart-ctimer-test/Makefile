#+-------------------------------------------------------------------------------------------------+
#| Project makefile for the UART and ctimer test example.                                          |
#|                                                                                                 |
#| Author: Joksan Alvarado.                                                                        |
#+-------------------------------------------------------------------------------------------------+

#Set the main target.
CONTIKI_PROJECT = uart-ctimer-test
all: $(CONTIKI_PROJECT)

#Set the project configuration header
DEFINES += PROJECT_CONF_H=\"project-conf.h\"

#Configure contiki for out of tree compilation and include its main makefile.
CONTIKI = ../../contiki
TARGETDIRS += ../../platform
include $(CONTIKI)/Makefile.include
