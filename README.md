Welcome to Contiki - Hackerspace San Salvador
===================
This repository contains an out-of-tree implementation of [Contiki](http://www.contiki-os.org/) that
adds support for new platforms and projects used or developed in the
[Hackerspace San Salvador](http://hackerspace.teubi.co/wiki/).

Contiki is the Operating System for the Internet of Things. It supports cooperative multi-tasking
and provides an extensive API to develop network-enabled solutions. It is known to work in highly
resource-constrained embedded enviroments and its framework-oriented design facilitates to migrate
it to new microcontrollers.

On this repository, the Hackerspace San Salvador expects to return back to the comunity all
knowledge acquired during the development of solutions using this Operating System.

## Supported Platforms
This is the current list of the platforms and microcontrollers supported by this repository:

- PJRC's [Teensy 3.6](https://www.pjrc.com/store/teensy36.html) based on Freescale's
  [Kinetis mk66fx1m0](https://www.nxp.com/products/processors-and-microcontrollers/arm-based-processors-and-mcus/kinetis-cortex-m-mcus/k-seriesperformancem4/k6x-ethernet/kinetis-k66-180-mhz-dual-high-speed-full-speed-usbs-2mb-flash-microcontrollers-mcus-based-on-arm-cortex-m4-core:K66_180)
- PJRC's [Teensy 3.2](https://www.pjrc.com/store/teensy32.html) based on Freescale's
  [Kinetis mk20dx256](https://www.nxp.com/products/processors-and-microcontrollers/arm-based-processors-and-mcus/kinetis-cortex-m-mcus/k-seriesperformancem4/k2x-usb/kinetis-k20-72-mhz-full-speed-usb-mixed-signal-integration-microcontrollers-mcus-based-on-arm-cortex-m4-core:K20_72)
- PJRC's [Teensy LC](https://www.pjrc.com/store/teensylc.html) based on Freescale's
  [Kinetis mkl26z64](https://www.nxp.com/products/processors-and-microcontrollers/arm-based-processors-and-mcus/kinetis-cortex-m-mcus/l-seriesultra-low-powerm0-plus/kinetis-kl2x-48-mhz-usb-ultra-low-power-microcontrollers-mcus-based-on-arm-cortex-m0-plus-core:KL2x)

## Planned Support
This is the list of future (planned) implementations:
- Sparkfun's [SAMD21 Mini Breakout](https://www.sparkfun.com/products/13664) based on Microchip's
  [ATSAMD21G18](https://www.microchip.com/wwwproducts/en/ATSAMD21G18)
- Sparkfun's [nRF52382 breakout board](https://www.sparkfun.com/products/13990) based on Nordic's
  [nRF52832](https://www.nordicsemi.com/eng/Products/Bluetooth-low-energy/nRF52832)
- Nordic's [nRF52840 Preview DK](https://www.nordicsemi.com/eng/Products/nRF52840-Preview-DK) based
  on Nordic's [nRF52840](https://www.nordicsemi.com/eng/Products/nRF52840)

## Credits
Thanks to Joksan Alvarado for initiating the support for new platforms on Contiki.

## License
All the code included on this repository is licensed under BSD 3-Clause License.
