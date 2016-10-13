/*******************************************************************************
* File Name: moisture_interval_interrupt.h
* Version 1.70
*
*  Description:
*   Provides the function definitions for the Interrupt Controller.
*
*
********************************************************************************
* Copyright 2008-2015, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/
#if !defined(CY_ISR_moisture_interval_interrupt_H)
#define CY_ISR_moisture_interval_interrupt_H


#include <cytypes.h>
#include <cyfitter.h>

/* Interrupt Controller API. */
void moisture_interval_interrupt_Start(void);
void moisture_interval_interrupt_StartEx(cyisraddress address);
void moisture_interval_interrupt_Stop(void);

CY_ISR_PROTO(moisture_interval_interrupt_Interrupt);

void moisture_interval_interrupt_SetVector(cyisraddress address);
cyisraddress moisture_interval_interrupt_GetVector(void);

void moisture_interval_interrupt_SetPriority(uint8 priority);
uint8 moisture_interval_interrupt_GetPriority(void);

void moisture_interval_interrupt_Enable(void);
uint8 moisture_interval_interrupt_GetState(void);
void moisture_interval_interrupt_Disable(void);

void moisture_interval_interrupt_SetPending(void);
void moisture_interval_interrupt_ClearPending(void);


/* Interrupt Controller Constants */

/* Address of the INTC.VECT[x] register that contains the Address of the moisture_interval_interrupt ISR. */
#define moisture_interval_interrupt_INTC_VECTOR            ((reg32 *) moisture_interval_interrupt__INTC_VECT)

/* Address of the moisture_interval_interrupt ISR priority. */
#define moisture_interval_interrupt_INTC_PRIOR             ((reg8 *) moisture_interval_interrupt__INTC_PRIOR_REG)

/* Priority of the moisture_interval_interrupt interrupt. */
#define moisture_interval_interrupt_INTC_PRIOR_NUMBER      moisture_interval_interrupt__INTC_PRIOR_NUM

/* Address of the INTC.SET_EN[x] byte to bit enable moisture_interval_interrupt interrupt. */
#define moisture_interval_interrupt_INTC_SET_EN            ((reg32 *) moisture_interval_interrupt__INTC_SET_EN_REG)

/* Address of the INTC.CLR_EN[x] register to bit clear the moisture_interval_interrupt interrupt. */
#define moisture_interval_interrupt_INTC_CLR_EN            ((reg32 *) moisture_interval_interrupt__INTC_CLR_EN_REG)

/* Address of the INTC.SET_PD[x] register to set the moisture_interval_interrupt interrupt state to pending. */
#define moisture_interval_interrupt_INTC_SET_PD            ((reg32 *) moisture_interval_interrupt__INTC_SET_PD_REG)

/* Address of the INTC.CLR_PD[x] register to clear the moisture_interval_interrupt interrupt. */
#define moisture_interval_interrupt_INTC_CLR_PD            ((reg32 *) moisture_interval_interrupt__INTC_CLR_PD_REG)


#endif /* CY_ISR_moisture_interval_interrupt_H */


/* [] END OF FILE */
