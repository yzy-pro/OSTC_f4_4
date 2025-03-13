#include "PID.h"
#include "encoder.h"
#include "Setup_and_Loop.h"
#include "tim.h"
#include "motor.h"
#include "jetson.h"
#include "servo.h"
#include "usart.h"

RobotCondition getsettings()
{
    return {50,50,50};
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

    HAL_TIM_Encoder_Start(&htim2, TIM_CHANNEL_ALL);
    HAL_TIM_Encoder_Start(&htim3, TIM_CHANNEL_ALL);
    HAL_TIM_Encoder_Start(&htim4, TIM_CHANNEL_ALL);
    HAL_TIM_Encoder_Start(&htim5, TIM_CHANNEL_ALL);
    __HAL_TIM_SetCounter(&htim2, 0);
    __HAL_TIM_SetCounter(&htim3, 0);
    __HAL_TIM_SetCounter(&htim4, 0);
    __HAL_TIM_SetCounter(&htim5, 0);

    HAL_UART_Receive_IT(&huart3, rx_buffer, RX_BUFFER_SIZE);
    motors_control({0, 0, 0, 0});
    servos_control({90, 135});
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