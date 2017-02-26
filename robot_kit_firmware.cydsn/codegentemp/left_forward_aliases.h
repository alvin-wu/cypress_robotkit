/*******************************************************************************
* File Name: left_forward.h  
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

#if !defined(CY_PINS_left_forward_ALIASES_H) /* Pins left_forward_ALIASES_H */
#define CY_PINS_left_forward_ALIASES_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"


/***************************************
*              Constants        
***************************************/
#define left_forward_0			(left_forward__0__PC)
#define left_forward_0_PS		(left_forward__0__PS)
#define left_forward_0_PC		(left_forward__0__PC)
#define left_forward_0_DR		(left_forward__0__DR)
#define left_forward_0_SHIFT	(left_forward__0__SHIFT)
#define left_forward_0_INTR	((uint16)((uint16)0x0003u << (left_forward__0__SHIFT*2u)))

#define left_forward_INTR_ALL	 ((uint16)(left_forward_0_INTR))


#endif /* End Pins left_forward_ALIASES_H */


/* [] END OF FILE */
