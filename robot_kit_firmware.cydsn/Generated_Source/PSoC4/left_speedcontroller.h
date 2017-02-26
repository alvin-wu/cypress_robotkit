/*******************************************************************************
* File Name: left_speedcontroller.h
* Version 2.10
*
* Description:
*  This file provides constants and parameter values for the left_speedcontroller
*  component.
*
* Note:
*  None
*
********************************************************************************
* Copyright 2013-2015, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(CY_TCPWM_left_speedcontroller_H)
#define CY_TCPWM_left_speedcontroller_H


#include "CyLib.h"
#include "cytypes.h"
#include "cyfitter.h"


/*******************************************************************************
* Internal Type defines
*******************************************************************************/

/* Structure to save state before go to sleep */
typedef struct
{
    uint8  enableState;
} left_speedcontroller_BACKUP_STRUCT;


/*******************************************************************************
* Variables
*******************************************************************************/
extern uint8  left_speedcontroller_initVar;


/***************************************
*   Conditional Compilation Parameters
****************************************/

#define left_speedcontroller_CY_TCPWM_V2                    (CYIPBLOCK_m0s8tcpwm_VERSION == 2u)
#define left_speedcontroller_CY_TCPWM_4000                  (CY_PSOC4_4000)

/* TCPWM Configuration */
#define left_speedcontroller_CONFIG                         (7lu)

/* Quad Mode */
/* Parameters */
#define left_speedcontroller_QUAD_ENCODING_MODES            (0lu)
#define left_speedcontroller_QUAD_AUTO_START                (1lu)

/* Signal modes */
#define left_speedcontroller_QUAD_INDEX_SIGNAL_MODE         (0lu)
#define left_speedcontroller_QUAD_PHIA_SIGNAL_MODE          (3lu)
#define left_speedcontroller_QUAD_PHIB_SIGNAL_MODE          (3lu)
#define left_speedcontroller_QUAD_STOP_SIGNAL_MODE          (0lu)

/* Signal present */
#define left_speedcontroller_QUAD_INDEX_SIGNAL_PRESENT      (0lu)
#define left_speedcontroller_QUAD_STOP_SIGNAL_PRESENT       (0lu)

/* Interrupt Mask */
#define left_speedcontroller_QUAD_INTERRUPT_MASK            (1lu)

/* Timer/Counter Mode */
/* Parameters */
#define left_speedcontroller_TC_RUN_MODE                    (0lu)
#define left_speedcontroller_TC_COUNTER_MODE                (0lu)
#define left_speedcontroller_TC_COMP_CAP_MODE               (2lu)
#define left_speedcontroller_TC_PRESCALER                   (0lu)

/* Signal modes */
#define left_speedcontroller_TC_RELOAD_SIGNAL_MODE          (0lu)
#define left_speedcontroller_TC_COUNT_SIGNAL_MODE           (3lu)
#define left_speedcontroller_TC_START_SIGNAL_MODE           (0lu)
#define left_speedcontroller_TC_STOP_SIGNAL_MODE            (0lu)
#define left_speedcontroller_TC_CAPTURE_SIGNAL_MODE         (0lu)

/* Signal present */
#define left_speedcontroller_TC_RELOAD_SIGNAL_PRESENT       (0lu)
#define left_speedcontroller_TC_COUNT_SIGNAL_PRESENT        (0lu)
#define left_speedcontroller_TC_START_SIGNAL_PRESENT        (0lu)
#define left_speedcontroller_TC_STOP_SIGNAL_PRESENT         (0lu)
#define left_speedcontroller_TC_CAPTURE_SIGNAL_PRESENT      (0lu)

/* Interrupt Mask */
#define left_speedcontroller_TC_INTERRUPT_MASK              (1lu)

/* PWM Mode */
/* Parameters */
#define left_speedcontroller_PWM_KILL_EVENT                 (0lu)
#define left_speedcontroller_PWM_STOP_EVENT                 (0lu)
#define left_speedcontroller_PWM_MODE                       (4lu)
#define left_speedcontroller_PWM_OUT_N_INVERT               (0lu)
#define left_speedcontroller_PWM_OUT_INVERT                 (0lu)
#define left_speedcontroller_PWM_ALIGN                      (0lu)
#define left_speedcontroller_PWM_RUN_MODE                   (0lu)
#define left_speedcontroller_PWM_DEAD_TIME_CYCLE            (0lu)
#define left_speedcontroller_PWM_PRESCALER                  (0lu)

