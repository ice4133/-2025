#include "encoder.h"
float actual_velocity[4];
float Encoder_GetSpeed(int i)
{
	float encoder=0;
	float actual_velocity=0;
    switch(i)
    {
        case 1:
        {
	encoder=__HAL_TIM_GET_COUNTER(&htim1);
	if(encoder<10000)
	{
	actual_velocity=encoder*PROPORTION_ACTUAL;		
	}
	else if(encoder>55000)
	{
    actual_velocity=(encoder-65536)*PROPORTION_ACTUAL;		
	}
  __HAL_TIM_SET_COUNTER(&htim1,0);       
        }
        break;


        case 2:
        {
 	encoder=__HAL_TIM_GET_COUNTER(&htim2);
	if(encoder<10000)
	{
	actual_velocity=encoder*PROPORTION_ACTUAL;		
	}
	else if(encoder>55000)
	{
    actual_velocity=(encoder-65536)*PROPORTION_ACTUAL;		
	}
  __HAL_TIM_SET_COUNTER(&htim2,0);       
        }
        break;


        case 3:
        {
	encoder=__HAL_TIM_GET_COUNTER(&htim4);
	if(encoder<10000)
	{
	actual_velocity=encoder*PROPORTION_ACTUAL;		
	}
	else if(encoder>55000)
	{
    actual_velocity=(encoder-65536)*PROPORTION_ACTUAL;		
	}
  __HAL_TIM_SET_COUNTER(&htim4,0);            
        }
        break;

        case 4:
        {
 	encoder=__HAL_TIM_GET_COUNTER(&htim8);
	if(encoder<10000)
	{
	actual_velocity=encoder*PROPORTION_ACTUAL;		
	}
	else if(encoder>55000)
	{
    actual_velocity=(encoder-65536)*PROPORTION_ACTUAL;		
	}
  __HAL_TIM_SET_COUNTER(&htim8,0);                   
        }
        break;
    }
  return actual_velocity;
}

void encoder_proc()
{
    for(int i=1;i<5;i++)
	actual_velocity[i-1]=Encoder_GetSpeed(i);
}

