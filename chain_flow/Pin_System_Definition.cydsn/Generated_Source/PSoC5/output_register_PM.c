/*******************************************************************************
* File Name: output_register_PM.c
* Version 1.80
*
* Description:
*  This file contains the setup, control, and status commands to support 
*  the component operation in the low power mode. 
*
* Note:
*
********************************************************************************
* Copyright 2015, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#include "output_register.h"

/* Check for removal by optimization */
#if !defined(output_register_Sync_ctrl_reg__REMOVED)

static output_register_BACKUP_STRUCT  output_register_backup = {0u};

    
/*******************************************************************************
* Function Name: output_register_SaveConfig
********************************************************************************
*
* Summary:
*  Saves the control register value.
*
* Parameters:
*  None
*
* Return:
*  None
*
*******************************************************************************/
void output_register_SaveConfig(void) 
{
    output_register_backup.controlState = output_register_Control;
}


/*******************************************************************************
* Function Name: output_register_RestoreConfig
********************************************************************************
*
* Summary:
*  Restores the control register value.
*
* Parameters:
*  None
*
* Return:
*  None
*
*
*******************************************************************************/
void output_register_RestoreConfig(void) 
{
     output_register_Control = output_register_backup.controlState;
}


/*******************************************************************************
* Function Name: output_register_Sleep
********************************************************************************
*
* Summary:
*  Prepares the component for entering the low power mode.
*
* Parameters:
*  None
*
* Return:
*  None
*
*******************************************************************************/
void output_register_Sleep(void) 
{
    output_register_SaveConfig();
}


/*******************************************************************************
* Function Name: output_register_Wakeup
********************************************************************************
*
* Summary:
*  Restores the component after waking up from the low power mode.
*
* Parameters:
*  None
*
* Return:
*  None
*
*******************************************************************************/
void output_register_Wakeup(void)  
{
    output_register_RestoreConfig();
}

#endif /* End check for removal by optimization */


/* [] END OF FILE */
