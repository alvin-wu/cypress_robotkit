/*******************************************************************************
* File Name: right_backward.c  
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
#include "right_backward.h"

static right_backward_BACKUP_STRUCT  right_backward_backup = {0u, 0u, 0u};


/*******************************************************************************
* Function Name: right_backward_Sleep
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
*  \snippet right_backward_SUT.c usage_right_backward_Sleep_Wakeup
*******************************************************************************/
void right_backward_Sleep(void)
{
    #if defined(right_backward__PC)
        right_backward_backup.pcState = right_backward_PC;
    #else
        #if (CY_PSOC4_4200L)
            /* Save the regulator state and put the PHY into suspend mode */
            right_backward_backup.usbState = right_backward_CR1_REG;
            right_backward_USB_POWER_REG |= right_backward_USBIO_ENTER_SLEEP;
            right_backward_CR1_REG &= right_backward_USBIO_CR1_OFF;
        #endif
    #endif
    #if defined(CYIPBLOCK_m0s8ioss_VERSION) && defined(right_backward__SIO)
        right_backward_backup.sioState = right_backward_SIO_REG;
        /* SIO requires unregulated output buffer and single ended input buffer */
        right_backward_SIO_REG &= (uint32)(~right_backward_SIO_LPM_MASK);
    #endif  
}


/*******************************************************************************
* Function Name: right_backward_Wakeup
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
*  Refer to right_backward_Sleep() for an example usage.
*******************************************************************************/
void right_backward_Wakeup(void)
{
    #if defined(right_backward__PC)
        right_backward_PC = right_backward_backup.pcState;
    #else
        #if (CY_PSOC4_4200L)
            /* Restore the regulator state and come out of suspend mode */
            right_backward_USB_POWER_REG &= right_backward_USBIO_EXIT_SLEEP_PH1;
            right_backward_CR1_REG = right_backward_backup.usbState;
            right_backward_USB_POWER_REG &= right_backward_USBIO_EXIT_SLEEP_PH2;
        #endif
    #endif
    #if defined(CYIPBLOCK_m0s8ioss_VERSION) && defined(right_backward__SIO)
        right_backward_SIO_REG = right_backward_backup.sioState;
    #endif
}


/* [] END OF FILE */
