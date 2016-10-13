/*******************************************************************************
* File Name: Filter_Pressure_Low.h  
* Version 2.20
*
* Description:
*  This file contains Pin function prototypes and register defines
*
* Note:
*
********************************************************************************
* Copyright 2008-2015, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(CY_PINS_Filter_Pressure_Low_H) /* Pins Filter_Pressure_Low_H */
#define CY_PINS_Filter_Pressure_Low_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "Filter_Pressure_Low_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 Filter_Pressure_Low__PORT == 15 && ((Filter_Pressure_Low__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    Filter_Pressure_Low_Write(uint8 value);
void    Filter_Pressure_Low_SetDriveMode(uint8 mode);
uint8   Filter_Pressure_Low_ReadDataReg(void);
uint8   Filter_Pressure_Low_Read(void);
void    Filter_Pressure_Low_SetInterruptMode(uint16 position, uint16 mode);
uint8   Filter_Pressure_Low_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the Filter_Pressure_Low_SetDriveMode() function.
     *  @{
     */
        #define Filter_Pressure_Low_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define Filter_Pressure_Low_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define Filter_Pressure_Low_DM_RES_UP          PIN_DM_RES_UP
        #define Filter_Pressure_Low_DM_RES_DWN         PIN_DM_RES_DWN
        #define Filter_Pressure_Low_DM_OD_LO           PIN_DM_OD_LO
        #define Filter_Pressure_Low_DM_OD_HI           PIN_DM_OD_HI
        #define Filter_Pressure_Low_DM_STRONG          PIN_DM_STRONG
        #define Filter_Pressure_Low_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define Filter_Pressure_Low_MASK               Filter_Pressure_Low__MASK
#define Filter_Pressure_Low_SHIFT              Filter_Pressure_Low__SHIFT
#define Filter_Pressure_Low_WIDTH              1u

/* Interrupt constants */
#if defined(Filter_Pressure_Low__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in Filter_Pressure_Low_SetInterruptMode() function.
     *  @{
     */
        #define Filter_Pressure_Low_INTR_NONE      (uint16)(0x0000u)
        #define Filter_Pressure_Low_INTR_RISING    (uint16)(0x0001u)
        #define Filter_Pressure_Low_INTR_FALLING   (uint16)(0x0002u)
        #define Filter_Pressure_Low_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define Filter_Pressure_Low_INTR_MASK      (0x01u) 
#endif /* (Filter_Pressure_Low__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define Filter_Pressure_Low_PS                     (* (reg8 *) Filter_Pressure_Low__PS)
/* Data Register */
#define Filter_Pressure_Low_DR                     (* (reg8 *) Filter_Pressure_Low__DR)
/* Port Number */
#define Filter_Pressure_Low_PRT_NUM                (* (reg8 *) Filter_Pressure_Low__PRT) 
/* Connect to Analog Globals */                                                  
#define Filter_Pressure_Low_AG                     (* (reg8 *) Filter_Pressure_Low__AG)                       
/* Analog MUX bux enable */
#define Filter_Pressure_Low_AMUX                   (* (reg8 *) Filter_Pressure_Low__AMUX) 
/* Bidirectional Enable */                                                        
#define Filter_Pressure_Low_BIE                    (* (reg8 *) Filter_Pressure_Low__BIE)
/* Bit-mask for Aliased Register Access */
#define Filter_Pressure_Low_BIT_MASK               (* (reg8 *) Filter_Pressure_Low__BIT_MASK)
/* Bypass Enable */
#define Filter_Pressure_Low_BYP                    (* (reg8 *) Filter_Pressure_Low__BYP)
/* Port wide control signals */                                                   
#define Filter_Pressure_Low_CTL                    (* (reg8 *) Filter_Pressure_Low__CTL)
/* Drive Modes */
#define Filter_Pressure_Low_DM0                    (* (reg8 *) Filter_Pressure_Low__DM0) 
#define Filter_Pressure_Low_DM1                    (* (reg8 *) Filter_Pressure_Low__DM1)
#define Filter_Pressure_Low_DM2                    (* (reg8 *) Filter_Pressure_Low__DM2) 
/* Input Buffer Disable Override */
#define Filter_Pressure_Low_INP_DIS                (* (reg8 *) Filter_Pressure_Low__INP_DIS)
/* LCD Common or Segment Drive */
#define Filter_Pressure_Low_LCD_COM_SEG            (* (reg8 *) Filter_Pressure_Low__LCD_COM_SEG)
/* Enable Segment LCD */
#define Filter_Pressure_Low_LCD_EN                 (* (reg8 *) Filter_Pressure_Low__LCD_EN)
/* Slew Rate Control */
#define Filter_Pressure_Low_SLW                    (* (reg8 *) Filter_Pressure_Low__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define Filter_Pressure_Low_PRTDSI__CAPS_SEL       (* (reg8 *) Filter_Pressure_Low__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define Filter_Pressure_Low_PRTDSI__DBL_SYNC_IN    (* (reg8 *) Filter_Pressure_Low__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define Filter_Pressure_Low_PRTDSI__OE_SEL0        (* (reg8 *) Filter_Pressure_Low__PRTDSI__OE_SEL0) 
#define Filter_Pressure_Low_PRTDSI__OE_SEL1        (* (reg8 *) Filter_Pressure_Low__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define Filter_Pressure_Low_PRTDSI__OUT_SEL0       (* (reg8 *) Filter_Pressure_Low__PRTDSI__OUT_SEL0) 
#define Filter_Pressure_Low_PRTDSI__OUT_SEL1       (* (reg8 *) Filter_Pressure_Low__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define Filter_Pressure_Low_PRTDSI__SYNC_OUT       (* (reg8 *) Filter_Pressure_Low__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(Filter_Pressure_Low__SIO_CFG)
    #define Filter_Pressure_Low_SIO_HYST_EN        (* (reg8 *) Filter_Pressure_Low__SIO_HYST_EN)
    #define Filter_Pressure_Low_SIO_REG_HIFREQ     (* (reg8 *) Filter_Pressure_Low__SIO_REG_HIFREQ)
    #define Filter_Pressure_Low_SIO_CFG            (* (reg8 *) Filter_Pressure_Low__SIO_CFG)
    #define Filter_Pressure_Low_SIO_DIFF           (* (reg8 *) Filter_Pressure_Low__SIO_DIFF)
#endif /* (Filter_Pressure_Low__SIO_CFG) */

/* Interrupt Registers */
#if defined(Filter_Pressure_Low__INTSTAT)
    #define Filter_Pressure_Low_INTSTAT            (* (reg8 *) Filter_Pressure_Low__INTSTAT)
    #define Filter_Pressure_Low_SNAP               (* (reg8 *) Filter_Pressure_Low__SNAP)
    
	#define Filter_Pressure_Low_0_INTTYPE_REG 		(* (reg8 *) Filter_Pressure_Low__0__INTTYPE)
#endif /* (Filter_Pressure_Low__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_Filter_Pressure_Low_H */


/* [] END OF FILE */
