/*******************************************************************************
* File Name: IR_pin2.h  
* Version 2.20
*
* Description:
*  This file contains Pin function prototypes and register defines
*
********************************************************************************
* Copyright 2008-2015, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(CY_PINS_IR_pin2_H) /* Pins IR_pin2_H */
#define CY_PINS_IR_pin2_H

#include "cytypes.h"
#include "cyfitter.h"
#include "IR_pin2_aliases.h"


/***************************************
*     Data Struct Definitions
***************************************/

/**
* \addtogroup group_structures
* @{
*/
    
/* Structure for sleep mode support */
typedef struct
{
    uint32 pcState; /**< State of the port control register */
    uint32 sioState; /**< State of the SIO configuration */
    uint32 usbState; /**< State of the USBIO regulator */
} IR_pin2_BACKUP_STRUCT;

/** @} structures */


/***************************************
*        Function Prototypes             
***************************************/
/**
* \addtogroup group_general
* @{
*/
uint8   IR_pin2_Read(void);
void    IR_pin2_Write(uint8 value);
uint8   IR_pin2_ReadDataReg(void);
#if defined(IR_pin2__PC) || (CY_PSOC4_4200L) 
    void    IR_pin2_SetDriveMode(uint8 mode);
#endif
void    IR_pin2_SetInterruptMode(uint16 position, uint16 mode);
uint8   IR_pin2_ClearInterrupt(void);
/** @} general */

/**
* \addtogroup group_power
* @{
*/
void IR_pin2_Sleep(void); 
void IR_pin2_Wakeup(void);
/** @} power */


/***************************************
*           API Constants        
***************************************/
#if defined(IR_pin2__PC) || (CY_PSOC4_4200L) 
    /* Drive Modes */
    #define IR_pin2_DRIVE_MODE_BITS        (3)
    #define IR_pin2_DRIVE_MODE_IND_MASK    (0xFFFFFFFFu >> (32 - IR_pin2_DRIVE_MODE_BITS))

    /**
    * \addtogroup group_constants
    * @{
    */
        /** \addtogroup driveMode Drive mode constants
         * \brief Constants to be passed as "mode" parameter in the IR_pin2_SetDriveMode() function.
         *  @{
         */
        #define IR_pin2_DM_ALG_HIZ         (0x00u) /**< \brief High Impedance Analog   */
        #define IR_pin2_DM_DIG_HIZ         (0x01u) /**< \brief High Impedance Digital  */
        #define IR_pin2_DM_RES_UP          (0x02u) /**< \brief Resistive Pull Up       */
        #define IR_pin2_DM_RES_DWN         (0x03u) /**< \brief Resistive Pull Down     */
        #define IR_pin2_DM_OD_LO           (0x04u) /**< \brief Open Drain, Drives Low  */
        #define IR_pin2_DM_OD_HI           (0x05u) /**< \brief Open Drain, Drives High */
        #define IR_pin2_DM_STRONG          (0x06u) /**< \brief Strong Drive            */
        #define IR_pin2_DM_RES_UPDWN       (0x07u) /**< \brief Resistive Pull Up/Down  */
        /** @} driveMode */
    /** @} group_constants */
#endif

/* Digital Port Constants */
#define IR_pin2_MASK               IR_pin2__MASK
#define IR_pin2_SHIFT              IR_pin2__SHIFT
#define IR_pin2_WIDTH              1u

