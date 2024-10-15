# SL² - STM32-LiteLibs

SL² (STM32-LiteLibs) is collection of lightweight, easy-to-use libraries designed for STM32 peripherals (e.g., I2C, SPI, Timers) and external devices like sensors (e.g. MAX6675, WS2812). 
These libraries are meant to speed up development by providing hardware-near, yet simple-to-understand code, based on the LL (Low Layer) abstraction.

## Key Features
  - Lightweight libraries for common STM32 peripherals and sensors.
  - Focus on simplifying development while maintaining low-level hardware control.
  - Built on the STM32 LL (Low Layer) abstraction layer for efficient and direct access to hardware.

## Motivation
  The motivation for this project is to move away from copying the same template code when working with STM32 peripherals.
  It should provide a more polished look and feel while staying close to the hardware near aprocach that the LL layer of stm provides.
  While the STM HAL Library or simply using the STM Arduino Framework is much simpler and easier, it abstracts away a lot of the hardware relationships. 
  This makes it a bit harder to relate how a hardware feature of the chip is implemented in the code. (at least for my taste).
  The LL library on the other hand is powerful and stays very close to the actual registers, but can be challenging for beginners.
  This collection of libraries and wrappers aims to fit right in between, providing a way to skip the sometimes messy LL code while staying close to the actual hardware registers.

## Roadmap

  For now, the library will be far from complete. I will extend it on the go, while I need specific features in my other STM projects.

  A proper rodamap will follow in the future.
