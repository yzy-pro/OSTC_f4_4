#ifndef PID_H
#define PID_H

#ifdef __cplusplus
extern "C" {
#endif
#include "condition.h"

double velocity_PID(double target, double current);
WheelCondition velocity_control(const WheelCondition & target, const
WheelCondition & current);

#ifdef __cplusplus
}
#endif
#endif //PID_H
