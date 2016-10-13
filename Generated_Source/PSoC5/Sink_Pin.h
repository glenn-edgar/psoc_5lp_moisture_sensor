/*******************************************************************************
* File Name: Sink_Pin.h  
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

#if !defined(CY_PINS_Sink_Pin_H) /* Pins Sink_Pin_H */
#define CY_PINS_Sink_Pin_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "Sink_Pin_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 Sink_Pin__PORT == 15 && ((Sink_Pin__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    Sink_Pin_Write(uint8 value);
void    Sink_Pin_SetDriveMode(uint8 mode);
uint8   Sink_Pin_ReadDataReg(void);
uint8   Sink_Pin_Read(void);
void    Sink_Pin_SetInterruptMode(uint16 position, uint16 mode);
uint8   Sink_Pin_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the Sink_Pin_SetDriveMode() function.
     *  @{
     */
        #define Sink_Pin_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define Sink_Pin_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define Sink_Pin_DM_RES_UP          PIN_DM_RES_UP
        #define Sink_Pin_DM_RES_DWN         PIN_DM_RES_DWN
        #define Sink_Pin_DM_OD_LO           PIN_DM_OD_LO
        #define Sink_Pin_DM_OD_HI           PIN_DM_OD_HI
        #define Sink_Pin_DM_STRONG          PIN_DM_STRONG
        #define Sink_Pin_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define Sink_Pin_MASK               Sink_Pin__MASK
#define Sink_Pin_SHIFT              Sink_Pin__SHIFT
#define Sink_Pin_WIDTH              1u

/* Interrupt constants */
#if defined(Sink_Pin__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in Sink_Pin_SetInterruptMode() function.
     *  @{
     */
        #define Sink_Pin_INTR_NONE      (uint16)(0x0000u)
        #define Sink_Pin_INTR_RISING    (uint16)(0x0001u)
        #define Sink_Pin_INTR_FALLING   (uint16)(0x0002u)
        #define Sink_Pin_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define Sink_Pin_INTR_MASK      (0x01u) 
#endif /* (Sink_Pin__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define Sink_Pin_PS                     (* (reg8 *) Sink_Pin__PS)
/* Data Register */
#define Sink_Pin_DR                     (* (reg8 *) Sink_Pin__DR)
/* Port Number */
#define Sink_Pin_PRT_NUM                (* (reg8 *) Sink_Pin__PRT) 
/* Connect to Analog Globals */                                                  
#define Sink_Pin_AG                     (* (reg8 *) Sink_Pin__AG)                       
/* Analog MUX bux enable */
#define Sink_Pin_AMUX                   (* (reg8 *) Sink_Pin__AMUX) 
/* Bidirectional Enable */                                                        
#define Sink_Pin_BIE                    (* (reg8 *) Sink_Pin__BIE)
/* Bit-mask for Aliased Register Access */
#define Sink_Pin_BIT_MASK               (* (reg8 *) Sink_Pin__BIT_MASK)
/* Bypass Enable */
#define Sink_Pin_BYP                    (* (reg8 *) Sink_Pin__BYP)
/* Port wide control signals */                                                   
#define Sink_Pin_CTL                    (* (reg8 *) Sink_Pin__CTL)
/* Drive Modes */
#define Sink_Pin_DM0                    (* (reg8 *) Sink_Pin__DM0) 
#define Sink_Pin_DM1                    (* (reg8 *) Sink_Pin__DM1)
#define Sink_Pin_DM2                    (* (reg8 *) Sink_Pin__DM2) 
/* Input Buffer Disable Override */
#define Sink_Pin_INP_DIS                (* (reg8 *) Sink_Pin__INP_DIS)
/* LCD Common or Segment Drive */
#define Sink_Pin_LCD_COM_SEG            (* (reg8 *) Sink_Pin__LCD_COM_SEG)
/* Enable Segment LCD */
#define Sink_Pin_LCD_EN                 (* (reg8 *) Sink_Pin__LCD_EN)
/* Slew Rate Control */
#define Sink_Pin_SLW                    (* (reg8 *) Sink_Pin__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define Sink_Pin_PRTDSI__CAPS_SEL       (* (reg8 *) Sink_Pin__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define Sink_Pin_PRTDSI__DBL_SYNC_IN    (* (reg8 *) Sink_Pin__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define Sink_Pin_PRTDSI__OE_SEL0        (* (reg8 *) Sink_Pin__PRTDSI__OE_SEL0) 
#define Sink_Pin_PRTDSI__OE_SEL1        (* (reg8 *) Sink_Pin__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define Sink_Pin_PRTDSI__OUT_SEL0       (* (reg8 *) Sink_Pin__PRTDSI__OUT_SEL0) 
#define Sink_Pin_PRTDSI__OUT_SEL1       (* (reg8 *) Sink_Pin__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define Sink_Pin_PRTDSI__SYNC_OUT       (* (reg8 *) Sink_Pin__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(Sink_Pin__SIO_CFG)
    #define Sink_Pin_SIO_HYST_EN        (* (reg8 *) Sink_Pin__SIO_HYST_EN)
    #define Sink_Pin_SIO_REG_HIFREQ     (* (reg8 *) Sink_Pin__SIO_REG_HIFREQ)
    #define Sink_Pin_SIO_CFG            (* (reg8 *) Sink_Pin__SIO_CFG)
    #define Sink_Pin_SIO_DIFF           (* (reg8 *) Sink_Pin__SIO_DIFF)
#endif /* (Sink_Pin__SIO_CFG) */

/* Interrupt Registers */
#if defined(Sink_Pin__INTSTAT)
    #define Sink_Pin_INTSTAT            (* (reg8 *) Sink_Pin__INTSTAT)
    #define Sink_Pin_SNAP               (* (reg8 *) Sink_Pin__SNAP)
    
	#define Sink_Pin_0_INTTYPE_REG 		(* (reg8 *) Sink_Pin__0__INTTYPE)
#endif /* (Sink_Pin__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_Sink_Pin_H */


/* [] END OF FILE */
