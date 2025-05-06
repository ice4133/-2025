/**
 * @file drv_uart.h
 * @brief 串口底层
 * @author xxl
 *
 *
 */
 
 #ifndef __DRV_UART_H__
 #define __DRV_UART_H__
 
 #ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/

#include "stm32f4xx_hal.h"
	#include "usart.h"

/* Exported macros -----------------------------------------------------------*/

// 缓冲区字节长度
#define UART_BUFFER_SIZE 128

/* Exported types ------------------------------------------------------------*/

/**
 * @brief UART通信接收回调函数数据类型
 *
 */
typedef void (*UART_Call_Back)(uint8_t *Buffer, uint16_t Length);

/**
 * @brief UART通信处理结构体
 */
struct Struct_UART_Manage_Object
{
    UART_HandleTypeDef *UART_Handler;
    uint8_t Tx_Buffer[UART_BUFFER_SIZE];
    uint8_t Rx_Buffer[UART_BUFFER_SIZE];
    uint16_t Rx_Buffer_Length;
    uint16_t Tx_Buffer_Length;
    uint16_t Rx_Length;
    uint16_t Tx_Length;
    UART_Call_Back Callback_Function;
};

/* Exported variables --------------------------------------------------------*/



extern UART_HandleTypeDef huart1;
//extern UART_HandleTypeDef huart2;
//extern UART_HandleTypeDef huart3;
//extern UART_HandleTypeDef huart6;
//extern UART_HandleTypeDef huart7;

extern struct Struct_UART_Manage_Object UART1_Manage_Object;
//extern struct Struct_UART_Manage_Object UART2_Manage_Object;
//extern struct Struct_UART_Manage_Object UART3_Manage_Object;
//extern struct Struct_UART_Manage_Object UART4_Manage_Object;
//extern struct Struct_UART_Manage_Object UART5_Manage_Object;
//extern struct Struct_UART_Manage_Object UART6_Manage_Object;
//extern struct Struct_UART_Manage_Object UART7_Manage_Object;
//extern struct Struct_UART_Manage_Object UART8_Manage_Object;

/* Exported function declarations --------------------------------------------*/

void UART_Init(UART_HandleTypeDef *huart, UART_Call_Back Callback_Function, uint16_t Rx_Buffer_Length);

//uint8_t UART_Send_Data(UART_HandleTypeDef *huart, uint8_t *Data, uint16_t Length);

//void TIM_UART_PeriodElapsedCallback();
		void PWM_PeriodElapsedCallBack();
#ifdef __cplusplus
}
#endif

#endif

/************************ COPYRIGHT(C) USTC-ROBOWALKER **************************/
