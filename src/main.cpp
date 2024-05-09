// main.cpp
#include <stdio.h>
#include <Eigen/Dense>
#include <iostream>
// #include "robot/TX2_60.h"

void forward_kin();
void inverse_kin();

#define PI 3.141592653
#define HalfPi 1.570796326

#define RAD2DEG 180/PI
#define DEG2RAD PI/180

// calc forward kinematics of 6-axis robot 
void forward_kin()
{
    
}

// calc inverse kinematics of 6-axis robot
void inverse_kin()
{
}


int main(int argc, char **argv)
{
    Eigen::MatrixXd m = Eigen::MatrixXd::Random(4, 4);
    std::cout << "Original matrix: \n";
    std::cout << m;

    std::cout << std::endl;
    std::cout << "Transpose: \n";
    std::cout << m.transpose();
    std::cout << std::endl;
    printf("hello there!\n");
    return 0;
}
