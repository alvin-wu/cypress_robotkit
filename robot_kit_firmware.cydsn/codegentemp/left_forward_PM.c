/*******************************************************************************
* File Name: left_forward.c  
* Version 2.20
*
* Description:
*  This file contains APIs to set up the Pins component for low power modes.
*
* Note:
*
********************************************************************************
* Copyright 2015, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#include "cytypes.h"
#include "left_forward.h"

static left_forward_BACKUP_STRUCT  left_forward_backup = {0u, 0u, 0u};


/*******************************************************************************
* Function Name: left_forward_Sleep
****************************************************************************//**
*
* \brief Stores the pin configuration and prepares the pin for entering chip 
*  deep-sleep/hibernate modes. This function must be called for SIO and USBIO
*  pins. It is not essential if using GPIO or GPIO_OVT pins.
*
* <b>Note</b> This function is available in PSoC 4 only.
*
* \return 
*  None 
*  
* \sideeffect
*  For SIO pins, this function configures the pin input threshold to CMOS and
*  drive level to Vddio. This is needed for SIO pins when in device 
*  deep-sleep/hibernate modes.
*
* \funcusage
*  \snippet left_forward_SUT.c usage_left_forward_Sleep_Wakeup
*******************************************************************************/
void left_forward_Sleep(void)
{
    #if defined(left_forward__PC)
        left_forward_backup.pcState = left_forward_PC;
    #else
        #if (CY_PSOC4_4200L)
            /* Save the regulator state and put the PHY into suspend mode */
            left_forward_backup.usbState = left_forward_CR1_REG;
            left_forward_USB_POWER_REG |= left_forward_USBIO_ENTER_SLEEP;
            left_forward_CR1_REG &= left_forward_USBIO_CR1_OFF;
        #endif
    #endif
    #if defined(CYIPBLOCK_m0s8ioss_VERSION) && defined(left_forward__SIO)
        left_forward_backup.sioState = left_forward_SIO_REG;
        /* SIO requires unregulated output buffer and single ended input buffer */
        left_forward_SIO_REG &= (uint32)(~left_forward_SIO_LPM_MASK);
    #endif  
}


/*******************************************************************************
* Function Name: left_forward_Wakeup
****************************************************************************//**
*
* \brief Restores the pin configuration that was saved during Pin_Sleep().
*
* For USBIO pins, the wakeup is only triggered for falling edge interrupts.
*
* <b>Note</b> This function is available in PSoC 4 only.
*
* \return 
*  None
*  
* \funcusage
*  Refer to left_forward_Sleep() for an example usage.
*******************************************************************************/
void left_forward_Wakeup(void)
{
    #if defined(left_forward__PC)
        left_forward_PC = left_forward_backup.pcState;
    #else
        #if (CY_PSOC4_4200L)
            /* Restore the regulator state and come out of suspend mode */
            left_forward_USB_POWER_REG &= left_forward_USBIO_EXIT_SLEEP_PH1;
            left_forward_CR1_REG = left_forward_backup.usbState;
            left_forward_USB_POWER_REG &= left_forward_USBIO_EXIT_SLEEP_PH2;
        #endif
    #endif
    #if defined(CYIPBLOCK_m0s8ioss_VERSION) && defined(left_forward__SIO)
        left_forward_SIO_REG = left_forward_backup.sioState;
    #endif
}


/* [] END OF FILE */
