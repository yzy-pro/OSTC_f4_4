#ifndef ROBOT_H
#define ROBOT_H

#ifdef __cplusplus
extern "C" {
#endif

#include "condition.h"

typedef struct{
    //polar
    Polar_RobotCondition polar_traget;
    Polar_RobotCondition polar_current;
    //robot
    RobotCondition robot_traget;
    RobotCondition robot_current;
    //wheel
    WheelCondition wheel_traget;
    WheelCondition wheel_current;
    WheelCondition wheel_traget_pwm;
    WheelCondition wheel_current_pwm;
    //jetson

    //servo
    Servos servo_traget;
    Servos servo_current;
    Servos servos_target_plus;
    Servos servos_current_plus;
    //location
    Location location;
    //calls
    int tim7_call;
    int dma2_call;
}Robot;

Robot * robot_init();

#ifdef __cplusplus
    }
#endif

#endif //ROBOT_H
