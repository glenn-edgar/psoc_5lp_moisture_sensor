/*******************************************************************************
* File Name: filter_pressure.h  
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

#if !defined(CY_PINS_filter_pressure_H) /* Pins filter_pressure_H */
#define CY_PINS_filter_pressure_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "filter_pressure_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 filter_pressure__PORT == 15 && ((filter_pressure__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    filter_pressure_Write(uint8 value);
void    filter_pressure_SetDriveMode(uint8 mode);
uint8   filter_pressure_ReadDataReg(void);
uint8   filter_pressure_Read(void);
void    filter_pressure_SetInterruptMode(uint16 position, uint16 mode);
uint8   filter_pressure_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the filter_pressure_SetDriveMode() function.
     *  @{
     */
        #define filter_pressure_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define filter_pressure_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define filter_pressure_DM_RES_UP          PIN_DM_RES_UP
        #define filter_pressure_DM_RES_DWN         PIN_DM_RES_DWN
        #define filter_pressure_DM_OD_LO           PIN_DM_OD_LO
        #define filter_pressure_DM_OD_HI           PIN_DM_OD_HI
        #define filter_pressure_DM_STRONG          PIN_DM_STRONG
        #define filter_pressure_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define filter_pressure_MASK               filter_pressure__MASK
#define filter_pressure_SHIFT              filter_pressure__SHIFT
#define filter_pressure_WIDTH              1u

/* Interrupt constants */
#if defined(filter_pressure__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in filter_pressure_SetInterruptMode() function.
     *  @{
     */
        #define filter_pressure_INTR_NONE      (uint16)(0x0000u)
        #define filter_pressure_INTR_RISING    (uint16)(0x0001u)
        #define filter_pressure_INTR_FALLING   (uint16)(0x0002u)
        #define filter_pressure_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define filter_pressure_INTR_MASK      (0x01u) 
#endif /* (filter_pressure__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define filter_pressure_PS                     (* (reg8 *) filter_pressure__PS)
/* Data Register */
#define filter_pressure_DR                     (* (reg8 *) filter_pressure__DR)
/* Port Number */
#define filter_pressure_PRT_NUM                (* (reg8 *) filter_pressure__PRT) 
/* Connect to Analog Globals */                                                  
#define filter_pressure_AG                     (* (reg8 *) filter_pressure__AG)                       
/* Analog MUX bux enable */
#define filter_pressure_AMUX                   (* (reg8 *) filter_pressure__AMUX) 
/* Bidirectional Enable */                                                        
#define filter_pressure_BIE                    (* (reg8 *) filter_pressure__BIE)
/* Bit-mask for Aliased Register Access */
#define filter_pressure_BIT_MASK               (* (reg8 *) filter_pressure__BIT_MASK)
/* Bypass Enable */
#define filter_pressure_BYP                    (* (reg8 *) filter_pressure__BYP)
/* Port wide control signals */                                                   
#define filter_pressure_CTL                    (* (reg8 *) filter_pressure__CTL)
/* Drive Modes */
#define filter_pressure_DM0                    (* (reg8 *) filter_pressure__DM0) 
#define filter_pressure_DM1                    (* (reg8 *) filter_pressure__DM1)
#define filter_pressure_DM2                    (* (reg8 *) filter_pressure__DM2) 
/* Input Buffer Disable Override */
#define filter_pressure_INP_DIS                (* (reg8 *) filter_pressure__INP_DIS)
/* LCD Common or Segment Drive */
#define filter_pressure_LCD_COM_SEG            (* (reg8 *) filter_pressure__LCD_COM_SEG)
/* Enable Segment LCD */
#define filter_pressure_LCD_EN                 (* (reg8 *) filter_pressure__LCD_EN)
/* Slew Rate Control */
#define filter_pressure_SLW                    (* (reg8 *) filter_pressure__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define filter_pressure_PRTDSI__CAPS_SEL       (* (reg8 *) filter_pressure__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define filter_pressure_PRTDSI__DBL_SYNC_IN    (* (reg8 *) filter_pressure__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define filter_pressure_PRTDSI__OE_SEL0        (* (reg8 *) filter_pressure__PRTDSI__OE_SEL0) 
#define filter_pressure_PRTDSI__OE_SEL1        (* (reg8 *) filter_pressure__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define filter_pressure_PRTDSI__OUT_SEL0       (* (reg8 *) filter_pressure__PRTDSI__OUT_SEL0) 
#define filter_pressure_PRTDSI__OUT_SEL1       (* (reg8 *) filter_pressure__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define filter_pressure_PRTDSI__SYNC_OUT       (* (reg8 *) filter_pressure__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(filter_pressure__SIO_CFG)
    #define filter_pressure_SIO_HYST_EN        (* (reg8 *) filter_pressure__SIO_HYST_EN)
    #define filter_pressure_SIO_REG_HIFREQ     (* (reg8 *) filter_pressure__SIO_REG_HIFREQ)
    #define filter_pressure_SIO_CFG            (* (reg8 *) filter_pressure__SIO_CFG)
    #define filter_pressure_SIO_DIFF           (* (reg8 *) filter_pressure__SIO_DIFF)
#endif /* (filter_pressure__SIO_CFG) */

/* Interrupt Registers */
#if defined(filter_pressure__INTSTAT)
    #define filter_pressure_INTSTAT            (* (reg8 *) filter_pressure__INTSTAT)
    #define filter_pressure_SNAP               (* (reg8 *) filter_pressure__SNAP)
    
	#define filter_pressure_0_INTTYPE_REG 		(* (reg8 *) filter_pressure__0__INTTYPE)
#endif /* (filter_pressure__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_filter_pressure_H */


/* [] END OF FILE */
