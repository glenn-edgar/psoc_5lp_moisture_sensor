/*******************************************************************************
* File Name: Source_Dac.c  
* Version 1.90
*
* Description:
*  This file provides the source code to the API for the 8-bit Voltage DAC 
*  (VDAC8) User Module.
*
* Note:
*  Any unusual or non-standard behavior should be noted here. Other-
*  wise, this section should remain blank.
*
********************************************************************************
* Copyright 2008-2012, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#include "cytypes.h"
#include "Source_Dac.h"

#if (CY_PSOC5A)
#include <CyLib.h>
#endif /* CY_PSOC5A */

uint8 Source_Dac_initVar = 0u;

#if (CY_PSOC5A)
    static uint8 Source_Dac_restoreVal = 0u;
#endif /* CY_PSOC5A */

#if (CY_PSOC5A)
    static Source_Dac_backupStruct Source_Dac_backup;
#endif /* CY_PSOC5A */


/*******************************************************************************
* Function Name: Source_Dac_Init
********************************************************************************
* Summary:
*  Initialize to the schematic state.
* 
* Parameters:
*  void:
*
* Return:
*  void
*
* Theory:
*
* Side Effects:
*
*******************************************************************************/
void Source_Dac_Init(void) 
{
    Source_Dac_CR0 = (Source_Dac_MODE_V );

    /* Set default data source */
    #if(Source_Dac_DEFAULT_DATA_SRC != 0 )
        Source_Dac_CR1 = (Source_Dac_DEFAULT_CNTL | Source_Dac_DACBUS_ENABLE) ;
    #else
        Source_Dac_CR1 = (Source_Dac_DEFAULT_CNTL | Source_Dac_DACBUS_DISABLE) ;
    #endif /* (Source_Dac_DEFAULT_DATA_SRC != 0 ) */

    /* Set default strobe mode */
    #if(Source_Dac_DEFAULT_STRB != 0)
        Source_Dac_Strobe |= Source_Dac_STRB_EN ;
    #endif/* (Source_Dac_DEFAULT_STRB != 0) */

    /* Set default range */
    Source_Dac_SetRange(Source_Dac_DEFAULT_RANGE); 

    /* Set default speed */
    Source_Dac_SetSpeed(Source_Dac_DEFAULT_SPEED);
}


/*******************************************************************************
* Function Name: Source_Dac_Enable
********************************************************************************
* Summary:
*  Enable the VDAC8
* 
* Parameters:
*  void
*
* Return:
*  void
*
* Theory:
*
* Side Effects:
*
*******************************************************************************/
void Source_Dac_Enable(void) 
{
    Source_Dac_PWRMGR |= Source_Dac_ACT_PWR_EN;
    Source_Dac_STBY_PWRMGR |= Source_Dac_STBY_PWR_EN;

    /*This is to restore the value of register CR0 ,
    which is modified  in Stop API , this prevents misbehaviour of VDAC */
    #if (CY_PSOC5A)
        if(Source_Dac_restoreVal == 1u) 
        {
             Source_Dac_CR0 = Source_Dac_backup.data_value;
             Source_Dac_restoreVal = 0u;
        }
    #endif /* CY_PSOC5A */
}


/*******************************************************************************
* Function Name: Source_Dac_Start
********************************************************************************
*
* Summary:
*  The start function initializes the voltage DAC with the default values, 
*  and sets the power to the given level.  A power level of 0, is the same as
*  executing the stop function.
*
* Parameters:
*  Power: Sets power level between off (0) and (3) high power
*
* Return:
*  void 
*
* Global variables:
*  Source_Dac_initVar: Is modified when this function is called for the 
*  first time. Is used to ensure that initialization happens only once.
*
*******************************************************************************/
void Source_Dac_Start(void)  
{
    /* Hardware initiazation only needs to occure the first time */
    if(Source_Dac_initVar == 0u)
    { 
        Source_Dac_Init();
        Source_Dac_initVar = 1u;
    }

    /* Enable power to DAC */
    Source_Dac_Enable();

    /* Set default value */
    Source_Dac_SetValue(Source_Dac_DEFAULT_DATA); 
}


