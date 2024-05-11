#include "global_defines.h"

// Define global constants here

// Example:
// const int GLOBAL_CONSTANT = 42;

// Define global variables here

// Example:
// int global_variable = 0;

// Define global functions here

// Example:
// int add(int a, int b) {
//     return a + b;
// }

// Define global macros here

// Example:
// #define GLOBAL_MACRO "Hello, World!"


/** 初始化函数 */
void init_HM(int ar[][4], int row, int col)
{
	for (int i = 0; i < row; ++i)
	{
		for (int j = 0; j < col; ++j)
		{
			ar[i][j] = 0;
		}
	}
}

/** 打印函数 */
void print_HMItem(HomoMatrixItems hm)
{ printf("Homogeneous Matrix: \n");
    printf("| %.4f  %.4f  %.4f  %.4f | \n", hm.t11, hm.t12, hm.t13, hm.t14);
    printf("| %.4f  %.4f  %.4f  %.4f | \n", hm.t21, hm.t22, hm.t23, hm.t24);
    printf("| %.4f  %.4f  %.4f  %.4f | \n", hm.t31, hm.t32, hm.t33, hm.t34);
    printf("| %.4f  %.4f  %.4f  %.4f | \n", hm.t41, hm.t42, hm.t43, hm.t44);
}

void print(double ar[4][4], int row, int col)
{
    printf("Homogeneous Matrix: \n");
	for (int i = 0; i < row; ++i)
	{
		for (int j = 0; j < col; ++j)
		{
			printf("%4.4f\t", ar[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}

void print(double q[], int size){
    for(int i=0; i<size; i++){
        printf("%4.4f ", q[i]);
    }
    printf("\n");
}

void print_vector(double v[], int size){
    for(int i=0; i<size; i++){
        printf("%4.4f ", v[i]);
    }
    printf("\n");
}

