#include "jetson.h"
#include <stdlib.h>
#include <stdio.h>


Servos Jetson2Servo(const uint8_t* jetson_data)
{
    // Servos servo;
    // if (sscanf((char*)jetson_data, "<%d,%d", &servo.pitch, &servo.yaw) == 2)
    // {
    //     //printf("Received Pan: %d, Tilt: %d\n", servo.pitch, servo.yaw);
    //     return servo;
    // }
    // else
    // {
    //     printf("Invalid data format!\n");
    //     return {90, 135};
    // }

    Servos servo = {90, 135};

    const uint8_t* ptr = jetson_data;

    while (*ptr && *ptr != '<')
    {
        ptr++;
    }

    if (*ptr == '<') {
        ptr++;

        char* endptr;
        servo.pitch = (int)strtol((char*)ptr, &endptr, 10);
        ptr = (const uint8_t*)endptr;

        if (*ptr == ',') {
            ptr++;

            servo.yaw = (int)strtol((char*)ptr, &endptr, 10);
            ptr = (const uint8_t*)endptr;
        }
        else {
            printf("Invalid data format: missing ','\n");
            return servo;
        }

        if (*ptr == '\n') {
            return servo;
        }
        else {
            printf("Invalid data format: missing newline '\\n'\n");
            return servo;
        }
    }
    else {
        printf("Invalid data format: missing '<'\n");
        return servo;
    }
}

