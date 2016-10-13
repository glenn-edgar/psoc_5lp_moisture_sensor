/*******************************************************************************
* File Name: Source_Dac_PM.c  
* Version 1.90
*
* Description:
*  This file provides the power management source code to API for the
*  VDAC8.  
*
* Note:
*  None
*
********************************************************************************
* Copyright 2008-2012, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#include "Source_Dac.h"

static Source_Dac_backupStruct Source_Dac_backup;


/*******************************************************************************
* Function Name: Source_Dac_SaveConfig
********************************************************************************
* Summary:
*  Save the current user configuration
*
* Parameters:  
*  void  
*
* Return: 
*  void
*
*******************************************************************************/
void Source_Dac_SaveConfig(void) 
{
    if (!((Source_Dac_CR1 & Source_Dac_SRC_MASK) == Source_Dac_SRC_UDB))
    {
        Source_Dac_backup.data_value = Source_Dac_Data;
    }
}


/*******************************************************************************
* Function Name: Source_Dac_RestoreConfig
********************************************************************************
*
* Summary:
*  Restores the current user configuration.
*
* Parameters:  
*  void
*
* Return: 
*  void
*
*******************************************************************************/
void Source_Dac_RestoreConfig(void) 
{
    if (!((Source_Dac_CR1 & Source_Dac_SRC_MASK) == Source_Dac_SRC_UDB))
    {
        if((Source_Dac_Strobe & Source_Dac_STRB_MASK) == Source_Dac_STRB_EN)
        {
            Source_Dac_Strobe &= (uint8)(~Source_Dac_STRB_MASK);
            Source_Dac_Data = Source_Dac_backup.data_value;
            Source_Dac_Strobe |= Source_Dac_STRB_EN;
        }
        else
        {
            Source_Dac_Data = Source_Dac_backup.data_value;
        }
    }
}


/*******************************************************************************
* Function Name: Source_Dac_Sleep
********************************************************************************
* Summary:
*  Stop and Save the user configuration
*
* Parameters:  
*  void:  
*
* Return: 
*  void
*
* Global variables:
*  Source_Dac_backup.enableState:  Is modified depending on the enable 
*  state  of the block before entering sleep mode.
*
*******************************************************************************/
void Source_Dac_Sleep(void) 
{
    /* Save VDAC8's enable state */    
    if(Source_Dac_ACT_PWR_EN == (Source_Dac_PWRMGR & Source_Dac_ACT_PWR_EN))
    {
        /* VDAC8 is enabled */
        Source_Dac_backup.enableState = 1u;
    }
    else
    {
        /* VDAC8 is disabled */
        Source_Dac_backup.enableState = 0u;
    }
    
    Source_Dac_Stop();
    Source_Dac_SaveConfig();
}


/*******************************************************************************
* Function Name: Source_Dac_Wakeup
********************************************************************************
*
* Summary:
*  Restores and enables the user configuration
*  
* Parameters:  
*  void
*
* Return: 
*  void
*
* Global variables:
*  Source_Dac_backup.enableState:  Is used to restore the enable state of 
*  block on wakeup from sleep mode.
*
*******************************************************************************/
void Source_Dac_Wakeup(void) 
{
    Source_Dac_RestoreConfig();
    
    if(Source_Dac_backup.enableState == 1u)
    {
        /* Enable VDAC8's operation */
        Source_Dac_Enable();

        /* Restore the data register */
        Source_Dac_SetValue(Source_Dac_Data);
    } /* Do nothing if VDAC8 was disabled before */    
}


/* [] END OF FILE */
