#ifndef ENCODER_H
#define ENCODER_H

#ifdef __cplusplus
extern "C" {
#endif

#include "condition.h"

int Encoder_GetCounter (int name);
void Encoder_SetCounter (int name, int value);

WheelCondition Encoder2Wheel(void);

#ifdef __cplusplus
}
#endif

#endif //ENCODER_H