/*******************************************************************************
* Function Name: Source_Dac_Stop
********************************************************************************
*
* Summary:
*  Powers down DAC to lowest power state.
*
* Parameters:
*  void
*
* Return:
*  void
*
* Theory:
*
* Side Effects:
*
*******************************************************************************/
void Source_Dac_Stop(void) 
{
    /* Disble power to DAC */
    Source_Dac_PWRMGR &= (uint8)(~Source_Dac_ACT_PWR_EN);
    Source_Dac_STBY_PWRMGR &= (uint8)(~Source_Dac_STBY_PWR_EN);

    /* This is a work around for PSoC5A  ,
    this sets VDAC to current mode with output off */
    #if (CY_PSOC5A)
        Source_Dac_backup.data_value = Source_Dac_CR0;
        Source_Dac_CR0 = Source_Dac_CUR_MODE_OUT_OFF;
        Source_Dac_restoreVal = 1u;
    #endif /* CY_PSOC5A */
}


/*******************************************************************************
* Function Name: Source_Dac_SetSpeed
********************************************************************************
*
* Summary:
*  Set DAC speed
*
* Parameters:
*  power: Sets speed value
*
* Return:
*  void
*
* Theory:
*
* Side Effects:
*
*******************************************************************************/
void Source_Dac_SetSpeed(uint8 speed) 
{
    /* Clear power mask then write in new value */
    Source_Dac_CR0 &= (uint8)(~Source_Dac_HS_MASK);
    Source_Dac_CR0 |=  (speed & Source_Dac_HS_MASK);
}


/*******************************************************************************
* Function Name: Source_Dac_SetRange
********************************************************************************
*
* Summary:
*  Set one of three current ranges.
*
* Parameters:
*  Range: Sets one of Three valid ranges.
*
* Return:
*  void 
*
* Theory:
*
* Side Effects:
*
*******************************************************************************/
void Source_Dac_SetRange(uint8 range) 
{
    Source_Dac_CR0 &= (uint8)(~Source_Dac_RANGE_MASK);      /* Clear existing mode */
    Source_Dac_CR0 |= (range & Source_Dac_RANGE_MASK);      /*  Set Range  */
    Source_Dac_DacTrim();
}


/*******************************************************************************
* Function Name: Source_Dac_SetValue
********************************************************************************
*
* Summary:
*  Set 8-bit DAC value
*
* Parameters:  
*  value:  Sets DAC value between 0 and 255.
*
* Return: 
*  void 
*
* Theory: 
*
* Side Effects:
*
*******************************************************************************/
void Source_Dac_SetValue(uint8 value) 
{
    #if (CY_PSOC5A)
        uint8 Source_Dac_intrStatus = CyEnterCriticalSection();
    #endif /* CY_PSOC5A */

    Source_Dac_Data = value;                /*  Set Value  */

    /* PSOC5A requires a double write */
    /* Exit Critical Section */
    #if (CY_PSOC5A)
        Source_Dac_Data = value;
        CyExitCriticalSection(Source_Dac_intrStatus);
    #endif /* CY_PSOC5A */
}


/*******************************************************************************
* Function Name: Source_Dac_DacTrim
********************************************************************************
*
* Summary:
*  Set the trim value for the given range.
*
* Parameters:
*  range:  1V or 4V range.  See constants.
*
* Return:
*  void
*
* Theory: 
*
* Side Effects:
*
*******************************************************************************/
void Source_Dac_DacTrim(void) 
{
    uint8 mode;

    mode = (uint8)((Source_Dac_CR0 & Source_Dac_RANGE_MASK) >> 2) + Source_Dac_TRIM_M7_1V_RNG_OFFSET;
    Source_Dac_TR = CY_GET_XTND_REG8((uint8 *)(Source_Dac_DAC_TRIM_BASE + mode));
}


/* [] END OF FILE */
