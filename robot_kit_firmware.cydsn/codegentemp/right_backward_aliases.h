/*******************************************************************************
* File Name: right_backward.h  
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

#if !defined(CY_PINS_right_backward_ALIASES_H) /* Pins right_backward_ALIASES_H */
#define CY_PINS_right_backward_ALIASES_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"


/***************************************
*              Constants        
***************************************/
#define right_backward_0			(right_backward__0__PC)
#define right_backward_0_PS		(right_backward__0__PS)
#define right_backward_0_PC		(right_backward__0__PC)
#define right_backward_0_DR		(right_backward__0__DR)
#define right_backward_0_SHIFT	(right_backward__0__SHIFT)
#define right_backward_0_INTR	((uint16)((uint16)0x0003u << (right_backward__0__SHIFT*2u)))

#define right_backward_INTR_ALL	 ((uint16)(right_backward_0_INTR))


#endif /* End Pins right_backward_ALIASES_H */


/* [] END OF FILE */
