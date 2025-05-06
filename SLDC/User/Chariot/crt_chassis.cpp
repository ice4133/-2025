/**
 * @file crt_chassis.cpp
 * @author xxl
 * @brief 底盘
 * @version 0.1
 * 
 *
 *
 *
 */
 
 /* Include--------------------*/
 #include "crt_chassis.h"
 
 
 
 
 void Class_Mecanum_Chassis::Speed_Resolution()
 {
	 
 }
 /**
 * @brief 定时器3，定时处理雷达回传和编码器回传的数据，处理完得到了target和now的数据，在speedsolution中传给pwm，由pwm输出
 *
 * @introduce 下放模块化，把数据传给电机，target和now，电机里面要有
 */
 void Class_Mecanum_Chassis::TIM_Calculate_PeriodElapsedCallback()
 {
	 //todo 处理雷达数据，把雷达这种类似超声波测距给算成实际速度
	 
	 Speed_Resolution();
 }

 
 void Class_Mecanum_Chassis::UART_RxCpltCallback(uint8_t *Buffer,uint16_t Length)
 {
	 int i=0;
	 UART_Radar_Manage_Object->Rx_Buffer_Length=Length;
	 if(UART_Radar_Manage_Object->Rx_Buffer_Length==14)
	 {
		for(i=0;i<14;i++)
		 {
			 UART_Radar_Manage_Object->Rx_Buffer[i]=Buffer[i];//UART_Radar_Manage_Object->Rx_Buffer6、7、8才是数据
		 }
	 }

 }
 
 