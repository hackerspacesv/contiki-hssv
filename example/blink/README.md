# Blink example.

This extremely simple example shows how to blink an LED using a Contiki event timer (`etimer`) and
the GPIO driver library. It serves as a general test for the compilation chain and basic system
support for Contiki too.

## Building.

To compile this example, simply provide a target name (e.g. `teensy-lc`, `teensy-32` or `teensy-36`)
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

You can use the teensy loader program to upload the .hex file to the board.
