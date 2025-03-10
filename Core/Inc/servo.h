#ifndef SERVO_H
#define SERVO_H
#ifdef __cplusplus
extern "C" {
#endif

#include "condition.h"

void servo_control(int name, int pwm_angle);
void servos_control(const Servos Plus);

#ifdef __cplusplus
}
#endif

#endif //SERVO_H
