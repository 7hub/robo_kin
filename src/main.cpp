// main.cpp
#include <stdio.h>
// #include <Eigen/Dense>
#include <iostream>
#include <math.h>
#include "TX2_60.h"
#include "global_defines.h"
#include "mathHelper.h"

using namespace std;
using namespace robo_kin;


int main(int argc, char **argv)
{

    double q[6] = {0, 0, 90 * DEG2RAD, 0, 0, 0};
    double T[4][4];

    TX2_60 robo1;
    robo1.fwd_kinemtaic(q, T);
   
    print(T, 4, 4);

    print(q,6);
    
    double po[6]={0,0,0,0,0,0};
    T2pose(T, po,EULER::XYZ);
    
    print(po,6);
    
    

    // printf("hello there!\n");
    return 0;
}
