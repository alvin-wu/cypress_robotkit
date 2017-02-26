/*******************************************************************************
* File Name: right_forward.h  
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

#if !defined(CY_PINS_right_forward_H) /* Pins right_forward_H */
#define CY_PINS_right_forward_H

#include "cytypes.h"
#include "cyfitter.h"
#include "right_forward_aliases.h"


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
} right_forward_BACKUP_STRUCT;

/** @} structures */


/***************************************
*        Function Prototypes             
***************************************/
/**
* \addtogroup group_general
* @{
*/
uint8   right_forward_Read(void);
void    right_forward_Write(uint8 value);
uint8   right_forward_ReadDataReg(void);
#if defined(right_forward__PC) || (CY_PSOC4_4200L) 
    void    right_forward_SetDriveMode(uint8 mode);
#endif
void    right_forward_SetInterruptMode(uint16 position, uint16 mode);
uint8   right_forward_ClearInterrupt(void);
/** @} general */

/**
* \addtogroup group_power
* @{
*/
void right_forward_Sleep(void); 
void right_forward_Wakeup(void);
/** @} power */


/***************************************
*           API Constants        
***************************************/
#if defined(right_forward__PC) || (CY_PSOC4_4200L) 
    /* Drive Modes */
    #define right_forward_DRIVE_MODE_BITS        (3)
    #define right_forward_DRIVE_MODE_IND_MASK    (0xFFFFFFFFu >> (32 - right_forward_DRIVE_MODE_BITS))

    /**
    * \addtogroup group_constants
    * @{
    */
        /** \addtogroup driveMode Drive mode constants
         * \brief Constants to be passed as "mode" parameter in the right_forward_SetDriveMode() function.
         *  @{
         */
        #define right_forward_DM_ALG_HIZ         (0x00u) /**< \brief High Impedance Analog   */
        #define right_forward_DM_DIG_HIZ         (0x01u) /**< \brief High Impedance Digital  */
        #define right_forward_DM_RES_UP          (0x02u) /**< \brief Resistive Pull Up       */
        #define right_forward_DM_RES_DWN         (0x03u) /**< \brief Resistive Pull Down     */
        #define right_forward_DM_OD_LO           (0x04u) /**< \brief Open Drain, Drives Low  */
        #define right_forward_DM_OD_HI           (0x05u) /**< \brief Open Drain, Drives High */
        #define right_forward_DM_STRONG          (0x06u) /**< \brief Strong Drive            */
        #define right_forward_DM_RES_UPDWN       (0x07u) /**< \brief Resistive Pull Up/Down  */
        /** @} driveMode */
    /** @} group_constants */
#endif

/* Digital Port Constants */
#define right_forward_MASK               right_forward__MASK
#define right_forward_SHIFT              right_forward__SHIFT
#define right_forward_WIDTH              1u

/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in right_forward_SetInterruptMode() function.
     *  @{
     */
        #define right_forward_INTR_NONE      ((uint16)(0x0000u)) /**< \brief Disabled             */
        #define right_forward_INTR_RISING    ((uint16)(0x5555u)) /**< \brief Rising edge trigger  */
        #define right_forward_INTR_FALLING   ((uint16)(0xaaaau)) /**< \brief Falling edge trigger */
        #define right_forward_INTR_BOTH      ((uint16)(0xffffu)) /**< \brief Both edge trigger    */
    /** @} intrMode */
/** @} group_constants */

/* SIO LPM definition */
#if defined(right_forward__SIO)
    #define right_forward_SIO_LPM_MASK       (0x03u)
#endif

/* USBIO definitions */
#if !defined(right_forward__PC) && (CY_PSOC4_4200L)
    #define right_forward_USBIO_ENABLE               ((uint32)0x80000000u)
    #define right_forward_USBIO_DISABLE              ((uint32)(~right_forward_USBIO_ENABLE))
    #define right_forward_USBIO_SUSPEND_SHIFT        CYFLD_USBDEVv2_USB_SUSPEND__OFFSET
    #define right_forward_USBIO_SUSPEND_DEL_SHIFT    CYFLD_USBDEVv2_USB_SUSPEND_DEL__OFFSET
    #define right_forward_USBIO_ENTER_SLEEP          ((uint32)((1u << right_forward_USBIO_SUSPEND_SHIFT) \
                                                        | (1u << right_forward_USBIO_SUSPEND_DEL_SHIFT)))
    #define right_forward_USBIO_EXIT_SLEEP_PH1       ((uint32)~((uint32)(1u << right_forward_USBIO_SUSPEND_SHIFT)))
    #define right_forward_USBIO_EXIT_SLEEP_PH2       ((uint32)~((uint32)(1u << right_forward_USBIO_SUSPEND_DEL_SHIFT)))
    #define right_forward_USBIO_CR1_OFF              ((uint32)0xfffffffeu)
#endif


/***************************************
*             Registers        
***************************************/
/* Main Port Registers */
#if defined(right_forward__PC)
    /* Port Configuration */
    #define right_forward_PC                 (* (reg32 *) right_forward__PC)
#endif
/* Pin State */
#define right_forward_PS                     (* (reg32 *) right_forward__PS)
/* Data Register */
#define right_forward_DR                     (* (reg32 *) right_forward__DR)
/* Input Buffer Disable Override */
#define right_forward_INP_DIS                (* (reg32 *) right_forward__PC2)

/* Interrupt configuration Registers */
#define right_forward_INTCFG                 (* (reg32 *) right_forward__INTCFG)
#define right_forward_INTSTAT                (* (reg32 *) right_forward__INTSTAT)

/* "Interrupt cause" register for Combined Port Interrupt (AllPortInt) in GSRef component */
#if defined (CYREG_GPIO_INTR_CAUSE)
    #define right_forward_INTR_CAUSE         (* (reg32 *) CYREG_GPIO_INTR_CAUSE)
#endif

/* SIO register */
#if defined(right_forward__SIO)
    #define right_forward_SIO_REG            (* (reg32 *) right_forward__SIO)
#endif /* (right_forward__SIO_CFG) */

/* USBIO registers */
#if !defined(right_forward__PC) && (CY_PSOC4_4200L)
    #define right_forward_USB_POWER_REG       (* (reg32 *) CYREG_USBDEVv2_USB_POWER_CTRL)
    #define right_forward_CR1_REG             (* (reg32 *) CYREG_USBDEVv2_CR1)
    #define right_forward_USBIO_CTRL_REG      (* (reg32 *) CYREG_USBDEVv2_USB_USBIO_CTRL)
#endif    
    
    
/***************************************
* The following code is DEPRECATED and 
* must not be used in new designs.
***************************************/
/**
* \addtogroup group_deprecated
* @{
*/
#define right_forward_DRIVE_MODE_SHIFT       (0x00u)
#define right_forward_DRIVE_MODE_MASK        (0x07u << right_forward_DRIVE_MODE_SHIFT)
/** @} deprecated */

#endif /* End Pins right_forward_H */


/* [] END OF FILE */
