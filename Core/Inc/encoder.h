#ifndef ENCODER_H
#define ENCODER_H
//编码器控制
#ifdef __cplusplus
extern "C" {
#endif

#include "condition.h"

void encoder_init(void);
int Encoder_GetCounter (int name);
void Encoder_SetCounter (int name, int value);

void Encoder2Wheel(WheelCondition * Wheel);

// bool encoder_timer();

#ifdef __cplusplus
}
#endif

#endif //ENCODER_H
