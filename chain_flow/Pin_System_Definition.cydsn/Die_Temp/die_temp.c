/*
**
** File: die_temp.c
**
**
*/

#include <device.h>
#include "moving_average.h"
#include "cf_chain_flow_support.h" 
#include "cf_events.h"
#include "process_modbus_message.h"

#include "die_temp.h"


static uint16                   temp_die;
static MOVING_AVERAGE_STRUCT ma_die_temp;

uint16 die_get_temperature( void )
{
    return temp_die;
}



int initialize_die_temp_measurement(unsigned link_id, unsigned param_1,
  unsigned param_2, unsigned param_3, unsigned event, unsigned data)
{
    ma_initialize( &ma_die_temp, .1,0 );
    return CF_DISABLE;
}

int meaure_die_temperature(unsigned link_id, unsigned param_1,
  unsigned param_2, unsigned param_3, unsigned event, unsigned data)
{
    int16 temp;
    DieTemp_1_GetTemp(&temp);
    temp = ((temp*9)/5)+32; 
    temp_die = ma_update( &ma_die_temp, temp);
    store_modbus_data_registers( MOD_UNIT_TEMP, 1, &temp_die );

    return CF_DISABLE;
}