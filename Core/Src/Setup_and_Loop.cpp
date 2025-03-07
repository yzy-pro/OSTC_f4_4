#include "PID.h"
#include "encoder.h"
#include "Setup_and_Loop.h"
#include "tim.h"

#include "motor.h"

RobotCondition getsettings()
{
    return {0,0,0};
}

void setup()
{
    HAL_TIM_PWM_Start(&htim1, TIM_CHANNEL_3);
    HAL_TIM_PWM_Start(&htim1, TIM_CHANNEL_4);
    HAL_TIM_PWM_Start(&htim1, TIM_CHANNEL_1);
    HAL_TIM_PWM_Start(&htim1, TIM_CHANNEL_2);
    HAL_TIM_PWM_Start(&htim9, TIM_CHANNEL_1);
    HAL_TIM_PWM_Start(&htim9, TIM_CHANNEL_2);
    HAL_TIM_PWM_Start(&htim10, TIM_CHANNEL_1);
    HAL_TIM_PWM_Start(&htim11, TIM_CHANNEL_1);
    __HAL_TIM_SetCounter(&htim3, 0);
    __HAL_TIM_SetCounter(&htim3, 0);
    __HAL_TIM_SetCounter(&htim4, 0);
    __HAL_TIM_SetCounter(&htim5, 0);
}

void loop()
{
    if (encoder_timer())
    {
        const WheelCondition target = Robot2Wheel(getsettings());
        const WheelCondition current = Encoder2Wheel();
        motors_control(velocity_control(target, current));
    }
}