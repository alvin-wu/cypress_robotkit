/*******************************************************************************
* File Name: left_speedcontroller.c
* Version 2.10
*
* Description:
*  This file provides the source code to the API for the left_speedcontroller
*  component
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

#include "left_speedcontroller.h"

uint8 left_speedcontroller_initVar = 0u;


/*******************************************************************************
* Function Name: left_speedcontroller_Init
********************************************************************************
*
* Summary:
*  Initialize/Restore default left_speedcontroller configuration.
*
* Parameters:
*  None
*
* Return:
*  None
*
*******************************************************************************/
void left_speedcontroller_Init(void)
{

    /* Set values from customizer to CTRL */
    #if (left_speedcontroller__QUAD == left_speedcontroller_CONFIG)
        left_speedcontroller_CONTROL_REG = left_speedcontroller_CTRL_QUAD_BASE_CONFIG;
        
        /* Set values from customizer to CTRL1 */
        left_speedcontroller_TRIG_CONTROL1_REG  = left_speedcontroller_QUAD_SIGNALS_MODES;

        /* Set values from customizer to INTR */
        left_speedcontroller_SetInterruptMode(left_speedcontroller_QUAD_INTERRUPT_MASK);
        
         /* Set other values */
        left_speedcontroller_SetCounterMode(left_speedcontroller_COUNT_DOWN);
        left_speedcontroller_WritePeriod(left_speedcontroller_QUAD_PERIOD_INIT_VALUE);
        left_speedcontroller_WriteCounter(left_speedcontroller_QUAD_PERIOD_INIT_VALUE);
    #endif  /* (left_speedcontroller__QUAD == left_speedcontroller_CONFIG) */

    #if (left_speedcontroller__TIMER == left_speedcontroller_CONFIG)
        left_speedcontroller_CONTROL_REG = left_speedcontroller_CTRL_TIMER_BASE_CONFIG;
        
        /* Set values from customizer to CTRL1 */
        left_speedcontroller_TRIG_CONTROL1_REG  = left_speedcontroller_TIMER_SIGNALS_MODES;
    
        /* Set values from customizer to INTR */
        left_speedcontroller_SetInterruptMode(left_speedcontroller_TC_INTERRUPT_MASK);
        
        /* Set other values from customizer */
        left_speedcontroller_WritePeriod(left_speedcontroller_TC_PERIOD_VALUE );

        #if (left_speedcontroller__COMPARE == left_speedcontroller_TC_COMP_CAP_MODE)
            left_speedcontroller_WriteCompare(left_speedcontroller_TC_COMPARE_VALUE);

            #if (1u == left_speedcontroller_TC_COMPARE_SWAP)
                left_speedcontroller_SetCompareSwap(1u);
                left_speedcontroller_WriteCompareBuf(left_speedcontroller_TC_COMPARE_BUF_VALUE);
            #endif  /* (1u == left_speedcontroller_TC_COMPARE_SWAP) */
        #endif  /* (left_speedcontroller__COMPARE == left_speedcontroller_TC_COMP_CAP_MODE) */

        /* Initialize counter value */
        #if (left_speedcontroller_CY_TCPWM_V2 && left_speedcontroller_TIMER_UPDOWN_CNT_USED && !left_speedcontroller_CY_TCPWM_4000)
            left_speedcontroller_WriteCounter(1u);
        #elif(left_speedcontroller__COUNT_DOWN == left_speedcontroller_TC_COUNTER_MODE)
            left_speedcontroller_WriteCounter(left_speedcontroller_TC_PERIOD_VALUE);
        #else
            left_speedcontroller_WriteCounter(0u);
        #endif /* (left_speedcontroller_CY_TCPWM_V2 && left_speedcontroller_TIMER_UPDOWN_CNT_USED && !left_speedcontroller_CY_TCPWM_4000) */
    #endif  /* (left_speedcontroller__TIMER == left_speedcontroller_CONFIG) */

    #if (left_speedcontroller__PWM_SEL == left_speedcontroller_CONFIG)
        left_speedcontroller_CONTROL_REG = left_speedcontroller_CTRL_PWM_BASE_CONFIG;

        #if (left_speedcontroller__PWM_PR == left_speedcontroller_PWM_MODE)
            left_speedcontroller_CONTROL_REG |= left_speedcontroller_CTRL_PWM_RUN_MODE;
            left_speedcontroller_WriteCounter(left_speedcontroller_PWM_PR_INIT_VALUE);
        #else
            left_speedcontroller_CONTROL_REG |= left_speedcontroller_CTRL_PWM_ALIGN | left_speedcontroller_CTRL_PWM_KILL_EVENT;
            
            /* Initialize counter value */
            #if (left_speedcontroller_CY_TCPWM_V2 && left_speedcontroller_PWM_UPDOWN_CNT_USED && !left_speedcontroller_CY_TCPWM_4000)
                left_speedcontroller_WriteCounter(1u);
            #elif (left_speedcontroller__RIGHT == left_speedcontroller_PWM_ALIGN)
                left_speedcontroller_WriteCounter(left_speedcontroller_PWM_PERIOD_VALUE);
            #else 
                left_speedcontroller_WriteCounter(0u);
            #endif  /* (left_speedcontroller_CY_TCPWM_V2 && left_speedcontroller_PWM_UPDOWN_CNT_USED && !left_speedcontroller_CY_TCPWM_4000) */
        #endif  /* (left_speedcontroller__PWM_PR == left_speedcontroller_PWM_MODE) */

        #if (left_speedcontroller__PWM_DT == left_speedcontroller_PWM_MODE)
            left_speedcontroller_CONTROL_REG |= left_speedcontroller_CTRL_PWM_DEAD_TIME_CYCLE;
        #endif  /* (left_speedcontroller__PWM_DT == left_speedcontroller_PWM_MODE) */

        #if (left_speedcontroller__PWM == left_speedcontroller_PWM_MODE)
            left_speedcontroller_CONTROL_REG |= left_speedcontroller_CTRL_PWM_PRESCALER;
        #endif  /* (left_speedcontroller__PWM == left_speedcontroller_PWM_MODE) */

        /* Set values from customizer to CTRL1 */
        left_speedcontroller_TRIG_CONTROL1_REG  = left_speedcontroller_PWM_SIGNALS_MODES;
    
        /* Set values from customizer to INTR */
        left_speedcontroller_SetInterruptMode(left_speedcontroller_PWM_INTERRUPT_MASK);

        /* Set values from customizer to CTRL2 */
        #if (left_speedcontroller__PWM_PR == left_speedcontroller_PWM_MODE)
            left_speedcontroller_TRIG_CONTROL2_REG =
                    (left_speedcontroller_CC_MATCH_NO_CHANGE    |
                    left_speedcontroller_OVERLOW_NO_CHANGE      |
                    left_speedcontroller_UNDERFLOW_NO_CHANGE);
        #else
            #if (left_speedcontroller__LEFT == left_speedcontroller_PWM_ALIGN)
                left_speedcontroller_TRIG_CONTROL2_REG = left_speedcontroller_PWM_MODE_LEFT;
            #endif  /* ( left_speedcontroller_PWM_LEFT == left_speedcontroller_PWM_ALIGN) */

            #if (left_speedcontroller__RIGHT == left_speedcontroller_PWM_ALIGN)
                left_speedcontroller_TRIG_CONTROL2_REG = left_speedcontroller_PWM_MODE_RIGHT;
            #endif  /* ( left_speedcontroller_PWM_RIGHT == left_speedcontroller_PWM_ALIGN) */

            #if (left_speedcontroller__CENTER == left_speedcontroller_PWM_ALIGN)
                left_speedcontroller_TRIG_CONTROL2_REG = left_speedcontroller_PWM_MODE_CENTER;
            #endif  /* ( left_speedcontroller_PWM_CENTER == left_speedcontroller_PWM_ALIGN) */

            #if (left_speedcontroller__ASYMMETRIC == left_speedcontroller_PWM_ALIGN)
                left_speedcontroller_TRIG_CONTROL2_REG = left_speedcontroller_PWM_MODE_ASYM;
            #endif  /* (left_speedcontroller__ASYMMETRIC == left_speedcontroller_PWM_ALIGN) */
        #endif  /* (left_speedcontroller__PWM_PR == left_speedcontroller_PWM_MODE) */

        /* Set other values from customizer */
        left_speedcontroller_WritePeriod(left_speedcontroller_PWM_PERIOD_VALUE );
        left_speedcontroller_WriteCompare(left_speedcontroller_PWM_COMPARE_VALUE);

        #if (1u == left_speedcontroller_PWM_COMPARE_SWAP)
            left_speedcontroller_SetCompareSwap(1u);
            left_speedcontroller_WriteCompareBuf(left_speedcontroller_PWM_COMPARE_BUF_VALUE);
        #endif  /* (1u == left_speedcontroller_PWM_COMPARE_SWAP) */

        #if (1u == left_speedcontroller_PWM_PERIOD_SWAP)
            left_speedcontroller_SetPeriodSwap(1u);
            left_speedcontroller_WritePeriodBuf(left_speedcontroller_PWM_PERIOD_BUF_VALUE);
        #endif  /* (1u == left_speedcontroller_PWM_PERIOD_SWAP) */
    #endif  /* (left_speedcontroller__PWM_SEL == left_speedcontroller_CONFIG) */
    
}


