// main.cpp
#include <stdio.h>
// #include <Eigen/Dense>
#include <iostream>
#include "TX2_60.h"
#include "global_defines.h"
#include <math.h>

using namespace std;


int main(int argc, char **argv)
{

    double q[6] = {0, 0, 0 * DEG2RAD, 0, 0, 0};
    double T[4][4];

    TX2_60::fwd_kinemtaic(q, T);

    print_HM(T, 4, 4);

    // printf("hello there!\n");
    return 0;
}
