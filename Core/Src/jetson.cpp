#include "jetson.h"
#include <stdlib.h>
#include <stdio.h>
#include "Setup_and_Loop.h"
#include "usart.h"

uint8_t * jetson_init()
{
    static bool is_init = false;
    static const int RX_BUFFER_SIZE=100;
    static uint8_t * JETSON_RX_BUFFER;
    if (!is_init)
    {
        JETSON_RX_BUFFER = (uint8_t*)malloc(RX_BUFFER_SIZE * sizeof
    (uint8_t));
        HAL_UART_Receive_DMA(&JETSON_HUART, JETSON_RX_BUFFER, RX_BUFFER_SIZE);
        HAL_NVIC_EnableIRQ(JETSON_DMA_IRQn);
        is_init = true;
    }
    return JETSON_RX_BUFFER;
}

Servos Jetson2Servo(const uint8_t* jetson_data)
{
    Servos servo = {90, 135};  // Default values
    const char* ptr = (const char*)jetson_data;

    // Find opening '<'
    while (*ptr && *ptr != '<') ptr++;
    if (*ptr++ != '<') {
        printf("Invalid data format!\n");
        return servo;
    }

    // Parse pitch value
    char* endptr;
    servo.pitch = (int)strtol(ptr, &endptr, 10);
    if (endptr == ptr || *endptr != ',') {
        printf("Invalid data format!\n");
        return servo;
    }

    // Parse yaw value
    ptr = endptr + 1;
    servo.yaw = (int)strtol(ptr, &endptr, 10);
    if (endptr == ptr) {
        printf("Invalid data format!\n");
        return servo;
    }

    return servo;

    // Servos servo = {90, 135};  // Default values
    //
    // // 使用 sscanf 解析数据
    // int result = sscanf((const char*)jetson_data, "<%d,%d", &servo.pitch, &servo.yaw);
    //
    // if (result != 2) {
    //     printf("Invalid data format!\n");
    //     return servo;
    // }
    //
    // return servo;

}

