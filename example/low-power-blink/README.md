# Low power blink example.

This example allows testing the potential power savings that platforms can provide by switching to a
lower power profile. Keep in mind that lowering power consumption has a direct impact on processor
performance (system clocks run slower and the system sleeps periodically when idle). This means that
under high processing load the system won't perform the same as if configured for maximum
performance.

In order to switch to a low power profile simply `#define` the power profile configuration in the
project configuration header, as shown below.

For the teensy-lc platform:

```
#define MKL26_CONF_POWER_PROFILE MKL26_POWER_PROFILE_LOWPOWER_4MHZ_INTREF
```

For the samd21-mini-breakout platform:

```
#define SAMD21_CONF_POWER_PROFILE SAMD21_POWER_PROFILE_LOWPOWER_4MHZ
```

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

## Testing on Teensy LC.

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

## Testing on SAMD21 mini breakout.

Unfortunately, the onboard regulator and peripherals cause an amount of current draw which is larger
than the current drawn by the MCU, making this platform unsuitable for low power applications as it
comes out of the box.

By desoldering the regulator (which removes power from external peripherals) we were capable to
isolate the MCU current draw, which allowed more precise measurements. Measured currents were around
19uA to 24uA in low power mode this way.

To upload the program to the board you can use the bossac bootloader and its accompanying command
line tool, which can be conveniently called from the Makefile toolchain by using the `flash` target,
as shown below. To enter bootloader mode remember to quickly push the reset button twice. Also,
make sure that bossac resides in your system path.

```
make TARGET=samd21-mini-breakout flash
```
