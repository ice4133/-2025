#include "app_gimbal.h"
#include "config.h"
#include "tim.h"
float target_velocity[2]={200,200};





void gimbal_proc()
{
//	for(int i=0;i<2;i++)
//	{
//	target_velocity[i]=radar_data[i];		
//	}
//	for(int i=0;i<2;i++)
//	{
//	photo_data[i]+=pwm_error[i];
//	}
	__HAL_TIM_SET_COMPARE(&htim4, TIM_CHANNEL_1,photo_data[0]);
	__HAL_TIM_SET_COMPARE(&htim4, TIM_CHANNEL_2,photo_data[1]);

}

