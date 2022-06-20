---
parent: Harmony 3 peripheral library application examples for SAM RH707 family
title: DACC waveform generation 
has_children: false
has_toc: false
---

[![MCHP](https://www.microchip.com/ResourcePackages/Microchip/assets/dist/images/logo.png)](https://www.microchip.com)

# DACC waveform generation

This example shows how to use the DACC peripheral to generate a 5 KHz sine wave or triangle wave using a lookup table.

## Description

The DACC Peripheral library is used to generate either sine wave or triangle wave, by writing digital data to the DACC in periodic callback on every Timer Counter (TC) Interrupt.

## Downloading and building the application

To clone or download this application from Github, go to the [main page of this repository](https://github.com/Microchip-MPLAB-Harmony/csp_apps_sam_rh707) and then click **Clone** button to clone this repository or download as zip file.
This content can also be downloaded using content manager by following these [instructions](https://github.com/Microchip-MPLAB-Harmony/contentmanager/wiki).

Path of the application within the repository is **apps/dacc/dacc_wav_gen/firmware** .

To build the application, refer to the following table and open the project using its IDE.

| Project Name      | Description                                    |
| ----------------- | ---------------------------------------------- |
| sam_rh707_ek.X    | MPLABX project for [SAM RH707 Evaluation Kit](https://www.microchip.com/en-us/development-tool/SAMRH707F18-EK)  |
|||

## Setting up the hardware

The following table shows the target hardware for the application projects.

| Project Name| Board|
|:---------|:---------:|
| sam_rh707_ek.X | [SAM RH707 Evaluation Kit](https://www.microchip.com/en-us/development-tool/SAMRH707F18-EK) |
|||

### Setting up [SAM RH707 Evaluation Kit](https://www.microchip.com/en-us/development-tool/SAMRH707F18-EK)

- Connect the DACC "Channel 0" output pin to oscilloscope probe for observing the analog output waveform
  - DACC Channel 0 is available through DAC0 SMB connector
- Connect the debugger probe to J5 connector
- Connect the J1 (USB-C) port on the board to the computer using a USB-C cable

## Running the Application

1. Build and Program the application using its respective IDE
2. Observe a sine wave of 5 KHz frequency on DACC output pin
3. Press switch PB0 to toggle the waveform shape from sine wave to triangle wave and back

| Board      | DACC output pins |
| ----------------- | ---------------------------------------------- |
| [[SAM RH707 Evaluation Kit](https://www.microchip.com/en-us/development-tool/SAMRH707F18-EK)]()    | DAC0 SMB connector |
|||
