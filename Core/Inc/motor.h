#ifndef MOTOR_H
#define MOTOR_H
//电机控制
#ifdef __cplusplus
extern "C" {
#endif

#include "condition.h"

#define abs_MAX_pwm_velocity 100 // ARR为 100 - 1
void motors_init();
void motor_control(int name, int pwm_velocity);
//电机控制函数
//轮子编号，速度（pwm）

void motors_control(WheelCondition * pwm_velocity);
//


#ifdef __cplusplus
}
#endif

#endif //MOTOR_H