/*******************************************************************************
* Function Name: left_speedcontroller_Enable
********************************************************************************
*
* Summary:
*  Enables the left_speedcontroller.
*
* Parameters:
*  None
*
* Return:
*  None
*
*******************************************************************************/
void left_speedcontroller_Enable(void)
{
    uint8 enableInterrupts;

    enableInterrupts = CyEnterCriticalSection();
    left_speedcontroller_BLOCK_CONTROL_REG |= left_speedcontroller_MASK;
    CyExitCriticalSection(enableInterrupts);

    /* Start Timer or PWM if start input is absent */
    #if (left_speedcontroller__PWM_SEL == left_speedcontroller_CONFIG)
        #if (0u == left_speedcontroller_PWM_START_SIGNAL_PRESENT)
            left_speedcontroller_TriggerCommand(left_speedcontroller_MASK, left_speedcontroller_CMD_START);
        #endif /* (0u == left_speedcontroller_PWM_START_SIGNAL_PRESENT) */
    #endif /* (left_speedcontroller__PWM_SEL == left_speedcontroller_CONFIG) */

    #if (left_speedcontroller__TIMER == left_speedcontroller_CONFIG)
        #if (0u == left_speedcontroller_TC_START_SIGNAL_PRESENT)
            left_speedcontroller_TriggerCommand(left_speedcontroller_MASK, left_speedcontroller_CMD_START);
        #endif /* (0u == left_speedcontroller_TC_START_SIGNAL_PRESENT) */
    #endif /* (left_speedcontroller__TIMER == left_speedcontroller_CONFIG) */
    
    #if (left_speedcontroller__QUAD == left_speedcontroller_CONFIG)
        #if (0u != left_speedcontroller_QUAD_AUTO_START)
            left_speedcontroller_TriggerCommand(left_speedcontroller_MASK, left_speedcontroller_CMD_RELOAD);
        #endif /* (0u != left_speedcontroller_QUAD_AUTO_START) */
    #endif  /* (left_speedcontroller__QUAD == left_speedcontroller_CONFIG) */
}


/*******************************************************************************
* Function Name: left_speedcontroller_Start
********************************************************************************
*
* Summary:
*  Initializes the left_speedcontroller with default customizer
*  values when called the first time and enables the left_speedcontroller.
*  For subsequent calls the configuration is left unchanged and the component is
*  just enabled.
*
* Parameters:
*  None
*
* Return:
*  None
*
* Global variables:
*  left_speedcontroller_initVar: global variable is used to indicate initial
*  configuration of this component.  The variable is initialized to zero and set
*  to 1 the first time left_speedcontroller_Start() is called. This allows
*  enabling/disabling a component without re-initialization in all subsequent
*  calls to the left_speedcontroller_Start() routine.
*
*******************************************************************************/
void left_speedcontroller_Start(void)
{
    if (0u == left_speedcontroller_initVar)
    {
        left_speedcontroller_Init();
        left_speedcontroller_initVar = 1u;
    }

    left_speedcontroller_Enable();
}


