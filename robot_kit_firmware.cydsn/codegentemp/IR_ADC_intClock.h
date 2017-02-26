/*******************************************************************************
* File Name: IR_ADC_intClock.h
* Version 2.20
*
*  Description:
*   Provides the function and constant definitions for the clock component.
*
*  Note:
*
********************************************************************************
* Copyright 2008-2012, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(CY_CLOCK_IR_ADC_intClock_H)
#define CY_CLOCK_IR_ADC_intClock_H

#include <cytypes.h>
#include <cyfitter.h>


/***************************************
*        Function Prototypes
***************************************/
#if defined CYREG_PERI_DIV_CMD

void IR_ADC_intClock_StartEx(uint32 alignClkDiv);
#define IR_ADC_intClock_Start() \
    IR_ADC_intClock_StartEx(IR_ADC_intClock__PA_DIV_ID)

#else

void IR_ADC_intClock_Start(void);

#endif/* CYREG_PERI_DIV_CMD */

void IR_ADC_intClock_Stop(void);

void IR_ADC_intClock_SetFractionalDividerRegister(uint16 clkDivider, uint8 clkFractional);

uint16 IR_ADC_intClock_GetDividerRegister(void);
uint8  IR_ADC_intClock_GetFractionalDividerRegister(void);

#define IR_ADC_intClock_Enable()                         IR_ADC_intClock_Start()
#define IR_ADC_intClock_Disable()                        IR_ADC_intClock_Stop()
#define IR_ADC_intClock_SetDividerRegister(clkDivider, reset)  \
    IR_ADC_intClock_SetFractionalDividerRegister((clkDivider), 0u)
#define IR_ADC_intClock_SetDivider(clkDivider)           IR_ADC_intClock_SetDividerRegister((clkDivider), 1u)
#define IR_ADC_intClock_SetDividerValue(clkDivider)      IR_ADC_intClock_SetDividerRegister((clkDivider) - 1u, 1u)


/***************************************
*             Registers
***************************************/
#if defined CYREG_PERI_DIV_CMD

#define IR_ADC_intClock_DIV_ID     IR_ADC_intClock__DIV_ID

#define IR_ADC_intClock_CMD_REG    (*(reg32 *)CYREG_PERI_DIV_CMD)
#define IR_ADC_intClock_CTRL_REG   (*(reg32 *)IR_ADC_intClock__CTRL_REGISTER)
#define IR_ADC_intClock_DIV_REG    (*(reg32 *)IR_ADC_intClock__DIV_REGISTER)

#define IR_ADC_intClock_CMD_DIV_SHIFT          (0u)
#define IR_ADC_intClock_CMD_PA_DIV_SHIFT       (8u)
#define IR_ADC_intClock_CMD_DISABLE_SHIFT      (30u)
#define IR_ADC_intClock_CMD_ENABLE_SHIFT       (31u)

#define IR_ADC_intClock_CMD_DISABLE_MASK       ((uint32)((uint32)1u << IR_ADC_intClock_CMD_DISABLE_SHIFT))
#define IR_ADC_intClock_CMD_ENABLE_MASK        ((uint32)((uint32)1u << IR_ADC_intClock_CMD_ENABLE_SHIFT))

#define IR_ADC_intClock_DIV_FRAC_MASK  (0x000000F8u)
#define IR_ADC_intClock_DIV_FRAC_SHIFT (3u)
#define IR_ADC_intClock_DIV_INT_MASK   (0xFFFFFF00u)
#define IR_ADC_intClock_DIV_INT_SHIFT  (8u)

#else 

#define IR_ADC_intClock_DIV_REG        (*(reg32 *)IR_ADC_intClock__REGISTER)
#define IR_ADC_intClock_ENABLE_REG     IR_ADC_intClock_DIV_REG
#define IR_ADC_intClock_DIV_FRAC_MASK  IR_ADC_intClock__FRAC_MASK
#define IR_ADC_intClock_DIV_FRAC_SHIFT (16u)
#define IR_ADC_intClock_DIV_INT_MASK   IR_ADC_intClock__DIVIDER_MASK
#define IR_ADC_intClock_DIV_INT_SHIFT  (0u)

#endif/* CYREG_PERI_DIV_CMD */

#endif /* !defined(CY_CLOCK_IR_ADC_intClock_H) */

/* [] END OF FILE */
