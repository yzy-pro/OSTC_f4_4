#include "servo.h"
#include "tim.h"
#include "stm32f4xx_hal_tim.h"
#include "Setup_and_Loop.h"

void servo_init()
{
    HAL_TIM_PWM_Start(&SERVO_TIM, SERVO_PITCH_CHANNEL);
    HAL_TIM_PWM_Start(&SERVO_TIM, SERVO_YAW_CHANNEL);
    servos_control(Servo2PLus({90, 135}));
}

void servo_control(const int name, const int pwm_angle)
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

void servo_test() {
    for (int i = 0; i < 180; i++) {
        servos_control(Servo2PLus({i, (int)(i*1.5)}));
        HAL_Delay(10);
    }
    HAL_Delay(5000);
    for (int i = 0; i < 180; i++) {
        servos_control(Servo2PLus({180 - i, int((180-i)*1.5)}));
        HAL_Delay(10);
    }
    HAL_Delay(5000);
}