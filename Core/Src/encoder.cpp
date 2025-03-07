#include "encoder.h"
#include "tim.h"
#include "condition.h"


int Encoder_GetCounter (const int name)
{
    int counter{};
    if (name == 'A')
    {
        counter = __HAL_TIM_GetCounter(&A_ENCODER_TIM);
    }
    else if (name == 'B')
    {
        counter = __HAL_TIM_GetCounter(&B_ENCODER_TIM);
    }
    else if (name == 'C')
    {
        counter = __HAL_TIM_GetCounter(&C_ENCODER_TIM);
    }
    else if (name == 'D')
    {
        counter = __HAL_TIM_GetCounter(&D_ENCODER_TIM);
    }

    return counter;

}

void Encoder_SetCounter (const int name, const int value)
{
    if (name == 'A')
    {
        __HAL_TIM_SetCounter(&A_ENCODER_TIM, value);
    }
    else if (name == 'B')
    {
        __HAL_TIM_SetCounter(&B_ENCODER_TIM, value);
    }
    else if (name == 'C')
    {
        __HAL_TIM_SetCounter(&C_ENCODER_TIM, value);
    }
    else if (name == 'D')
    {
        __HAL_TIM_SetCounter(&D_ENCODER_TIM, value);
    }
}

WheelCondition Encoder2Wheel(void)
{
    const double v_A = Encoder_GetCounter('A') * conversion_factor;
    const double v_B = Encoder_GetCounter('B') * conversion_factor;
    const double v_C = Encoder_GetCounter('C') * conversion_factor;
    const double v_D = Encoder_GetCounter('D') * conversion_factor;

    const WheelCondition Wheel={
        .A_velocity = v_A,
        .B_velocity = v_B,
        .C_velocity = v_C,
        .D_velocity = v_D
    };

    Encoder_SetCounter ('A', 0);
    Encoder_SetCounter ('B', 0);
    Encoder_SetCounter ('C', 0);
    Encoder_SetCounter ('D', 0);

    return Wheel;
}