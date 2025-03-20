#include "jetson.h"
#include <stdio.h>
#include "Setup_and_Loop.h"
#include "usart.h"
// #include "dma.h"

uint8_t * jetson_init()
{
    static const int RX_BUFFER_SIZE = 9;
    static uint8_t JETSON_RX_BUFFER[RX_BUFFER_SIZE];
    return JETSON_RX_BUFFER;
}

void Jetson2Servo(const uint8_t* jetson_data, Servos * servo)
{
    servo->pitch = 100 * (jetson_data[1] - '0') + 10 * (jetson_data[2] - '0') + (jetson_data[3] - '0');
    servo->yaw = 100 * (jetson_data[5] - '0') + 10 * (jetson_data[6] - '0') + (jetson_data[7] - '0');
}


