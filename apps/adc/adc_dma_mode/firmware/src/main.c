/*******************************************************************************
  Main Source File

  Company:
    Microchip Technology Inc.

  File Name:
    main.c

  Summary:
    This file contains the "main" function for a project.

  Description:
    This file contains the "main" function for a project.  The
    "main" function calls the "SYS_Initialize" function to initialize the state
    machines of all modules in the system
 *******************************************************************************/

// DOM-IGNORE-BEGIN
/*******************************************************************************
* Copyright (C) 2023 Microchip Technology Inc. and its subsidiaries.
*
* Subject to your compliance with these terms, you may use Microchip software
* and any derivatives exclusively with Microchip products. It is your
* responsibility to comply with third party license terms applicable to your
* use of third party software (including open source software) that may
* accompany Microchip software.
*
* THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS". NO WARRANTIES, WHETHER
* EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE, INCLUDING ANY IMPLIED
* WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY, AND FITNESS FOR A
* PARTICULAR PURPOSE.
*
* IN NO EVENT WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE,
* INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND
* WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP HAS
* BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE. TO THE
* FULLEST EXTENT ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL CLAIMS IN
* ANY WAY RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT OF FEES, IF ANY,
* THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS SOFTWARE.
*******************************************************************************/
// DOM-IGNORE-END

// *****************************************************************************
// *****************************************************************************
// Section: Included Files
// *****************************************************************************
// *****************************************************************************

#include <stddef.h>                     // Defines NULL
#include <stdbool.h>                    // Defines true
#include <stdlib.h>                     // Defines EXIT_FAILURE
#include "definitions.h"                // SYS function prototypes

/* ADC reference voltage value in volt */
#define ADC_VREF                                       (3.3f)

/* Number of ADC conversions in a DMA transfer */
#define NUM_CONVERSIONS                                (20U)

/* DMA output buffer */
static uint16_t __attribute__ ((aligned (16))) dstBuffer[NUM_CONVERSIONS];

/* flag variable to notify the end of XDMAC transfer.*/
bool transfert_done = false;

/* Variable to compute the average value of samples in a transfer */
float transferAverage;

/* XDMAC callback function */
void XDMAC_Callback(XDMAC_TRANSFER_EVENT status, uintptr_t context)
{
    if(status == XDMAC_TRANSFER_COMPLETE)
    {
        /*Transfer is completed.*/
        transfert_done = true;
    }
}
// *****************************************************************************
// *****************************************************************************
// Section: Main Entry Point
// *****************************************************************************
// *****************************************************************************
//

int main ( void )
{
    uint8_t i=0;
    float sample;
    
    /* Initialize all modules */
    SYS_Initialize ( NULL );
    
    XDMAC_ChannelCallbackRegister(XDMAC_CHANNEL_0, XDMAC_Callback, 0);
    
    printf("\n\r---------------------------------------------------------");
    printf("\n\r                   ADC with DMA Demo                     ");
    printf("\n\r---------------------------------------------------------\n\r");
    
    SYSTICK_TimerStart();
    
    ADC_ConversionStart();
    
    while(1)
    {
        /* ADC_REGS->ADC_LCDR is the DMA source address, refer to ADC output value */
        XDMAC_ChannelTransfer(XDMAC_CHANNEL_0, (const void *) &ADC_REGS->ADC_LCDR , &dstBuffer, NUM_CONVERSIONS );
        while(transfert_done == false)
        {
            //Wait until DMA transfer is complete.
        }
        transfert_done=false;
        
        /*Invalidate the cache to ensure DMA get values from SRAM*/
        SCB_InvalidateDCache_by_Addr((uint16_t *)&dstBuffer, sizeof(dstBuffer));

        /* Print samples and average */
        transferAverage = 0;
        printf("\r\nADC Input Sample in Volt :\r\n");
        for(i=0; i<NUM_CONVERSIONS; i++)
        {
            if( ( i != 0 ) && (( i % 10 ) == 0) )
                printf("\r\n");

            /*Mask the TAG field from the result in dstBuffer with 0xFFF mask and convert it into voltage*/
            sample = (float)(dstBuffer[i] & 0xFFF) * ADC_VREF / 4095U;
            printf("%0.2f, ", sample);
            transferAverage += sample;
        }
        printf("\r\n    Average : %0.2f V\r\n", (transferAverage/NUM_CONVERSIONS));

        SYSTICK_DelayMs(1000);
    }
    
    return ( EXIT_FAILURE );
}


/*******************************************************************************
 End of File
*/