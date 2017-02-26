/*******************************************************************************
* File Name: right_speedcontroller_PM.c
* Version 2.10
*
* Description:
*  This file contains the setup, control, and status commands to support
*  the component operations in the low power mode.
*
* Note:
*  None
*
********************************************************************************
* Copyright 2013-2015, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
*******************************************************************************/

#include "right_speedcontroller.h"

static right_speedcontroller_BACKUP_STRUCT right_speedcontroller_backup;


/*******************************************************************************
* Function Name: right_speedcontroller_SaveConfig
********************************************************************************
*
* Summary:
*  All configuration registers are retention. Nothing to save here.
*
* Parameters:
*  None
*
* Return:
*  None
*
*******************************************************************************/
void right_speedcontroller_SaveConfig(void)
{

}


/*******************************************************************************
* Function Name: right_speedcontroller_Sleep
********************************************************************************
*
* Summary:
*  Stops the component operation and saves the user configuration.
*
* Parameters:
*  None
*
* Return:
*  None
*
*******************************************************************************/
void right_speedcontroller_Sleep(void)
{
    if(0u != (right_speedcontroller_BLOCK_CONTROL_REG & right_speedcontroller_MASK))
    {
        right_speedcontroller_backup.enableState = 1u;
    }
    else
    {
        right_speedcontroller_backup.enableState = 0u;
    }

    right_speedcontroller_Stop();
    right_speedcontroller_SaveConfig();
}


/*******************************************************************************
* Function Name: right_speedcontroller_RestoreConfig
********************************************************************************
*
* Summary:
*  All configuration registers are retention. Nothing to restore here.
*
* Parameters:
*  None
*
* Return:
*  None
*
*******************************************************************************/
void right_speedcontroller_RestoreConfig(void)
{

}


/*******************************************************************************
* Function Name: right_speedcontroller_Wakeup
********************************************************************************
*
* Summary:
*  Restores the user configuration and restores the enable state.
*
* Parameters:
*  None
*
* Return:
*  None
*
*******************************************************************************/
void right_speedcontroller_Wakeup(void)
{
    right_speedcontroller_RestoreConfig();

    if(0u != right_speedcontroller_backup.enableState)
    {
        right_speedcontroller_Enable();
    }
}


/* [] END OF FILE */
