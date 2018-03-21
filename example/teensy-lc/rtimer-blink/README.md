# Blink example using Contiki's rtimer library.

This alternate blink example uses the `rtimer` library instead of `etimer`. This aids in testing
because `rtimer` doesn't depend on the `clock` module as `etimer` does.

## Building.

To compile this example simply call make (target name has been saved in Makefile.target):

```
$ make
```

You can clean all generated files (except .elf and .hex) with the `clean` target:

```
$ make clean
```

And to clean all output files use the `distclean` target:

```
$ make distclean
```

## Testing.

You can use the teensy loader program to upload the .hex file to the board.
