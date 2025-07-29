#include "app_gimbal.h"
#include "alg_limit.h"
#include "alg_datachange.h"
#include "config.h"
#include "tim.h"
float target_velocity[2];
float error[2]={0};
extern uint8_t uart3_rx_data[12];
uint8_t unwatch_flag;
void gimbal_proc()
{
		char_to_uint32(uart3_rx_data);	
	float temp[2];
	temp[0]=yaw.PID_Compute(error[0]);
	temp[1]=pitch.PID_Compute(error[1]);
	for(int i=0;i<2;i++)
	photo_data[i]+=temp[i];
	output_limit(photo_data);
	if(unwatch_flag==1)
	{
		photo_data[0]=140;
		photo_data[1]=157;
		unwatch_flag=error[0]=error[1]=0;
	}
	__HAL_TIM_SET_COMPARE(&htim4, TIM_CHANNEL_1,photo_data[0]);
	__HAL_TIM_SET_COMPARE(&htim4, TIM_CHANNEL_2,photo_data[1]);
}
