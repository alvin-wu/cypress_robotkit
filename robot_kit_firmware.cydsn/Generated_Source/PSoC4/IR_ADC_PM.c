/*******************************************************************************
* File Name: IR_ADC_PM.c
* Version 2.40
*
* Description:
*  This file provides Sleep/WakeUp APIs functionality.
*
* Note:
*
********************************************************************************
* Copyright 2008-2015, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
*******************************************************************************/

#include "IR_ADC.h"


/***************************************
* Local data allocation
***************************************/

static IR_ADC_BACKUP_STRUCT  IR_ADC_backup =
{
    IR_ADC_DISABLED
};


/*******************************************************************************
* Function Name: IR_ADC_SaveConfig
********************************************************************************
*
* Summary:
*  Saves the current user configuration.
*
* Parameters:
*  None.
*
* Return:
*  None.
*
*******************************************************************************/
void IR_ADC_SaveConfig(void)
{
    /* All configuration registers are marked as [reset_all_retention] */
}


/*******************************************************************************
* Function Name: IR_ADC_RestoreConfig
********************************************************************************
*
* Summary:
*  Restores the current user configuration.
*
* Parameters:
*  None.
*
* Return:
*  None.
*
*******************************************************************************/
void IR_ADC_RestoreConfig(void)
{
    /* All congiguration registers are marked as [reset_all_retention] */
}


/*******************************************************************************
* Function Name: IR_ADC_Sleep
********************************************************************************
*
* Summary:
*  Stops the ADC operation and saves the configuration registers and component
*  enable state. Should be called just prior to entering sleep.
*
* Parameters:
*  None.
*
* Return:
*  None.
*
* Global Variables:
*  IR_ADC_backup - modified.
*
*******************************************************************************/
void IR_ADC_Sleep(void)
{
    /* During deepsleep/ hibernate mode keep SARMUX active, i.e. do not open
    *   all switches (disconnect), to be used for ADFT
    */
    IR_ADC_SAR_DFT_CTRL_REG |= IR_ADC_ADFT_OVERRIDE;
    if((IR_ADC_SAR_CTRL_REG  & IR_ADC_ENABLE) != 0u)
    {
        if((IR_ADC_SAR_SAMPLE_CTRL_REG & IR_ADC_CONTINUOUS_EN) != 0u)
        {
            IR_ADC_backup.enableState = IR_ADC_ENABLED | IR_ADC_STARTED;
        }
        else
        {
            IR_ADC_backup.enableState = IR_ADC_ENABLED;
        }
        IR_ADC_StopConvert();
        IR_ADC_Stop();
        
        /* Disable the SAR internal pump before entering the chip low power mode */
        if((IR_ADC_SAR_CTRL_REG & IR_ADC_BOOSTPUMP_EN) != 0u)
        {
            IR_ADC_SAR_CTRL_REG &= (uint32)~IR_ADC_BOOSTPUMP_EN;
            IR_ADC_backup.enableState |= IR_ADC_BOOSTPUMP_ENABLED;
        }
    }
    else
    {
        IR_ADC_backup.enableState = IR_ADC_DISABLED;
    }
}


/*******************************************************************************
* Function Name: IR_ADC_Wakeup
********************************************************************************
*
* Summary:
*  Restores the component enable state and configuration registers.
*  This should be called just after awaking from sleep mode.
*
* Parameters:
*  None.
*
* Return:
*  None.
*
* Global Variables:
*  IR_ADC_backup - used.
*
*******************************************************************************/
void IR_ADC_Wakeup(void)
{
    IR_ADC_SAR_DFT_CTRL_REG &= (uint32)~IR_ADC_ADFT_OVERRIDE;
    if(IR_ADC_backup.enableState != IR_ADC_DISABLED)
    {
        /* Enable the SAR internal pump  */
        if((IR_ADC_backup.enableState & IR_ADC_BOOSTPUMP_ENABLED) != 0u)
        {
            IR_ADC_SAR_CTRL_REG |= IR_ADC_BOOSTPUMP_EN;
        }
        IR_ADC_Enable();
        if((IR_ADC_backup.enableState & IR_ADC_STARTED) != 0u)
        {
            IR_ADC_StartConvert();
        }
    }
}
/* [] END OF FILE */
