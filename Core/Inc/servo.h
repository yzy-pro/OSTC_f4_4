#ifndef SERVO_H
#define SERVO_H
//舵机控制
#ifdef __cplusplus
extern "C" {
#endif

#include "condition.h"
#include "robot.h"

void servos_init();
void servo_control(int name, int pwm_angle);
void servos_control(const Servos * Plus);
    void servos_test(Robot * myrobot);

#ifdef __cplusplus
}
#endif

#endif //SERVO_H