/*******************************************************************************
* Function Name: left_speedcontroller_Stop
********************************************************************************
*
* Summary:
*  Disables the left_speedcontroller.
*
* Parameters:
*  None
*
* Return:
*  None
*
*******************************************************************************/
void left_speedcontroller_Stop(void)
{
    uint8 enableInterrupts;

    enableInterrupts = CyEnterCriticalSection();

    left_speedcontroller_BLOCK_CONTROL_REG &= (uint32)~left_speedcontroller_MASK;

    CyExitCriticalSection(enableInterrupts);
}


/*******************************************************************************
* Function Name: left_speedcontroller_SetMode
********************************************************************************
*
* Summary:
*  Sets the operation mode of the left_speedcontroller. This function is used when
*  configured as a generic left_speedcontroller and the actual mode of operation is
*  set at runtime. The mode must be set while the component is disabled.
*
* Parameters:
*  mode: Mode for the left_speedcontroller to operate in
*   Values:
*   - left_speedcontroller_MODE_TIMER_COMPARE - Timer / Counter with
*                                                 compare capability
*         - left_speedcontroller_MODE_TIMER_CAPTURE - Timer / Counter with
*                                                 capture capability
*         - left_speedcontroller_MODE_QUAD - Quadrature decoder
*         - left_speedcontroller_MODE_PWM - PWM
*         - left_speedcontroller_MODE_PWM_DT - PWM with dead time
*         - left_speedcontroller_MODE_PWM_PR - PWM with pseudo random capability
*
* Return:
*  None
*
*******************************************************************************/
void left_speedcontroller_SetMode(uint32 mode)
{
    uint8 enableInterrupts;

    enableInterrupts = CyEnterCriticalSection();

    left_speedcontroller_CONTROL_REG &= (uint32)~left_speedcontroller_MODE_MASK;
    left_speedcontroller_CONTROL_REG |= mode;

    CyExitCriticalSection(enableInterrupts);
}


/*******************************************************************************
* Function Name: left_speedcontroller_SetQDMode
********************************************************************************
*
* Summary:
*  Sets the the Quadrature Decoder to one of the 3 supported modes.
*  Its functionality is only applicable to Quadrature Decoder operation.
*
* Parameters:
*  qdMode: Quadrature Decoder mode
*   Values:
*         - left_speedcontroller_MODE_X1 - Counts on phi 1 rising
*         - left_speedcontroller_MODE_X2 - Counts on both edges of phi1 (2x faster)
*         - left_speedcontroller_MODE_X4 - Counts on both edges of phi1 and phi2
*                                        (4x faster)
*
* Return:
*  None
*
*******************************************************************************/
void left_speedcontroller_SetQDMode(uint32 qdMode)
{
    uint8 enableInterrupts;

    enableInterrupts = CyEnterCriticalSection();

    left_speedcontroller_CONTROL_REG &= (uint32)~left_speedcontroller_QUAD_MODE_MASK;
    left_speedcontroller_CONTROL_REG |= qdMode;

    CyExitCriticalSection(enableInterrupts);
}


/*******************************************************************************
* Function Name: left_speedcontroller_SetPrescaler
********************************************************************************
*
* Summary:
*  Sets the prescaler value that is applied to the clock input.  Not applicable
*  to a PWM with the dead time mode or Quadrature Decoder mode.
*
* Parameters:
*  prescaler: Prescaler divider value
*   Values:
*         - left_speedcontroller_PRESCALE_DIVBY1    - Divide by 1 (no prescaling)
*         - left_speedcontroller_PRESCALE_DIVBY2    - Divide by 2
*         - left_speedcontroller_PRESCALE_DIVBY4    - Divide by 4
*         - left_speedcontroller_PRESCALE_DIVBY8    - Divide by 8
*         - left_speedcontroller_PRESCALE_DIVBY16   - Divide by 16
*         - left_speedcontroller_PRESCALE_DIVBY32   - Divide by 32
*         - left_speedcontroller_PRESCALE_DIVBY64   - Divide by 64
*         - left_speedcontroller_PRESCALE_DIVBY128  - Divide by 128
*
* Return:
*  None
*
*******************************************************************************/
void left_speedcontroller_SetPrescaler(uint32 prescaler)
{
    uint8 enableInterrupts;

    enableInterrupts = CyEnterCriticalSection();

    left_speedcontroller_CONTROL_REG &= (uint32)~left_speedcontroller_PRESCALER_MASK;
    left_speedcontroller_CONTROL_REG |= prescaler;

    CyExitCriticalSection(enableInterrupts);
}


/*******************************************************************************
* Function Name: left_speedcontroller_SetOneShot
********************************************************************************
*
* Summary:
*  Writes the register that controls whether the left_speedcontroller runs
*  continuously or stops when terminal count is reached.  By default the
*  left_speedcontroller operates in the continuous mode.
*
* Parameters:
*  oneShotEnable
*   Values:
*     - 0 - Continuous
*     - 1 - Enable One Shot
*
* Return:
*  None
*
*******************************************************************************/
void left_speedcontroller_SetOneShot(uint32 oneShotEnable)
{
    uint8 enableInterrupts;

    enableInterrupts = CyEnterCriticalSection();

    left_speedcontroller_CONTROL_REG &= (uint32)~left_speedcontroller_ONESHOT_MASK;
    left_speedcontroller_CONTROL_REG |= ((uint32)((oneShotEnable & left_speedcontroller_1BIT_MASK) <<
                                                               left_speedcontroller_ONESHOT_SHIFT));

    CyExitCriticalSection(enableInterrupts);
}


