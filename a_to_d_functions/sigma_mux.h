/*
**
** File: sigma_mux.h
** Controls mux in front of sigma A/D
**
**
*/

#include <device.h>

#ifndef _SIGMA_MUX_H_
#define _SIGMA_MUX_H_

#define MUX_NUMBER 2

void sm_initialization( void );

void  sm_set_configuration( unsigned configuration, unsigned mux_channel );

void sm_store_value( unsigned mux_channel );



int16 sm_get_dc_channel_value( unsigned mux_channel );

int16 sm_get_ac_channel_value( unsigned mux_channel );


#endif