/* Signal modes */
#define left_speedcontroller_PWM_RELOAD_SIGNAL_MODE         (0lu)
#define left_speedcontroller_PWM_COUNT_SIGNAL_MODE          (3lu)
#define left_speedcontroller_PWM_START_SIGNAL_MODE          (0lu)
#define left_speedcontroller_PWM_STOP_SIGNAL_MODE           (0lu)
#define left_speedcontroller_PWM_SWITCH_SIGNAL_MODE         (0lu)

/* Signal present */
#define left_speedcontroller_PWM_RELOAD_SIGNAL_PRESENT      (0lu)
#define left_speedcontroller_PWM_COUNT_SIGNAL_PRESENT       (0lu)
#define left_speedcontroller_PWM_START_SIGNAL_PRESENT       (0lu)
#define left_speedcontroller_PWM_STOP_SIGNAL_PRESENT        (0lu)
#define left_speedcontroller_PWM_SWITCH_SIGNAL_PRESENT      (0lu)

/* Interrupt Mask */
#define left_speedcontroller_PWM_INTERRUPT_MASK             (1lu)


/***************************************
*    Initial Parameter Constants
***************************************/

/* Timer/Counter Mode */
#define left_speedcontroller_TC_PERIOD_VALUE                (65535lu)
#define left_speedcontroller_TC_COMPARE_VALUE               (65535lu)
#define left_speedcontroller_TC_COMPARE_BUF_VALUE           (65535lu)
#define left_speedcontroller_TC_COMPARE_SWAP                (0lu)

/* PWM Mode */
#define left_speedcontroller_PWM_PERIOD_VALUE               (32lu)
#define left_speedcontroller_PWM_PERIOD_BUF_VALUE           (65535lu)
#define left_speedcontroller_PWM_PERIOD_SWAP                (0lu)
#define left_speedcontroller_PWM_COMPARE_VALUE              (0lu)
#define left_speedcontroller_PWM_COMPARE_BUF_VALUE          (65535lu)
#define left_speedcontroller_PWM_COMPARE_SWAP               (0lu)


/***************************************
*    Enumerated Types and Parameters
***************************************/

#define left_speedcontroller__LEFT 0
#define left_speedcontroller__RIGHT 1
#define left_speedcontroller__CENTER 2
#define left_speedcontroller__ASYMMETRIC 3

#define left_speedcontroller__X1 0
#define left_speedcontroller__X2 1
#define left_speedcontroller__X4 2

#define left_speedcontroller__PWM 4
#define left_speedcontroller__PWM_DT 5
#define left_speedcontroller__PWM_PR 6

#define left_speedcontroller__INVERSE 1
#define left_speedcontroller__DIRECT 0

#define left_speedcontroller__CAPTURE 2
#define left_speedcontroller__COMPARE 0

#define left_speedcontroller__TRIG_LEVEL 3
#define left_speedcontroller__TRIG_RISING 0
#define left_speedcontroller__TRIG_FALLING 1
#define left_speedcontroller__TRIG_BOTH 2

#define left_speedcontroller__INTR_MASK_TC 1
#define left_speedcontroller__INTR_MASK_CC_MATCH 2
#define left_speedcontroller__INTR_MASK_NONE 0
#define left_speedcontroller__INTR_MASK_TC_CC 3

#define left_speedcontroller__UNCONFIG 8
#define left_speedcontroller__TIMER 1
#define left_speedcontroller__QUAD 3
#define left_speedcontroller__PWM_SEL 7

#define left_speedcontroller__COUNT_UP 0
#define left_speedcontroller__COUNT_DOWN 1
#define left_speedcontroller__COUNT_UPDOWN0 2
#define left_speedcontroller__COUNT_UPDOWN1 3


/* Prescaler */
#define left_speedcontroller_PRESCALE_DIVBY1                ((uint32)(0u << left_speedcontroller_PRESCALER_SHIFT))
#define left_speedcontroller_PRESCALE_DIVBY2                ((uint32)(1u << left_speedcontroller_PRESCALER_SHIFT))
#define left_speedcontroller_PRESCALE_DIVBY4                ((uint32)(2u << left_speedcontroller_PRESCALER_SHIFT))
#define left_speedcontroller_PRESCALE_DIVBY8                ((uint32)(3u << left_speedcontroller_PRESCALER_SHIFT))
#define left_speedcontroller_PRESCALE_DIVBY16               ((uint32)(4u << left_speedcontroller_PRESCALER_SHIFT))
#define left_speedcontroller_PRESCALE_DIVBY32               ((uint32)(5u << left_speedcontroller_PRESCALER_SHIFT))
#define left_speedcontroller_PRESCALE_DIVBY64               ((uint32)(6u << left_speedcontroller_PRESCALER_SHIFT))
#define left_speedcontroller_PRESCALE_DIVBY128              ((uint32)(7u << left_speedcontroller_PRESCALER_SHIFT))

