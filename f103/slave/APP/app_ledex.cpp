#include "app_ledex.h"
#include "config.h"
void data_proc()
{
	if(photo_data[2]!=0)
	{
		HAL_GPIO_WritePin(GPIOB,GPIO_PIN_12,GPIO_PIN_SET);
	}
	if(photo_data[3]!=0)
	{
		HAL_GPIO_WritePin(GPIOB,GPIO_PIN_13,GPIO_PIN_SET);		
	}
}
void ledex_proc()
{
	data_proc();
}

