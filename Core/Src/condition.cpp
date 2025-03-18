#include "condition.h"
#include <math.h>
static inline double deg2rad(const double x)
{
    return x * M_PI / 180.0;
}

static inline double rad2deg(const double x)
{
    return x * 180.0 / M_PI;
}

Polar_RobotCondition Cartesian2Polar(const RobotCondition Cartesian)
{
    return {0,0,0};//@@@
}

RobotCondition Polar2Cartesian(const Polar_RobotCondition Polar)
{
    const double Theta = deg2rad(Polar.Theta_velocity);

    const RobotCondition Cartesian = {
        .X_velocity = Polar.Rho_velocity * cos(Theta),
        .Y_velocity = Polar.Rho_velocity * sin(Theta),
        .Omega_velocity = Polar.Omega_velocity
    };
    return Cartesian;
}

WheelCondition Robot2Wheel(const RobotCondition Robot)
{
    const WheelCondition Wheel = {
        .A_velocity = +sqrt2 * Robot.X_velocity + +sqrt2 * Robot.Y_velocity + Robot.Omega_velocity * R_of_robot,
        .B_velocity = -sqrt2 * Robot.X_velocity + +sqrt2 * Robot.Y_velocity + Robot.Omega_velocity * R_of_robot,
        .C_velocity = -sqrt2 * Robot.X_velocity + -sqrt2 * Robot.Y_velocity + Robot.Omega_velocity * R_of_robot,
        .D_velocity = +sqrt2 * Robot.X_velocity + -sqrt2 * Robot.Y_velocity + Robot.Omega_velocity * R_of_robot,
    };
    return Wheel;
}
RobotCondition Wheel2Robot(const WheelCondition Wheel)
{
    const RobotCondition Robot = {
        .X_velocity = (Wheel.A_velocity - Wheel.B_velocity - Wheel.C_velocity + Wheel.D_velocity) / (4 * sqrt2),
        .Y_velocity = (Wheel.A_velocity + Wheel.B_velocity - Wheel.C_velocity - Wheel.D_velocity) / (4 * sqrt2),
        .Omega_velocity = (Wheel.A_velocity + Wheel.B_velocity + Wheel.C_velocity + Wheel.D_velocity) / (4 * R_of_robot),
    };
    return Robot;
}

Servos Servo2PLus(const Servos Servo)
{
    Servos Plus = {
        .pitch = 500 + (Servo.pitch * 2000) / 180,
        .yaw = 500 + Servo.yaw * 8
    };
    return Plus;
}

Location GetLocation(const RobotCondition Robot)
{
    static Location location=
    {
        .x = 0,
        .y = 0,
        .theta = 0,
    };
    location.theta += Robot.Omega_velocity * PID_period * 1e3;
    while (location.theta > 360 || location.theta <= -360)
    {
        if (location.theta > 360)
        {
            location.theta -= 360;
        }
        else if (location.theta <= -360)
        {
            location.theta += 360;
        }
    }
    location.x += Robot.X_velocity * PID_period * 1e3 * cos(location.theta);
    location.y += Robot.Y_velocity * PID_period * 1e3 * sin(location.theta);

    return location;
}

