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

//declare and initialise array Y of required size to hold result of M x N
double Y[4][4] = {{0}};

// ***** For (3) WRITE YOUR FUNCTION HERE *****

//declare function
void multiply2Matrices()
{

    int RowA, rowB, ColA, colB, x, y;
    double  products[3];

    while (true) {

         //ask user for inputs and store in the relevant variable
         printf("enter NUMBER of rows in matrix A\n");
         scanf("%d", &RowA);

         printf("enter NUMBER of columns in matrix A\n");
         scanf("%d", &ColA);

         printf("enter NUMBER of rows in matrix B\n");
         scanf("%d", &rowB);

         printf("enter NUMBER of columns in matrix B\n");
         scanf("%d", &colB);

         printf("matrix A has %d rows,and %d columns\n", RowA, ColA);
         printf("matrix B has %d rows, and %d columns\n", rowB, colB);

        //test compatability of entered matrix configurations
        if( ColA == rowB) {
           
            break;          // if multiplyable move on
        }

        else {            

            printf("ERROR incompatible matrices\n");        //advise user of error and return to start
            printf("please try again\n");
        }
    }

    //declare matrix arrays, and set size with user entered values
    double matrixA[RowA][ColA], matrixB[rowB][colB], result[RowA][colB];

    //ask user to enter values to fill matrix A and write into matrix A
    for (x = 0; x < RowA; x++) {
        for (y = 0; y < ColA; y++) {  

            printf("enter matrix A value for position %d%d\n", x,y);
            scanf("%lf", &matrixA[x][y]);
        }            
    }

    //ask user to enter values to fill matrix B and write into matrix B
    for (x = 0; x < rowB; x++) {
        for (y = 0; y < colB; y++) {   

            printf("enter matrix B value for position %d%d\n", x,y);
            scanf("%lf", &matrixB[x][y]);
        }
    }

    //nested for loops to cycle through the matrix elements
    for ( int i=0; i < RowA; i++) {
        for ( int j=0; j < colB; j++) {
            for ( int k=0; k < rowB; k++) {

                //multiply row elemnts of A with column elements of B, and write results to array "products"
                products[k] = matrixA[i][k] * matrixB[k][j];

                // sum array "products" and write into the correct element of matrix array "result"
                result[i][j] += products[k];
              
                if (k == rowB - 1) {
                  
                    //print value of result element, delay is to improve readability for demonstration
                    printf("sum of row %d x column %d = %.2lf\n", i, j, result[i][j]);
                    wait_us(100000);
                }
            }
        }
    }

    printf("\n");
    
    //nested loops to print array "result"
    for ( int i=0; i < RowA; i++) {        
        if( i>0) {
            //print new line for every row
            printf("\n");
        }
        for (int j=0; j < colB; j++) {
        
            printf("%8.1lf\t", result[i][j]);
        }

    }
    
    //clear some space for general readability on multiple passes
    printf("\n"); 
    printf("\n");
} 


// *****  END YOUR FUNCTION HERE  *****


int main()
{
    double* addressOfArray = (double*)M;    //Obtain base address of the array M
    displayArray(4,3,(double*)M);           //Display in terminal

    // ***** MODIFY THE CODE BELOW HERE *****
     
      
    printf("\n");
    
    //delcare and initilase array
    double product[3];

    //nested loops to cycle through matrix elements
    for (int a = 0; a < 4; a++) {
        for (int b = 0; b < 4; b ++){
            for (int c = 0; c < 3; c++) {

                //multiply row of matrix M with column of matrix N and write result to array "product"
                product[c] = M[a][c] * N[c][b];

                //sum array and write result into specifyed element of array "Y"
                Y[a][b] += product[c];
                
            }
        }
    }
    //use supplied function to display result matrix Y
    displayArray(4,4,(double*)Y);

    printf("\n");
    
    //run function to demonstrate it works
    multiply2Matrices();

    // 1. Create another Array Y with the correct dimensions to hold the result of M*N (see comments above)
     // 2. Write a nested loop to perform a matrix multiplication M*N and store the result in Y   
    // 3. Write a function to multiply two matrices together (see comments above). Include some text code to demonstrate it working

    // ***** MODIFY THE CODE ABOVE HERE *****


    while (true) {
    }
}

