#include "drv_dma.h"
#include "config.h"
#include "alg_datachange.h"
float radar_data[3]={0};
uint8_t uart2_rx_data[14];//雷达数据
uint8_t uart3_rx_data[10];
void HAL_UARTEx_RxEventCallback(UART_HandleTypeDef *huart, uint16_t Size)
{
	if(huart->Instance==USART2)
	{
		
		for(int i=0;i<8;i++)
		{
			uart2_tx_buffer[i]=uart2_rx_data[i]=uart2_rx_buffer[i];
		}
		//char_to_float(uart2_rx_data);
	}
	
	HAL_UARTEx_ReceiveToIdle_DMA(&huart2, uart2_rx_buffer, sizeof(uart2_rx_buffer));
  __HAL_DMA_DISABLE_IT(&hdma_usart2_rx ,DMA_IT_HT);
	//HAL_UART_Transmit_DMA(&huart2,uart2_tx_buffer,sizeof(uart2_tx_buffer));
	//HAL_UART_Transmit_DMA(&huart3,uart2_tx_buffer,sizeof(uart2_tx_buffer));	
}
