/*******************************************************************************
* File Name: SWITCH_CLOCK.h
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

#if !defined(CY_CLOCK_SWITCH_CLOCK_H)
#define CY_CLOCK_SWITCH_CLOCK_H

#include <cytypes.h>
#include <cyfitter.h>


/***************************************
* Conditional Compilation Parameters
***************************************/

/* Check to see if required defines such as CY_PSOC5LP are available */
/* They are defined starting with cy_boot v3.0 */
#if !defined (CY_PSOC5LP)
    #error Component cy_clock_v2_20 requires cy_boot v3.0 or later
#endif /* (CY_PSOC5LP) */


/***************************************
*        Function Prototypes
***************************************/

void SWITCH_CLOCK_Start(void) ;
void SWITCH_CLOCK_Stop(void) ;

#if(CY_PSOC3 || CY_PSOC5LP)
void SWITCH_CLOCK_StopBlock(void) ;
#endif /* (CY_PSOC3 || CY_PSOC5LP) */

void SWITCH_CLOCK_StandbyPower(uint8 state) ;
void SWITCH_CLOCK_SetDividerRegister(uint16 clkDivider, uint8 restart) 
                                ;
uint16 SWITCH_CLOCK_GetDividerRegister(void) ;
void SWITCH_CLOCK_SetModeRegister(uint8 modeBitMask) ;
void SWITCH_CLOCK_ClearModeRegister(uint8 modeBitMask) ;
uint8 SWITCH_CLOCK_GetModeRegister(void) ;
void SWITCH_CLOCK_SetSourceRegister(uint8 clkSource) ;
uint8 SWITCH_CLOCK_GetSourceRegister(void) ;
#if defined(SWITCH_CLOCK__CFG3)
void SWITCH_CLOCK_SetPhaseRegister(uint8 clkPhase) ;
uint8 SWITCH_CLOCK_GetPhaseRegister(void) ;
#endif /* defined(SWITCH_CLOCK__CFG3) */

#define SWITCH_CLOCK_Enable()                       SWITCH_CLOCK_Start()
#define SWITCH_CLOCK_Disable()                      SWITCH_CLOCK_Stop()
#define SWITCH_CLOCK_SetDivider(clkDivider)         SWITCH_CLOCK_SetDividerRegister(clkDivider, 1u)
#define SWITCH_CLOCK_SetDividerValue(clkDivider)    SWITCH_CLOCK_SetDividerRegister((clkDivider) - 1u, 1u)
#define SWITCH_CLOCK_SetMode(clkMode)               SWITCH_CLOCK_SetModeRegister(clkMode)
#define SWITCH_CLOCK_SetSource(clkSource)           SWITCH_CLOCK_SetSourceRegister(clkSource)
#if defined(SWITCH_CLOCK__CFG3)
#define SWITCH_CLOCK_SetPhase(clkPhase)             SWITCH_CLOCK_SetPhaseRegister(clkPhase)
#define SWITCH_CLOCK_SetPhaseValue(clkPhase)        SWITCH_CLOCK_SetPhaseRegister((clkPhase) + 1u)
#endif /* defined(SWITCH_CLOCK__CFG3) */


/***************************************
*             Registers
***************************************/

/* Register to enable or disable the clock */
#define SWITCH_CLOCK_CLKEN              (* (reg8 *) SWITCH_CLOCK__PM_ACT_CFG)
#define SWITCH_CLOCK_CLKEN_PTR          ((reg8 *) SWITCH_CLOCK__PM_ACT_CFG)

/* Register to enable or disable the clock */
#define SWITCH_CLOCK_CLKSTBY            (* (reg8 *) SWITCH_CLOCK__PM_STBY_CFG)
#define SWITCH_CLOCK_CLKSTBY_PTR        ((reg8 *) SWITCH_CLOCK__PM_STBY_CFG)

/* Clock LSB divider configuration register. */
#define SWITCH_CLOCK_DIV_LSB            (* (reg8 *) SWITCH_CLOCK__CFG0)
#define SWITCH_CLOCK_DIV_LSB_PTR        ((reg8 *) SWITCH_CLOCK__CFG0)
#define SWITCH_CLOCK_DIV_PTR            ((reg16 *) SWITCH_CLOCK__CFG0)

/* Clock MSB divider configuration register. */
#define SWITCH_CLOCK_DIV_MSB            (* (reg8 *) SWITCH_CLOCK__CFG1)
#define SWITCH_CLOCK_DIV_MSB_PTR        ((reg8 *) SWITCH_CLOCK__CFG1)

/* Mode and source configuration register */
#define SWITCH_CLOCK_MOD_SRC            (* (reg8 *) SWITCH_CLOCK__CFG2)
#define SWITCH_CLOCK_MOD_SRC_PTR        ((reg8 *) SWITCH_CLOCK__CFG2)

#if defined(SWITCH_CLOCK__CFG3)
/* Analog clock phase configuration register */
#define SWITCH_CLOCK_PHASE              (* (reg8 *) SWITCH_CLOCK__CFG3)
#define SWITCH_CLOCK_PHASE_PTR          ((reg8 *) SWITCH_CLOCK__CFG3)
#endif /* defined(SWITCH_CLOCK__CFG3) */


/**************************************
*       Register Constants
**************************************/

/* Power manager register masks */
#define SWITCH_CLOCK_CLKEN_MASK         SWITCH_CLOCK__PM_ACT_MSK
#define SWITCH_CLOCK_CLKSTBY_MASK       SWITCH_CLOCK__PM_STBY_MSK

/* CFG2 field masks */
#define SWITCH_CLOCK_SRC_SEL_MSK        SWITCH_CLOCK__CFG2_SRC_SEL_MASK
#define SWITCH_CLOCK_MODE_MASK          (~(SWITCH_CLOCK_SRC_SEL_MSK))

#if defined(SWITCH_CLOCK__CFG3)
/* CFG3 phase mask */
#define SWITCH_CLOCK_PHASE_MASK         SWITCH_CLOCK__CFG3_PHASE_DLY_MASK
#endif /* defined(SWITCH_CLOCK__CFG3) */

#endif /* CY_CLOCK_SWITCH_CLOCK_H */


/* [] END OF FILE */
