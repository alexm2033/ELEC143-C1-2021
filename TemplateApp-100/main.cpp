//#include "mbed.h"
#include "uop_msb.h"
using namespace uop_msb;

//On board LEDs
DigitalOut led1(LED1);
DigitalOut led2(LED2);
DigitalOut led3(LED3);

//On board switch
DigitalIn BlueButton(USER_BUTTON);

//LCD Display
LCD_16X2_DISPLAY disp;

//Buzzer
Buzzer buzz;

//Traffic Lights
DigitalOut traf1RedLED(TRAF_RED1_PIN,1);
DigitalOut traf1YelLED(TRAF_YEL1_PIN);
DigitalOut traf1GrnLED(TRAF_GRN1_PIN);
DigitalInOut traf2RedLED(TRAF_RED2_PIN, PIN_OUTPUT, OpenDrainNoPull, 0);
DigitalInOut traf2YelLED(TRAF_YEL2_PIN, PIN_OUTPUT, OpenDrainNoPull, 1);
DigitalInOut traf2GrnLED(TRAF_GRN2_PIN, PIN_OUTPUT, OpenDrainNoPull, 1);

//Light Levels
AnalogIn ldr(AN_LDR_PIN);

//LCD Backlight
DigitalOut backLight(LCD_BKL_PIN);

int main()
{

    / 4x4 Array
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

//int main()
//{
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

    //LCD Backlight ON
  //backLight = 1;

   // while (true) {
      //  led1 = 1;
       // led2 = 1;
       // led3 = 1;
       // wait_us(500000);
      //  led1 = 0;
      // led3 = 0;  
       // wait_us(500000);    

     //   disp.cls();
     //   disp.printf("LDR: %0.3f", ldr.read());    
  //  }
//}