/* TCPWM set modes */
#define left_speedcontroller_MODE_TIMER_COMPARE             ((uint32)(left_speedcontroller__COMPARE         <<  \
                                                                  left_speedcontroller_MODE_SHIFT))
#define left_speedcontroller_MODE_TIMER_CAPTURE             ((uint32)(left_speedcontroller__CAPTURE         <<  \
                                                                  left_speedcontroller_MODE_SHIFT))
#define left_speedcontroller_MODE_QUAD                      ((uint32)(left_speedcontroller__QUAD            <<  \
                                                                  left_speedcontroller_MODE_SHIFT))
#define left_speedcontroller_MODE_PWM                       ((uint32)(left_speedcontroller__PWM             <<  \
                                                                  left_speedcontroller_MODE_SHIFT))
#define left_speedcontroller_MODE_PWM_DT                    ((uint32)(left_speedcontroller__PWM_DT          <<  \
                                                                  left_speedcontroller_MODE_SHIFT))
#define left_speedcontroller_MODE_PWM_PR                    ((uint32)(left_speedcontroller__PWM_PR          <<  \
                                                                  left_speedcontroller_MODE_SHIFT))

/* Quad Modes */
#define left_speedcontroller_MODE_X1                        ((uint32)(left_speedcontroller__X1              <<  \
                                                                  left_speedcontroller_QUAD_MODE_SHIFT))
#define left_speedcontroller_MODE_X2                        ((uint32)(left_speedcontroller__X2              <<  \
                                                                  left_speedcontroller_QUAD_MODE_SHIFT))
#define left_speedcontroller_MODE_X4                        ((uint32)(left_speedcontroller__X4              <<  \
                                                                  left_speedcontroller_QUAD_MODE_SHIFT))

/* Counter modes */
#define left_speedcontroller_COUNT_UP                       ((uint32)(left_speedcontroller__COUNT_UP        <<  \
                                                                  left_speedcontroller_UPDOWN_SHIFT))
#define left_speedcontroller_COUNT_DOWN                     ((uint32)(left_speedcontroller__COUNT_DOWN      <<  \
                                                                  left_speedcontroller_UPDOWN_SHIFT))
#define left_speedcontroller_COUNT_UPDOWN0                  ((uint32)(left_speedcontroller__COUNT_UPDOWN0   <<  \
                                                                  left_speedcontroller_UPDOWN_SHIFT))
#define left_speedcontroller_COUNT_UPDOWN1                  ((uint32)(left_speedcontroller__COUNT_UPDOWN1   <<  \
                                                                  left_speedcontroller_UPDOWN_SHIFT))

/* PWM output invert */
#define left_speedcontroller_INVERT_LINE                    ((uint32)(left_speedcontroller__INVERSE         <<  \
                                                                  left_speedcontroller_INV_OUT_SHIFT))
#define left_speedcontroller_INVERT_LINE_N                  ((uint32)(left_speedcontroller__INVERSE         <<  \
                                                                  left_speedcontroller_INV_COMPL_OUT_SHIFT))

/* Trigger modes */
#define left_speedcontroller_TRIG_RISING                    ((uint32)left_speedcontroller__TRIG_RISING)
#define left_speedcontroller_TRIG_FALLING                   ((uint32)left_speedcontroller__TRIG_FALLING)
#define left_speedcontroller_TRIG_BOTH                      ((uint32)left_speedcontroller__TRIG_BOTH)
#define left_speedcontroller_TRIG_LEVEL                     ((uint32)left_speedcontroller__TRIG_LEVEL)

/* Interrupt mask */
#define left_speedcontroller_INTR_MASK_TC                   ((uint32)left_speedcontroller__INTR_MASK_TC)
#define left_speedcontroller_INTR_MASK_CC_MATCH             ((uint32)left_speedcontroller__INTR_MASK_CC_MATCH)

/* PWM Output Controls */
#define left_speedcontroller_CC_MATCH_SET                   (0x00u)
#define left_speedcontroller_CC_MATCH_CLEAR                 (0x01u)
#define left_speedcontroller_CC_MATCH_INVERT                (0x02u)
#define left_speedcontroller_CC_MATCH_NO_CHANGE             (0x03u)
#define left_speedcontroller_OVERLOW_SET                    (0x00u)
#define left_speedcontroller_OVERLOW_CLEAR                  (0x04u)
#define left_speedcontroller_OVERLOW_INVERT                 (0x08u)
#define left_speedcontroller_OVERLOW_NO_CHANGE              (0x0Cu)
#define left_speedcontroller_UNDERFLOW_SET                  (0x00u)
#define left_speedcontroller_UNDERFLOW_CLEAR                (0x10u)
#define left_speedcontroller_UNDERFLOW_INVERT               (0x20u)
#define left_speedcontroller_UNDERFLOW_NO_CHANGE            (0x30u)

