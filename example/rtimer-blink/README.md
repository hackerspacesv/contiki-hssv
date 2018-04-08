# Blink example using Contiki's rtimer library.

This alternate blink example uses the `rtimer` library instead of `etimer`. This aids in testing
because `rtimer` doesn't depend on the `clock` module as `etimer` does.

## Building.

To compile this example, simply provide a target name (e.g. `teensy-lc` or `samd21-mini-breakout`)
to the make command:

```
$ make TARGET=teensy-lc
```

You can clean all generated files (except .elf and .hex) with the `clean` target:

```
$ make TARGET=teensy-lc clean
```

And to clean all output files use the `distclean` target:

```
$ make TARGET=teensy-lc distclean
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
