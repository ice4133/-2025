#ifndef __CHASSIS_H__
#define __CHASSIS_H__

#include "config.h"
#include "alg_pid.h"

class CHASSIS
{
public:
    void Chassis_Solution();
    void Chassis_Init();
    PID pid[4];
void Motor_SetOutput(float pid_output,int i);
private:

};

void chassis_proc();
extern CHASSIS chassis;
#endif

