# UART and ctimer test example.

This very simple demo tests the functionality of the UART output and the ctimer library in order to
print the current system time (seconds count) to the standard output.

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

## Testing.

At the time of creation of this example, the standard output of the teensy boards is transmitted by
default through UART on pin number 1 (TX), at 115200 baud per second (8 data bits, no parity, 1 stop
bit). You can use any serial-to-usb adapter and your favorite serial terminal program for this
purpose.
