/*******************************************************************************
* File Name: Temp_Sensor.h  
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

#if !defined(CY_PINS_Temp_Sensor_H) /* Pins Temp_Sensor_H */
#define CY_PINS_Temp_Sensor_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "Temp_Sensor_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 Temp_Sensor__PORT == 15 && ((Temp_Sensor__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    Temp_Sensor_Write(uint8 value);
void    Temp_Sensor_SetDriveMode(uint8 mode);
uint8   Temp_Sensor_ReadDataReg(void);
uint8   Temp_Sensor_Read(void);
void    Temp_Sensor_SetInterruptMode(uint16 position, uint16 mode);
uint8   Temp_Sensor_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the Temp_Sensor_SetDriveMode() function.
     *  @{
     */
        #define Temp_Sensor_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define Temp_Sensor_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define Temp_Sensor_DM_RES_UP          PIN_DM_RES_UP
        #define Temp_Sensor_DM_RES_DWN         PIN_DM_RES_DWN
        #define Temp_Sensor_DM_OD_LO           PIN_DM_OD_LO
        #define Temp_Sensor_DM_OD_HI           PIN_DM_OD_HI
        #define Temp_Sensor_DM_STRONG          PIN_DM_STRONG
        #define Temp_Sensor_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define Temp_Sensor_MASK               Temp_Sensor__MASK
#define Temp_Sensor_SHIFT              Temp_Sensor__SHIFT
#define Temp_Sensor_WIDTH              1u

/* Interrupt constants */
#if defined(Temp_Sensor__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in Temp_Sensor_SetInterruptMode() function.
     *  @{
     */
        #define Temp_Sensor_INTR_NONE      (uint16)(0x0000u)
        #define Temp_Sensor_INTR_RISING    (uint16)(0x0001u)
        #define Temp_Sensor_INTR_FALLING   (uint16)(0x0002u)
        #define Temp_Sensor_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define Temp_Sensor_INTR_MASK      (0x01u) 
#endif /* (Temp_Sensor__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define Temp_Sensor_PS                     (* (reg8 *) Temp_Sensor__PS)
/* Data Register */
#define Temp_Sensor_DR                     (* (reg8 *) Temp_Sensor__DR)
/* Port Number */
#define Temp_Sensor_PRT_NUM                (* (reg8 *) Temp_Sensor__PRT) 
/* Connect to Analog Globals */                                                  
#define Temp_Sensor_AG                     (* (reg8 *) Temp_Sensor__AG)                       
/* Analog MUX bux enable */
#define Temp_Sensor_AMUX                   (* (reg8 *) Temp_Sensor__AMUX) 
/* Bidirectional Enable */                                                        
#define Temp_Sensor_BIE                    (* (reg8 *) Temp_Sensor__BIE)
/* Bit-mask for Aliased Register Access */
#define Temp_Sensor_BIT_MASK               (* (reg8 *) Temp_Sensor__BIT_MASK)
/* Bypass Enable */
#define Temp_Sensor_BYP                    (* (reg8 *) Temp_Sensor__BYP)
/* Port wide control signals */                                                   
#define Temp_Sensor_CTL                    (* (reg8 *) Temp_Sensor__CTL)
/* Drive Modes */
#define Temp_Sensor_DM0                    (* (reg8 *) Temp_Sensor__DM0) 
#define Temp_Sensor_DM1                    (* (reg8 *) Temp_Sensor__DM1)
#define Temp_Sensor_DM2                    (* (reg8 *) Temp_Sensor__DM2) 
/* Input Buffer Disable Override */
#define Temp_Sensor_INP_DIS                (* (reg8 *) Temp_Sensor__INP_DIS)
/* LCD Common or Segment Drive */
#define Temp_Sensor_LCD_COM_SEG            (* (reg8 *) Temp_Sensor__LCD_COM_SEG)
/* Enable Segment LCD */
#define Temp_Sensor_LCD_EN                 (* (reg8 *) Temp_Sensor__LCD_EN)
/* Slew Rate Control */
#define Temp_Sensor_SLW                    (* (reg8 *) Temp_Sensor__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define Temp_Sensor_PRTDSI__CAPS_SEL       (* (reg8 *) Temp_Sensor__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define Temp_Sensor_PRTDSI__DBL_SYNC_IN    (* (reg8 *) Temp_Sensor__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define Temp_Sensor_PRTDSI__OE_SEL0        (* (reg8 *) Temp_Sensor__PRTDSI__OE_SEL0) 
#define Temp_Sensor_PRTDSI__OE_SEL1        (* (reg8 *) Temp_Sensor__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define Temp_Sensor_PRTDSI__OUT_SEL0       (* (reg8 *) Temp_Sensor__PRTDSI__OUT_SEL0) 
#define Temp_Sensor_PRTDSI__OUT_SEL1       (* (reg8 *) Temp_Sensor__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define Temp_Sensor_PRTDSI__SYNC_OUT       (* (reg8 *) Temp_Sensor__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(Temp_Sensor__SIO_CFG)
    #define Temp_Sensor_SIO_HYST_EN        (* (reg8 *) Temp_Sensor__SIO_HYST_EN)
    #define Temp_Sensor_SIO_REG_HIFREQ     (* (reg8 *) Temp_Sensor__SIO_REG_HIFREQ)
    #define Temp_Sensor_SIO_CFG            (* (reg8 *) Temp_Sensor__SIO_CFG)
    #define Temp_Sensor_SIO_DIFF           (* (reg8 *) Temp_Sensor__SIO_DIFF)
#endif /* (Temp_Sensor__SIO_CFG) */

/* Interrupt Registers */
#if defined(Temp_Sensor__INTSTAT)
    #define Temp_Sensor_INTSTAT            (* (reg8 *) Temp_Sensor__INTSTAT)
    #define Temp_Sensor_SNAP               (* (reg8 *) Temp_Sensor__SNAP)
    
	#define Temp_Sensor_0_INTTYPE_REG 		(* (reg8 *) Temp_Sensor__0__INTTYPE)
#endif /* (Temp_Sensor__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_Temp_Sensor_H */


/* [] END OF FILE */
