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





/**
 * @brief 雷达回传给底盘的数据
 *
 * @param Buffer UART收到的消息
 * @param Length 长度
 */


void Radar_UART6_Callback(uint8_t *Buffer, uint16_t Length)
{
    //todo 写把雷达数据传给底盘
}


/**
* @brief 定时器中断循环任务
*
*
*/
void Task500us_TIM3_Callback()
{
	//todo 进行循环任务
}
extern "C" void Task_Init()
{
	
	//串口初始化
			UART_Init(&huart1, Radar_UART6_Callback, 128);	
	    // 定时器循环任务
    TIM_Init(&htim3, Task500us_TIM3_Callback);
    //TIM_Init(&htim5, Task1ms_TIM5_Callback);先配置一个定时器，预留一个定时器
	
	
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
