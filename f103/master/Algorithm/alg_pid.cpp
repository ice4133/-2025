#include "alg_pid.h"

float PID::PID_Compute(float target, float actual)
{


    // 误差计算
   this->error = target - actual;
    
    // 积分项限幅
    this->integral += this->error;
    if(this->integral > this->integral_max) 
        this->integral = this->integral_max;
    else if(this->integral < -this->integral_max)
        this->integral = -this->integral_max;
    
    // 微分项计算
    float derivative = this->error - this->last_error;
    
    // PID输出
    float output = this->Kp * this->error + 
                  this->Ki * this->integral + 
                  this->Kd * derivative;
    
    // 输出限幅
    if(output > this->output_max) output = this->output_max;
    else if(output < -this->output_max) output = -this->output_max;
    
    // 更新历史误差
    this->last_error = this->error;
    
    return output; // 返回带符号输出
}

void PID::PID_Init(float kp,float ki,float kd,float integral_max,float output_max)
{
    this->Kp=kp;
    this->Ki=ki;
    this->Kd=kd;
    this->integral_max=integral_max;
    this->output_max=output_max;
}



