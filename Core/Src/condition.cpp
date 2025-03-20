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

void Cartesian2Polar(const RobotCondition * Cartesian,
    Polar_RobotCondition * Polar)
{
    Polar->Rho_velocity = sqrt(Cartesian->X_velocity * Cartesian->X_velocity + Cartesian->Y_velocity * Cartesian->Y_velocity);
    Polar->Theta_velocity = rad2deg(atan2(Cartesian->Y_velocity, Cartesian->X_velocity));
    Polar->Omega_velocity = Cartesian->Omega_velocity;
}


void Polar2Cartesian(const Polar_RobotCondition * Polar,
        RobotCondition * Cartesian){
    const double Theta = deg2rad(Polar->Theta_velocity);

    Cartesian->X_velocity = Polar->Rho_velocity * cos(Theta);
    Cartesian->Y_velocity = Polar->Rho_velocity * sin(Theta);
    Cartesian->Omega_velocity = Polar->Omega_velocity;
}

void Robot2Wheel(const RobotCondition* Robot, WheelCondition* Wheel)
{
    Wheel->A_velocity = +sqrt2 * Robot->X_velocity + +sqrt2 * Robot->Y_velocity + Robot->Omega_velocity * R_of_robot;
    Wheel->B_velocity = -sqrt2 * Robot->X_velocity + +sqrt2 * Robot->Y_velocity + Robot->Omega_velocity * R_of_robot;
    Wheel->C_velocity = -sqrt2 * Robot->X_velocity + -sqrt2 * Robot->Y_velocity + Robot->Omega_velocity * R_of_robot;
    Wheel->D_velocity = +sqrt2 * Robot->X_velocity + -sqrt2 * Robot->Y_velocity + Robot->Omega_velocity * R_of_robot;
}

void Wheel2Robot(const WheelCondition* Wheel, RobotCondition* Robot)
{
    Robot->X_velocity = (Wheel->A_velocity - Wheel->B_velocity - Wheel->C_velocity + Wheel->D_velocity) / (4 * sqrt2);
    Robot->Y_velocity = (Wheel->A_velocity + Wheel->B_velocity - Wheel->C_velocity - Wheel->D_velocity) / (4 * sqrt2);
    Robot->Omega_velocity = (Wheel->A_velocity + Wheel->B_velocity + Wheel->C_velocity + Wheel->D_velocity) / (4 * R_of_robot);
}

void Servo2PLus(Servos * Servo, Servos * Plus)
{
    if (Servo->pitch < 0 ||Servo->pitch > 180) {
        if (Servo->pitch < 0) {
            Servo->pitch = 0;
        } else {
            Servo->pitch = 180;
        }
    }

    if (Servo->yaw < 0 ||Servo->yaw > 270) {
        if (Servo->yaw < 0) {
            Servo->yaw = 0;
        } else {
            Servo->yaw = 270;
        }
    }

    Plus->pitch = 500 + (Servo->pitch * 2000) / 180;
    Plus->yaw = 500 + Servo->yaw * 8;
}
void GetLocation(const RobotCondition * Robot, Location * Location)
{

    Location->theta += Robot->Omega_velocity * PID_period * 1e-3;

    while (Location->theta > 360 || Location->theta <= -360)
    {
        if (Location->theta > 360)
        {
            Location->theta -= 360;
        }
        else if (Location->theta <= -360)
        {
            Location->theta += 360;
        }
    }

    double theta_rad = deg2rad(Location->theta);
    Location->x += Robot->X_velocity * PID_period * 1e-3 * cos(theta_rad);
    Location->y += Robot->Y_velocity * PID_period * 1e-3 * sin(theta_rad);
}

