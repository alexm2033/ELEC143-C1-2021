#include "uop_msb.h"
using namespace uop_msb;

// 4x4 Array
double M[4][3] = {
    {1.0, 2.0, 3.0},
    {-3.0, -4.0, -5.0},
    {10.0, 11.0, 12.0},
    {-1.0, -2.0, -3.0}
};

double N[3][4] = {
    {1.0, 2.0, 3.0, 4.0},
    {-3.0, -4.0, -5.0, -6.0},
    {10.0, 11.0, 12.0, 13.0}
};

void displayArray(int rows, int cols, double *Array)
{
    for (unsigned row=0; row<rows; row++) {
        for (unsigned col=0; col<cols; col++) {
            printf("%8.1f\t", Array[(row*cols)+col]);
        }
        printf("\n");
    }
}

// ***** For (1) WRITE YOUR ARRAY Y HERE *****
double Y[4][4] = {0};


// ***** For (3) WRITE YOUR FUNCTION HERE *****

// *****  END YOUR FUNCTION HERE  *****

int main()
{
    double* addressOfArray = (double*)M;    //Obtain base address of the array M
    displayArray(4,3,(double*)M);           //Display in terminal
printf("i'm working\n");
    // ***** MODIFY THE CODE BELOW HERE *****
int a, b, c, d, e, x, tempn[3], tempm[3], tempe[3];
    // 1. Create another Array Y with the correct dimensions to hold the result of M*N (see comments above)
        for (a=0; a<1;) {
            for (b=0; b<3; b++){
                tempm[b] = M[a][b];
            }
        }
            for ( c = 0; c<3; c++) {
                for (d = 0; d<1; ) {
                    tempn[c] = N[c][d];
                }
            }

                for ( e = 0; e<3; e++) {
                    tempe[e] = tempm[e] * tempn[e];
                }
                    Y[0][0] += tempe[e];
                    printf("%f\n", Y[0][0]);
    // 2. Write a nested loop to perform a matrix multiplication M*N and store the result in Y

    // 3. Write a function to multiply two matrices together (see comments above). Include some text code to demonstrate it working

    // ***** MODIFY THE CODE ABOVE HERE *****


    while (true) {
    }
}