/* PWM Align */
#define left_speedcontroller_PWM_MODE_LEFT                  (left_speedcontroller_CC_MATCH_CLEAR        |   \
                                                         left_speedcontroller_OVERLOW_SET           |   \
                                                         left_speedcontroller_UNDERFLOW_NO_CHANGE)
#define left_speedcontroller_PWM_MODE_RIGHT                 (left_speedcontroller_CC_MATCH_SET          |   \
                                                         left_speedcontroller_OVERLOW_NO_CHANGE     |   \
                                                         left_speedcontroller_UNDERFLOW_CLEAR)
#define left_speedcontroller_PWM_MODE_ASYM                  (left_speedcontroller_CC_MATCH_INVERT       |   \
                                                         left_speedcontroller_OVERLOW_SET           |   \
                                                         left_speedcontroller_UNDERFLOW_CLEAR)

#if (left_speedcontroller_CY_TCPWM_V2)
    #if(left_speedcontroller_CY_TCPWM_4000)
        #define left_speedcontroller_PWM_MODE_CENTER                (left_speedcontroller_CC_MATCH_INVERT       |   \
                                                                 left_speedcontroller_OVERLOW_NO_CHANGE     |   \
                                                                 left_speedcontroller_UNDERFLOW_CLEAR)
    #else
        #define left_speedcontroller_PWM_MODE_CENTER                (left_speedcontroller_CC_MATCH_INVERT       |   \
                                                                 left_speedcontroller_OVERLOW_SET           |   \
                                                                 left_speedcontroller_UNDERFLOW_CLEAR)
    #endif /* (left_speedcontroller_CY_TCPWM_4000) */
#else
    #define left_speedcontroller_PWM_MODE_CENTER                (left_speedcontroller_CC_MATCH_INVERT       |   \
                                                             left_speedcontroller_OVERLOW_NO_CHANGE     |   \
                                                             left_speedcontroller_UNDERFLOW_CLEAR)
#endif /* (left_speedcontroller_CY_TCPWM_NEW) */

/* Command operations without condition */
#define left_speedcontroller_CMD_CAPTURE                    (0u)
#define left_speedcontroller_CMD_RELOAD                     (8u)
#define left_speedcontroller_CMD_STOP                       (16u)
#define left_speedcontroller_CMD_START                      (24u)

/* Status */
#define left_speedcontroller_STATUS_DOWN                    (1u)
#define left_speedcontroller_STATUS_RUNNING                 (2u)


/***************************************
*        Function Prototypes
****************************************/

void   left_speedcontroller_Init(void);
void   left_speedcontroller_Enable(void);
void   left_speedcontroller_Start(void);
void   left_speedcontroller_Stop(void);

void   left_speedcontroller_SetMode(uint32 mode);
void   left_speedcontroller_SetCounterMode(uint32 counterMode);
void   left_speedcontroller_SetPWMMode(uint32 modeMask);
void   left_speedcontroller_SetQDMode(uint32 qdMode);

void   left_speedcontroller_SetPrescaler(uint32 prescaler);
void   left_speedcontroller_TriggerCommand(uint32 mask, uint32 command);
void   left_speedcontroller_SetOneShot(uint32 oneShotEnable);
uint32 left_speedcontroller_ReadStatus(void);

void   left_speedcontroller_SetPWMSyncKill(uint32 syncKillEnable);
void   left_speedcontroller_SetPWMStopOnKill(uint32 stopOnKillEnable);
void   left_speedcontroller_SetPWMDeadTime(uint32 deadTime);
void   left_speedcontroller_SetPWMInvert(uint32 mask);

void   left_speedcontroller_SetInterruptMode(uint32 interruptMask);
uint32 left_speedcontroller_GetInterruptSourceMasked(void);
uint32 left_speedcontroller_GetInterruptSource(void);
void   left_speedcontroller_ClearInterrupt(uint32 interruptMask);
void   left_speedcontroller_SetInterrupt(uint32 interruptMask);

void   left_speedcontroller_WriteCounter(uint32 count);
uint32 left_speedcontroller_ReadCounter(void);

uint32 left_speedcontroller_ReadCapture(void);
uint32 left_speedcontroller_ReadCaptureBuf(void);