/*******************************************************************************
* Function Name: left_speedcontroller_SetPWMMode
********************************************************************************
*
* Summary:
*  Writes the control register that determines what mode of operation the PWM
*  output lines are driven in.  There is a setting for what to do on a
*  comparison match (CC_MATCH), on an overflow (OVERFLOW) and on an underflow
*  (UNDERFLOW).  The value for each of the three must be ORed together to form
*  the mode.
*
* Parameters:
*  modeMask: A combination of three mode settings.  Mask must include a value
*  for each of the three or use one of the preconfigured PWM settings.
*   Values:
*     - CC_MATCH_SET        - Set on comparison match
*     - CC_MATCH_CLEAR      - Clear on comparison match
*     - CC_MATCH_INVERT     - Invert on comparison match
*     - CC_MATCH_NO_CHANGE  - No change on comparison match
*     - OVERLOW_SET         - Set on overflow
*     - OVERLOW_CLEAR       - Clear on  overflow
*     - OVERLOW_INVERT      - Invert on overflow
*     - OVERLOW_NO_CHANGE   - No change on overflow
*     - UNDERFLOW_SET       - Set on underflow
*     - UNDERFLOW_CLEAR     - Clear on underflow
*     - UNDERFLOW_INVERT    - Invert on underflow
*     - UNDERFLOW_NO_CHANGE - No change on underflow
*     - PWM_MODE_LEFT       - Setting for left aligned PWM.  Should be combined
*                             with up counting mode
*     - PWM_MODE_RIGHT      - Setting for right aligned PWM.  Should be combined
*                             with down counting mode
*     - PWM_MODE_CENTER     - Setting for center aligned PWM.  Should be
*                             combined with up/down 0 mode
*     - PWM_MODE_ASYM       - Setting for asymmetric PWM.  Should be combined
*                             with up/down 1 mode
*
* Return:
*  None
*
*******************************************************************************/
void left_speedcontroller_SetPWMMode(uint32 modeMask)
{
    left_speedcontroller_TRIG_CONTROL2_REG = (modeMask & left_speedcontroller_6BIT_MASK);
}



/*******************************************************************************
* Function Name: left_speedcontroller_SetPWMSyncKill
********************************************************************************
*
* Summary:
*  Writes the register that controls whether the PWM kill signal (stop input)
*  causes asynchronous or synchronous kill operation.  By default the kill
*  operation is asynchronous.  This functionality is only applicable to the PWM
*  and PWM with dead time modes.
*
*  For Synchronous mode the kill signal disables both the line and line_n
*  signals until the next terminal count.
*
*  For Asynchronous mode the kill signal disables both the line and line_n
*  signals when the kill signal is present.  This mode should only be used
*  when the kill signal (stop input) is configured in the pass through mode
*  (Level sensitive signal).

*
* Parameters:
*  syncKillEnable
*   Values:
*     - 0 - Asynchronous
*     - 1 - Synchronous
*
* Return:
*  None
*
*******************************************************************************/
void left_speedcontroller_SetPWMSyncKill(uint32 syncKillEnable)
{
    uint8 enableInterrupts;

    enableInterrupts = CyEnterCriticalSection();

    left_speedcontroller_CONTROL_REG &= (uint32)~left_speedcontroller_PWM_SYNC_KILL_MASK;
    left_speedcontroller_CONTROL_REG |= ((uint32)((syncKillEnable & left_speedcontroller_1BIT_MASK)  <<
                                               left_speedcontroller_PWM_SYNC_KILL_SHIFT));

    CyExitCriticalSection(enableInterrupts);
}


/*******************************************************************************
* Function Name: left_speedcontroller_SetPWMStopOnKill
********************************************************************************
*
* Summary:
*  Writes the register that controls whether the PWM kill signal (stop input)
*  causes the PWM counter to stop.  By default the kill operation does not stop
*  the counter.  This functionality is only applicable to the three PWM modes.
*
*
* Parameters:
*  stopOnKillEnable
*   Values:
*     - 0 - Don't stop
*     - 1 - Stop
*
* Return:
*  None
*
*******************************************************************************/
void left_speedcontroller_SetPWMStopOnKill(uint32 stopOnKillEnable)
{
    uint8 enableInterrupts;

    enableInterrupts = CyEnterCriticalSection();

    left_speedcontroller_CONTROL_REG &= (uint32)~left_speedcontroller_PWM_STOP_KILL_MASK;
    left_speedcontroller_CONTROL_REG |= ((uint32)((stopOnKillEnable & left_speedcontroller_1BIT_MASK)  <<
                                                         left_speedcontroller_PWM_STOP_KILL_SHIFT));

    CyExitCriticalSection(enableInterrupts);
}


/*******************************************************************************
* Function Name: left_speedcontroller_SetPWMDeadTime
********************************************************************************
*
* Summary:
*  Writes the dead time control value.  This value delays the rising edge of
*  both the line and line_n signals the designated number of cycles resulting
*  in both signals being inactive for that many cycles.  This functionality is
*  only applicable to the PWM in the dead time mode.

*
* Parameters:
*  Dead time to insert
*   Values: 0 to 255
*
* Return:
*  None
*
*******************************************************************************/
void left_speedcontroller_SetPWMDeadTime(uint32 deadTime)
{
    uint8 enableInterrupts;

    enableInterrupts = CyEnterCriticalSection();

    left_speedcontroller_CONTROL_REG &= (uint32)~left_speedcontroller_PRESCALER_MASK;
    left_speedcontroller_CONTROL_REG |= ((uint32)((deadTime & left_speedcontroller_8BIT_MASK) <<
                                                          left_speedcontroller_PRESCALER_SHIFT));

    CyExitCriticalSection(enableInterrupts);
}


/*******************************************************************************
* Function Name: left_speedcontroller_SetPWMInvert
********************************************************************************
*
* Summary:
*  Writes the bits that control whether the line and line_n outputs are
*  inverted from their normal output values.  This functionality is only
*  applicable to the three PWM modes.
*
* Parameters:
*  mask: Mask of outputs to invert.
*   Values:
*         - left_speedcontroller_INVERT_LINE   - Inverts the line output
*         - left_speedcontroller_INVERT_LINE_N - Inverts the line_n output
*
* Return:
*  None
*
*******************************************************************************/
void left_speedcontroller_SetPWMInvert(uint32 mask)
{
    uint8 enableInterrupts;

    enableInterrupts = CyEnterCriticalSection();

    left_speedcontroller_CONTROL_REG &= (uint32)~left_speedcontroller_INV_OUT_MASK;
    left_speedcontroller_CONTROL_REG |= mask;

    CyExitCriticalSection(enableInterrupts);
}



/*******************************************************************************
* Function Name: left_speedcontroller_WriteCounter
********************************************************************************
*
* Summary:
*  Writes a new 16bit counter value directly into the counter register, thus
*  setting the counter (not the period) to the value written. It is not
*  advised to write to this field when the counter is running.
*
* Parameters:
*  count: value to write
*
* Return:
*  None
*
*******************************************************************************/
void left_speedcontroller_WriteCounter(uint32 count)
{
    left_speedcontroller_COUNTER_REG = (count & left_speedcontroller_16BIT_MASK);
}


