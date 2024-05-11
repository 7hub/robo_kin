#ifndef GLOBAL_DEFINES_H
#define GLOBAL_DEFINES_H


#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <iostream>

#define Pi 3.141592653
#define HalfPi 1.570796326

#define RAD2DEG 180/Pi
#define DEG2RAD Pi/180

struct HomoMatrixItems
{
    double t11,t12,t13,t14,t21,t22,t23,t24,t31,t32,t33,t34,t41=0,t42=0,t43=0,t44=1;
};

void init_HM(int ar[][4], int row, int col);

void print_HMItem(HomoMatrixItems hm);

void print(double ar[4][4], int row, int col);

void print(double q[], int size);
void print_vector(double v[], int size);

#endif // !GLOBAL_DEFINES_H