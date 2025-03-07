#ifndef EXCHANGE_DEFINE_H
#define EXCHANGE_DEFINE_H
#ifdef  __cplusplus
extern "C"
#endif

typedef struct
{
    double X_velocity;
    double Y_velocity;
    double Omega_velocity;
}RobotCondition;

typedef struct
{
    double A_velocity;
    double B_velocity;
    double C_velocity;
    double D_velocity;
}WheelCondition;

typedef struct
{
    double Rho_velocity;
    double Theta_velocity;
    double Omega_velocity;
}Polar_RobotCondition;


#ifdef  __cplusplus
}
#endif
#endif //EXCHANGE_DEFINE_H