/*******************************************************************************
* Function Name: left_speedcontroller_ReadCounter
********************************************************************************
*
* Summary:
*  Reads the current counter value.
*
* Parameters:
*  None
*
* Return:
*  Current counter value
*
*******************************************************************************/
uint32 left_speedcontroller_ReadCounter(void)
{
    return (left_speedcontroller_COUNTER_REG & left_speedcontroller_16BIT_MASK);
}


/*******************************************************************************
* Function Name: left_speedcontroller_SetCounterMode
********************************************************************************
*
* Summary:
*  Sets the counter mode.  Applicable to all modes except Quadrature Decoder
*  and the PWM with a pseudo random output.
*
* Parameters:
*  counterMode: Enumerated counter type values
*   Values:
*     - left_speedcontroller_COUNT_UP       - Counts up
*     - left_speedcontroller_COUNT_DOWN     - Counts down
*     - left_speedcontroller_COUNT_UPDOWN0  - Counts up and down. Terminal count
*                                         generated when counter reaches 0
*     - left_speedcontroller_COUNT_UPDOWN1  - Counts up and down. Terminal count
*                                         generated both when counter reaches 0
*                                         and period
*
* Return:
*  None
*
*******************************************************************************/
void left_speedcontroller_SetCounterMode(uint32 counterMode)
{
    uint8 enableInterrupts;

    enableInterrupts = CyEnterCriticalSection();

    left_speedcontroller_CONTROL_REG &= (uint32)~left_speedcontroller_UPDOWN_MASK;
    left_speedcontroller_CONTROL_REG |= counterMode;

    CyExitCriticalSection(enableInterrupts);
}


/*******************************************************************************
* Function Name: left_speedcontroller_WritePeriod
********************************************************************************
*
* Summary:
*  Writes the 16 bit period register with the new period value.
*  To cause the counter to count for N cycles this register should be written
*  with N-1 (counts from 0 to period inclusive).
*
* Parameters:
*  period: Period value
*
* Return:
*  None
*
*******************************************************************************/
void left_speedcontroller_WritePeriod(uint32 period)
{
    left_speedcontroller_PERIOD_REG = (period & left_speedcontroller_16BIT_MASK);
}


/*******************************************************************************
* Function Name: left_speedcontroller_ReadPeriod
********************************************************************************
*
* Summary:
*  Reads the 16 bit period register.
*
* Parameters:
*  None
*
* Return:
*  Period value
*
*******************************************************************************/
uint32 left_speedcontroller_ReadPeriod(void)
{
    return (left_speedcontroller_PERIOD_REG & left_speedcontroller_16BIT_MASK);
}


/*******************************************************************************
* Function Name: left_speedcontroller_SetCompareSwap
********************************************************************************
*
* Summary:
*  Writes the register that controls whether the compare registers are
*  swapped. When enabled in the Timer/Counter mode(without capture) the swap
*  occurs at a TC event. In the PWM mode the swap occurs at the next TC event
*  following a hardware switch event.
*
* Parameters:
*  swapEnable
*   Values:
*     - 0 - Disable swap
*     - 1 - Enable swap
*
* Return:
*  None
*
*******************************************************************************/
void left_speedcontroller_SetCompareSwap(uint32 swapEnable)
{
    uint8 enableInterrupts;

    enableInterrupts = CyEnterCriticalSection();

    left_speedcontroller_CONTROL_REG &= (uint32)~left_speedcontroller_RELOAD_CC_MASK;
    left_speedcontroller_CONTROL_REG |= (swapEnable & left_speedcontroller_1BIT_MASK);

    CyExitCriticalSection(enableInterrupts);
}


/*******************************************************************************
* Function Name: left_speedcontroller_WritePeriodBuf
********************************************************************************
*
* Summary:
*  Writes the 16 bit period buf register with the new period value.
*
* Parameters:
*  periodBuf: Period value
*
* Return:
*  None
*
*******************************************************************************/
void left_speedcontroller_WritePeriodBuf(uint32 periodBuf)
{
    left_speedcontroller_PERIOD_BUF_REG = (periodBuf & left_speedcontroller_16BIT_MASK);
}


/*******************************************************************************
* Function Name: left_speedcontroller_ReadPeriodBuf
********************************************************************************
*
* Summary:
*  Reads the 16 bit period buf register.
*
* Parameters:
*  None
*
* Return:
*  Period value
*
*******************************************************************************/
uint32 left_speedcontroller_ReadPeriodBuf(void)
{
    return (left_speedcontroller_PERIOD_BUF_REG & left_speedcontroller_16BIT_MASK);
}


/*******************************************************************************
* Function Name: left_speedcontroller_SetPeriodSwap
********************************************************************************
*
* Summary:
*  Writes the register that controls whether the period registers are
*  swapped. When enabled in Timer/Counter mode the swap occurs at a TC event.
*  In the PWM mode the swap occurs at the next TC event following a hardware
*  switch event.
*
* Parameters:
*  swapEnable
*   Values:
*     - 0 - Disable swap
*     - 1 - Enable swap
*
* Return:
*  None
*
*******************************************************************************/
void left_speedcontroller_SetPeriodSwap(uint32 swapEnable)
{
    uint8 enableInterrupts;

    enableInterrupts = CyEnterCriticalSection();

    left_speedcontroller_CONTROL_REG &= (uint32)~left_speedcontroller_RELOAD_PERIOD_MASK;
    left_speedcontroller_CONTROL_REG |= ((uint32)((swapEnable & left_speedcontroller_1BIT_MASK) <<
                                                            left_speedcontroller_RELOAD_PERIOD_SHIFT));

    CyExitCriticalSection(enableInterrupts);
}


