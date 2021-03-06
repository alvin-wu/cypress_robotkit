/*******************************************************************************
* File Name: IR_ADC_INT.c
* Version 2.40
*
*  Description:
*    This file contains the code that operates during the ADC_SAR interrupt
*    service routine.
*
*   Note:
*
********************************************************************************
* Copyright 2008-2015, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
*******************************************************************************/

#include "IR_ADC.h"
#include "cyapicallbacks.h"


/******************************************************************************
* Custom Declarations and Variables
* - add user inlcude files, prototypes and variables between the following
*   #START and #END tags
******************************************************************************/
/* `#START ADC_SYS_VAR`  */

/* `#END`  */

#if(IR_ADC_IRQ_REMOVE == 0u)


    /******************************************************************************
    * Function Name: IR_ADC_ISR
    *******************************************************************************
    *
    * Summary:
    *  Handle Interrupt Service Routine.
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
    ******************************************************************************/
    CY_ISR( IR_ADC_ISR )
    {
        uint32 intr_status;

        /* Read interrupt status register */
        intr_status = IR_ADC_SAR_INTR_REG;

        #ifdef IR_ADC_ISR_INTERRUPT_CALLBACK
            IR_ADC_ISR_InterruptCallback();
        #endif /* IR_ADC_ISR_INTERRUPT_CALLBACK */


        /************************************************************************
        *  Custom Code
        *  - add user ISR code between the following #START and #END tags
        *************************************************************************/
        /* `#START MAIN_ADC_ISR`  */

        /* `#END`  */
        
        /* Clear handled interrupt */
        IR_ADC_SAR_INTR_REG = intr_status;
    }

#endif   /* End IR_ADC_IRQ_REMOVE */


/* [] END OF FILE */
