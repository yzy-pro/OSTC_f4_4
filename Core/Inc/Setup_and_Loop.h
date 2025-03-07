
#ifndef SETUP_AND_LOOP_H
#define SETUP_AND_LOOP_H
#ifdef __cplusplus
extern "C"{
#endif

    //define motors
#define A_MOTOR_TIM htim9
#define A_MOTOR_CHANNEL_BI TIM_CHANNEL_2
#define A_MOTOR_CHANNEL_FI TIM_CHANNEL_1

#define B_MOTOR_TIM htim1
#define B_MOTOR_CHANNEL_BI TIM_CHANNEL_1
#define B_MOTOR_CHANNEL_FI TIM_CHANNEL_2

#define C_MOTOR_TIM htim1
#define C_MOTOR_CHANNEL_BI TIM_CHANNEL_3
#define C_MOTOR_CHANNEL_FI TIM_CHANNEL_4

#define D_MOTOR_TIM_BI htim10
#define D_MOTOR_CHANNEL_BI TIM_CHANNEL_1
#define D_MOTOR_TIM_FI htim11
#define D_MOTOR_CHANNEL_FI TIM_CHANNEL_1

    //define encoders
#define A_ENCODER_TIM htim4
#define B_ENCODER_TIM htim5
#define C_ENCODER_TIM htim2
#define D_ENCODER_TIM htim3

    //define pins
#define A_MOTOR_FI_Pin GPIO_PIN_5
#define A_MOTOR_FI_GPIO_Port GPIOE
#define A_MOTOR_BI_Pin GPIO_PIN_6
#define A_MOTOR_BI_GPIO_Port GPIOE
#define B_ENCODER_3_Pin GPIO_PIN_0
#define B_ENCODER_3_GPIO_Port GPIOA
#define B_ENCODER_4_Pin GPIO_PIN_1
#define B_ENCODER_4_GPIO_Port GPIOA
#define B_MOTOR_BI_Pin GPIO_PIN_9
#define B_MOTOR_BI_GPIO_Port GPIOE
#define B_MOTOR_FI_Pin GPIO_PIN_11
#define B_MOTOR_FI_GPIO_Port GPIOE
#define C_MOTOR_BI_Pin GPIO_PIN_13
#define C_MOTOR_BI_GPIO_Port GPIOE
#define C_MOTOR_FI_Pin GPIO_PIN_14
#define C_MOTOR_FI_GPIO_Port GPIOE
#define C_ENCODER_3_Pin GPIO_PIN_15
#define C_ENCODER_3_GPIO_Port GPIOA
#define C_ENCODER_4_Pin GPIO_PIN_3
#define C_ENCODER_4_GPIO_Port GPIOB
#define D_ENCODER_3_Pin GPIO_PIN_4
#define D_ENCODER_3_GPIO_Port GPIOB
#define D_ENCODER_4_Pin GPIO_PIN_5
#define D_ENCODER_4_GPIO_Port GPIOB
#define A_ENCODER_3_Pin GPIO_PIN_6
#define A_ENCODER_3_GPIO_Port GPIOB
#define A_ENCODER_4_Pin GPIO_PIN_7
#define A_ENCODER_4_GPIO_Port GPIOB
#define D_MOTOR_BI_Pin GPIO_PIN_8
#define D_MOTOR_BI_GPIO_Port GPIOB
#define D_MOTOR_FI_Pin GPIO_PIN_9
#define D_MOTOR_FI_GPIO_Port GPIOB

void setup();
void loop();

#ifdef __cplusplus
}
#endif
#endif //SETUP_AND_LOOP_H
