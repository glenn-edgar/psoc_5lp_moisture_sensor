/*******************************************************************************
* File Name: ADC_1_PM.c
* Version 2.0
*
* Description:
*  This file contains the setup, control and status commands to support
*  component operations in low power mode.
*
* Note:
*
********************************************************************************
* Copyright 2012-2015, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
*******************************************************************************/

#include "ADC_1.h"
#include "ADC_1_SAR.h"
#if(ADC_1_CLOCK_SOURCE == ADC_1_CLOCK_INTERNAL)
    #include "ADC_1_IntClock.h"
#endif   /* ADC_1_CLOCK_SOURCE == ADC_1_CLOCK_INTERNAL */


/*******************************************************************************
* Function Name: ADC_1_Sleep
********************************************************************************
*
* Summary:
*  Stops the ADC operation and saves the configuration registers and component
*  enable state. Should be called just prior to entering sleep
*
* Parameters:
*  None.
*
* Return:
*  None.
*
* Side Effects:
*  None.
*
* Reentrant:
*  No.
*
*******************************************************************************/
void ADC_1_Sleep(void)
{
    ADC_1_SAR_Stop();
    ADC_1_SAR_Sleep();
    ADC_1_Disable();

    #if(ADC_1_CLOCK_SOURCE == ADC_1_CLOCK_INTERNAL)
        ADC_1_IntClock_Stop();
    #endif   /* ADC_1_CLOCK_SOURCE == ADC_1_CLOCK_INTERNAL */
}


/*******************************************************************************
* Function Name: ADC_1_Wakeup
********************************************************************************
*
* Summary:
*  Restores the component enable state and configuration registers. This should
*  be called just after awaking from sleep mode
*
* Parameters:
*  None.
*
* Return:
*  None.
*
* Side Effects:
*  None.
*
* Reentrant:
*  No.
*
*******************************************************************************/
void ADC_1_Wakeup(void)
{
    ADC_1_SAR_Wakeup();
    ADC_1_SAR_Enable();

    #if(ADC_1_CLOCK_SOURCE == ADC_1_CLOCK_INTERNAL)
        ADC_1_IntClock_Start();
    #endif   /* ADC_1_CLOCK_SOURCE == ADC_1_CLOCK_INTERNAL */

    /* The block is ready to use 10 us after the SAR enable signal is set high. */
    CyDelayUs(10u);
    
    ADC_1_Enable();

    #if(ADC_1_SAMPLE_MODE == ADC_1_SAMPLE_MODE_FREE_RUNNING)
        ADC_1_SAR_StartConvert();
    #endif /* (ADC_1_SAMPLE_MODE == ADC_1_SAMPLE_MODE_FREE_RUNNING) */

    (void) CY_GET_REG8(ADC_1_STATUS_PTR);
}


/*******************************************************************************
* Function Name: ADC_1_SaveConfig
********************************************************************************
*
* Summary:
*  Save the current configuration of ADC non-retention registers
*
* Parameters:
*  None.
*
* Return:
*  None.
*
* Side Effects:
*  None.
*
* Reentrant:
*  No.
*
*******************************************************************************/
void ADC_1_SaveConfig(void)
{

}


/*******************************************************************************
* Function Name: ADC_1_RestoreConfig
********************************************************************************
*
* Summary:
*  Restores the configuration of ADC non-retention registers
*
* Parameters:
*  None.
*
* Return:
*  None.
*
* Side Effects:
*  None.
*
* Reentrant:
*  No.
*
*******************************************************************************/
void ADC_1_RestoreConfig(void)
{

}


/* [] END OF FILE */
