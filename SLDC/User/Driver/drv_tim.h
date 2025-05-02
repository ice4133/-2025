/**
 * @file drv_tim.h
 * @author xxl
 * @brief TIM定时器初始化与配置流程, 仅有中断回调函数参数
 * @version 0.1
 * @date 
 *
 * 
 *
 */
 
 #ifndef __DRV_TIM_H__
 #define __DRV_TIM_H__
 
 
/* Include */

#include "stm32f4xx_hal.h"
 extern "C" 
{
 typedef void(* TIM_Call_Back)();

 
/**
* @brief 
*
*
*/
struct Struct_TIM_Manage_Object
{
    TIM_HandleTypeDef *TIM_Handler;
    TIM_Call_Back Callback_Function;
};
 

extern TIM_HandleTypeDef htim1;
extern TIM_HandleTypeDef htim2;
extern TIM_HandleTypeDef htim3;
extern TIM_HandleTypeDef htim4;
extern TIM_HandleTypeDef htim5;
extern TIM_HandleTypeDef htim8;
extern TIM_HandleTypeDef htim9;
extern TIM_HandleTypeDef htim11;
extern TIM_HandleTypeDef htim12;


extern Struct_TIM_Manage_Object TIM3_Manage_Object;
extern Struct_TIM_Manage_Object TIM5_Manage_Object;


/* Exported function declarations --------------------------------------------*/

void TIM_Init(TIM_HandleTypeDef *htim, TIM_Call_Back Callback_Function);

}
#endif
