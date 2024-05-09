#ifndef TX2_60_H
#define TX2_60_H

#include "global_defines.h"
#include <math.h>

#pragma once

/*
* DH Parameters
| -   | $\alpha$(deg) | a(mm) | $\theta$(deg) | d(mm) |
| --- | ------------- | ----- | ------------- | ----- |
| j1  | 0             | 0     | 0             | 375   |
| j2  | -90           | 0     | -90           | 20    |
| j3  | 0             | 290   | -90           | 0     |
| j4  | -90           | 0     | 0             | 310   |
| j5  | 90            | 0     | 0             | 0     |
| j6  | -90           | 0     | Pi           | 70    |

*/
// T0_3.t11 = (sin(q1) * sin(HalfPi - q2) * cos(HalfPi) + cos(q1) * cos(HalfPi - q2)) * cos(HalfPi + q3) + (-sin(q1) * cos(HalfPi) * cos(HalfPi - q2) + sin(HalfPi - q2) * cos(q1)) * sin(HalfPi + q3);
// T0_3.t12 = -(sin(q1) * sin(HalfPi - q2) * cos(HalfPi) + cos(q1) * cos(HalfPi - q2)) * sin(HalfPi + q3) * cos(HalfPi) + (-sin(q1) * cos(HalfPi) * cos(HalfPi - q2) + sin(HalfPi - q2) * cos(q1)) * cos(HalfPi) * cos(HalfPi + q3) - 1 * sin(q1);
// T0_3.t13 = (sin(q1) * sin(HalfPi - q2) * cos(HalfPi) + cos(q1) * cos(HalfPi - q2)) * sin(HalfPi) * sin(HalfPi + q3) - (-sin(q1) * cos(HalfPi) * cos(HalfPi - q2) + sin(HalfPi - q2) * cos(q1)) * sin(HalfPi) * cos(HalfPi + q3) - sin(HalfPi) * sin(q1) * cos(HalfPi);
// T0_3.t14 = -20 * sin(HalfPi) * sin(q1) + 290 * sin(q1) * sin(HalfPi - q2) * cos(HalfPi);
// T0_3.t21 = (sin(q1) * sin(HalfPi - q2) + cos(HalfPi) * cos(q1) * cos(HalfPi - q2)) * sin(HalfPi + q3) + (sin(q1) * cos(HalfPi - q2) - sin(HalfPi - q2) * cos(HalfPi) * cos(q1)) * cos(HalfPi + q3);
// T0_3.t22 = (sin(q1) * sin(HalfPi - q2) + cos(HalfPi) * cos(q1) * cos(HalfPi - q2)) * cos(HalfPi) * cos(HalfPi + q3) - (sin(q1) * cos(HalfPi - q2) - sin(HalfPi - q2) * cos(HalfPi) * cos(q1)) * sin(HalfPi + q3) * cos(HalfPi) + 1 * cos(q1);
// T0_3.t23 = -(sin(q1) * sin(HalfPi - q2) + cos(HalfPi) * cos(q1) * cos(HalfPi - q2)) * sin(HalfPi) * cos(HalfPi + q3) + (sin(q1) * cos(HalfPi - q2) - sin(HalfPi - q2) * cos(HalfPi) * cos(q1)) * sin(HalfPi) * sin(HalfPi + q3) + sin(HalfPi) * cos(HalfPi) * cos(q1);
// T0_3.t24 = 20 * sin(HalfPi) * cos(q1) - 290 * sin(HalfPi - q2) * cos(HalfPi) * cos(q1);
// T0_3.t31 = sin(HalfPi) * sin(HalfPi - q2) * cos(HalfPi + q3) - sin(HalfPi) * sin(HalfPi + q3) * cos(HalfPi - q2);
// T0_3.t32 = -sin(HalfPi) * sin(HalfPi - q2) * sin(HalfPi + q3) * cos(HalfPi) - sin(HalfPi) * cos(HalfPi) * cos(HalfPi - q2) * cos(HalfPi + q3) + sin(HalfPi) * cos(HalfPi);
// T0_3.t33 = 1 * sin(HalfPi - q2) * sin(HalfPi + q3) + 1 * cos(HalfPi - q2) * cos(HalfPi + q3) + 0;
// T0_3.t34 = 290 * sin(HalfPi) * sin(HalfPi - q2) + 20 * cos(HalfPi);
// T3_6.t11 = (-sin(q4) * sin(q5) * cos(HalfPi) + cos(q4) * cos(q5)) * cos(q6) + (-1 * sin(q4) - sin(q4) * 0 * cos(q5) - sin(q5) * cos(HalfPi) * cos(q4)) * sin(q6);
// T3_6.t12 = -(-sin(q4) * sin(q5) * cos(HalfPi) + cos(q4) * cos(q5)) * sin(q6) + (-1 * sin(q4) - sin(q4) * 0 * cos(q5) - sin(q5) * cos(HalfPi) * cos(q4)) * cos(q6);
// T3_6.t13 = sin(HalfPi) * sin(q4) * cos(HalfPi) * cos(q5) - sin(HalfPi) * sin(q4) * cos(HalfPi) + sin(HalfPi) * sin(q5) * cos(q4);
// T3_6.t14 = 70 * sin(HalfPi) * sin(q4) * cos(HalfPi) * cos(q5) - 70 * sin(HalfPi) * sin(q4) * cos(HalfPi) + 70 * sin(HalfPi) * sin(q5) * cos(q4);
// T3_6.t21 = (sin(q4) * cos(q5) + sin(q5) * cos(HalfPi) * cos(q4)) * cos(q6) + (1 * cos(q4) - sin(q4) * sin(q5) * cos(HalfPi) + 0 * cos(q4) * cos(q5)) * sin(q6);
// T3_6.t22 = -(sin(q4) * cos(q5) + sin(q5) * cos(HalfPi) * cos(q4)) * sin(q6) + (1 * cos(q4) - sin(q4) * sin(q5) * cos(HalfPi) + 0 * cos(q4) * cos(q5)) * cos(q6);
// T3_6.t23 = sin(HalfPi) * sin(q4) * sin(q5) - sin(HalfPi) * cos(HalfPi) * cos(q4) * cos(q5) + sin(HalfPi) * cos(HalfPi) * cos(q4);
// T3_6.t24 = 70 * sin(HalfPi) * sin(q4) * sin(q5) - 70 * sin(HalfPi) * cos(HalfPi) * cos(q4) * cos(q5) + 70 * sin(HalfPi) * cos(HalfPi) * cos(q4);
// T3_6.t31 = (-sin(HalfPi) * cos(HalfPi) * cos(q5) + sin(HalfPi) * cos(HalfPi)) * sin(q6) - sin(HalfPi) * sin(q5) * cos(q6);
// T3_6.t32 = (-sin(HalfPi) * cos(HalfPi) * cos(q5) + sin(HalfPi) * cos(HalfPi)) * cos(q6) + sin(HalfPi) * sin(q5) * sin(q6);
// T3_6.t33 = 1 * cos(q5) + 0;
// T3_6.t34 = 70 * 1 * cos(q5) + 70 * 0 + 310;

class TX2_60
{
public:

    static void fwd_kinemtaic(double q[6], double T[4][4]);
    static void inv_kinematic();

private:
};

#endif