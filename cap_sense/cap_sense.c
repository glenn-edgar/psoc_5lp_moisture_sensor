/*
**
** File: cap_sense.c
**
**
**
*/

#include <device.h>
#include "cf_chain_flow_support.h"
#include "cf_external_functions.h"
#include "cap_sense.h"

#define NOT_BUSY 0
#define PROXIMITY_SENSOR_INDEX			CapSense_1_SENSOR_PROXIMITYSENSOR0_0__PROX
 
int init_cap_sense(unsigned link_id, unsigned param_1,
  unsigned param_2, unsigned param_3, unsigned event, unsigned data)
{

   /* Initialize the input - CapSense block */

  /* 1. Enable Proximity sensor as it is disabled by default */
  CapSense_1_EnableWidget(CapSense_1_PROXIMITYSENSOR0__PROX);

  /* 2. Start CapSense block - Calibrates the proximity sensor for the set sensitivity setting (in the Scan Order tab of Component Configuration */
  CapSense_1_Start();

 /* 3. Initialize Proximity baseline */
  CapSense_1_InitializeSensorBaseline( PROXIMITY_SENSOR_INDEX );

  return CF_DISABLE;
}

static volatile int proximityActive;
static volatile int proximityValue;

int process_capsense(unsigned link_id, unsigned param_1,
  unsigned param_2, unsigned param_3, unsigned event, unsigned data)

{  
   
    if(CapSense_1_IsBusy() == NOT_BUSY)
    {
       /* Update proximity sensor baseline */
       //CapSense_1_UpdateSensorBaseline(PROXIMITY_SENSOR_INDEX);

       /* Check if proximity sensor is active - thresholds are dynamically calculated during run-time
          proximityActive variable will have a non-zero value if Proximity was active */
       proximityActive = CapSense_1_CheckIsSensorActive(PROXIMITY_SENSOR_INDEX);
       proximityValue = CapSense_1_ReadSensorRaw(PROXIMITY_SENSOR_INDEX);
       /* Trigger the next Scan of proximity sensor */
       CapSense_1_ScanSensor(PROXIMITY_SENSOR_INDEX);
    }
    return CF_DISABLE;
}
 