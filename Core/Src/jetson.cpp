#include "jetson.h"

#include <stdio.h>


Servos Jetson2Servo(const uint8_t* jetson_data)
{
    Servos servo;
    if (sscanf((char*)jetson_data, "<%d,%d", &servo.pitch, &servo.yaw) == 2)
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

