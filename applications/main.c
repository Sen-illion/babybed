#include <rtthread.h>
#include <rtdevice.h>
#include <board.h>
#include "app_task.h"

int main(void)
{
    rt_kprintf("\r\n=== BabyBed Safety Node Boot ===\r\n");
    rt_kprintf("RT-Thread core: Cortex-M33\r\n");

    if (app_task_init() != RT_EOK)
    {
        rt_kprintf("[main] app_task_init failed\r\n");
        return -RT_ERROR;
    }

    rt_kprintf("[main] task framework started\r\n");
    return 0;
}
