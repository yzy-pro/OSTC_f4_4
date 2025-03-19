#include "servo.h"
#include "tim.h"
#include "stm32f4xx_hal_tim.h"
#include "Setup_and_Loop.h"

void servos_init()
{
    HAL_TIM_PWM_Start(&SERVO_TIM, SERVO_PITCH_CHANNEL);
    HAL_TIM_PWM_Start(&SERVO_TIM, SERVO_YAW_CHANNEL);
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

void servos_control(const Servos * Plus)
{
    servo_control('P', Plus->pitch);
    servo_control('Y', Plus->yaw);
}

void servos_test(Robot * myrobot) {
    for (int i = 0; i < 80 ; i++) {
        myrobot->servo_traget = {i, int(i * 1.5)};
        Servo2PLus(&myrobot->servo_traget, &myrobot->servos_target_plus);
        servos_control(&myrobot->servos_target_plus);
        HAL_Delay(10);
    }
    HAL_Delay(1000);
    for (int i = 80; i > 0 ; i--) {
        myrobot->servo_traget = {i, int(i * 1.5)};
        Servo2PLus(&myrobot->servo_traget, &myrobot->servos_target_plus);
        servos_control(&myrobot->servos_target_plus);
        HAL_Delay(10);
    }
    HAL_Delay(1000);
}
