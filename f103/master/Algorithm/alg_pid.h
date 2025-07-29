#ifndef __ALG_PID_H__
#define __ALG_PID_H__

class PID
{
public:
    void PID_Init(float kp,float ki,float kd,float integral_max,float output_max);
    float PID_Compute(float target, float actual);

private:
    float Kp;            // 比例系数
    float Ki;            // 积分系数
    float Kd;            // 微分系数
    float target;        // 目标转速
    float integral_max;  // 积分限幅
    float output_max;    // 输出限幅
    
    // 内部状态变量
    float error;         // 当前误差
    float last_error;    // 上次误差
    float integral;      // 积分累积值
};

#endif
