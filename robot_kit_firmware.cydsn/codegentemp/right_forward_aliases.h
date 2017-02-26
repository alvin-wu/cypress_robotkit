/*******************************************************************************
* File Name: right_forward.h  
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

#if !defined(CY_PINS_right_forward_ALIASES_H) /* Pins right_forward_ALIASES_H */
#define CY_PINS_right_forward_ALIASES_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"


/***************************************
*              Constants        
***************************************/
#define right_forward_0			(right_forward__0__PC)
#define right_forward_0_PS		(right_forward__0__PS)
#define right_forward_0_PC		(right_forward__0__PC)
#define right_forward_0_DR		(right_forward__0__DR)
#define right_forward_0_SHIFT	(right_forward__0__SHIFT)
#define right_forward_0_INTR	((uint16)((uint16)0x0003u << (right_forward__0__SHIFT*2u)))

#define right_forward_INTR_ALL	 ((uint16)(right_forward_0_INTR))


#endif /* End Pins right_forward_ALIASES_H */


/* [] END OF FILE */
