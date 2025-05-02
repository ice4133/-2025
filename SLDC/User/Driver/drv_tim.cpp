/**
 * @file drv_tim.cpp
 * @author xxl
 * @brief TIM定时器初始化与配置流程, 仅有中断回调函数参数
 * @version 0.1
 * @date 
 *
 * @copyright 
 *
 */

/* Includes ------------------------------------------------------------------*/

#include "drv_tim.h"

/* Private macros ------------------------------------------------------------*/

/* Private types -------------------------------------------------------------*/

/* Private variables ---------------------------------------------------------*/


Struct_TIM_Manage_Object TIM3_Manage_Object;
Struct_TIM_Manage_Object TIM5_Manage_Object;


/* Private function declarations ---------------------------------------------*/

/* function prototypes -------------------------------------------------------*/
/* include */
#include "drv_tim.h"
/**
 * @brief 初始化TIM定时器
 *
 * @param htim 定时器编号
 * @param Callback_Function 处理回调函数
 */
void TIM_Init(TIM_HandleTypeDef *htim, TIM_Call_Back Callback_Function)
{
  
		if (htim->Instance == TIM3)
    {
        TIM3_Manage_Object.TIM_Handler = htim;
        TIM3_Manage_Object.Callback_Function = Callback_Function;
    }

    else if (htim->Instance == TIM5)
    {
        TIM5_Manage_Object.TIM_Handler = htim;
        TIM5_Manage_Object.Callback_Function = Callback_Function;
    }

 
}

/**
 * @brief HAL库TIM定时器中断
 *
 * @param htim TIM编号
 */
void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim)
{
    // //判断程序初始化完成
    // if(init_finished == 0)
    // {
    //     return;
    // }


    if (htim->Instance == TIM3)
    {
        TIM3_Manage_Object.Callback_Function();
    }

    else if (htim->Instance == TIM5)
    {
        TIM5_Manage_Object.Callback_Function();
    }
}
/************************ COPYRIGHT(C) USTC-ROBOWALKER **************************/
