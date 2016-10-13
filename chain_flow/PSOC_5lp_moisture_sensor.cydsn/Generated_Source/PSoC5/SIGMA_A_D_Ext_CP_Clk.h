/*******************************************************************************
* File Name: SIGMA_A_D_Ext_CP_Clk.h
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

#if !defined(CY_CLOCK_SIGMA_A_D_Ext_CP_Clk_H)
#define CY_CLOCK_SIGMA_A_D_Ext_CP_Clk_H

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

void SIGMA_A_D_Ext_CP_Clk_Start(void) ;
void SIGMA_A_D_Ext_CP_Clk_Stop(void) ;

#if(CY_PSOC3 || CY_PSOC5LP)
void SIGMA_A_D_Ext_CP_Clk_StopBlock(void) ;
#endif /* (CY_PSOC3 || CY_PSOC5LP) */

void SIGMA_A_D_Ext_CP_Clk_StandbyPower(uint8 state) ;
void SIGMA_A_D_Ext_CP_Clk_SetDividerRegister(uint16 clkDivider, uint8 restart) 
                                ;
uint16 SIGMA_A_D_Ext_CP_Clk_GetDividerRegister(void) ;
void SIGMA_A_D_Ext_CP_Clk_SetModeRegister(uint8 modeBitMask) ;
void SIGMA_A_D_Ext_CP_Clk_ClearModeRegister(uint8 modeBitMask) ;
uint8 SIGMA_A_D_Ext_CP_Clk_GetModeRegister(void) ;
void SIGMA_A_D_Ext_CP_Clk_SetSourceRegister(uint8 clkSource) ;
uint8 SIGMA_A_D_Ext_CP_Clk_GetSourceRegister(void) ;
#if defined(SIGMA_A_D_Ext_CP_Clk__CFG3)
void SIGMA_A_D_Ext_CP_Clk_SetPhaseRegister(uint8 clkPhase) ;
uint8 SIGMA_A_D_Ext_CP_Clk_GetPhaseRegister(void) ;
#endif /* defined(SIGMA_A_D_Ext_CP_Clk__CFG3) */

#define SIGMA_A_D_Ext_CP_Clk_Enable()                       SIGMA_A_D_Ext_CP_Clk_Start()
#define SIGMA_A_D_Ext_CP_Clk_Disable()                      SIGMA_A_D_Ext_CP_Clk_Stop()
#define SIGMA_A_D_Ext_CP_Clk_SetDivider(clkDivider)         SIGMA_A_D_Ext_CP_Clk_SetDividerRegister(clkDivider, 1u)
#define SIGMA_A_D_Ext_CP_Clk_SetDividerValue(clkDivider)    SIGMA_A_D_Ext_CP_Clk_SetDividerRegister((clkDivider) - 1u, 1u)
#define SIGMA_A_D_Ext_CP_Clk_SetMode(clkMode)               SIGMA_A_D_Ext_CP_Clk_SetModeRegister(clkMode)
#define SIGMA_A_D_Ext_CP_Clk_SetSource(clkSource)           SIGMA_A_D_Ext_CP_Clk_SetSourceRegister(clkSource)
#if defined(SIGMA_A_D_Ext_CP_Clk__CFG3)
#define SIGMA_A_D_Ext_CP_Clk_SetPhase(clkPhase)             SIGMA_A_D_Ext_CP_Clk_SetPhaseRegister(clkPhase)
#define SIGMA_A_D_Ext_CP_Clk_SetPhaseValue(clkPhase)        SIGMA_A_D_Ext_CP_Clk_SetPhaseRegister((clkPhase) + 1u)
#endif /* defined(SIGMA_A_D_Ext_CP_Clk__CFG3) */


/***************************************
*             Registers
***************************************/

/* Register to enable or disable the clock */
#define SIGMA_A_D_Ext_CP_Clk_CLKEN              (* (reg8 *) SIGMA_A_D_Ext_CP_Clk__PM_ACT_CFG)
#define SIGMA_A_D_Ext_CP_Clk_CLKEN_PTR          ((reg8 *) SIGMA_A_D_Ext_CP_Clk__PM_ACT_CFG)

/* Register to enable or disable the clock */
#define SIGMA_A_D_Ext_CP_Clk_CLKSTBY            (* (reg8 *) SIGMA_A_D_Ext_CP_Clk__PM_STBY_CFG)
#define SIGMA_A_D_Ext_CP_Clk_CLKSTBY_PTR        ((reg8 *) SIGMA_A_D_Ext_CP_Clk__PM_STBY_CFG)

/* Clock LSB divider configuration register. */
#define SIGMA_A_D_Ext_CP_Clk_DIV_LSB            (* (reg8 *) SIGMA_A_D_Ext_CP_Clk__CFG0)
#define SIGMA_A_D_Ext_CP_Clk_DIV_LSB_PTR        ((reg8 *) SIGMA_A_D_Ext_CP_Clk__CFG0)
#define SIGMA_A_D_Ext_CP_Clk_DIV_PTR            ((reg16 *) SIGMA_A_D_Ext_CP_Clk__CFG0)

/* Clock MSB divider configuration register. */
#define SIGMA_A_D_Ext_CP_Clk_DIV_MSB            (* (reg8 *) SIGMA_A_D_Ext_CP_Clk__CFG1)
#define SIGMA_A_D_Ext_CP_Clk_DIV_MSB_PTR        ((reg8 *) SIGMA_A_D_Ext_CP_Clk__CFG1)

/* Mode and source configuration register */
#define SIGMA_A_D_Ext_CP_Clk_MOD_SRC            (* (reg8 *) SIGMA_A_D_Ext_CP_Clk__CFG2)
#define SIGMA_A_D_Ext_CP_Clk_MOD_SRC_PTR        ((reg8 *) SIGMA_A_D_Ext_CP_Clk__CFG2)

#if defined(SIGMA_A_D_Ext_CP_Clk__CFG3)
/* Analog clock phase configuration register */
#define SIGMA_A_D_Ext_CP_Clk_PHASE              (* (reg8 *) SIGMA_A_D_Ext_CP_Clk__CFG3)
#define SIGMA_A_D_Ext_CP_Clk_PHASE_PTR          ((reg8 *) SIGMA_A_D_Ext_CP_Clk__CFG3)
#endif /* defined(SIGMA_A_D_Ext_CP_Clk__CFG3) */


/**************************************
*       Register Constants
**************************************/

/* Power manager register masks */
#define SIGMA_A_D_Ext_CP_Clk_CLKEN_MASK         SIGMA_A_D_Ext_CP_Clk__PM_ACT_MSK
#define SIGMA_A_D_Ext_CP_Clk_CLKSTBY_MASK       SIGMA_A_D_Ext_CP_Clk__PM_STBY_MSK

/* CFG2 field masks */
#define SIGMA_A_D_Ext_CP_Clk_SRC_SEL_MSK        SIGMA_A_D_Ext_CP_Clk__CFG2_SRC_SEL_MASK
#define SIGMA_A_D_Ext_CP_Clk_MODE_MASK          (~(SIGMA_A_D_Ext_CP_Clk_SRC_SEL_MSK))

#if defined(SIGMA_A_D_Ext_CP_Clk__CFG3)
/* CFG3 phase mask */
#define SIGMA_A_D_Ext_CP_Clk_PHASE_MASK         SIGMA_A_D_Ext_CP_Clk__CFG3_PHASE_DLY_MASK
#endif /* defined(SIGMA_A_D_Ext_CP_Clk__CFG3) */

#endif /* CY_CLOCK_SIGMA_A_D_Ext_CP_Clk_H */


/* [] END OF FILE */
