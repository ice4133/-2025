/**
 * @file tsk_config_and_callback.cpp
 * @author xxl
 * @brief 任务概述
 * @version 0.1
 * @date 
 * @copyright
 */

/* include */

#include "drv_tim.h"
#include "tsk_config_and_callback.h"
//#include "usart.h"
#include "drv_uart.h"
//#include "tim.h"
#include "dvc_gmrmotor.h"
#include "crt_chassis.h"

/* 变量 --------------*/
uint32_t pwm_slow_down;
bool pwm_flag=0;
bool encoder_flag=0;
int encoder_t;
Class_Mecanum_Chassis chassis;//定义底盘
/**
 * @brief 雷达回传给底盘的数据
 *
 * @param Buffer UART收到的消息
 * @param Length 长度
 */


void Radar_UART6_Callback(uint8_t *Buffer, uint16_t Length)
{
	//todo 写把雷达数据传给底盘，底盘进行解算，解算完的数据传给电机模块
	chassis.UART_RxCpltCallback(Buffer,Length);//得到target数据
}


/**
* @brief 定时器中断循环任务，循环获取编码器数值
*
*
*/
void Task250ms_TIM5_Callback()
{
	
	int i=0;
	for(i=0;i<4;i++)
	{
		chassis.Motor_Wheel[i].Data_Process();//得到编码器数据，now
	}

}
/**
* @brief 定时器中断循环任务,循环处理数据，发送数据
*
*
*/
void Task500ms_TIM3_Callback()
{
	//todo 进行循环任务，统一把电机模块的缓冲数据发送给电机
	if(++pwm_slow_down<1000)
	{
		return;
	}
	pwm_slow_down=0;
	pwm_flag=1;
	
	if(pwm_flag)
	{
		chassis.TIM_Calculate_PeriodElapsedCallback();//统一处理数据，处理now和target数据
		PWM_PeriodElapsedCallBack();//统一发送PWM数据，500ms周期
	}
}
extern "C" void Task_Init()
{
	
	//串口初始化
			UART_Init(&huart1, Radar_UART6_Callback, 128);	
	    // 定时器循环任务
    TIM_Init(&htim3, Task500ms_TIM3_Callback);
    TIM_Init(&htim5, Task250ms_TIM5_Callback);//先配置一个定时器，预留一个定时器
	
	
				/* 定时器初始化 */
	  HAL_TIM_Base_Start_IT(&htim3);
    HAL_TIM_Base_Start_IT(&htim5);
	
		/* 编码器初始化 */
	HAL_TIM_Encoder_Start(&htim1, TIM_CHANNEL_ALL);//左上
	HAL_TIM_Encoder_Start(&htim2, TIM_CHANNEL_ALL);//左下
	HAL_TIM_Encoder_Start(&htim4, TIM_CHANNEL_ALL);//右上
	HAL_TIM_Encoder_Start(&htim8, TIM_CHANNEL_ALL);//右下
	/* PWM初始化 */
	HAL_TIM_PWM_Start(&htim3,TIM_CHANNEL_1);//每两个为一组，同上
	HAL_TIM_PWM_Start(&htim3,TIM_CHANNEL_3);
	HAL_TIM_PWM_Start(&htim3,TIM_CHANNEL_4);
	HAL_TIM_PWM_Start(&htim4,TIM_CHANNEL_1);
	HAL_TIM_PWM_Start(&htim4,TIM_CHANNEL_4);
	HAL_TIM_PWM_Start(&htim9,TIM_CHANNEL_1);
	HAL_TIM_PWM_Start(&htim9,TIM_CHANNEL_2);
	HAL_TIM_PWM_Start(&htim11,TIM_CHANNEL_1);
	HAL_TIM_PWM_Start(&htim12,TIM_CHANNEL_1);//留给舵机，频率50HZ
	HAL_TIM_PWM_Start(&htim12,TIM_CHANNEL_2);//留给舵机，频率50HZ
	
}
