#ifndef SETUP_AND_LOOP_H
#define SETUP_AND_LOOP_H
#ifdef __cplusplus
extern "C"{
#endif
   //define motors
#define C_MOTOR_TIM htim9
#define C_MOTOR_CHANNEL_BI TIM_CHANNEL_2
#define C_MOTOR_CHANNEL_FI TIM_CHANNEL_1

#define B_MOTOR_TIM htim1
#define B_MOTOR_CHANNEL_BI TIM_CHANNEL_1
#define B_MOTOR_CHANNEL_FI TIM_CHANNEL_2

#define A_MOTOR_TIM htim1
#define A_MOTOR_CHANNEL_BI TIM_CHANNEL_3
#define A_MOTOR_CHANNEL_FI TIM_CHANNEL_4

#define D_MOTOR_TIM_BI htim10
#define D_MOTOR_CHANNEL_BI TIM_CHANNEL_1
#define D_MOTOR_TIM_FI htim11
#define D_MOTOR_CHANNEL_FI TIM_CHANNEL_1

    //define encoders
#define C_ENCODER_TIM htim4
#define A_ENCODER_TIM htim5
#define B_ENCODER_TIM htim2
#define D_ENCODER_TIM htim3

    //define pins

#define JETSON_HUART huart1

#define SERVO_TIM htim3
#define SERVO_PITCH_CHANNEL TIM_CHANNEL_3
#define SERVO_YAW_CHANNEL TIM_CHANNEL_4

void setup();
void loop();

#ifdef __cplusplus
}
#endif

#endif //SETUP_AND_LOOP_H