void   left_speedcontroller_WritePeriod(uint32 period);
uint32 left_speedcontroller_ReadPeriod(void);
void   left_speedcontroller_WritePeriodBuf(uint32 periodBuf);
uint32 left_speedcontroller_ReadPeriodBuf(void);

void   left_speedcontroller_WriteCompare(uint32 compare);
uint32 left_speedcontroller_ReadCompare(void);
void   left_speedcontroller_WriteCompareBuf(uint32 compareBuf);
uint32 left_speedcontroller_ReadCompareBuf(void);

void   left_speedcontroller_SetPeriodSwap(uint32 swapEnable);
void   left_speedcontroller_SetCompareSwap(uint32 swapEnable);

void   left_speedcontroller_SetCaptureMode(uint32 triggerMode);
void   left_speedcontroller_SetReloadMode(uint32 triggerMode);
void   left_speedcontroller_SetStartMode(uint32 triggerMode);
void   left_speedcontroller_SetStopMode(uint32 triggerMode);
void   left_speedcontroller_SetCountMode(uint32 triggerMode);

void   left_speedcontroller_SaveConfig(void);
void   left_speedcontroller_RestoreConfig(void);
void   left_speedcontroller_Sleep(void);
void   left_speedcontroller_Wakeup(void);


/***************************************
*             Registers
***************************************/

#define left_speedcontroller_BLOCK_CONTROL_REG              (*(reg32 *) left_speedcontroller_cy_m0s8_tcpwm_1__TCPWM_CTRL )
#define left_speedcontroller_BLOCK_CONTROL_PTR              ( (reg32 *) left_speedcontroller_cy_m0s8_tcpwm_1__TCPWM_CTRL )
#define left_speedcontroller_COMMAND_REG                    (*(reg32 *) left_speedcontroller_cy_m0s8_tcpwm_1__TCPWM_CMD )
#define left_speedcontroller_COMMAND_PTR                    ( (reg32 *) left_speedcontroller_cy_m0s8_tcpwm_1__TCPWM_CMD )
#define left_speedcontroller_INTRRUPT_CAUSE_REG             (*(reg32 *) left_speedcontroller_cy_m0s8_tcpwm_1__TCPWM_INTR_CAUSE )
#define left_speedcontroller_INTRRUPT_CAUSE_PTR             ( (reg32 *) left_speedcontroller_cy_m0s8_tcpwm_1__TCPWM_INTR_CAUSE )
#define left_speedcontroller_CONTROL_REG                    (*(reg32 *) left_speedcontroller_cy_m0s8_tcpwm_1__CTRL )
#define left_speedcontroller_CONTROL_PTR                    ( (reg32 *) left_speedcontroller_cy_m0s8_tcpwm_1__CTRL )
#define left_speedcontroller_STATUS_REG                     (*(reg32 *) left_speedcontroller_cy_m0s8_tcpwm_1__STATUS )
#define left_speedcontroller_STATUS_PTR                     ( (reg32 *) left_speedcontroller_cy_m0s8_tcpwm_1__STATUS )
#define left_speedcontroller_COUNTER_REG                    (*(reg32 *) left_speedcontroller_cy_m0s8_tcpwm_1__COUNTER )
#define left_speedcontroller_COUNTER_PTR                    ( (reg32 *) left_speedcontroller_cy_m0s8_tcpwm_1__COUNTER )
#define left_speedcontroller_COMP_CAP_REG                   (*(reg32 *) left_speedcontroller_cy_m0s8_tcpwm_1__CC )
#define left_speedcontroller_COMP_CAP_PTR                   ( (reg32 *) left_speedcontroller_cy_m0s8_tcpwm_1__CC )
#define left_speedcontroller_COMP_CAP_BUF_REG               (*(reg32 *) left_speedcontroller_cy_m0s8_tcpwm_1__CC_BUFF )
#define left_speedcontroller_COMP_CAP_BUF_PTR               ( (reg32 *) left_speedcontroller_cy_m0s8_tcpwm_1__CC_BUFF )
#define left_speedcontroller_PERIOD_REG                     (*(reg32 *) left_speedcontroller_cy_m0s8_tcpwm_1__PERIOD )
#define left_speedcontroller_PERIOD_PTR                     ( (reg32 *) left_speedcontroller_cy_m0s8_tcpwm_1__PERIOD )
#define left_speedcontroller_PERIOD_BUF_REG                 (*(reg32 *) left_speedcontroller_cy_m0s8_tcpwm_1__PERIOD_BUFF )
#define left_speedcontroller_PERIOD_BUF_PTR                 ( (reg32 *) left_speedcontroller_cy_m0s8_tcpwm_1__PERIOD_BUFF )
#define left_speedcontroller_TRIG_CONTROL0_REG              (*(reg32 *) left_speedcontroller_cy_m0s8_tcpwm_1__TR_CTRL0 )
#define left_speedcontroller_TRIG_CONTROL0_PTR              ( (reg32 *) left_speedcontroller_cy_m0s8_tcpwm_1__TR_CTRL0 )
#define left_speedcontroller_TRIG_CONTROL1_REG              (*(reg32 *) left_speedcontroller_cy_m0s8_tcpwm_1__TR_CTRL1 )
#define left_speedcontroller_TRIG_CONTROL1_PTR              ( (reg32 *) left_speedcontroller_cy_m0s8_tcpwm_1__TR_CTRL1 )
#define left_speedcontroller_TRIG_CONTROL2_REG              (*(reg32 *) left_speedcontroller_cy_m0s8_tcpwm_1__TR_CTRL2 )
#define left_speedcontroller_TRIG_CONTROL2_PTR              ( (reg32 *) left_speedcontroller_cy_m0s8_tcpwm_1__TR_CTRL2 )
#define left_speedcontroller_INTERRUPT_REQ_REG              (*(reg32 *) left_speedcontroller_cy_m0s8_tcpwm_1__INTR )
#define left_speedcontroller_INTERRUPT_REQ_PTR              ( (reg32 *) left_speedcontroller_cy_m0s8_tcpwm_1__INTR )
#define left_speedcontroller_INTERRUPT_SET_REG              (*(reg32 *) left_speedcontroller_cy_m0s8_tcpwm_1__INTR_SET )
#define left_speedcontroller_INTERRUPT_SET_PTR              ( (reg32 *) left_speedcontroller_cy_m0s8_tcpwm_1__INTR_SET )
#define left_speedcontroller_INTERRUPT_MASK_REG             (*(reg32 *) left_speedcontroller_cy_m0s8_tcpwm_1__INTR_MASK )
#define left_speedcontroller_INTERRUPT_MASK_PTR             ( (reg32 *) left_speedcontroller_cy_m0s8_tcpwm_1__INTR_MASK )
#define left_speedcontroller_INTERRUPT_MASKED_REG           (*(reg32 *) left_speedcontroller_cy_m0s8_tcpwm_1__INTR_MASKED )
#define left_speedcontroller_INTERRUPT_MASKED_PTR           ( (reg32 *) left_speedcontroller_cy_m0s8_tcpwm_1__INTR_MASKED )


