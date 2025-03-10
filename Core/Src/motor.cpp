#include "motor.h"
#include "Setup_and_Loop.h"
#include "tim.h"

void motor_control(const int name, int pwm_velocity)
{
    if (pwm_velocity > abs_MAX_pwm_velocity || pwm_velocity < -abs_MAX_pwm_velocity)
    {
        if (pwm_velocity > abs_MAX_pwm_velocity)
        {
            pwm_velocity = abs_MAX_pwm_velocity;
        }
        else if (pwm_velocity < -abs_MAX_pwm_velocity)
        {
            pwm_velocity = -abs_MAX_pwm_velocity;
        }
    }

    if (name == 'A')
    {
        if (pwm_velocity == 0)
        {
            __HAL_TIM_SetCompare(&A_MOTOR_TIM, A_MOTOR_CHANNEL_BI, 
            abs_MAX_pwm_velocity);
            __HAL_TIM_SetCompare(&A_MOTOR_TIM, A_MOTOR_CHANNEL_FI, 
            abs_MAX_pwm_velocity);
        }
        else if (pwm_velocity > 0)
        {
            __HAL_TIM_SetCompare(&A_MOTOR_TIM, A_MOTOR_CHANNEL_BI, pwm_velocity);
            __HAL_TIM_SetCompare(&A_MOTOR_TIM, A_MOTOR_CHANNEL_FI, 0);
        }
        else if (pwm_velocity < -0)
        {
            pwm_velocity = -pwm_velocity;
            __HAL_TIM_SetCompare(&A_MOTOR_TIM, A_MOTOR_CHANNEL_BI, 0);
            __HAL_TIM_SetCompare(&A_MOTOR_TIM, A_MOTOR_CHANNEL_FI, pwm_velocity);
        }

    }
    else if (name == 'B')
    {
        if (pwm_velocity == 0)
        {
            __HAL_TIM_SetCompare(&B_MOTOR_TIM, B_MOTOR_CHANNEL_BI, abs_MAX_pwm_velocity);
            __HAL_TIM_SetCompare(&B_MOTOR_TIM, B_MOTOR_CHANNEL_FI, abs_MAX_pwm_velocity);
        }
        else if (pwm_velocity > 0)
        {
            __HAL_TIM_SetCompare(&B_MOTOR_TIM, B_MOTOR_CHANNEL_BI, pwm_velocity);
            __HAL_TIM_SetCompare(&B_MOTOR_TIM, B_MOTOR_CHANNEL_FI, 0);
        }
        else if (pwm_velocity < -0)
        {
            pwm_velocity = -pwm_velocity;
            __HAL_TIM_SetCompare(&B_MOTOR_TIM, B_MOTOR_CHANNEL_BI, 0);
            __HAL_TIM_SetCompare(&B_MOTOR_TIM, B_MOTOR_CHANNEL_FI, pwm_velocity);
        }

    }
    else if (name == 'C')
    {
        if (pwm_velocity == 0)
        {
            __HAL_TIM_SetCompare(&C_MOTOR_TIM, C_MOTOR_CHANNEL_BI, abs_MAX_pwm_velocity);
            __HAL_TIM_SetCompare(&C_MOTOR_TIM, C_MOTOR_CHANNEL_FI, abs_MAX_pwm_velocity);
        }
        else if (pwm_velocity > 0)
        {
            __HAL_TIM_SetCompare(&C_MOTOR_TIM, C_MOTOR_CHANNEL_BI, pwm_velocity);
            __HAL_TIM_SetCompare(&C_MOTOR_TIM, C_MOTOR_CHANNEL_FI, 0);
        }
        else if (pwm_velocity < -0)
        {
            pwm_velocity = -pwm_velocity;
            __HAL_TIM_SetCompare(&C_MOTOR_TIM, C_MOTOR_CHANNEL_BI, 0);
            __HAL_TIM_SetCompare(&C_MOTOR_TIM, C_MOTOR_CHANNEL_FI, pwm_velocity);
        }

    }
    else if (name == 'D')
    {
        if (pwm_velocity == 0)
        {
            __HAL_TIM_SetCompare(&D_MOTOR_TIM_BI, D_MOTOR_CHANNEL_BI, abs_MAX_pwm_velocity);
            __HAL_TIM_SetCompare(&D_MOTOR_TIM_FI, D_MOTOR_CHANNEL_FI,
            abs_MAX_pwm_velocity);
        }
        else if (pwm_velocity > 0)
        {
            __HAL_TIM_SetCompare(&D_MOTOR_TIM_BI, D_MOTOR_CHANNEL_BI,
            pwm_velocity);
            __HAL_TIM_SetCompare(&D_MOTOR_TIM_FI, D_MOTOR_CHANNEL_FI, 0);
        }
        else if (pwm_velocity < -0)
        {
            pwm_velocity = -pwm_velocity;
            __HAL_TIM_SetCompare(&D_MOTOR_TIM_BI, D_MOTOR_CHANNEL_BI, 0);
            __HAL_TIM_SetCompare(&D_MOTOR_TIM_FI, D_MOTOR_CHANNEL_FI,
            pwm_velocity);
        }
    }
}

void motors_control(const WheelCondition pwm_velocity)
{
    motor_control('A', static_cast<int>(pwm_velocity.A_velocity));
    motor_control('B', static_cast<int>(pwm_velocity.B_velocity));
    motor_control('C', static_cast<int>(pwm_velocity.C_velocity));
    motor_control('D', static_cast<int>(pwm_velocity.D_velocity));
}
