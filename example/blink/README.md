# Blink example.

This extremely simple example shows how to blink an LED using a Contiki event timer (`etimer`) and
the GPIO driver library. It serves as a general test for the compilation chain and basic system
support for Contiki too.

## Building.

To compile this example, simply provide a target name (e.g. `teensy-lc`, `teensy-32`, `teensy-36` or
`samd21-mini-breakout`)
to the make command:

```
$ make TARGET=teensy-32
```

You can clean all generated files (except .elf and .hex) with this command:

```
$ make TARGET=teensy-32 clean
```

And to clean all output files use this command:

```
$ make TARGET=teensy-32 distclean
```

## Testing on Teensy.

You can use the teensy loader program to upload the .hex file to the board.

## Testing on SAMD21 mini breakout.

To upload the program to the board you can use the bossac bootloader and its accompanying command
line tool, which can be conveniently called from the Makefile toolchain by using the `flash` target,
as shown below. To enter bootloader mode remember to quickly push the reset button twice. Also,
make sure that bossac resides in your system path.

```
make TARGET=samd21-mini-breakout flash
```
