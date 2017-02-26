/*******************************************************************************
* File Name: left_backward.h  
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

#if !defined(CY_PINS_left_backward_ALIASES_H) /* Pins left_backward_ALIASES_H */
#define CY_PINS_left_backward_ALIASES_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"


/***************************************
*              Constants        
***************************************/
#define left_backward_0			(left_backward__0__PC)
#define left_backward_0_PS		(left_backward__0__PS)
#define left_backward_0_PC		(left_backward__0__PC)
#define left_backward_0_DR		(left_backward__0__DR)
#define left_backward_0_SHIFT	(left_backward__0__SHIFT)
#define left_backward_0_INTR	((uint16)((uint16)0x0003u << (left_backward__0__SHIFT*2u)))

#define left_backward_INTR_ALL	 ((uint16)(left_backward_0_INTR))


#endif /* End Pins left_backward_ALIASES_H */


/* [] END OF FILE */
