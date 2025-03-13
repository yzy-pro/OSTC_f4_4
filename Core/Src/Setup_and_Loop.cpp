#include "PID.h"
#include "encoder.h"
#include "Setup_and_Loop.h"
#include "motor.h"
#include "jetson.h"
#include "servo.h"


RobotCondition getsettings()
{
    return {50,50,50};
}

void setup()
{
    motors_init();
    encoder_init();
    servo_init();
    jetson_init();
}

void loop()
{
    if (encoder_timer())
    {
        const WheelCondition target = Robot2Wheel(getsettings());
        const WheelCondition current = Encoder2Wheel();
        motors_control(velocity_control(target, current));
        Location location = GetLocation(Wheel2Robot(current));
    }
    //其他控制参看stm32f4xx_it.c中的中断处理
}