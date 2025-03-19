#include "PID.h"
#include "condition.h"

int velocity_PID(const double target, double current)
{
    static PID_k velocity_PID = {
        .kp = 450,
        .ki = 0.015 * velocity_PID.kp,
        .kd = 0,
        .error_limit = 1500,
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

void velocity_control(const WheelCondition * target,
const WheelCondition * current, WheelCondition * target_pwm)
{

    target_pwm->A_velocity = velocity_PID(target->A_velocity, current->A_velocity);
    target_pwm->B_velocity = velocity_PID(target->B_velocity, current->B_velocity);
    target_pwm->C_velocity = velocity_PID(target->C_velocity, current->C_velocity);
    target_pwm->D_velocity = velocity_PID(target->D_velocity, current->D_velocity);

}