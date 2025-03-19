#ifndef JETSON_H
#define JETSON_H
//jetson通信
#ifdef __cplusplus
extern "C" {
#endif
#include <stdint.h>
#include "condition.h"

    uint8_t * jetson_init(void);
    void Jetson2Servo(const uint8_t* jetson_data, Servos * servo);

#ifdef __cplusplus
}
#endif
#endif //JETSON_H
