#ifndef PID_H
#define PID_H
//PID算法
#ifdef __cplusplus
extern "C" {
#endif
#include "condition.h"

int velocity_PID(double target, double current);
void velocity_control(const WheelCondition * target,
const WheelCondition * current, WheelCondition * target_pwm);

#ifdef __cplusplus
}
#endif
#endif //PID_H
