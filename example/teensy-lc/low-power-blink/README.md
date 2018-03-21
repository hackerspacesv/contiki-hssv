# Low power blink example.

This example allows testing the potential power savings that the Teensy LC platform can provide by
switching to a lower power profile.

In order to switch to a low power profile simply set the `MKL26_POWER_PROFILE` make variable in
the project makefile. Keep in mind that lowering power consumption has a direct impact on processor
performance (system clocks run slower and the system sleeps periodically when idle). This means that
under high processing load the system won't perform the same as if configured for maximum
performance.

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

You can use the teensy loader program to upload the .hex file to the board. To test power
consumption provide power to the board through the Vin (5V) pin with an ammeter in series. Current
draw should be around 100uA (your mileage may vary).

Remember that the Vin pin is rated from 3.7 to 5.5V, so you can power the board using a LiPo
battery.

Additional power savings can be obtained if you connect a low power 32.768kHz oscillator that
outputs an square wave at 3.3V to Pin 22 (PTC1/CLKIN), then setting the `MKL26_POWER_PROFILE` make
variable to `LOWPOWER_4MHZ_EXTREF` (remember to fully recompile after editing the project makefile).
This can reduce power consumption by around 2/3 when compared to the `LOWPOWER_4MHZ_INTREF` profile
(without considering the consumption of the oscillator itself) and has the added benefit of a higher
precision reference (internal reference is rated to 3%, while oscillators are usually rated from
tens to hundreds ppm).