/*******************************************************************************
* Function Name: left_speedcontroller_WriteCompare
********************************************************************************
*
* Summary:
*  Writes the 16 bit compare register with the new compare value. Not
*  applicable for Timer/Counter with Capture or in Quadrature Decoder modes.
*
* Parameters:
*  compare: Compare value
*
* Return:
*  None
*
* Note:
*  It is not recommended to use the value equal to "0" or equal to 
*  "period value" in Center or Asymmetric align PWM modes on the 
*  PSoC 4100/PSoC 4200 devices.
*  PSoC 4000 devices write the 16 bit compare register with the decremented 
*  compare value in the Up counting mode (except 0x0u), and the incremented 
*  compare value in the Down counting mode (except 0xFFFFu).
*
*******************************************************************************/
void left_speedcontroller_WriteCompare(uint32 compare)
{
    #if (left_speedcontroller_CY_TCPWM_4000)
        uint32 currentMode;
    #endif /* (left_speedcontroller_CY_TCPWM_4000) */

    #if (left_speedcontroller_CY_TCPWM_4000)
        currentMode = ((left_speedcontroller_CONTROL_REG & left_speedcontroller_UPDOWN_MASK) >> left_speedcontroller_UPDOWN_SHIFT);

        if (((uint32)left_speedcontroller__COUNT_DOWN == currentMode) && (0xFFFFu != compare))
        {
            compare++;
        }
        else if (((uint32)left_speedcontroller__COUNT_UP == currentMode) && (0u != compare))
        {
            compare--;
        }
        else
        {
        }
        
    
    #endif /* (left_speedcontroller_CY_TCPWM_4000) */
    
    left_speedcontroller_COMP_CAP_REG = (compare & left_speedcontroller_16BIT_MASK);
}


/*******************************************************************************
* Function Name: left_speedcontroller_ReadCompare
********************************************************************************
*
* Summary:
*  Reads the compare register. Not applicable for Timer/Counter with Capture
*  or in Quadrature Decoder modes.
*  PSoC 4000 devices read the incremented compare register value in the 
*  Up counting mode (except 0xFFFFu), and the decremented value in the 
*  Down counting mode (except 0x0u).
*
* Parameters:
*  None
*
* Return:
*  Compare value
*
* Note:
*  PSoC 4000 devices read the incremented compare register value in the 
*  Up counting mode (except 0xFFFFu), and the decremented value in the 
*  Down counting mode (except 0x0u).
*
*******************************************************************************/
uint32 left_speedcontroller_ReadCompare(void)
{
    #if (left_speedcontroller_CY_TCPWM_4000)
        uint32 currentMode;
        uint32 regVal;
    #endif /* (left_speedcontroller_CY_TCPWM_4000) */

    #if (left_speedcontroller_CY_TCPWM_4000)
        currentMode = ((left_speedcontroller_CONTROL_REG & left_speedcontroller_UPDOWN_MASK) >> left_speedcontroller_UPDOWN_SHIFT);
        
        regVal = left_speedcontroller_COMP_CAP_REG;
        
        if (((uint32)left_speedcontroller__COUNT_DOWN == currentMode) && (0u != regVal))
        {
            regVal--;
        }
        else if (((uint32)left_speedcontroller__COUNT_UP == currentMode) && (0xFFFFu != regVal))
        {
            regVal++;
        }
        else
        {
        }

        return (regVal & left_speedcontroller_16BIT_MASK);
    #else
        return (left_speedcontroller_COMP_CAP_REG & left_speedcontroller_16BIT_MASK);
    #endif /* (left_speedcontroller_CY_TCPWM_4000) */
}


/*******************************************************************************
* Function Name: left_speedcontroller_WriteCompareBuf
********************************************************************************
*
* Summary:
*  Writes the 16 bit compare buffer register with the new compare value. Not
*  applicable for Timer/Counter with Capture or in Quadrature Decoder modes.
*
* Parameters:
*  compareBuf: Compare value
*
* Return:
*  None
*
* Note:
*  It is not recommended to use the value equal to "0" or equal to 
*  "period value" in Center or Asymmetric align PWM modes on the 
*  PSoC 4100/PSoC 4200 devices.
*  PSoC 4000 devices write the 16 bit compare register with the decremented 
*  compare value in the Up counting mode (except 0x0u), and the incremented 
*  compare value in the Down counting mode (except 0xFFFFu).
*
*******************************************************************************/
void left_speedcontroller_WriteCompareBuf(uint32 compareBuf)
{
    #if (left_speedcontroller_CY_TCPWM_4000)
        uint32 currentMode;
    #endif /* (left_speedcontroller_CY_TCPWM_4000) */

    #if (left_speedcontroller_CY_TCPWM_4000)
        currentMode = ((left_speedcontroller_CONTROL_REG & left_speedcontroller_UPDOWN_MASK) >> left_speedcontroller_UPDOWN_SHIFT);

        if (((uint32)left_speedcontroller__COUNT_DOWN == currentMode) && (0xFFFFu != compareBuf))
        {
            compareBuf++;
        }
        else if (((uint32)left_speedcontroller__COUNT_UP == currentMode) && (0u != compareBuf))
        {
            compareBuf --;
        }
        else
        {
        }
    #endif /* (left_speedcontroller_CY_TCPWM_4000) */
    
    left_speedcontroller_COMP_CAP_BUF_REG = (compareBuf & left_speedcontroller_16BIT_MASK);
}


/*******************************************************************************
* Function Name: left_speedcontroller_ReadCompareBuf
********************************************************************************
*
* Summary:
*  Reads the compare buffer register. Not applicable for Timer/Counter with
*  Capture or in Quadrature Decoder modes.
*
* Parameters:
*  None
*
* Return:
*  Compare buffer value
*
* Note:
*  PSoC 4000 devices read the incremented compare register value in the 
*  Up counting mode (except 0xFFFFu), and the decremented value in the 
*  Down counting mode (except 0x0u).
*
*******************************************************************************/
uint32 left_speedcontroller_ReadCompareBuf(void)
{
    #if (left_speedcontroller_CY_TCPWM_4000)
        uint32 currentMode;
        uint32 regVal;
    #endif /* (left_speedcontroller_CY_TCPWM_4000) */

    #if (left_speedcontroller_CY_TCPWM_4000)
        currentMode = ((left_speedcontroller_CONTROL_REG & left_speedcontroller_UPDOWN_MASK) >> left_speedcontroller_UPDOWN_SHIFT);

        regVal = left_speedcontroller_COMP_CAP_BUF_REG;
        
        if (((uint32)left_speedcontroller__COUNT_DOWN == currentMode) && (0u != regVal))
        {
            regVal--;
        }
        else if (((uint32)left_speedcontroller__COUNT_UP == currentMode) && (0xFFFFu != regVal))
        {
            regVal++;
        }
        else
        {
        }

        return (regVal & left_speedcontroller_16BIT_MASK);
    #else
        return (left_speedcontroller_COMP_CAP_BUF_REG & left_speedcontroller_16BIT_MASK);
    #endif /* (left_speedcontroller_CY_TCPWM_4000) */
}


