#include "app_chassis.h"
#include "config.h"
#include "main.h"
#include "tim.h"
#include "math.h"

int test_data=1000;
float output[2]={0};
void CHASSIS::Chassis_Init()
{
    for(int i=0;i<2;i++)
//    this->pid[i].PID_Init(40,1.2,0.5,400,1000);
    this->pid[i].PID_Init(50,1.0,0,500,1000);	
}
void CHASSIS::data_proc(float* data)
{
	target_velocity[0]=data[0]-data[1];
	target_velocity[1]=data[0]+data[1];
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
			__HAL_TIM_SET_COMPARE(&htim3, TIM_CHANNEL_1,0);
			uint32_t pwm_val = (uint32_t)fabsf(pid_output);
			__HAL_TIM_SET_COMPARE(&htim3, TIM_CHANNEL_2, pwm_val);			
			}
			else 
			{
			__HAL_TIM_SET_COMPARE(&htim3, TIM_CHANNEL_2,0);
			uint32_t pwm_val = (uint32_t)fabsf(pid_output);
			__HAL_TIM_SET_COMPARE(&htim3, TIM_CHANNEL_1,pwm_val);	
			}   			
		}
			break;
		
		
		case 2:
		{
			if(pid_output >= 0)	
			{
			__HAL_TIM_SET_COMPARE(&htim3, TIM_CHANNEL_4,0);
			uint32_t pwm_val = (uint32_t)fabsf(pid_output);
			__HAL_TIM_SET_COMPARE(&htim3, TIM_CHANNEL_3, pwm_val);			
			}
			else 
			{
			__HAL_TIM_SET_COMPARE(&htim3, TIM_CHANNEL_3,0);
			uint32_t pwm_val = (uint32_t)fabsf(pid_output);
			__HAL_TIM_SET_COMPARE(&htim3, TIM_CHANNEL_4, pwm_val);	
			}   			
		}
			break;
		
		

}
}

void CHASSIS::Chassis_Solution()
{
//    float output[2]={0};
// 
			output[0]=this->pid[0].PID_Compute(target_velocity[0],actual_velocity[0]);
			output[1]=this->pid[1].PID_Compute(target_velocity[1],actual_velocity[1]);
	
//			Motor_SetOutput(output[0],1); 
	//		Motor_SetOutput(output[1],2);
			Motor_SetOutput(output[0],1); 
		Motor_SetOutput(output[1],2);		
			
}



void chassis_proc()
{
		//chassis.data_proc(radar_data);//获取目标速度
    chassis.Chassis_Solution();
}

