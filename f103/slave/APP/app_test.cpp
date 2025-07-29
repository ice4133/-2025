#include "app_test.h"
#include "tim.h"
#include "config.h"
uint16_t pwm[2]={ 1000,1000};
void pwm_output()
{
	__HAL_TIM_SET_COMPARE(&htim4, TIM_CHANNEL_1,pwm[0]);
	__HAL_TIM_SET_COMPARE(&htim4, TIM_CHANNEL_2,pwm[1]);
}



void test_proc()
{
	pwm_output();
}
