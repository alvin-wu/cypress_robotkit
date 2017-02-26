/*******************************************************************************
* File Name: left_backward.h  
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

#if !defined(CY_PINS_left_backward_H) /* Pins left_backward_H */
#define CY_PINS_left_backward_H

#include "cytypes.h"
#include "cyfitter.h"
#include "left_backward_aliases.h"


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
} left_backward_BACKUP_STRUCT;

/** @} structures */


/***************************************
*        Function Prototypes             
***************************************/
/**
* \addtogroup group_general
* @{
*/
uint8   left_backward_Read(void);
void    left_backward_Write(uint8 value);
uint8   left_backward_ReadDataReg(void);
#if defined(left_backward__PC) || (CY_PSOC4_4200L) 
    void    left_backward_SetDriveMode(uint8 mode);
#endif
void    left_backward_SetInterruptMode(uint16 position, uint16 mode);
uint8   left_backward_ClearInterrupt(void);
/** @} general */

/**
* \addtogroup group_power
* @{
*/
void left_backward_Sleep(void); 
void left_backward_Wakeup(void);
/** @} power */


/***************************************
*           API Constants        
***************************************/
#if defined(left_backward__PC) || (CY_PSOC4_4200L) 
    /* Drive Modes */
    #define left_backward_DRIVE_MODE_BITS        (3)
    #define left_backward_DRIVE_MODE_IND_MASK    (0xFFFFFFFFu >> (32 - left_backward_DRIVE_MODE_BITS))

    /**
    * \addtogroup group_constants
    * @{
    */
        /** \addtogroup driveMode Drive mode constants
         * \brief Constants to be passed as "mode" parameter in the left_backward_SetDriveMode() function.
         *  @{
         */
        #define left_backward_DM_ALG_HIZ         (0x00u) /**< \brief High Impedance Analog   */
        #define left_backward_DM_DIG_HIZ         (0x01u) /**< \brief High Impedance Digital  */
        #define left_backward_DM_RES_UP          (0x02u) /**< \brief Resistive Pull Up       */
        #define left_backward_DM_RES_DWN         (0x03u) /**< \brief Resistive Pull Down     */
        #define left_backward_DM_OD_LO           (0x04u) /**< \brief Open Drain, Drives Low  */
        #define left_backward_DM_OD_HI           (0x05u) /**< \brief Open Drain, Drives High */
        #define left_backward_DM_STRONG          (0x06u) /**< \brief Strong Drive            */
        #define left_backward_DM_RES_UPDWN       (0x07u) /**< \brief Resistive Pull Up/Down  */
        /** @} driveMode */
    /** @} group_constants */
#endif

/* Digital Port Constants */
#define left_backward_MASK               left_backward__MASK
#define left_backward_SHIFT              left_backward__SHIFT
#define left_backward_WIDTH              1u

/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in left_backward_SetInterruptMode() function.
     *  @{
     */
        #define left_backward_INTR_NONE      ((uint16)(0x0000u)) /**< \brief Disabled             */
        #define left_backward_INTR_RISING    ((uint16)(0x5555u)) /**< \brief Rising edge trigger  */
        #define left_backward_INTR_FALLING   ((uint16)(0xaaaau)) /**< \brief Falling edge trigger */
        #define left_backward_INTR_BOTH      ((uint16)(0xffffu)) /**< \brief Both edge trigger    */
    /** @} intrMode */
/** @} group_constants */

/* SIO LPM definition */
#if defined(left_backward__SIO)
    #define left_backward_SIO_LPM_MASK       (0x03u)
#endif

/* USBIO definitions */
#if !defined(left_backward__PC) && (CY_PSOC4_4200L)
    #define left_backward_USBIO_ENABLE               ((uint32)0x80000000u)
    #define left_backward_USBIO_DISABLE              ((uint32)(~left_backward_USBIO_ENABLE))
    #define left_backward_USBIO_SUSPEND_SHIFT        CYFLD_USBDEVv2_USB_SUSPEND__OFFSET
    #define left_backward_USBIO_SUSPEND_DEL_SHIFT    CYFLD_USBDEVv2_USB_SUSPEND_DEL__OFFSET
    #define left_backward_USBIO_ENTER_SLEEP          ((uint32)((1u << left_backward_USBIO_SUSPEND_SHIFT) \
                                                        | (1u << left_backward_USBIO_SUSPEND_DEL_SHIFT)))
    #define left_backward_USBIO_EXIT_SLEEP_PH1       ((uint32)~((uint32)(1u << left_backward_USBIO_SUSPEND_SHIFT)))
    #define left_backward_USBIO_EXIT_SLEEP_PH2       ((uint32)~((uint32)(1u << left_backward_USBIO_SUSPEND_DEL_SHIFT)))
    #define left_backward_USBIO_CR1_OFF              ((uint32)0xfffffffeu)
#endif


/***************************************
*             Registers        
***************************************/
/* Main Port Registers */
#if defined(left_backward__PC)
    /* Port Configuration */
    #define left_backward_PC                 (* (reg32 *) left_backward__PC)
#endif
/* Pin State */
#define left_backward_PS                     (* (reg32 *) left_backward__PS)
/* Data Register */
#define left_backward_DR                     (* (reg32 *) left_backward__DR)
/* Input Buffer Disable Override */
#define left_backward_INP_DIS                (* (reg32 *) left_backward__PC2)

/* Interrupt configuration Registers */
#define left_backward_INTCFG                 (* (reg32 *) left_backward__INTCFG)
#define left_backward_INTSTAT                (* (reg32 *) left_backward__INTSTAT)

/* "Interrupt cause" register for Combined Port Interrupt (AllPortInt) in GSRef component */
#if defined (CYREG_GPIO_INTR_CAUSE)
    #define left_backward_INTR_CAUSE         (* (reg32 *) CYREG_GPIO_INTR_CAUSE)
#endif

/* SIO register */
#if defined(left_backward__SIO)
    #define left_backward_SIO_REG            (* (reg32 *) left_backward__SIO)
#endif /* (left_backward__SIO_CFG) */

/* USBIO registers */
#if !defined(left_backward__PC) && (CY_PSOC4_4200L)
    #define left_backward_USB_POWER_REG       (* (reg32 *) CYREG_USBDEVv2_USB_POWER_CTRL)
    #define left_backward_CR1_REG             (* (reg32 *) CYREG_USBDEVv2_CR1)
    #define left_backward_USBIO_CTRL_REG      (* (reg32 *) CYREG_USBDEVv2_USB_USBIO_CTRL)
#endif    
    
    
/***************************************
* The following code is DEPRECATED and 
* must not be used in new designs.
***************************************/
/**
* \addtogroup group_deprecated
* @{
*/
#define left_backward_DRIVE_MODE_SHIFT       (0x00u)
#define left_backward_DRIVE_MODE_MASK        (0x07u << left_backward_DRIVE_MODE_SHIFT)
/** @} deprecated */

#endif /* End Pins left_backward_H */


/* [] END OF FILE */
