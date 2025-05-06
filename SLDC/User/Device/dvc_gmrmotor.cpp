/**
* @file dvc_gmrmotor.cpp
* @author xxl
* @brief 这个是模块化文件，它的作用是设置一些属性，是一个底层，应用层在chassis.cpp中
*
*/

/* Include--------------- */
#include "dvc_gmrmotor.h"
#include "tim.h"
int encoder_type;
void Class_GMR_Motor::Data_Process()
{
	encoder_type++;
	if(encoder_type==1)
	{
		encoder_flag++;
		if(encoder_flag==1)
		{
			last_count=__HAL_TIM_GET_COUNTER(&htim1);
		}
		else if(encoder_flag==2)
		{
			
			current_count=__HAL_TIM_GET_COUNTER(&htim1);
			//todo 解算具体速度
			delta=current_count-last_count;
			current_count=last_count=0;
			float temp_now_velocity=delta/4;//这个delta具体得计算，单位得统一成cm或者m
			encoder_flag=0;
		}		
	}

}

