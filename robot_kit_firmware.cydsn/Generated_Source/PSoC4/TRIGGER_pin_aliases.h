/*******************************************************************************
* File Name: TRIGGER_pin.h  
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

#if !defined(CY_PINS_TRIGGER_pin_ALIASES_H) /* Pins TRIGGER_pin_ALIASES_H */
#define CY_PINS_TRIGGER_pin_ALIASES_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"


/***************************************
*              Constants        
***************************************/
#define TRIGGER_pin_0			(TRIGGER_pin__0__PC)
#define TRIGGER_pin_0_PS		(TRIGGER_pin__0__PS)
#define TRIGGER_pin_0_PC		(TRIGGER_pin__0__PC)
#define TRIGGER_pin_0_DR		(TRIGGER_pin__0__DR)
#define TRIGGER_pin_0_SHIFT	(TRIGGER_pin__0__SHIFT)
#define TRIGGER_pin_0_INTR	((uint16)((uint16)0x0003u << (TRIGGER_pin__0__SHIFT*2u)))

#define TRIGGER_pin_INTR_ALL	 ((uint16)(TRIGGER_pin_0_INTR))


#endif /* End Pins TRIGGER_pin_ALIASES_H */


/* [] END OF FILE */
