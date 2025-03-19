#include "jetson.h"
#include <stdio.h>
#include "Setup_and_Loop.h"
#include "usart.h"
// #include "dma.h"

uint8_t * jetson_init()
{
    static const int RX_BUFFER_SIZE = 2;
    static uint8_t JETSON_RX_BUFFER[RX_BUFFER_SIZE];
    return JETSON_RX_BUFFER;
}

void Jetson2Servo(const uint8_t* jetson_data, Servos * servo)
{
    if (sscanf((const char*)jetson_data, "<%d,%d", &servo->pitch, &servo->yaw) != 2) {
        printf("Invalid data format!\n");
        return;
    }
}


