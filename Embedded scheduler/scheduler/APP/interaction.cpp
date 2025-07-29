#include "interaction.h"
#include "string.h"
//todo
//获取target和pwm的target
float target_velocity[4];
uint8_t receive_flag;

void HAL_UARTEx_RxEventCallback(UART_HandleTypeDef *huart, uint16_t Size)
{

    receive_flag=1;
    // 清空DMA缓冲区
    memset(uart_rx_buffer, 0, sizeof(uart_rx_buffer));
	HAL_UARTEx_ReceiveToIdle_DMA(&huart1, uart_rx_buffer, sizeof(uart_rx_buffer));
  __HAL_DMA_DISABLE_IT(&hdma_usart1_rx ,DMA_IT_HT);

}


void data_process()
{
    if(receive_flag!=1)return;

    receive_flag=0;
    //todo 解析
	
}
//todo 获取dma数据
void target_proc()
{
    data_process();
	for(int i=0;i<4;i++)
	target_velocity[i]=200;
}


