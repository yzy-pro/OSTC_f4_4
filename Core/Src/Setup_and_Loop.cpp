#include "PID.h"
#include "encoder.h"
#include "Setup_and_Loop.h"
#include "motor.h"
#include "jetson.h"
#include "servo.h"
#include "robot.h"


void getsettings(RobotCondition * Robot)
{
    Robot->X_velocity = 4;
    Robot->Y_velocity = 4;
    Robot->Omega_velocity = 0;
}

void setup(Robot * myrobot)
{
    motors_init();
    motors_control(&myrobot->wheel_traget_pwm);

    encoder_init();

    jetson_init();

    servo_init();
    Servo2PLus(&myrobot->servo_traget, &myrobot->servos_target_plus);
    servos_control(&myrobot->servos_target_plus);

}

void loop(Robot * myrobot)
{
    if (myrobot->tim7_call)//tim7是一个10ms触发的计时器
    {
        getsettings(&(myrobot->robot_traget));
        Robot2Wheel(&(myrobot->robot_traget), &(myrobot->wheel_traget));
        Encoder2Wheel(&(myrobot->wheel_current));
        velocity_control(&(myrobot->wheel_traget),&(myrobot->wheel_current),&(myrobot->wheel_traget_pwm));
        motors_control(&(myrobot->wheel_traget_pwm));

        Wheel2Robot(&(myrobot->wheel_current), &(myrobot->robot_current));
        GetLocation(&(myrobot->robot_current), &(myrobot->location));

        reset_calls(&myrobot->tim7_call);
    }

    if (myrobot->dma2_call)//dma2上有jetson的通信
    {
        Jetson2Servo(jetson_init(), &(myrobot->servo_traget));
        Servo2PLus(&(myrobot->servo_traget), &(myrobot->servos_target_plus));
        servos_control(&(myrobot->servos_target_plus));

        reset_calls(&myrobot->dma2_call);
    }
    //其他控制参看stm32f4xx_it.c中的中断处理
}

void set_calls(int * call) {
    if (*call == 0) {
        *call = 1;
    }
}

void reset_calls(int * call) {
    if (*call == 1) {
        *call = 0;
    }
}