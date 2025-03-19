#include "robot.h"

Robot * robot_init() {
    static int is_init = 0;
    static Robot myrobot;
    if (!is_init) {
        myrobot.polar_traget={0,0,0};
        myrobot.polar_current={0,0,0};
        //robot
        myrobot.robot_traget={0,0,0};
        myrobot.robot_current={0,0,0};
        //wheel
        myrobot.wheel_traget={0,0,0,0};
        myrobot.wheel_current={0,0,0,0};
        myrobot.wheel_traget_pwm={0,0,0,0};
        myrobot.wheel_current_pwm={0,0,0,0};
        //jetson

        //servo
        myrobot.servo_traget={0, 0};
        myrobot.servo_current={0,0};
        myrobot.servos_target_plus={0,0};
        myrobot.servos_current_plus={0,0};
        //location
        myrobot.location={0,0};
        //calls
        myrobot.tim7_call=0;
        myrobot.dma2_call=0;

        is_init = 1;
    }
    return &myrobot;
}