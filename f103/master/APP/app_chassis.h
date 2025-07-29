#ifndef __APP_CHASSIS_H__
#define __APP_CHASSIS_H__


#include "alg_pid.h"
class CHASSIS
{
public:
    void Chassis_Solution();
    void Chassis_Init();
    PID pid[2];
void Motor_SetOutput(float pid_output,int i);
void data_proc(float* data);

};

void chassis_proc();
//extern CHASSIS chassis;

#endif
