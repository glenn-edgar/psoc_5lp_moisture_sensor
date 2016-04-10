/*
**
** File: moving_average.c
**
**
*/

#include "moving_average.h"



void ma_initialize( MOVING_AVERAGE_STRUCT *ma, float alpha )
{
	ma->alpha = alpha;
    ma->minus_alpha = 1.0 - alpha;
    ma->average     = 0.0;
}

int32 ma_update( MOVING_AVERAGE_STRUCT *ma, int32 new_sample)
{
    ma->average *= ma->minus_alpha;
    ma->average += ((float) new_sample)*ma->alpha;
    return ma->average;
 
}

int32 ma_get_value( MOVING_AVERAGE_STRUCT *ma )
{
    return ma->average;
}
