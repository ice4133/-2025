/**
* @file dvc_gmrmotor.h
* @brief 电机模块集成PID，相当于舵小板，下放任务，模块化，这个文件只需要一个数据，就是缓冲数值，发送放在另一个模块
* @author xxl
* 
*
*/


#ifndef __DEV_GMRMOTOR_H__
#define __DEV_GMRMOTOR_H__

/* Include */
#include "alg_pid.h"
#include <stdint.h> 



class Class_GMR_Motor
{
public:
	
	Class_GMR_Motor()
	{
	total_count=last_count=0;
	}
	//速度环
	Class_PID PID_Omega;
  
		void Data_Process();//编码器数据处理

protected:
	int encoder_flag;
	int32_t total_count;
	uint16_t last_count;
	uint16_t current_count;
	int16_t delta;
};



#endif
