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
#include "plib_clk.h"


/*********************************************************************************
Initialize Slow Clock (SLCK)
*********************************************************************************/
static void CLK_SlowClockInitialize(void)
{
    SUPC_REGS->SUPC_CR = SUPC_CR_KEY_PASSWD;

}


/*********************************************************************************
Initialize Main Clock (MAINCK)
*********************************************************************************/
static void CLK_MainClockInitialize(void)
{
    /* Enable External Clock Signal on XIN pin */
    PMC_REGS->CKGR_MOR |= CKGR_MOR_MOSCXTEN_Msk | CKGR_MOR_KEY_PASSWD;

    /* External clock signal (XIN pin) is selected as the Main Clock (MAINCK) source.
       Switch Main Clock (MAINCK) to External signal on XIN pin */
    PMC_REGS->CKGR_MOR |= CKGR_MOR_KEY_PASSWD | CKGR_MOR_MOSCSEL_Msk;

    /* Wait until MAINCK is switched to External Clock Signal (XIN pin) */
    while ( (PMC_REGS->PMC_SR & PMC_SR_MOSCSELS_Msk) != PMC_SR_MOSCSELS_Msk);

    /* Disable the RC Oscillator */
    PMC_REGS->CKGR_MOR = CKGR_MOR_KEY_PASSWD | (PMC_REGS->CKGR_MOR & ~CKGR_MOR_MOSCRCEN_Msk);


    while ((PMC_REGS->PMC_SR & PMC_SR_MCKRDY_Msk) != PMC_SR_MCKRDY_Msk);
}


/*********************************************************************************
Initialize RC2 Clock (RC2CK)
*********************************************************************************/
static void CLK_RC2ClockInitialize(void)
{
    PMC_REGS->PMC_OSC2 = PMC_OSC2_OSCRCF_10_MHz | PMC_OSC2_EN_Msk | PMC_OSC2_KEY_PASSWD;
}

/*********************************************************************************
Initialize PLLACK/PLLBCK
*********************************************************************************/
static void CLK_PLLxClockInitialize(void)
{
    PMC_REGS->PMC_PLL_CFG = PMC_PLL_CFG_SRB_SR_VAL_24K |
                            PMC_PLL_CFG_SCB_SC_VAL_20p |
                            PMC_PLL_CFG_OUTCUR_PLLB_ICP0 |
                            PMC_PLL_CFG_SRA_SR_VAL_24K |
                            PMC_PLL_CFG_SCA_SC_VAL_60p |
                            PMC_PLL_CFG_OUTCUR_PLLA_ICP3;

    /* Configure and Enable PLLA */
    PMC_REGS->CKGR_PLLAR =  CKGR_PLLAR_ONE_Msk |
                            CKGR_PLLAR_FREQ_VCO_VCO1 |
                            CKGR_PLLAR_PLLACOUNT(0x3f) |
                            CKGR_PLLAR_MULA(9) |
                            CKGR_PLLAR_DIVA(1);

    while ( (PMC_REGS->PMC_SR & PMC_SR_LOCKA_Msk) != PMC_SR_LOCKA_Msk);

}

/*********************************************************************************
Initialize Master clock (MCK)
*********************************************************************************/
static void CLK_MasterClockInitialize(void)
{
    /* Program PMC_MCKR.PRES and wait for PMC_SR.MCKRDY to be set   */
    PMC_REGS->PMC_MCKR = (PMC_REGS->PMC_MCKR & ~PMC_MCKR_PRES_Msk) | PMC_MCKR_PRES_CLK_2;
    while ((PMC_REGS->PMC_SR & PMC_SR_MCKRDY_Msk) != PMC_SR_MCKRDY_Msk);

    /* Program PMC_MCKR.MDIV and Wait for PMC_SR.MCKRDY to be set   */
    PMC_REGS->PMC_MCKR = (PMC_REGS->PMC_MCKR & ~PMC_MCKR_MDIV_Msk) | PMC_MCKR_MDIV_EQ_PCK;
    while ((PMC_REGS->PMC_SR & PMC_SR_MCKRDY_Msk) != PMC_SR_MCKRDY_Msk);

    /* Program PMC_MCKR.CSS and Wait for PMC_SR.MCKRDY to be set    */
    PMC_REGS->PMC_MCKR = (PMC_REGS->PMC_MCKR & ~PMC_MCKR_CSS_Msk) | PMC_MCKR_CSS_PLLA_CLK;
    while ((PMC_REGS->PMC_SR & PMC_SR_MCKRDY_Msk) != PMC_SR_MCKRDY_Msk);

}

/*********************************************************************************
Initialize Peripheral Clock
*********************************************************************************/
static void CLK_PeripheralClockInitialize(void)
{
    PMC_REGS->PMC_PCR = PMC_PCR_EN_Msk | PMC_PCR_CMD_Msk | PMC_PCR_PID(8); /* FLEXCOM1 */
    PMC_REGS->PMC_PCR = PMC_PCR_EN_Msk | PMC_PCR_CMD_Msk | PMC_PCR_PID(10); /* PIO */
    PMC_REGS->PMC_PCR = PMC_PCR_EN_Msk | PMC_PCR_CMD_Msk | PMC_PCR_PID(23)  /* ADC */
        | PMC_PCR_GCLKEN_Msk | PMC_PCR_GCLKCSS_MCK_CLK | PMC_PCR_GCLKDIV(0);
}

/*********************************************************************************
Clock Initialize
*********************************************************************************/
void CLOCK_Initialize( void )
{
    SCB_DisableDCache();
    SCB_DisableICache();

    /* Initialize Slow Clock */
    CLK_SlowClockInitialize();

    /* Initialize Main Clock */
    CLK_MainClockInitialize();

    /* Initialize RC2 */
    CLK_RC2ClockInitialize();

    /* Initialize PLLA/PLLB */
    CLK_PLLxClockInitialize();

    /* Initialize Master Clock */
    CLK_MasterClockInitialize();

    /* Initialize Peripheral Clock */
    CLK_PeripheralClockInitialize();


    SCB_EnableDCache();
    SCB_EnableICache();
}
