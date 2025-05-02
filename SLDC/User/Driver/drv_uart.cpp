/**
* @file drv_uart.cpp
* @author xxl
* @brief 底层串口DMA初始化以及配置DMA模式
*
*
*/


/*  Include ---------- */
#include "drv_uart.h"
#include "usart.h"
#include "string.h"


//定义一个数据包，这个数据包包括数据以及函数，小结构
Struct_UART_Manage_Object UART1_Manage_Object={0};


void UART_Init(UART_HandleTypeDef *huart, UART_Call_Back Callback_Function, uint16_t Rx_Buffer_Length)
{
	if(huart->Instance==USART1)
	{
		UART1_Manage_Object.UART_Handler=huart;
		UART1_Manage_Object.Callback_Function=Callback_Function;
		UART1_Manage_Object.Rx_Buffer_Length=Rx_Buffer_Length;
		       HAL_UARTEx_ReceiveToIdle_DMA(huart, UART1_Manage_Object.Rx_Buffer, UART1_Manage_Object.Rx_Buffer_Length);
			__HAL_DMA_DISABLE_IT(&hdma_usart1_rx, DMA_IT_HT);
	}
}

/**
 * @brief 发送数据帧
 *
 * @param huart UART编号
 * @param Data 被发送的数据指针
 * @param Length 长度
 * @return uint8_t 执行状态
 */
uint8_t UART_Send_Data(UART_HandleTypeDef *huart, uint8_t *Data, uint16_t Length)
{
    return (HAL_UART_Transmit_DMA(huart, Data, Length));
}


/** 
* @brief 串口接收DMA中断
* @param huart 串口句柄编号
* @param Size长度
* @introduction 这个DMA空闲中断和HAL_UART_RxCpltCallback的区别在于，前者是专门为DMA的，后者是专门为中断模式，但是后者可以被DMA使用，但是我们一般还是用空闲
*/
void HAL_UARTEx_RxEventCallback(UART_HandleTypeDef *huart, uint16_t Size)
{
	if(huart->Instance==USART1)
	{
        UART1_Manage_Object.Rx_Length = Size;//获取数据长度
        UART1_Manage_Object.Callback_Function(UART1_Manage_Object.Rx_Buffer, Size);//调用函数，在这里我把task里面的uart传到这里，所以这里调用函数，会调用task中的串口函数
		HAL_UARTEx_ReceiveToIdle_DMA(huart, UART1_Manage_Object.Rx_Buffer, UART1_Manage_Object.Rx_Buffer_Length);//开启，因为每次DMA空闲接收完成就会关闭，防止数据重复刷新，硬件关闭，但是我们要多次接收数据，所以要再次开启
				__HAL_DMA_DISABLE_IT(&hdma_usart1_rx, DMA_IT_HT);//失能发送一半就中断的模式		
	}
}


