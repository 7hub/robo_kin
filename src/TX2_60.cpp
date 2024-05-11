#include "TX2_60.h"
#include "global_defines.h"
#include "mathHelper.h"

// calc forward kinematics of 6-axis robot
void TX2_60::fwd_kinemtaic(double q[6], double T[4][4])
{
    HomoMatrixItems T0_3, T3_6, TM0_6;
    double q1, q2, q3, q4, q5, q6;
    q1 = q[0];
    q2 = q[1];
    q3 = q[2];
    q4 = q[3];
    q5 = q[4];
    q6 = q[5];

    // 简化
    T0_3.t11 = (cos(q1) * cos(HalfPi - q2)) * cos(HalfPi + q3) + (sin(HalfPi - q2) * cos(q1)) * sin(HalfPi + q3);
    T0_3.t12 = -sin(q1);
    T0_3.t13 = (cos(q1) * cos(HalfPi - q2)) * sin(HalfPi + q3) - (sin(HalfPi - q2) * cos(q1)) * cos(HalfPi + q3);
    T0_3.t14 = -20 * sin(q1);
    T0_3.t21 = (sin(q1) * sin(HalfPi - q2)) * sin(HalfPi + q3) + (sin(q1) * cos(HalfPi - q2)) * cos(HalfPi + q3);
    T0_3.t22 = cos(q1);
    T0_3.t23 = -(sin(q1) * sin(HalfPi - q2)) * cos(HalfPi + q3) + (sin(q1) * cos(HalfPi - q2)) * sin(HalfPi + q3);
    T0_3.t24 = 20 * cos(q1);
    T0_3.t31 = sin(HalfPi - q2) * cos(HalfPi + q3) - sin(HalfPi + q3) * cos(HalfPi - q2);
    T0_3.t32 = 0;
    T0_3.t33 = sin(HalfPi - q2) * sin(HalfPi + q3) + cos(HalfPi - q2) * cos(HalfPi + q3);
    T0_3.t34 = 290 * sin(HalfPi - q2);
    T3_6.t11 = (cos(q4) * cos(q5)) * cos(q6);
    T3_6.t12 = -(+cos(q4) * cos(q5)) * sin(q6) + (-sin(q4)) * cos(q6);
    T3_6.t13 = sin(q5) * cos(q4);
    T3_6.t14 = 70 * sin(q5) * cos(q4);
    T3_6.t21 = (sin(q4) * cos(q5)) * cos(q6) + (cos(q4)) * sin(q6);
    T3_6.t22 = -(sin(q4) * cos(q5)) * sin(q6) + (cos(q4)) * cos(q6);
    T3_6.t23 = sin(q4) * sin(q5);
    T3_6.t24 = 70 * sin(q4) * sin(q5);
    T3_6.t31 = -sin(q5) * cos(q6);
    T3_6.t32 = sin(q5) * sin(q6);
    T3_6.t33 = cos(q5);
    T3_6.t34 = 70 * cos(q5) + 310;

    TM0_6.t11 = T0_3.t11 * T3_6.t11 + T0_3.t12 * T3_6.t21 + T0_3.t13 * T3_6.t31;
    TM0_6.t12 = T0_3.t11 * T3_6.t12 + T0_3.t12 * T3_6.t22 + T0_3.t13 * T3_6.t32;
    TM0_6.t13 = T0_3.t11 * T3_6.t13 + T0_3.t12 * T3_6.t23 + T0_3.t13 * T3_6.t33;
    TM0_6.t14 = T0_3.t11 * T3_6.t14 + T0_3.t12 * T3_6.t24 + T0_3.t13 * T3_6.t34 + T0_3.t14;
    TM0_6.t21 = T0_3.t21 * T3_6.t11 + T0_3.t22 * T3_6.t21 + T0_3.t23 * T3_6.t31;
    TM0_6.t22 = T0_3.t21 * T3_6.t12 + T0_3.t22 * T3_6.t22 + T0_3.t23 * T3_6.t32;
    TM0_6.t23 = T0_3.t21 * T3_6.t13 + T0_3.t22 * T3_6.t23 + T0_3.t23 * T3_6.t33;
    TM0_6.t24 = T0_3.t21 * T3_6.t14 + T0_3.t22 * T3_6.t24 + T0_3.t23 * T3_6.t34 + T0_3.t24;
    TM0_6.t31 = T0_3.t31 * T3_6.t11 + T0_3.t32 * T3_6.t21 + T0_3.t33 * T3_6.t31;
    TM0_6.t32 = T0_3.t31 * T3_6.t12 + T0_3.t32 * T3_6.t22 + T0_3.t33 * T3_6.t32;
    TM0_6.t33 = T0_3.t31 * T3_6.t13 + T0_3.t32 * T3_6.t23 + T0_3.t33 * T3_6.t33;
    TM0_6.t34 = T0_3.t31 * T3_6.t14 + T0_3.t32 * T3_6.t24 + T0_3.t33 * T3_6.t34 + T0_3.t34;

    print_HMItem(T0_3);

    print_HMItem(T3_6);

    print_HMItem(TM0_6);

    T[0][0] = TM0_6.t11;
    T[0][1] = TM0_6.t12;
    T[0][2] = TM0_6.t13;
    T[0][3] = TM0_6.t14;
    T[1][0] = TM0_6.t21;
    T[1][1] = TM0_6.t22;
    T[1][2] = TM0_6.t23;
    T[1][3] = TM0_6.t24;
    T[2][0] = TM0_6.t31;
    T[2][1] = TM0_6.t32;
    T[2][2] = TM0_6.t33;
    T[2][3] = TM0_6.t34;
    T[3][0] = 0;
    T[3][1] = 0;
    T[3][2] = 0;
    T[3][3] = 1;

    print_HMItem(T0_3);

    print_HMItem(T3_6);

    print_HMItem(TM0_6);
}

// calc inverse kinematics of 6-axis robot
void TX2_60::inv_kinematic()
{
}

void TX2_60::T2pose(double T[4][4], double pose[6])
{
    robo_kin::T2pose(T, pose, robo_kin::EULER::XYZ);
}
