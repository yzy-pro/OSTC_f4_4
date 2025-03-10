#include "servo.h"
#include "tim.h"
#include "stm32f4xx_hal_tim.h"
#include "Setup_and_Loop.h"

void servo_control(int name, int pwm_angle)
{
    if (name == 'P')
    {
        __HAL_TIM_SetCompare(&SERVO_TIM, SERVO_PITCH_CHANNEL, pwm_angle);
    }
    else if (name == 'Y')
    {
        __HAL_TIM_SetCompare(&SERVO_TIM, SERVO_YAW_CHANNEL, pwm_angle);
    }
}

void servos_control(const Servos Plus)
{
    servo_control('P', Plus.pitch);
    servo_control('Y', Plus.yaw);
}
