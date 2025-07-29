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





extern float radar_data[3];
extern uint8_t uart2_rx_buffer[10];//接收缓冲数据
extern uint8_t uart2_tx_buffer[14];
extern float actual_velocity[2];
extern float target_velocity[2];
extern CHASSIS chassis;
extern uint8_t uart3_rx_data[10];
extern float photo_data[2];
//extern float pwm_error[2];
/*
数据核心已经从这里看出来了，两个地方，第一个地方是电机回传的数据，也就是actual_velocity,我的看法是
对于所有原始数据都应该进行一定的处理，一定要写一个函数进行处理、或者宏直接定义一个比例系数

第二个是上位机传输的数据，但是要经过解包，一定要解包，我感觉必须规范化，把这个过程规范化

*/
#endif
