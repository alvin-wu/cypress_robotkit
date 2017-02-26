/*******************************************************************************
* File Name: left_backward.c  
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
#include "left_backward.h"

static left_backward_BACKUP_STRUCT  left_backward_backup = {0u, 0u, 0u};


/*******************************************************************************
* Function Name: left_backward_Sleep
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
*  \snippet left_backward_SUT.c usage_left_backward_Sleep_Wakeup
*******************************************************************************/
void left_backward_Sleep(void)
{
    #if defined(left_backward__PC)
        left_backward_backup.pcState = left_backward_PC;
    #else
        #if (CY_PSOC4_4200L)
            /* Save the regulator state and put the PHY into suspend mode */
            left_backward_backup.usbState = left_backward_CR1_REG;
            left_backward_USB_POWER_REG |= left_backward_USBIO_ENTER_SLEEP;
            left_backward_CR1_REG &= left_backward_USBIO_CR1_OFF;
        #endif
    #endif
    #if defined(CYIPBLOCK_m0s8ioss_VERSION) && defined(left_backward__SIO)
        left_backward_backup.sioState = left_backward_SIO_REG;
        /* SIO requires unregulated output buffer and single ended input buffer */
        left_backward_SIO_REG &= (uint32)(~left_backward_SIO_LPM_MASK);
    #endif  
}


/*******************************************************************************
* Function Name: left_backward_Wakeup
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
*  Refer to left_backward_Sleep() for an example usage.
*******************************************************************************/
void left_backward_Wakeup(void)
{
    #if defined(left_backward__PC)
        left_backward_PC = left_backward_backup.pcState;
    #else
        #if (CY_PSOC4_4200L)
            /* Restore the regulator state and come out of suspend mode */
            left_backward_USB_POWER_REG &= left_backward_USBIO_EXIT_SLEEP_PH1;
            left_backward_CR1_REG = left_backward_backup.usbState;
            left_backward_USB_POWER_REG &= left_backward_USBIO_EXIT_SLEEP_PH2;
        #endif
    #endif
    #if defined(CYIPBLOCK_m0s8ioss_VERSION) && defined(left_backward__SIO)
        left_backward_SIO_REG = left_backward_backup.sioState;
    #endif
}


/* [] END OF FILE */
