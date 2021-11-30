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
double Y[4][4] = {{0}};

// ***** For (3) WRITE YOUR FUNCTION HERE *****
void multiply2Matrices()
{
    int Row, row, Col, col, x, y;
    double matrixA[10][10] {{0}}, matrixB[10][10] {{0}}, products[3] {0};
    double result[10][10] {{0}};
    while (true) {
         printf("enter rows in matrix A\n");
         scanf("%d", &Row);
          printf("enter columns in matrix A\n");
          scanf("%d", &Col);
          printf("enter rows in matrix B\n");
          scanf("%d", &row);
           printf("enter columns in matrix B\n");
          scanf("%d", &col);
           printf("matrix A has %d rows,and %d columns\n", Row, Col);
           printf("matrix B has %d rows, and %d columns\n", row, col);
          if( Col == row) {
             break;
           }
          else {
              printf("ERROR incompatible matrices\n");
              printf("please try again\n");
            }
    }
    //fill matrix A
        for (x = 0; x < Row; x++) {
             for (y = 0; y < Col; y++) {
                printf("enter matrix A\n");
                 printf("enter value for %d%d\n", x,y);
                 scanf("%lf", &matrixA[x][y]);
             }            
        }

        for (x = 0; x < row; x++) {
            for (y = 0; y < col; y++) {
                printf("enter matrix B\n");
                printf("enter value for %d%d\n", x,y);
                scanf("%lf", &matrixB[x][y]);
            }
        }

            for ( int i=0; i < Row; i++) {
                for ( int j=0; j < col; j++) {
                    for ( int k=0; k < row; k++) {

                        products[k] = matrixA[i][k] * matrixB[k][j];

                        result[i][j] += products[k];

                        printf("%.2lf x %.2lf = %.2lf\n", matrixA[i][k], matrixB[k][j], products[k]);
                        wait_us(500000);
                        printf("sum of row %d x column %d = %.2lf\n", i, k, result[i][j]);
                        wait_us(500000);
                    }
                }
            }

            for ( int i=0; i < Row; i++) {
                 if( i>0) {printf("\n");}
                for (int j=0; j < col; j++) {
                   

                    printf("%8.1lf\t", result[i][j]);
                }
            }
            printf("\n"); 
}   
// *****  END YOUR FUNCTION HERE  *****

int main()
{
    double* addressOfArray = (double*)M;    //Obtain base address of the array M
    displayArray(4,3,(double*)M);           //Display in terminal

    // ***** MODIFY THE CODE BELOW HERE *****
       // 1. Create another Array Y with the correct dimensions to hold the result of M*N (see comments above)
       //double* addressOfArrayy = (double*)Y;
      // displayArray(4,4,(double*)Y);
       printf("\n");
       // 2. Write a nested loop to perform a matrix multiplication M*N and store the result in Y
       int a, b, c, product[3];
        for (a = 0; a < 4; a++) {

            for (b = 0; b < 4; b ++){

                for (c = 0; c < 3; c++) {

                    product[c] = M[a][c] * N[c][b];

                    Y[a][b] += product[c];

                }
            }
        }
         displayArray(4,4,(double*)Y);

         multiply2Matrices();

    
   
    // 3. Write a function to multiply two matrices together (see comments above). Include some text code to demonstrate it working

    // ***** MODIFY THE CODE ABOVE HERE *****


    while (true) {
    }
}

