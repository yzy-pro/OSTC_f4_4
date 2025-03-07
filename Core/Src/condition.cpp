#include "condition.h"
#include <cmath>
inline double deg2rad(const double x)
{
    return x * M_PI / 180.0;
}

inline double rad2deg(const double x)
{
    return x * 180.0 / M_PI;
}

Polar_RobotCondition Cartesian2Polar(const RobotCondition & Cartesian)
{
    return {0,0,0};//@@@
}

RobotCondition Polar2Cartesian(const Polar_RobotCondition & Polar)
{
    const double Theta = deg2rad(Polar.Theta_velocity);

    const RobotCondition Cartesian = {
        .X_velocity = Polar.Rho_velocity * cos(Theta),
        .Y_velocity = Polar.Rho_velocity * sin(Theta),
        .Omega_velocity = Polar.Omega_velocity
    };
    return Cartesian;
}

WheelCondition Robot2Wheel(const RobotCondition & Robot)
{
    const WheelCondition Wheel = {
        .A_velocity = sqrt2 * Robot.X_velocity + Robot.Omega_velocity * R_of_robot,
        .B_velocity = sqrt2 * Robot.Y_velocity + Robot.Omega_velocity * R_of_robot,
        .C_velocity = -sqrt2 * Robot.X_velocity + Robot.Omega_velocity * R_of_robot,
        .D_velocity = -sqrt2 * Robot.Y_velocity + Robot.Omega_velocity * R_of_robot,
    };
    return Wheel;
}
RobotCondition Wheel2Robot(const WheelCondition & Wheel)
{
    const RobotCondition Robot = {
        .X_velocity = (Wheel.A_velocity - Wheel.C_velocity) / (2 * sqrt2),
        .Y_velocity = (Wheel.B_velocity - Wheel.D_velocity) / (2 * sqrt2),
        .Omega_velocity = (Wheel.A_velocity + Wheel.B_velocity +
            Wheel.C_velocity + Wheel.D_velocity) / (4 * R_of_robot),
    };
    return Robot;
}