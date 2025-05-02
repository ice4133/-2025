/**
 * @file crt_chassis.h
 * @author xxl
 * @brief 底盘
 * @version 0.1
 * @date 
 *
 * 
 *
 */

#ifndef __CRT_CHASSIS_H__
#define __CRT_CHASSIS_H__

/* Include ------------------------*/
#include "dvc_gmrmotor.h"



/** 
 *
 * @brief 麦轮底盘类
 *
 */
class Class_Mecanum_Chassis
{
public:
	Class_GMR_Motor Motor_Wheel[4];//声明四个麦轮的轮组，用数组来写


		Class_Mecanum_Chassis()
		{
		
		Target_Velocity_X = 0.0f;

		Target_Velocity_Y = 0.0f;

    Target_Omega = 0.0f;

    Now_Velocity_X = 0.0f;

    Now_Velocity_Y = 0.0f;

    Now_Omega = 0.0f;
		}
		void Init(float __Velocity_X_Max = 4.0f, float __Velocity_Y_Max = 4.0f, float __Omega_Max = 8.0f);
		
		// 需要进行保护的变量其实总共有9个，分别是三速度的最大值，目标三速度、现在三速度，但是封装的意义在于保护，但是不需要对现在三速度进行设置，因为不需要
		inline float Get_Velocity_X_Max();
    inline float Get_Velocity_Y_Max();
    inline float Get_Omega_Max();
		
		
		inline void Set_Velocity_Y_Max(float __Velocity_Y_Max);
    inline void Set_Velocity_X_Max(float __Velocity_X_Max);
		inline void Set_Target_Omega_Max(float __Omega_Max);	
		
		
		inline float Get_Target_Velocity_X();		
    inline float Get_Target_Velocity_Y();
    inline float Get_Target_Omega();

    inline void Set_Target_Velocity_X(float __Target_Velocity_X);
    inline void Set_Target_Velocity_Y(float __Target_Velocity_Y);
    inline void Set_Target_Omega(float __Target_Omega);
    inline void Set_Now_Velocity_X(float __Now_Velocity_X);
    inline void Set_Now_Velocity_Y(float __Now_Velocity_Y);
    inline void Set_Now_Omega(float __Now_Omega);


		
		void TIM_Calculate_PeriodElapsedCallback();
protected:

    //初始化相关常量


		//读写变量
    //速度X限制
    float Velocity_X_Max;
    //速度Y限制
    float Velocity_Y_Max;
    //角速度限制
    float Omega_Max;

		//读写变量
	   //目标速度X
    float Target_Velocity_X ;
    //目标速度Y
    float Target_Velocity_Y ;
    //目标角速度
    float Target_Omega ;
    //当前速度X
    float Now_Velocity_X;
    //当前速度Y
    float Now_Velocity_Y;
    //当前角速度
    float Now_Omega;
		
		void Speed_Resolution();//速度解算函数
};


/**
 * @brief 获取目标速度X的最大值
 *
 * @return 返回目标速度最大值
 */
float Class_Mecanum_Chassis::Get_Velocity_X_Max()
{
	 return (Velocity_X_Max);
}


/**
* @brief 获取目标速度Y的最大值
*
* @return 返回目标速度Y最大值
*/
float Class_Mecanum_Chassis::Get_Velocity_Y_Max()
{
	 return (Velocity_Y_Max);
}


/**
* @brief 获取目标角速度的最大值
*
* @return 返回目标角速度最大值
*/
float Class_Mecanum_Chassis::Get_Omega_Max()
{
	return (Omega_Max);
}


/**
 * @brief 获取目标速度Y的最大值
 *
 * 
 */
void Class_Mecanum_Chassis::Set_Velocity_Y_Max(float __Velocity_Y_Max)
{
	 Velocity_Y_Max=__Velocity_Y_Max;
}


/**
* @brief 获取目标速度X的最大值
*
* 
*/
void Class_Mecanum_Chassis::Set_Velocity_X_Max(float __Velocity_X_Max)
{
	 Velocity_X_Max=__Velocity_X_Max;
}


/**
* @brief 获取目标角速度的最大值
*
* 
*/
void Class_Mecanum_Chassis::Set_Target_Omega_Max(float __Omega_Max)
{
	Omega_Max=__Omega_Max;
}


float Class_Mecanum_Chassis::Get_Target_Velocity_X()
{
	return Target_Velocity_X;
}

float Class_Mecanum_Chassis::Get_Target_Velocity_Y()
{
	return Target_Velocity_Y;
}

float Class_Mecanum_Chassis::Get_Target_Omega()
{
	return Target_Omega;
}

/**
 * @brief 设定目标速度X
 *
 * @param __Target_Velocity_X 目标速度X
 */
void Class_Mecanum_Chassis::Set_Target_Velocity_X(float __Target_Velocity_X)
{
    Target_Velocity_X = __Target_Velocity_X;
}

/**
 * @brief 设定目标速度Y
 *
 * @param __Target_Velocity_Y 目标速度Y
 */
void Class_Mecanum_Chassis::Set_Target_Velocity_Y(float __Target_Velocity_Y)
{
    Target_Velocity_Y = __Target_Velocity_Y;
}

/**
 * @brief 设定目标角速度
 *
 * @param __Target_Omega 目标角速度
 */
void Class_Mecanum_Chassis::Set_Target_Omega(float __Target_Omega)
{
    Target_Omega = __Target_Omega;
}

/**
 * @brief 设定当前速度X
 *
 * @param __Now_Velocity_X 当前速度X
 */
void Class_Mecanum_Chassis::Set_Now_Velocity_X(float __Now_Velocity_X)
{
    Now_Velocity_X = __Now_Velocity_X;
}

/**
 * @brief 设定当前速度Y
 *
 * @param __Now_Velocity_Y 当前速度Y
 */
void Class_Mecanum_Chassis::Set_Now_Velocity_Y(float __Now_Velocity_Y)
{
    Now_Velocity_Y = __Now_Velocity_Y;
}

/**
 * @brief 设定当前角速度
 *
 * @param __Now_Omega 当前角速度
 */
void Class_Mecanum_Chassis::Set_Now_Omega(float __Now_Omega)
{
    Now_Omega = __Now_Omega;
}
#endif
