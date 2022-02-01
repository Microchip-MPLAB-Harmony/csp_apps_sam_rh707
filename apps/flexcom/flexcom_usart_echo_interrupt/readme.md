---
parent: Harmony 3 peripheral library application examples for SAM RH707 family
title: FLEXCOM USART interrupt 
has_children: false
has_toc: false
---

[![MCHP](https://www.microchip.com/ResourcePackages/Microchip/assets/dist/images/logo.png)](https://www.microchip.com)

# FLEXCOM USART interrupt

This example application shows how to use the flexcom module in USART mode.

## Description

This application configures the flexcom peripheral in USART mode and performs read and write operation in a non-blocking manner. The peripheral interrupt is used to manage the transfer. It receives 10 characters from the terminal window and echoes them back.

## Downloading and building the application

To clone or download this application from Github, go to the [main page of this repository](https://github.com/Microchip-MPLAB-Harmony/csp_apps_sam_rh707) and then click **Clone** button to clone this repository or download as zip file.
This content can also be downloaded using content manager by following these [instructions](https://github.com/Microchip-MPLAB-Harmony/contentmanager/wiki).

Path of the application within the repository is **apps/flexcom/flexcom_usart_echo_interrupt/firmware** .

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

- Connect the Debug USB port on the board to the computer using a micro USB cable
- Connect the debugger probe to J5 connector
- Connect the J1 (USB-C) port on the board to the computer using a USB-C cable

## Running the Application

1. Open the Terminal application (Ex.:Tera term) on the computer
2. Connect to the EDBG Virtual COM port and configure the serial settings as follows:
    - Baud : 115200
    - Data : 8 Bits
    - Parity : None
    - Stop : 1 Bit
    - Flow Control : None
3. Build and Program the application using its IDE
4. The console displays the following message

    ![output](images/output_flexcom_usart_echo_interrupt.png)

5. Type 10 characters in the console
6. Entered characters will be echoed back and the LED is toggled
7. The following table provides the LED names

| Board      | LED Name                                    |
| ----------------- | ---------------------------------------------- |
| SAM RH707 Evaluation Kit    |LED0 |
|||
