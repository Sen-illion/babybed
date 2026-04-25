#include "sensor_temp_humi.h"
#include <rtthread.h>
#include <rtdevice.h>
#include "sensor_asair_aht10.h"

#define AHT10_I2C_BUS "i2c4"

static rt_device_t temp_dev = RT_NULL;
static rt_device_t humi_dev = RT_NULL;

int sensor_temp_humi_init(void)
{
    struct rt_sensor_config cfg;

    cfg.intf.dev_name = AHT10_I2C_BUS;
    cfg.intf.user_data = (void *)AHT10_I2C_ADDR;

    rt_hw_aht10_init("aht10", &cfg);

    temp_dev = rt_device_find("temp_aht10");
    humi_dev = rt_device_find("humi_aht10");

    if (temp_dev == RT_NULL || humi_dev == RT_NULL)
    {
        rt_kprintf("AHT10 sensor find failed\n");
        return -1;
    }

    rt_device_open(temp_dev, RT_DEVICE_FLAG_RDONLY);
    rt_device_open(humi_dev, RT_DEVICE_FLAG_RDONLY);

    rt_kprintf("AHT10 init success\n");
    return 0;
}

int sensor_temp_humi_read(float *temp, float *humi)
{
    struct rt_sensor_data temp_data;
    struct rt_sensor_data humi_data;

    if (temp == RT_NULL || humi == RT_NULL)
        return -1;

    if (rt_device_read(temp_dev, 0, &temp_data, 1) != 1)
        return -1;

    if (rt_device_read(humi_dev, 0, &humi_data, 1) != 1)
        return -1;

    *temp = temp_data.data.temp / 10.0f;
    *humi = humi_data.data.humi / 10.0f;

    return 0;
}