/***************************************
*       Registers Constants
***************************************/

/* Mask */
#define left_speedcontroller_MASK                           ((uint32)left_speedcontroller_cy_m0s8_tcpwm_1__TCPWM_CTRL_MASK)

/* Shift constants for control register */
#define left_speedcontroller_RELOAD_CC_SHIFT                (0u)
#define left_speedcontroller_RELOAD_PERIOD_SHIFT            (1u)
#define left_speedcontroller_PWM_SYNC_KILL_SHIFT            (2u)
#define left_speedcontroller_PWM_STOP_KILL_SHIFT            (3u)
#define left_speedcontroller_PRESCALER_SHIFT                (8u)
#define left_speedcontroller_UPDOWN_SHIFT                   (16u)
#define left_speedcontroller_ONESHOT_SHIFT                  (18u)
#define left_speedcontroller_QUAD_MODE_SHIFT                (20u)
#define left_speedcontroller_INV_OUT_SHIFT                  (20u)
#define left_speedcontroller_INV_COMPL_OUT_SHIFT            (21u)
#define left_speedcontroller_MODE_SHIFT                     (24u)

/* Mask constants for control register */
#define left_speedcontroller_RELOAD_CC_MASK                 ((uint32)(left_speedcontroller_1BIT_MASK        <<  \
                                                                            left_speedcontroller_RELOAD_CC_SHIFT))
#define left_speedcontroller_RELOAD_PERIOD_MASK             ((uint32)(left_speedcontroller_1BIT_MASK        <<  \
                                                                            left_speedcontroller_RELOAD_PERIOD_SHIFT))
#define left_speedcontroller_PWM_SYNC_KILL_MASK             ((uint32)(left_speedcontroller_1BIT_MASK        <<  \
                                                                            left_speedcontroller_PWM_SYNC_KILL_SHIFT))
#define left_speedcontroller_PWM_STOP_KILL_MASK             ((uint32)(left_speedcontroller_1BIT_MASK        <<  \
                                                                            left_speedcontroller_PWM_STOP_KILL_SHIFT))
#define left_speedcontroller_PRESCALER_MASK                 ((uint32)(left_speedcontroller_8BIT_MASK        <<  \
                                                                            left_speedcontroller_PRESCALER_SHIFT))
