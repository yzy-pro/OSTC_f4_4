#include "PID.h"

#include "condition.h"

double velocity_PID(const double target, double current)
{
    static PID_k velocity_PID = {
        .kp = 100,
        .ki = 0.02 * velocity_PID.kp,
        .kd = 0,
        .error_limit = 50,
    };//@@@

    static double last_current{}, filter_parameters = 0.3; //@@@
    current = current * filter_parameters + last_current * (1 - filter_parameters);

    static double error{}, last_error{}, sum_error{};
    int pwm_velocity{};

    error = current - target;
    sum_error += error;

    if (sum_error > velocity_PID.error_limit)
    {
        sum_error = velocity_PID.error_limit;
    }
    else if (sum_error < -velocity_PID.error_limit)
    {
        sum_error = -velocity_PID.error_limit;
    }

    pwm_velocity = static_cast<int>(velocity_PID.kp * error + velocity_PID.ki
    * sum_error + velocity_PID.kd * (error - last_error));

    last_error = error;

    return pwm_velocity;
}

WheelCondition velocity_control(const WheelCondition target,
const WheelCondition current)
{

    const double pwm_A = velocity_PID(target.A_velocity, current.A_velocity);
    const double pwm_B = velocity_PID(target.B_velocity, current.B_velocity);
    const double pwm_C = velocity_PID(target.C_velocity, current.C_velocity);
    const double pwm_D = velocity_PID(target.D_velocity, current.D_velocity);

    const WheelCondition pwm_target = {
    .A_velocity = pwm_A,
    .B_velocity = pwm_B,
    .C_velocity = pwm_C,
    .D_velocity = pwm_D,};

    return pwm_target;
}