/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in IR_pin2_SetInterruptMode() function.
     *  @{
     */
        #define IR_pin2_INTR_NONE      ((uint16)(0x0000u)) /**< \brief Disabled             */
        #define IR_pin2_INTR_RISING    ((uint16)(0x5555u)) /**< \brief Rising edge trigger  */
        #define IR_pin2_INTR_FALLING   ((uint16)(0xaaaau)) /**< \brief Falling edge trigger */
        #define IR_pin2_INTR_BOTH      ((uint16)(0xffffu)) /**< \brief Both edge trigger    */
    /** @} intrMode */
/** @} group_constants */

/* SIO LPM definition */
#if defined(IR_pin2__SIO)
    #define IR_pin2_SIO_LPM_MASK       (0x03u)
#endif

/* USBIO definitions */
#if !defined(IR_pin2__PC) && (CY_PSOC4_4200L)
    #define IR_pin2_USBIO_ENABLE               ((uint32)0x80000000u)
    #define IR_pin2_USBIO_DISABLE              ((uint32)(~IR_pin2_USBIO_ENABLE))
    #define IR_pin2_USBIO_SUSPEND_SHIFT        CYFLD_USBDEVv2_USB_SUSPEND__OFFSET
    #define IR_pin2_USBIO_SUSPEND_DEL_SHIFT    CYFLD_USBDEVv2_USB_SUSPEND_DEL__OFFSET
    #define IR_pin2_USBIO_ENTER_SLEEP          ((uint32)((1u << IR_pin2_USBIO_SUSPEND_SHIFT) \
                                                        | (1u << IR_pin2_USBIO_SUSPEND_DEL_SHIFT)))
    #define IR_pin2_USBIO_EXIT_SLEEP_PH1       ((uint32)~((uint32)(1u << IR_pin2_USBIO_SUSPEND_SHIFT)))
    #define IR_pin2_USBIO_EXIT_SLEEP_PH2       ((uint32)~((uint32)(1u << IR_pin2_USBIO_SUSPEND_DEL_SHIFT)))
    #define IR_pin2_USBIO_CR1_OFF              ((uint32)0xfffffffeu)
#endif


/***************************************
*             Registers        
***************************************/
/* Main Port Registers */
#if defined(IR_pin2__PC)
    /* Port Configuration */
    #define IR_pin2_PC                 (* (reg32 *) IR_pin2__PC)
#endif
/* Pin State */
#define IR_pin2_PS                     (* (reg32 *) IR_pin2__PS)
/* Data Register */
#define IR_pin2_DR                     (* (reg32 *) IR_pin2__DR)
/* Input Buffer Disable Override */
#define IR_pin2_INP_DIS                (* (reg32 *) IR_pin2__PC2)

/* Interrupt configuration Registers */
#define IR_pin2_INTCFG                 (* (reg32 *) IR_pin2__INTCFG)
#define IR_pin2_INTSTAT                (* (reg32 *) IR_pin2__INTSTAT)

/* "Interrupt cause" register for Combined Port Interrupt (AllPortInt) in GSRef component */
#if defined (CYREG_GPIO_INTR_CAUSE)
    #define IR_pin2_INTR_CAUSE         (* (reg32 *) CYREG_GPIO_INTR_CAUSE)
#endif

/* SIO register */
#if defined(IR_pin2__SIO)
    #define IR_pin2_SIO_REG            (* (reg32 *) IR_pin2__SIO)
#endif /* (IR_pin2__SIO_CFG) */

/* USBIO registers */
#if !defined(IR_pin2__PC) && (CY_PSOC4_4200L)
    #define IR_pin2_USB_POWER_REG       (* (reg32 *) CYREG_USBDEVv2_USB_POWER_CTRL)
    #define IR_pin2_CR1_REG             (* (reg32 *) CYREG_USBDEVv2_CR1)
    #define IR_pin2_USBIO_CTRL_REG      (* (reg32 *) CYREG_USBDEVv2_USB_USBIO_CTRL)
#endif    
    
    
/***************************************
* The following code is DEPRECATED and 
* must not be used in new designs.
***************************************/
/**
* \addtogroup group_deprecated
* @{
*/
#define IR_pin2_DRIVE_MODE_SHIFT       (0x00u)
#define IR_pin2_DRIVE_MODE_MASK        (0x07u << IR_pin2_DRIVE_MODE_SHIFT)
/** @} deprecated */

#endif /* End Pins IR_pin2_H */


/* [] END OF FILE */
