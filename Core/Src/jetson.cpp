#include "jetson.h"
#include <stdlib.h>
#include <stdio.h>
#include "stm32f4xx_hal.h"
#include "stm32f4xx_hal_tim.h"
#include "stm32f4xx_hal_dma.h"
#include "stm32f4xx_hal_uart.h"

Servos Jetson2Servo(const char* jetson_data)
{
    Servos servo;
    if (sscanf(jetson_data, "<%d,%d", &servo.pitch, &servo.yaw) == 2)
    {
        //printf("Received Pan: %d, Tilt: %d\n", servo.pitch, servo.yaw);
        return servo;
    }
    else
    {
        printf("Invalid data format!\n");
        return {90, 135};
    }
}

