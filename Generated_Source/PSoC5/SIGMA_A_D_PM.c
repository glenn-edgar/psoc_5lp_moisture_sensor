/*******************************************************************************
* File Name: SIGMA_A_D_PM.c
* Version 3.20
*
* Description:
*  This file provides the power manager source code to the API for the
*  Delta-Sigma ADC Component.
*
* Note:
*
********************************************************************************
* Copyright 2008-2015, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
*******************************************************************************/

#include "SIGMA_A_D.h"

static SIGMA_A_D_BACKUP_STRUCT SIGMA_A_D_backup =
{
    SIGMA_A_D_DISABLED,
    SIGMA_A_D_CFG1_DEC_CR
};


/*******************************************************************************
* Function Name: SIGMA_A_D_SaveConfig
********************************************************************************
*
* Summary:
*  Save the register configuration which are not retention.
*
* Parameters:
*  None
*
* Return:
*  None
*
* Global variables:
*  SIGMA_A_D_backup:  This global structure variable is used to store
*  configuration registers which are non retention whenever user wants to go
*  sleep mode by calling Sleep() API.
*
*******************************************************************************/
void SIGMA_A_D_SaveConfig(void) 
{
    SIGMA_A_D_backup.deccr = SIGMA_A_D_DEC_CR_REG;
}


/*******************************************************************************
* Function Name: SIGMA_A_D_RestoreConfig
********************************************************************************
*
* Summary:
*  Restore the register configurations which are not retention.
*
* Parameters:
*  None
*
* Return:
*  None
*
* Global variables:
*  SIGMA_A_D_backup:  This global structure variable is used to restore
*  configuration registers which are non retention whenever user wants to switch
*  to active power mode by calling Wakeup() API.
*
*******************************************************************************/
void SIGMA_A_D_RestoreConfig(void) 
{
    SIGMA_A_D_DEC_CR_REG = SIGMA_A_D_backup.deccr;
}


/*******************************************************************************
* Function Name: SIGMA_A_D_Sleep
********************************************************************************
*
* Summary:
*  Stops the operation of the block and saves the user configuration.
*
* Parameters:
*  None
*
* Return:
*  None
*
* Global variables:
*  SIGMA_A_D_backup:  The structure field 'enableState' is modified
*  depending on the enable state of the block before entering to sleep mode.
*
*******************************************************************************/
void SIGMA_A_D_Sleep(void) 
{
    /* Save ADC enable state */
    if((SIGMA_A_D_ACT_PWR_DEC_EN == (SIGMA_A_D_PWRMGR_DEC_REG & SIGMA_A_D_ACT_PWR_DEC_EN)) &&
       (SIGMA_A_D_ACT_PWR_DSM_EN == (SIGMA_A_D_PWRMGR_DSM_REG & SIGMA_A_D_ACT_PWR_DSM_EN)))
    {
        /* Component is enabled */
        SIGMA_A_D_backup.enableState = SIGMA_A_D_ENABLED;
        if((SIGMA_A_D_DEC_CR_REG & SIGMA_A_D_DEC_START_CONV) != 0u)
        {   
            /* Conversion is started */
            SIGMA_A_D_backup.enableState |= SIGMA_A_D_STARTED;
        }
		
        /* Stop the configuration */
        SIGMA_A_D_Stop();
    }
    else
    {
        /* Component is disabled */
        SIGMA_A_D_backup.enableState = SIGMA_A_D_DISABLED;
    }

    /* Save the user configuration */
    SIGMA_A_D_SaveConfig();
}


/*******************************************************************************
* Function Name: SIGMA_A_D_Wakeup
********************************************************************************
*
* Summary:
*  Restores the user configuration and enables the power to the block.
*
* Parameters:
*  None
*
* Return:
*  None
*
* Global variables:
*  SIGMA_A_D_backup:  The structure field 'enableState' is used to
*  restore the enable state of block after wakeup from sleep mode.
*
*******************************************************************************/
void SIGMA_A_D_Wakeup(void) 
{
    /* Restore the configuration */
    SIGMA_A_D_RestoreConfig();

    /* Enables the component operation */
    if(SIGMA_A_D_backup.enableState != SIGMA_A_D_DISABLED)
    {
        SIGMA_A_D_Enable();
        if((SIGMA_A_D_backup.enableState & SIGMA_A_D_STARTED) != 0u)
        {
            SIGMA_A_D_StartConvert();
        }
    } /* Do nothing if component was disable before */
}


/* [] END OF FILE */
