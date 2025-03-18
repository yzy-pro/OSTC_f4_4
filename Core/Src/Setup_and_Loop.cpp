#include "PID.h"
#include "encoder.h"
#include "Setup_and_Loop.h"
#include "motor.h"
#include "jetson.h"
#include "servo.h"
#include "stm32f4xx_it.h"


RobotCondition getsettings()
{
    return {5,5,0};
}

void setup()
{
    // motors_init();
    // encoder_init();
    servo_init();
    jetson_init();
}

void loop()
{
    // if (tim7_call)//tim7是一个10ms触发的计时器
    // {
    //     const WheelCondition target = Robot2Wheel(getsettings());
    //     const WheelCondition current = Encoder2Wheel();
    //     motors_control(velocity_control(target, current));
    //     Location location = GetLocation(Wheel2Robot(current));
    //     tim7_call = 0;
    // }

    if (dma2_call)//dma2上有jetson的通信
    {
        servos_control(Servo2PLus(Jetson2Servo(jetson_init())));
        dma2_call = 0;
    }
    //其他控制参看stm32f4xx_it.c中的中断处理
}