/*******************************************************************************
* Function Name: left_speedcontroller_ReadCapture
********************************************************************************
*
* Summary:
*  Reads the captured counter value. This API is applicable only for
*  Timer/Counter with the capture mode and Quadrature Decoder modes.
*
* Parameters:
*  None
*
* Return:
*  Capture value
*
*******************************************************************************/
uint32 left_speedcontroller_ReadCapture(void)
{
    return (left_speedcontroller_COMP_CAP_REG & left_speedcontroller_16BIT_MASK);
}


/*******************************************************************************
* Function Name: left_speedcontroller_ReadCaptureBuf
********************************************************************************
*
* Summary:
*  Reads the capture buffer register. This API is applicable only for
*  Timer/Counter with the capture mode and Quadrature Decoder modes.
*
* Parameters:
*  None
*
* Return:
*  Capture buffer value
*
*******************************************************************************/
uint32 left_speedcontroller_ReadCaptureBuf(void)
{
    return (left_speedcontroller_COMP_CAP_BUF_REG & left_speedcontroller_16BIT_MASK);
}


/*******************************************************************************
* Function Name: left_speedcontroller_SetCaptureMode
********************************************************************************
*
* Summary:
*  Sets the capture trigger mode. For PWM mode this is the switch input.
*  This input is not applicable to the Timer/Counter without Capture and
*  Quadrature Decoder modes.
*
* Parameters:
*  triggerMode: Enumerated trigger mode value
*   Values:
*     - left_speedcontroller_TRIG_LEVEL     - Level
*     - left_speedcontroller_TRIG_RISING    - Rising edge
*     - left_speedcontroller_TRIG_FALLING   - Falling edge
*     - left_speedcontroller_TRIG_BOTH      - Both rising and falling edge
*
* Return:
*  None
*
*******************************************************************************/
void left_speedcontroller_SetCaptureMode(uint32 triggerMode)
{
    uint8 enableInterrupts;

    enableInterrupts = CyEnterCriticalSection();

    left_speedcontroller_TRIG_CONTROL1_REG &= (uint32)~left_speedcontroller_CAPTURE_MASK;
    left_speedcontroller_TRIG_CONTROL1_REG |= triggerMode;

    CyExitCriticalSection(enableInterrupts);
}


/*******************************************************************************
* Function Name: left_speedcontroller_SetReloadMode
********************************************************************************
*
* Summary:
*  Sets the reload trigger mode. For Quadrature Decoder mode this is the index
*  input.
*
* Parameters:
*  triggerMode: Enumerated trigger mode value
*   Values:
*     - left_speedcontroller_TRIG_LEVEL     - Level
*     - left_speedcontroller_TRIG_RISING    - Rising edge
*     - left_speedcontroller_TRIG_FALLING   - Falling edge
*     - left_speedcontroller_TRIG_BOTH      - Both rising and falling edge
*
* Return:
*  None
*
*******************************************************************************/
void left_speedcontroller_SetReloadMode(uint32 triggerMode)
{
    uint8 enableInterrupts;

    enableInterrupts = CyEnterCriticalSection();

    left_speedcontroller_TRIG_CONTROL1_REG &= (uint32)~left_speedcontroller_RELOAD_MASK;
    left_speedcontroller_TRIG_CONTROL1_REG |= ((uint32)(triggerMode << left_speedcontroller_RELOAD_SHIFT));

    CyExitCriticalSection(enableInterrupts);
}


/*******************************************************************************
* Function Name: left_speedcontroller_SetStartMode
********************************************************************************
*
* Summary:
*  Sets the start trigger mode. For Quadrature Decoder mode this is the
*  phiB input.
*
* Parameters:
*  triggerMode: Enumerated trigger mode value
*   Values:
*     - left_speedcontroller_TRIG_LEVEL     - Level
*     - left_speedcontroller_TRIG_RISING    - Rising edge
*     - left_speedcontroller_TRIG_FALLING   - Falling edge
*     - left_speedcontroller_TRIG_BOTH      - Both rising and falling edge
*
* Return:
*  None
*
*******************************************************************************/
void left_speedcontroller_SetStartMode(uint32 triggerMode)
{
    uint8 enableInterrupts;

    enableInterrupts = CyEnterCriticalSection();

    left_speedcontroller_TRIG_CONTROL1_REG &= (uint32)~left_speedcontroller_START_MASK;
    left_speedcontroller_TRIG_CONTROL1_REG |= ((uint32)(triggerMode << left_speedcontroller_START_SHIFT));

    CyExitCriticalSection(enableInterrupts);
}


/*******************************************************************************
* Function Name: left_speedcontroller_SetStopMode
********************************************************************************
*
* Summary:
*  Sets the stop trigger mode. For PWM mode this is the kill input.
*
* Parameters:
*  triggerMode: Enumerated trigger mode value
*   Values:
*     - left_speedcontroller_TRIG_LEVEL     - Level
*     - left_speedcontroller_TRIG_RISING    - Rising edge
*     - left_speedcontroller_TRIG_FALLING   - Falling edge
*     - left_speedcontroller_TRIG_BOTH      - Both rising and falling edge
*
* Return:
*  None
*
*******************************************************************************/
void left_speedcontroller_SetStopMode(uint32 triggerMode)
{
    uint8 enableInterrupts;

    enableInterrupts = CyEnterCriticalSection();

    left_speedcontroller_TRIG_CONTROL1_REG &= (uint32)~left_speedcontroller_STOP_MASK;
    left_speedcontroller_TRIG_CONTROL1_REG |= ((uint32)(triggerMode << left_speedcontroller_STOP_SHIFT));

    CyExitCriticalSection(enableInterrupts);
}


