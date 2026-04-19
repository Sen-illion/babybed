#include <rtdevice.h>
#include "app_proto.h"

rt_size_t app_proto_format_uplink(char *buf,
                                  rt_size_t buf_size,
                                  const app_env_frame_t *env,
                                  const app_risk_result_t *risk)
{
    rt_int32_t n;

    if ((buf == RT_NULL) || (env == RT_NULL) || (risk == RT_NULL) || (buf_size == 0))
    {
        return 0;
    }

    n = rt_snprintf(buf, buf_size,
                    "ts=%lu,temp=%d.%02dC,humi=%d.%02d%%,smoke=%dppm,risk=%d,score=%u,reason=%s",
                    (unsigned long)env->ts_ms,
                    env->temp_centi_c / 100, env->temp_centi_c % 100,
                    env->humi_centi_pct / 100, env->humi_centi_pct % 100,
                    env->smoke_ppm,
                    (int)risk->level,
                    (unsigned int)risk->score,
                    risk->reason);

    if (n <= 0)
    {
        return 0;
    }

    if ((rt_size_t)n >= buf_size)
    {
        return buf_size - 1;
    }

    return (rt_size_t)n;
}
