#ifndef EXCHANGE_DEFINE_H
#define EXCHANGE_DEFINE_H
//这个文件主要包括各种量的换算和计算
#ifdef  __cplusplus
extern "C"{
#endif
#define M_PI 3.14159265
#define sqrt2 1.41421356

#define PID_rate 100
#define PID_period (1000 / PID_rate)

#define encoder_resolution 13 //编码器分辨率
#define encoder_gear_ratio 30 //减速比
#define encoder_resolution_u (4 * encoder_resolution * encoder_gear_ratio)//4分频
#define conversion_factor (2 * M_PI * R_of_wheel * PID_rate / encoder_resolution_u) //轮子速度m/s与编码器转换系数

#define R_of_robot 0.98//@@@
#define R_of_wheel 0.35//@@@
#define Alpha 45.0//@@@

static inline double deg2rad(double x);
static inline double rad2deg(double x);

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

typedef struct
{
    double kp;
    double ki;
    double kd;
    double error_limit;
}PID_k;

typedef struct
{
    int pitch;
    int yaw;
}Servos;

typedef struct
{
    double x;
    double y;
    double theta;
}Location;

Polar_RobotCondition Cartesian2Polar(const RobotCondition Cartesian);
RobotCondition Polar2Cartesian(const Polar_RobotCondition Polar);

WheelCondition Robot2Wheel(const RobotCondition Robot);
RobotCondition Wheel2Robot(const WheelCondition Wheel);

Servos Servo2PLus(const Servos Servo);
Location GetLocation(const RobotCondition Robot);

#ifdef  __cplusplus
}
#endif

#endif //EXCHANGE_DEFINE_H
