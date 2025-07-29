#include "drv_dma.h"
#include "config.h"
#include "alg_datachange.h"

uint8_t uart3_rx_data[12]={0};//视觉暂时数据包
float photo_data[4]={140,157,0,0};//视觉实际数据包
uint8_t uart2_rx_data[12]={0};//雷达暂时数据包
float radar_data[3]={0};//雷达实际数据包
void HAL_UARTEx_RxEventCallback(UART_HandleTypeDef *huart, uint16_t Size)
{
	if(huart->Instance==USART2)
	{
		for(int i=0;i<12;i++)
		{
			uart3_rx_data[i]=uart2_rx_buffer[i];
		}
			char_to_float(uart3_rx_data);
		HAL_UARTEx_ReceiveToIdle_DMA(&huart2, uart2_rx_buffer, sizeof(uart2_rx_buffer));
  __HAL_DMA_DISABLE_IT(&hdma_usart2_rx ,DMA_IT_HT);
	}
	if(huart->Instance==USART3)
	{
		for(int i=0;i<12;i++)
		{
			uart3_rx_data[i]=uart3_rx_buffer[i];
		}
		
		//char_to_uint32(uart3_rx_data);
	HAL_UARTEx_ReceiveToIdle_DMA(&huart3, uart3_rx_buffer, sizeof(uart3_rx_buffer));
  __HAL_DMA_DISABLE_IT(&hdma_usart3_rx ,DMA_IT_HT);		
	}


}
