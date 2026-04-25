#include "sensor_temp_humi.h"
#include <rtthread.h>

int sensor_temp_humi_init(void)
{
    rt_kprintf("sensor init ok\n");
    return 0;
}

int sensor_temp_humi_read(float *temp, float *humi)
{
    if (temp == RT_NULL || humi == RT_NULL)
        return -1;

    *temp = 25.5;
    *humi = 60.0;

    return 0;
}