#define left_speedcontroller_UPDOWN_MASK                    ((uint32)(left_speedcontroller_2BIT_MASK        <<  \
                                                                            left_speedcontroller_UPDOWN_SHIFT))
#define left_speedcontroller_ONESHOT_MASK                   ((uint32)(left_speedcontroller_1BIT_MASK        <<  \
                                                                            left_speedcontroller_ONESHOT_SHIFT))
#define left_speedcontroller_QUAD_MODE_MASK                 ((uint32)(left_speedcontroller_3BIT_MASK        <<  \
                                                                            left_speedcontroller_QUAD_MODE_SHIFT))
#define left_speedcontroller_INV_OUT_MASK                   ((uint32)(left_speedcontroller_2BIT_MASK        <<  \
                                                                            left_speedcontroller_INV_OUT_SHIFT))
#define left_speedcontroller_MODE_MASK                      ((uint32)(left_speedcontroller_3BIT_MASK        <<  \
                                                                            left_speedcontroller_MODE_SHIFT))

/* Shift constants for trigger control register 1 */
#define left_speedcontroller_CAPTURE_SHIFT                  (0u)
#define left_speedcontroller_COUNT_SHIFT                    (2u)
#define left_speedcontroller_RELOAD_SHIFT                   (4u)
#define left_speedcontroller_STOP_SHIFT                     (6u)
#define left_speedcontroller_START_SHIFT                    (8u)

/* Mask constants for trigger control register 1 */
#define left_speedcontroller_CAPTURE_MASK                   ((uint32)(left_speedcontroller_2BIT_MASK        <<  \
                                                                  left_speedcontroller_CAPTURE_SHIFT))
#define left_speedcontroller_COUNT_MASK                     ((uint32)(left_speedcontroller_2BIT_MASK        <<  \
                                                                  left_speedcontroller_COUNT_SHIFT))
#define left_speedcontroller_RELOAD_MASK                    ((uint32)(left_speedcontroller_2BIT_MASK        <<  \
                                                                  left_speedcontroller_RELOAD_SHIFT))
#define left_speedcontroller_STOP_MASK                      ((uint32)(left_speedcontroller_2BIT_MASK        <<  \
                                                                  left_speedcontroller_STOP_SHIFT))
#define left_speedcontroller_START_MASK                     ((uint32)(left_speedcontroller_2BIT_MASK        <<  \
                                                                  left_speedcontroller_START_SHIFT))

/* MASK */
#define left_speedcontroller_1BIT_MASK                      ((uint32)0x01u)
#define left_speedcontroller_2BIT_MASK                      ((uint32)0x03u)
#define left_speedcontroller_3BIT_MASK                      ((uint32)0x07u)
#define left_speedcontroller_6BIT_MASK                      ((uint32)0x3Fu)
#define left_speedcontroller_8BIT_MASK                      ((uint32)0xFFu)
#define left_speedcontroller_16BIT_MASK                     ((uint32)0xFFFFu)

/* Shift constant for status register */
#define left_speedcontroller_RUNNING_STATUS_SHIFT           (30u)


/***************************************
*    Initial Constants
***************************************/

#define left_speedcontroller_CTRL_QUAD_BASE_CONFIG                                                          \
        (((uint32)(left_speedcontroller_QUAD_ENCODING_MODES     << left_speedcontroller_QUAD_MODE_SHIFT))       |\
         ((uint32)(left_speedcontroller_CONFIG                  << left_speedcontroller_MODE_SHIFT)))

#define left_speedcontroller_CTRL_PWM_BASE_CONFIG                                                           \
        (((uint32)(left_speedcontroller_PWM_STOP_EVENT          << left_speedcontroller_PWM_STOP_KILL_SHIFT))   |\
         ((uint32)(left_speedcontroller_PWM_OUT_INVERT          << left_speedcontroller_INV_OUT_SHIFT))         |\
         ((uint32)(left_speedcontroller_PWM_OUT_N_INVERT        << left_speedcontroller_INV_COMPL_OUT_SHIFT))   |\
         ((uint32)(left_speedcontroller_PWM_MODE                << left_speedcontroller_MODE_SHIFT)))

#define left_speedcontroller_CTRL_PWM_RUN_MODE                                                              \
            ((uint32)(left_speedcontroller_PWM_RUN_MODE         << left_speedcontroller_ONESHOT_SHIFT))
            
#define left_speedcontroller_CTRL_PWM_ALIGN                                                                 \
            ((uint32)(left_speedcontroller_PWM_ALIGN            << left_speedcontroller_UPDOWN_SHIFT))

