/*******************************************************************************
* File Name: LCD_display_PM.c
* Version 2.20
*
* Description:
*  This file provides the API source code for the Static Segment LCD component.
*
* Note:
*
********************************************************************************
* Copyright 2008-2014, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
*******************************************************************************/

#include "LCD_display.h"


static LCD_display_BACKUP_STRUCT LCD_display_backup;


/*******************************************************************************
* Function Name: LCD_display_SaveConfig
********************************************************************************
*
* Summary:
*  Does nothing, provided for consistency.
*
* Parameters:
*  None.
*
* Return:
*  None.
*
*******************************************************************************/
void LCD_display_SaveConfig(void) 
{
}


/*******************************************************************************
* Function Name: LCD_display_RestoreConfig
********************************************************************************
*
* Summary:
*  Does nothing, provided for consistency.
*
* Parameters:
*  None.
*
* Return:
*  None.
*
*******************************************************************************/
void LCD_display_RestoreConfig(void) 
{
}


/*******************************************************************************
* Function Name: LCD_display_Sleep
********************************************************************************
*
* Summary:
*  Prepares the component for entering the sleep mode.
*
* Parameters:
*  None.
*
* Return:
*  None.
*
* Reentrant:
*  No.
*
*******************************************************************************/
void LCD_display_Sleep(void) 
{
    LCD_display_backup.enableState = LCD_display_enableState;
    LCD_display_SaveConfig();
    LCD_display_Stop();
}


/*******************************************************************************
* Function Name: LCD_display_Wakeup
********************************************************************************
*
* Summary:
*  Wakes the component from sleep mode. Configures DMA and enables the component
*  for normal operation.
*
* Parameters:
*  LCD_display_enableState - Global variable.
*
* Return:
*  Status one of standard status for PSoC3 Component
*       CYRET_SUCCESS - Function completed successfully.
*       CYRET_LOCKED - The object was locked, already in use. Some of TDs or
*                      a channel already in use.
*
* Reentrant:
*  No.
*
*******************************************************************************/
void LCD_display_Wakeup(void) 
{
    LCD_display_RestoreConfig();

    if(LCD_display_backup.enableState == 1u)
    {
        LCD_display_Enable();
    }
}


/* [] END OF FILE */
