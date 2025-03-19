#ifndef SETUP_AND_LOOP_H
#define SETUP_AND_LOOP_H
//把控制主程序封装了一下，主要是因为用cubemx生成代码容易在main文件里面出现奇怪的问题
//控制的其他部分参看stm32f4xx_it.h文件中的中断控制
#ifdef __cplusplus
extern "C"{
#endif
   //define wheels
#define A_MOTOR_TIM htim1
#define A_MOTOR_CHANNEL_BI TIM_CHANNEL_3
#define A_MOTOR_CHANNEL_FI TIM_CHANNEL_4
#define A_ENCODER_TIM htim5

#define B_MOTOR_TIM htim1
#define B_MOTOR_CHANNEL_BI TIM_CHANNEL_1
#define B_MOTOR_CHANNEL_FI TIM_CHANNEL_2
#define B_ENCODER_TIM htim2

#define C_MOTOR_TIM htim9
#define C_MOTOR_CHANNEL_BI TIM_CHANNEL_2
#define C_MOTOR_CHANNEL_FI TIM_CHANNEL_1
#define C_ENCODER_TIM htim4

#define D_MOTOR_TIM_BI htim10
#define D_MOTOR_CHANNEL_BI TIM_CHANNEL_1
#define D_MOTOR_TIM_FI htim11
#define D_MOTOR_CHANNEL_FI TIM_CHANNEL_1
#define D_ENCODER_TIM htim3

#define ENCODER_TIM htim7

#define JETSON_HUART huart1

#define JETSON_DMA_IRQn DMA2_Stream0_IRQn

#define SERVO_TIM htim8
#define SERVO_PITCH_CHANNEL TIM_CHANNEL_3
#define SERVO_YAW_CHANNEL TIM_CHANNEL_4
#include "condition.h"
#include "robot.h"

   void setup(Robot * myrobot);
   void loop(Robot * myrobot);

   void getsettings(RobotCondition * Robot);
   void set_calls(int * call);
   void reset_calls(int * call);

#ifdef __cplusplus
}
#endif

#endif //SETUP_AND_LOOP_H