/*******************************************************************************
* Function Name: left_speedcontroller_SetCountMode
********************************************************************************
*
* Summary:
*  Sets the count trigger mode. For Quadrature Decoder mode this is the phiA
*  input.
*
* Parameters:
*  triggerMode: Enumerated trigger mode value
*   Values:
*     - left_speedcontroller_TRIG_LEVEL     - Level
*     - left_speedcontroller_TRIG_RISING    - Rising edge
*     - left_speedcontroller_TRIG_FALLING   - Falling edge
*     - left_speedcontroller_TRIG_BOTH      - Both rising and falling edge
*
* Return:
*  None
*
*******************************************************************************/
void left_speedcontroller_SetCountMode(uint32 triggerMode)
{
    uint8 enableInterrupts;

    enableInterrupts = CyEnterCriticalSection();

    left_speedcontroller_TRIG_CONTROL1_REG &= (uint32)~left_speedcontroller_COUNT_MASK;
    left_speedcontroller_TRIG_CONTROL1_REG |= ((uint32)(triggerMode << left_speedcontroller_COUNT_SHIFT));

    CyExitCriticalSection(enableInterrupts);
}


/*******************************************************************************
* Function Name: left_speedcontroller_TriggerCommand
********************************************************************************
*
* Summary:
*  Triggers the designated command to occur on the designated TCPWM instances.
*  The mask can be used to apply this command simultaneously to more than one
*  instance.  This allows multiple TCPWM instances to be synchronized.
*
* Parameters:
*  mask: A combination of mask bits for each instance of the TCPWM that the
*        command should apply to.  This function from one instance can be used
*        to apply the command to any of the instances in the design.
*        The mask value for a specific instance is available with the MASK
*        define.
*  command: Enumerated command values. Capture command only applicable for
*           Timer/Counter with Capture and PWM modes.
*   Values:
*     - left_speedcontroller_CMD_CAPTURE    - Trigger Capture/Switch command
*     - left_speedcontroller_CMD_RELOAD     - Trigger Reload/Index command
*     - left_speedcontroller_CMD_STOP       - Trigger Stop/Kill command
*     - left_speedcontroller_CMD_START      - Trigger Start/phiB command
*
* Return:
*  None
*
*******************************************************************************/
void left_speedcontroller_TriggerCommand(uint32 mask, uint32 command)
{
    uint8 enableInterrupts;

    enableInterrupts = CyEnterCriticalSection();

    left_speedcontroller_COMMAND_REG = ((uint32)(mask << command));

    CyExitCriticalSection(enableInterrupts);
}


/*******************************************************************************
* Function Name: left_speedcontroller_ReadStatus
********************************************************************************
*
* Summary:
*  Reads the status of the left_speedcontroller.
*
* Parameters:
*  None
*
* Return:
*  Status
*   Values:
*     - left_speedcontroller_STATUS_DOWN    - Set if counting down
*     - left_speedcontroller_STATUS_RUNNING - Set if counter is running
*
*******************************************************************************/
uint32 left_speedcontroller_ReadStatus(void)
{
    return ((left_speedcontroller_STATUS_REG >> left_speedcontroller_RUNNING_STATUS_SHIFT) |
            (left_speedcontroller_STATUS_REG & left_speedcontroller_STATUS_DOWN));
}


/*******************************************************************************
* Function Name: left_speedcontroller_SetInterruptMode
********************************************************************************
*
* Summary:
*  Sets the interrupt mask to control which interrupt
*  requests generate the interrupt signal.
*
* Parameters:
*   interruptMask: Mask of bits to be enabled
*   Values:
*     - left_speedcontroller_INTR_MASK_TC       - Terminal count mask
*     - left_speedcontroller_INTR_MASK_CC_MATCH - Compare count / capture mask
*
* Return:
*  None
*
*******************************************************************************/
void left_speedcontroller_SetInterruptMode(uint32 interruptMask)
{
    left_speedcontroller_INTERRUPT_MASK_REG =  interruptMask;
}


/*******************************************************************************
* Function Name: left_speedcontroller_GetInterruptSourceMasked
********************************************************************************
*
* Summary:
*  Gets the interrupt requests masked by the interrupt mask.
*
* Parameters:
*   None
*
* Return:
*  Masked interrupt source
*   Values:
*     - left_speedcontroller_INTR_MASK_TC       - Terminal count mask
*     - left_speedcontroller_INTR_MASK_CC_MATCH - Compare count / capture mask
*
*******************************************************************************/
uint32 left_speedcontroller_GetInterruptSourceMasked(void)
{
    return (left_speedcontroller_INTERRUPT_MASKED_REG);
}


/*******************************************************************************
* Function Name: left_speedcontroller_GetInterruptSource
********************************************************************************
*
* Summary:
*  Gets the interrupt requests (without masking).
*
* Parameters:
*  None
*
* Return:
*  Interrupt request value
*   Values:
*     - left_speedcontroller_INTR_MASK_TC       - Terminal count mask
*     - left_speedcontroller_INTR_MASK_CC_MATCH - Compare count / capture mask
*
*******************************************************************************/
uint32 left_speedcontroller_GetInterruptSource(void)
{
    return (left_speedcontroller_INTERRUPT_REQ_REG);
}


/*******************************************************************************
* Function Name: left_speedcontroller_ClearInterrupt
********************************************************************************
*
* Summary:
*  Clears the interrupt request.
*
* Parameters:
*   interruptMask: Mask of interrupts to clear
*   Values:
*     - left_speedcontroller_INTR_MASK_TC       - Terminal count mask
*     - left_speedcontroller_INTR_MASK_CC_MATCH - Compare count / capture mask
*
* Return:
*  None
*
*******************************************************************************/
void left_speedcontroller_ClearInterrupt(uint32 interruptMask)
{
    left_speedcontroller_INTERRUPT_REQ_REG = interruptMask;
}


/*******************************************************************************
* Function Name: left_speedcontroller_SetInterrupt
********************************************************************************
*
* Summary:
*  Sets a software interrupt request.
*
* Parameters:
*   interruptMask: Mask of interrupts to set
*   Values:
*     - left_speedcontroller_INTR_MASK_TC       - Terminal count mask
*     - left_speedcontroller_INTR_MASK_CC_MATCH - Compare count / capture mask
*
* Return:
*  None
*
*******************************************************************************/
void left_speedcontroller_SetInterrupt(uint32 interruptMask)
{
    left_speedcontroller_INTERRUPT_SET_REG = interruptMask;
}


/* [] END OF FILE */
