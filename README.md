# STM32f407 Bare metal for ili9341

We can use without `HAL` library or `STM32CubeIDE` to generate code. We just need to the definition of register and struct.

## Pre-request
- Need to include the core header.
- Need to include the definition of register and struct file.

## Hardware
- Stm32f407
- ili9341

## Achieved
- GPIO
- UART
- Interrupt
- DMA
- SPI
- I2C
- Systick
- Timer
- adc
- ili9341 driver

## ili9341 driver for stm32f407
I write a driver that it don't need to include `HAL` library. And I refer to (STM32-ILI9341)[https://github.com/martnak/STM32-ILI9341] , I modify some `HAL` function to my bare metal function that we don't need to set some settings. And we need to connect some wire between `STM32f407` and `ili9341`

|  STM32f407   | ili9341  |
|  ----  | ----  |
| GND  | GND |
| VDD  | VCC |
| PA5  | CLK |
| PA7  | MOSI|
| PC3  | RES |
| PC2  | DC  |
| PA6  | MISO|
| PC1  | CS1 |
