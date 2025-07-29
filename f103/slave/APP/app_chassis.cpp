#include "app_chassis.h"

#include "app_chassis.h"
#include "config.h"
#include "main.h"
#include "tim.h"
#include "math.h"

void CHASSIS::Chassis_Init()
{
    for(int i=0;i<4;i++)
    this->pid[i].PID_Init(40,1.2,0.5,400,2000);
}


void CHASSIS::Motor_SetOutput(float pid_output,int i)
{
     // 方向控制（正转高电平，反转低电平）
	switch(i)
	{
		case 1:
		{
			if(pid_output >= 0)	
			{
			uint32_t pwm_val = (uint32_t)fabsf(pid_output);				
			__HAL_TIM_SET_COMPARE(&htim3, TIM_CHANNEL_1,pwm_val);
			__HAL_TIM_SET_COMPARE(&htim3, TIM_CHANNEL_2,0);			
			}
			else 
			{
			uint32_t pwm_val = (uint32_t)fabsf(pid_output);				
			__HAL_TIM_SET_COMPARE(&htim3, TIM_CHANNEL_2,0);
			__HAL_TIM_SET_COMPARE(&htim3, TIM_CHANNEL_1, pwm_val);	
			}   			
		}
			break;
		
		
		case 2:
		{
			if(pid_output >= 0)	
			{
			uint32_t pwm_val = (uint32_t)fabsf(pid_output);				
			__HAL_TIM_SET_COMPARE(&htim3, TIM_CHANNEL_3,pwm_val);
			__HAL_TIM_SET_COMPARE(&htim3, TIM_CHANNEL_4, 0);			
			}
			else 
			{
			uint32_t pwm_val = (uint32_t)fabsf(pid_output);				
			__HAL_TIM_SET_COMPARE(&htim3, TIM_CHANNEL_4,pwm_val);
			__HAL_TIM_SET_COMPARE(&htim3, TIM_CHANNEL_3, 0);	
			}   			
		}
			break;
		
		

}
}

void CHASSIS::Chassis_Solution()
{
    float output[2];
    for(int i=0;i<2;i++)
    {
    output[i]=this->pid[i].PID_Compute(target_velocity[i],actual_velocity[i]);
			Motor_SetOutput(output[i],i+1);
    } 
}



void chassis_proc()
{
    chassis.Chassis_Solution();
}

