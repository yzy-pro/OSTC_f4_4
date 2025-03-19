#include "PID.h"
#include "encoder.h"
#include "Setup_and_Loop.h"
#include "motor.h"
#include "jetson.h"
#include "servo.h"
#include "robot.h"
#include "stm32f4xx_it.h"
// #include "dma.h"
#include "usart.h"

void getsettings(RobotCondition * Robot)
{
    Robot->X_velocity = 0;
    Robot->Y_velocity = 0;
    Robot->Omega_velocity = 0;
}

void setup(Robot * myrobot) {
    motors_init();
    motors_control(&myrobot->wheel_traget_pwm);

    encoder_init();

    jetson_init();

    servos_init();
    Servo2PLus(&myrobot->servo_traget, &myrobot->servos_target_plus);
    servos_control(&myrobot->servos_target_plus);

    HAL_UART_Receive_IT(&huart1, jetson_init(), 2);

    // servos_test(myrobot);
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

    // if (myrobot->dma2_call)//dma2上有jetson的通信
    // {
    //     Jetson2Servo(jetson_init(), &(myrobot->servo_traget));
    //     Servo2PLus(&(myrobot->servo_traget), &(myrobot->servos_target_plus));
    //     servos_control(&(myrobot->servos_target_plus));
    //
    //     reset_calls(&myrobot->dma2_call);
    // }
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

// void HAL_UARTEX_RxCpltCallback(UART_HandleTypeDef *huart, uint16_t Size)
// {
//     if (huart == &huart1)
//     {
//         HAL_UART_Transmit_DMA(&huart1, jetson_init(), Size);
//
//         HAL_UARTEx_ReceiveToIdle_DMA(&huart1, jetson_init(), 100);
//         // Servos servo;
//         // Jetson2Servo(jetson_init(), &servo);
//         // Servo2PLus(&servo, &robot_init()->servos_target_plus);
//         // servos_control(&robot_init()->servos_target_plus);
//     }
// }

void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart)
{
    HAL_UART_Transmit_IT(&huart1, jetson_init(),2);
    HAL_UART_Receive_IT(&huart1, jetson_init(), 2);
    if (jetson_init()[0] == '1') {
        // servos_test(robot_init());
        HAL_Delay(1000);
        jetson_init()[0] = 0;
    }

}

