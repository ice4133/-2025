#include "app_test.h"
#include "tim.h"

void set_output()
{
	__HAL_TIM_SET_COMPARE(&htim3,TIM_CHANNEL_1,0);
	__HAL_TIM_SET_COMPARE(&htim3,TIM_CHANNEL_2,1000);
}


void test_proc()
{
	set_output();
}	

