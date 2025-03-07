#include "PID.h"
#include "encoder.h"
#include "Setup_and_Loop.h"

#include "motor.h"

RobotCondition getsettings()
{
    return {0,0,0};
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