/*******************************************************************************
  Digital-to-Analog Converter Controller (DACC) Peripheral Library (PLIB)

  Company:
    Microchip Technology Inc.

  File Name:
    plib_dacc.c

  Summary:
    DACC Source File

  Description:
    None

*******************************************************************************/

/*******************************************************************************
* Copyright (C) 2021 Microchip Technology Inc. and its subsidiaries.
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

#include "device.h"
#include "plib_dacc.h"

// *****************************************************************************
// *****************************************************************************
// Section: DACC Implementation
// *****************************************************************************
// *****************************************************************************

void DACC_Initialize(void)
{
    /* Reset DACC Peripheral */
    DACC_REGS->DACC_CR = DACC_CR_SWRST_Msk;

    DACC_REGS->DACC_MR = DACC_MR_STARTUP(0x8) | DACC_MR_ONE_Msk;

    /* Enable DAC Channel */
    DACC_REGS->DACC_CHER = DACC_CHER_CH0_Msk;
}

bool DACC_IsReady(void)
{
    return (bool)((DACC_REGS->DACC_ISR & DACC_ISR_TXRDY_Msk) == DACC_ISR_TXRDY_Msk);
}

void DACC_ChannelSelect(DACC_CHANNEL_NUM channel)
{
    DACC_REGS->DACC_MR = (DACC_REGS->DACC_MR & ~DACC_MR_USER_SEL_Msk) | DACC_MR_USER_SEL(channel);
}

void DACC_DataWrite(uint16_t data)
{
    DACC_REGS->DACC_CDR = data;
}
