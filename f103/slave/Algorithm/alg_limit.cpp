#include "alg_limit.h"

extern float photo_data[4];
void output_limit(float* buffer)
{
	if(buffer[1]>=190)
	{
		buffer[1]=190;
	}
	else if(buffer[1]<=135)
	{
		buffer[1]=135;
	}
}

