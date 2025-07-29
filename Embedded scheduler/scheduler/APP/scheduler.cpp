#include "scheduler.h"
#include "chassis.h"
uint8_t task_num;

struct task_t
{
    void (*task_func)(void);
    uint32_t rate_ms;
    uint32_t last_run;
} ;


static task_t scheduler_task[] =
{
	{target_proc,100,0},
		{encoder_proc,20,0},
     {chassis_proc,20,0}
};


void scheduler_init()
{
    task_num = sizeof(scheduler_task) / sizeof(task_t);
}

void scheduler_run()
{

    for (uint8_t i = 0; i < task_num; i++)
    {
       
        uint32_t now_time = HAL_GetTick();

        if (now_time >= scheduler_task[i].rate_ms + scheduler_task[i].last_run)
        {
            scheduler_task[i].last_run = now_time;

            scheduler_task[i].task_func();
        }
    }
}

