#ifndef JETSON_H
#define JETSON_H
#ifdef __cplusplus
extern "C" {
#endif
#include <stdint.h>
#include "condition.h"

#define RX_BUFFER_SIZE 100
extern uint8_t* rx_buffer;

Servos Jetson2Servo(const uint8_t * jetson_data);
#ifdef __cplusplus
}
#endif
#endif //JETSON_H
