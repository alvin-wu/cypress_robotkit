/*******************************************************************************
* File Name: right_control_PM.c
* Version 1.80
*
* Description:
*  This file contains the setup, control, and status commands to support 
*  the component operation in the low power mode. 
*
* Note:
*
********************************************************************************
* Copyright 2015, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#include "right_control.h"

/* Check for removal by optimization */
#if !defined(right_control_Sync_ctrl_reg__REMOVED)

static right_control_BACKUP_STRUCT  right_control_backup = {0u};

    
/*******************************************************************************
* Function Name: right_control_SaveConfig
********************************************************************************
*
* Summary:
*  Saves the control register value.
*
* Parameters:
*  None
*
* Return:
*  None
*
*******************************************************************************/
void right_control_SaveConfig(void) 
{
    right_control_backup.controlState = right_control_Control;
}


/*******************************************************************************
* Function Name: right_control_RestoreConfig
********************************************************************************
*
* Summary:
*  Restores the control register value.
*
* Parameters:
*  None
*
* Return:
*  None
*
*
*******************************************************************************/
void right_control_RestoreConfig(void) 
{
     right_control_Control = right_control_backup.controlState;
}


/*******************************************************************************
* Function Name: right_control_Sleep
********************************************************************************
*
* Summary:
*  Prepares the component for entering the low power mode.
*
* Parameters:
*  None
*
* Return:
*  None
*
*******************************************************************************/
void right_control_Sleep(void) 
{
    right_control_SaveConfig();
}


/*******************************************************************************
* Function Name: right_control_Wakeup
********************************************************************************
*
* Summary:
*  Restores the component after waking up from the low power mode.
*
* Parameters:
*  None
*
* Return:
*  None
*
*******************************************************************************/
void right_control_Wakeup(void)  
{
    right_control_RestoreConfig();
}

#endif /* End check for removal by optimization */


/* [] END OF FILE */
