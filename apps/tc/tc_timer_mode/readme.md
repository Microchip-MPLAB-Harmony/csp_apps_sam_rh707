---
parent: Harmony 3 peripheral library application examples for SAM RH707 family
title: TC timer mode 
has_children: false
has_toc: false
---

[![MCHP](https://www.microchip.com/ResourcePackages/Microchip/assets/dist/images/logo.png)](https://www.microchip.com)

# TC timer mode

This example shows how to use the TC module in timer mode to generate periodic interrupt.

## Description

TC channel is configured in timer mode and generates periodic interrupt. LED is toggled in the interrupt handler to indicate periodic callback.

## Downloading and building the application

To clone or download this application from Github, go to the [main page of this repository](https://github.com/Microchip-MPLAB-Harmony/csp_apps_sam_rh707) and then click **Clone** button to clone this repository or download as zip file.
This content can also be downloaded using content manager by following these [instructions](https://github.com/Microchip-MPLAB-Harmony/contentmanager/wiki).

Path of the application within the repository is **apps/tc/tc_timer_mode/firmware** .

To build the application, refer to the following table and open the project using its IDE.

| Project Name      | Description                                    |
| ----------------- | ---------------------------------------------- |
| sam_rh707_ek.X | MPLABX project for SAM RH707 Evaluation Kit |
|||

## Setting up the hardware

The following table shows the target hardware for the application projects.

| Project Name| Board|
|:---------|:---------:|
| sam_rh707_ek.X | SAM RH707 Evaluation Kit
|||

### Setting up SAM RH707 Evaluation Kit

- Connect the debugger probe to J5 connector
- Connect the J1 (USB-C) port on the board to the computer using a USB-C cable

## Running the Application

1. Build and Program the application using its IDE
2. Observe that the LED blinks once every second

Following table provides the LED name:

| Board      | LED Name |
| ---------- | ---------------- |
| SAM RH707 Evaluation Kit | LED0 |
|||