#define left_speedcontroller_CTRL_PWM_KILL_EVENT                                                            \
             ((uint32)(left_speedcontroller_PWM_KILL_EVENT      << left_speedcontroller_PWM_SYNC_KILL_SHIFT))

#define left_speedcontroller_CTRL_PWM_DEAD_TIME_CYCLE                                                       \
            ((uint32)(left_speedcontroller_PWM_DEAD_TIME_CYCLE  << left_speedcontroller_PRESCALER_SHIFT))

#define left_speedcontroller_CTRL_PWM_PRESCALER                                                             \
            ((uint32)(left_speedcontroller_PWM_PRESCALER        << left_speedcontroller_PRESCALER_SHIFT))

#define left_speedcontroller_CTRL_TIMER_BASE_CONFIG                                                         \
        (((uint32)(left_speedcontroller_TC_PRESCALER            << left_speedcontroller_PRESCALER_SHIFT))       |\
         ((uint32)(left_speedcontroller_TC_COUNTER_MODE         << left_speedcontroller_UPDOWN_SHIFT))          |\
         ((uint32)(left_speedcontroller_TC_RUN_MODE             << left_speedcontroller_ONESHOT_SHIFT))         |\
         ((uint32)(left_speedcontroller_TC_COMP_CAP_MODE        << left_speedcontroller_MODE_SHIFT)))
        
#define left_speedcontroller_QUAD_SIGNALS_MODES                                                             \
        (((uint32)(left_speedcontroller_QUAD_PHIA_SIGNAL_MODE   << left_speedcontroller_COUNT_SHIFT))           |\
         ((uint32)(left_speedcontroller_QUAD_INDEX_SIGNAL_MODE  << left_speedcontroller_RELOAD_SHIFT))          |\
         ((uint32)(left_speedcontroller_QUAD_STOP_SIGNAL_MODE   << left_speedcontroller_STOP_SHIFT))            |\
         ((uint32)(left_speedcontroller_QUAD_PHIB_SIGNAL_MODE   << left_speedcontroller_START_SHIFT)))

#define left_speedcontroller_PWM_SIGNALS_MODES                                                              \
        (((uint32)(left_speedcontroller_PWM_SWITCH_SIGNAL_MODE  << left_speedcontroller_CAPTURE_SHIFT))         |\
         ((uint32)(left_speedcontroller_PWM_COUNT_SIGNAL_MODE   << left_speedcontroller_COUNT_SHIFT))           |\
         ((uint32)(left_speedcontroller_PWM_RELOAD_SIGNAL_MODE  << left_speedcontroller_RELOAD_SHIFT))          |\
         ((uint32)(left_speedcontroller_PWM_STOP_SIGNAL_MODE    << left_speedcontroller_STOP_SHIFT))            |\
         ((uint32)(left_speedcontroller_PWM_START_SIGNAL_MODE   << left_speedcontroller_START_SHIFT)))

#define left_speedcontroller_TIMER_SIGNALS_MODES                                                            \
        (((uint32)(left_speedcontroller_TC_CAPTURE_SIGNAL_MODE  << left_speedcontroller_CAPTURE_SHIFT))         |\
         ((uint32)(left_speedcontroller_TC_COUNT_SIGNAL_MODE    << left_speedcontroller_COUNT_SHIFT))           |\
         ((uint32)(left_speedcontroller_TC_RELOAD_SIGNAL_MODE   << left_speedcontroller_RELOAD_SHIFT))          |\
         ((uint32)(left_speedcontroller_TC_STOP_SIGNAL_MODE     << left_speedcontroller_STOP_SHIFT))            |\
         ((uint32)(left_speedcontroller_TC_START_SIGNAL_MODE    << left_speedcontroller_START_SHIFT)))
        
#define left_speedcontroller_TIMER_UPDOWN_CNT_USED                                                          \
                ((left_speedcontroller__COUNT_UPDOWN0 == left_speedcontroller_TC_COUNTER_MODE)                  ||\
                 (left_speedcontroller__COUNT_UPDOWN1 == left_speedcontroller_TC_COUNTER_MODE))

#define left_speedcontroller_PWM_UPDOWN_CNT_USED                                                            \
                ((left_speedcontroller__CENTER == left_speedcontroller_PWM_ALIGN)                               ||\
                 (left_speedcontroller__ASYMMETRIC == left_speedcontroller_PWM_ALIGN))               
        
#define left_speedcontroller_PWM_PR_INIT_VALUE              (1u)
#define left_speedcontroller_QUAD_PERIOD_INIT_VALUE         (0x8000u)



#endif /* End CY_TCPWM_left_speedcontroller_H */

/* [] END OF FILE */
