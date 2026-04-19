#ifndef APP_PROTO_H__
#define APP_PROTO_H__

#include <rtthread.h>
#include "app_risk.h"

#define APP_PROTO_MAX_TEXT_LEN 128

rt_size_t app_proto_format_uplink(char *buf,
                                  rt_size_t buf_size,
                                  const app_env_frame_t *env,
                                  const app_risk_result_t *risk);

#endif /* APP_PROTO_H__ */
