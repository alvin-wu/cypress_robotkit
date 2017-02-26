/*******************************************************************************
* File Name: left_control_PM.c
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

#include "left_control.h"

/* Check for removal by optimization */
#if !defined(left_control_Sync_ctrl_reg__REMOVED)

static left_control_BACKUP_STRUCT  left_control_backup = {0u};

    
/*******************************************************************************
* Function Name: left_control_SaveConfig
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
void left_control_SaveConfig(void) 
{
    left_control_backup.controlState = left_control_Control;
}


/*******************************************************************************
* Function Name: left_control_RestoreConfig
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
void left_control_RestoreConfig(void) 
{
     left_control_Control = left_control_backup.controlState;
}


/*******************************************************************************
* Function Name: left_control_Sleep
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
void left_control_Sleep(void) 
{
    left_control_SaveConfig();
}


/*******************************************************************************
* Function Name: left_control_Wakeup
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
void left_control_Wakeup(void)  
{
    left_control_RestoreConfig();
}

#endif /* End check for removal by optimization */


/* [] END OF FILE */
