#ifndef __CONFIG_H__
#define __CONFIG_H__

#include "main.h"
#include "app_chassis.h"

extern UART_HandleTypeDef huart2;
extern UART_HandleTypeDef huart3;
extern DMA_HandleTypeDef hdma_usart2_rx;
extern DMA_HandleTypeDef hdma_usart2_tx;
extern DMA_HandleTypeDef hdma_usart3_rx;
extern DMA_HandleTypeDef hdma_usart3_tx;


extern uint8_t uart2_rx_buffer[12];//雷达缓冲数据包
extern uint8_t uart3_rx_buffer[10];//视觉缓冲数据包
extern float photo_data[4];//视觉实际数据包，第三帧数据为led，第四帧为beep
extern float radar_data[3];//雷达实际数据包
extern float actual_velocity[2];//实际速度
extern float target_velocity[2];//目标速度
extern CHASSIS chassis;
extern Gimbal pitch;
extern Gimbal yaw;
extern float error[2];//第一个是yaw，第二个是pitch
extern uint16_t pwm[2];//50到250,测试数据
extern uint8_t unwatch_flag;//突然未识别到标志位
#endif
