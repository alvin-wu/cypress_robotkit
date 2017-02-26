/*******************************************************************************
* File Name: IR_pin2.h  
* Version 2.20
*
* Description:
*  This file contains the Alias definitions for Per-Pin APIs in cypins.h. 
*  Information on using these APIs can be found in the System Reference Guide.
*
* Note:
*
********************************************************************************
* Copyright 2008-2015, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(CY_PINS_IR_pin2_ALIASES_H) /* Pins IR_pin2_ALIASES_H */
#define CY_PINS_IR_pin2_ALIASES_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"


/***************************************
*              Constants        
***************************************/
#define IR_pin2_0			(IR_pin2__0__PC)
#define IR_pin2_0_PS		(IR_pin2__0__PS)
#define IR_pin2_0_PC		(IR_pin2__0__PC)
#define IR_pin2_0_DR		(IR_pin2__0__DR)
#define IR_pin2_0_SHIFT	(IR_pin2__0__SHIFT)
#define IR_pin2_0_INTR	((uint16)((uint16)0x0003u << (IR_pin2__0__SHIFT*2u)))

#define IR_pin2_INTR_ALL	 ((uint16)(IR_pin2_0_INTR))


#endif /* End Pins IR_pin2_ALIASES_H */


/* [] END OF FILE */
