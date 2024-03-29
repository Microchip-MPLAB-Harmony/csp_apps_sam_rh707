﻿---
title: Harmony 3 peripheral library application examples for SAM RH707 family
nav_order: 1
has_children: true
has_toc: false
---
[![MCHP](https://www.microchip.com/ResourcePackages/Microchip/assets/dist/images/logo.png)](https://www.microchip.com)

# Harmony 3 peripheral library application examples for SAM RH707 family

MPLAB® Harmony 3 is an extension of the MPLAB® ecosystem for creating embedded firmware solutions for Microchip 32-bit SAM and PIC® microcontroller and microprocessor devices.  Refer to the following links for more information.

- [Microchip 32-bit MCUs](https://www.microchip.com/design-centers/32-bit)
- [Microchip 32-bit MPUs](https://www.microchip.com/design-centers/32-bit-mpus)
- [Microchip MPLAB X IDE](https://www.microchip.com/mplab/mplab-x-ide)
- [Microchip MPLAB® Harmony](https://www.microchip.com/mplab/mplab-harmony)
- [Microchip MPLAB® Harmony Pages](https://microchip-mplab-harmony.github.io/)

This repository contains the MPLAB® Harmony 3 peripheral library application examples for SAM RH707 family

- [Release Notes](release_notes.md)
- [MPLAB® Harmony License](mplab_harmony_license.md)

To clone or download these applications from Github, go to the [main page of this repository](https://github.com/Microchip-MPLAB-Harmony/csp_apps_sam_rh707) and then click **Clone** button to clone this repository or download as zip file.
This content can also be downloaded using content manager by following these [instructions](https://github.com/Microchip-MPLAB-Harmony/contentmanager/wiki).

## Contents Summary

| Folder     | Description                             |
| ---        | ---                                     |
| apps       | Contains peripheral library example applications |
| docs       | Contains documentation in html format for offline viewing (to be used only after cloning this repository onto a local machine). Use [github pages](https://microchip-mplab-harmony.github.io/csp_apps_sam_rh707/) of this repository for viewing it online. |

## Code Examples

The following applications are provided to demonstrate the typical or interesting usage models of one or more peripheral libraries.

| Name | Description |
| ---- | ----------- |
| [ADC Polling](apps/adc/adc_polled_mode/readme.md) | This example application shows how to sample an analog input in polled mode and send the converted data to console |
| [ADC user sequence](apps/adc/adc_user_sequence/readme.md) | This example application shows how to sample three analog inputs using the user sequencer in software trigger mode and send the converted data to the console |
| [Cache maintenance](apps/cache/cache_maintenance/readme.md) | This example shows cache maintenance operation by cleaning and invalidating the cache for the DMA buffers located in the cacheable SRAM region |
| [Clock configuration](apps/clock/clock_config/readme.md) | This example application shows how to configure the clock system to run the device at maximum frequency. It also outputs a prescaled clock signal on a GPIO pin for measurement and verification |
| [DACC waveform generation](apps/dacc/dacc_wav_gen/readme.md) | This example shows how to use the DACC peripheral to generate a 5 KHz sine wave or triangle wave using a lookup table |
| [FLEXCOM SPI EEPROM read write](apps/flexcom/flexcom_spi_eeprom/readme.md) | This example application shows how to use the flexcom module in SPI mode |
| [FLEXCOM TWI (I2C) EEPROM](apps/flexcom/flexcom_twi_eeprom/readme.md) | This example application shows how to use the flexcom module in TWI mode |
| [FLEXCOM USART blocking](apps/flexcom/flexcom_usart_echo_blocking/readme.md) | This example application shows how to use the flexcom module in USART mode |
| [FLEXCOM USART interrupt](apps/flexcom/flexcom_usart_echo_interrupt/readme.md) | This example application shows how to use the flexcom module in USART mode |
| [FLEXCOM USART ring buffer](apps/flexcom/flexcom_usart_ring_buffer_interrupt/readme.md) | This example application demonstrates how to use the FLEXCOM peripheral in USART ring buffer mode |
| [HEFC flash read write](apps/hefc/flash_read_write/readme.md) | This example application demonstrates how to use the HEFC to erase and program the internal Flash memory |
| [MCAN FD blocking](apps/mcan/mcan_fd_operation_blocking/readme.md) | This example shows how to use the MCAN module to transmit and receive CAN FD messages in polling mode |
| [MCAN FD interrupt](apps/mcan/mcan_fd_operation_interrupt_timestamp/readme.md) | This example shows how to use the MCAN module to transmit and receive CAN FD messages in interrupt mode |
| [MPU cache coherency](apps/mpu/mpu_coherent_region/readme.md) | This example shows how to maintain cache coherency by allocating DMA buffers in non-cacheable SRAM region defined by MPU |
| [PIO interrupt](apps/pio/pio_led_on_off_interrupt/readme.md) | This example shows how to generate GPIO interrupt on switch press and release, and indicate the switch status using the LED |
| [PIO polling](apps/pio/pio_led_on_off_polling/readme.md) | This example shows how to poll the switch input, and indicate the switch status using the LED |
| [PWM Generation](apps/pwm/pwm_synchronous_channels/readme.md) | This example shows how to use the PWM peripheral to generate 3-phase PWM signals with dead time |
| [RTC alarm interrupt](apps/rtc/rtc_alarm/readme.md) | This example shows how to use the RTC to configure the time and generate the alarm |
| [RTT periodic interrupt](apps/rtt/rtt_periodic_timeout/readme.md) | This example shows how to use the RTT to generate periodic interrupts |
| [Systick periodic interrupt](apps/systick/systick_periodic_timeout/readme.md) | This example shows how to use the SysTick to generate periodic interrupts |
| [TC capture mode](apps/tc/tc_capture_mode/readme.md) | This example shows how to use the TC module in capture mode to measure duty cycle and frequency of an external input |
| [TC compare mode](apps/tc/tc_compare_mode/readme.md) | This example shows how to use the TC module in compare mode to generate an active low, active high, and toggle output on compare match |
| [TC timer mode](apps/tc/tc_timer_mode/readme.md) | This example shows how to use the TC module in timer mode to generate periodic interrupt |
| [TCM cache coherency](apps/tcm/data_tcm/readme.md) | This example shows how to  maintain cache coherency by allocating the DMA buffers in the Tightly Coupled Memory (TCM), which are not cacheable |
| [TRNG random number](apps/trng/random_number/readme.md) | This example shows how to use the TRNG Peripheral library to generate and read a random number |
| [WDT timeout](apps/wdt/wdt_timeout/readme.md) | This example shows how to generate a Watchdog timer reset by emulating a deadlock |
| [XDMAC memory transfer](apps/xdmac/xdmac_memory_transfer/readme.md) | This example shows how to use the XDMAC peripheral to do a memory to memory transfer and illustrates the usage of burst size to reduce the transfer time |

____

[![License](https://img.shields.io/badge/license-Harmony%20license-orange.svg)](https://github.com/Microchip-MPLAB-Harmony/csp_apps_sam_rh707/blob/master/mplab_harmony_license.md)
[![Latest release](https://img.shields.io/github/release/Microchip-MPLAB-Harmony/csp_apps_sam_rh707.svg)](https://github.com/Microchip-MPLAB-Harmony/csp_apps_sam_rh707/releases/latest)
[![Latest release date](https://img.shields.io/github/release-date/Microchip-MPLAB-Harmony/csp_apps_sam_rh707.svg)](https://github.com/Microchip-MPLAB-Harmony/csp_apps_sam_rh707/releases/latest)
[![Commit activity](https://img.shields.io/github/commit-activity/y/Microchip-MPLAB-Harmony/csp_apps_sam_rh707.svg)](https://github.com/Microchip-MPLAB-Harmony/csp_apps_sam_rh707/graphs/commit-activity)
[![Contributors](https://img.shields.io/github/contributors-anon/Microchip-MPLAB-Harmony/csp_apps_sam_rh707.svg)]()

____

[![Follow us on Youtube](https://img.shields.io/badge/Youtube-Follow%20us%20on%20Youtube-red.svg)](https://www.youtube.com/user/MicrochipTechnology)
[![Follow us on LinkedIn](https://img.shields.io/badge/LinkedIn-Follow%20us%20on%20LinkedIn-blue.svg)](https://www.linkedin.com/company/microchip-technology)
[![Follow us on Facebook](https://img.shields.io/badge/Facebook-Follow%20us%20on%20Facebook-blue.svg)](https://www.facebook.com/microchiptechnology/)
[![Follow us on Twitter](https://img.shields.io/twitter/follow/MicrochipTech.svg?style=social)](https://twitter.com/MicrochipTech)

[![](https://img.shields.io/github/stars/Microchip-MPLAB-Harmony/csp_apps_sam_rh707.svg?style=social)]()
[![](https://img.shields.io/github/watchers/Microchip-MPLAB-Harmony/csp_apps_sam_rh707.svg?style=social)]()