/*
**
**
**  File sigma_mux.c
**  Controls sequencing mux for sigma delta values
**
**
*/

#include <device.h>
#include "sigma_mux.h"
#include "a_to_d_functions.h"

#define MUX_NUMBER 2

static int16 mux_ac[ MUX_NUMBER ];
static int16 mux_dc[MUX_NUMBER ];

static inline unsigned check_channel( unsigned channel )
{
	if( channel > (MUX_NUMBER -1) )
	{
		return MUX_NUMBER-1;
	}
	return channel;
}


void sm_initialization( void )
{
    AMux_1_Start() ;
    AMux_1_FastSelect(0) ;
	ad_init_sigma_delta(1 );
	
}

void  sm_set_configuration( unsigned config, unsigned mux_channel )
{
    AMux_1_FastSelect(mux_channel) ;
	ad_init_sigma_delta( config );
}

void sm_store_value( unsigned mux_channel )
{
      mux_channel = check_channel( mux_channel );
      mux_dc[mux_channel] = ad_get_sigma_delta_dc( );
      mux_ac[mux_channel] = ad_get_sigma_delta_ac();
	
}

int16 sm_get_dc_channel_value( unsigned mux_channel )
{
     mux_channel = check_channel( mux_channel );	
     return mux_dc[mux_channel];
}

int16 sm_get_ac_channel_value( unsigned mux_channel )
{
	mux_channel = check_channel( mux_channel );
	return mux_ac[mux_channel];
}
