#ifndef __CONFIG_H__
#define __CONFIG_H__

#include "main.h"
#include "tim.h"
#include "gpio.h"
#include "math.h"

#include "scheduler.h"
#include "encoder.h"
#include "interaction.h"
//#include "chassis.h"
#include "gimbal.h"


#include "drv_dma.h"


#define PROPORTION_ACTUAL 0.666667f
#define PROPORTION_TARGET 0.14f

extern float actual_velocity[4];
extern float target_velocity[4];
extern float output;
extern uint8_t uart_rx_buffer[128];
extern DMA_HandleTypeDef hdma_usart1_rx;
extern UART_HandleTypeDef huart1;

#endif
