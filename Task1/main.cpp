#include "uop_msb.h"
using namespace uop_msb;

BusOut leds(TRAF_RED1_PIN, TRAF_YEL1_PIN, TRAF_GRN1_PIN);

int main()
{
    leds = 0;
    // ***** MODIFY THE CODE BELOW HERE *****

    // 1. Write a for-loop to count from 0 to 100 in steps of 10 - print the results to the serial terminal

    //set up for loop with initial value (0), condition for continuation (n is less than or equal to 100), and increment (+10 per loop)
    for (int n=0; n<=100; n = n+10) {

        //toggle red led using bitwise xor 
        leds = leds^1;

        //print value of n to serial monitor
        printf("%d\n", n);

        //pause for 1/2 second (500000 microseconds)
        wait_us(500000);
    }

    // 2. Write a for-loop to count from 100 down to 10 in steps of 5 - print the results to the serial terminal
    
    //set up for loop
    for(int m=100; m>=10; m = m-5) {

        //toggle yellow led
        leds = leds^2;

        //print value of m
        printf( "%d\n", m);

        //wait 1 second (10^6 microseconds)
        wait_us(1000000);
    }

    // 3. Write some code to demonstrate nested for-loops (one loop within another)

    //define variable
    int x;

    //set conditions for for loop
    for (int n=0; n<=100; n = n+10) {

        //toggle red led
        leds = leds^4;

            //set conditions for nested for loop
            for(int m=100; m>=0; m = m-10) {

                //toggle yellow led
                leds = leds^2;
                
                //multiply m and n, and set result as x
                 x = m*n;

                    //if the product of m & n is 0 light the green led
                    if(x == 0) {

                        //light green led
                        leds = leds|4;
                    }
                 //print current value of m
                 printf("m = %d\n", m);

                 //printcurrent value of n
                 printf("n = %d\n", n);

                 //print result x
                 printf("n multiplyed by m = %d\n", x);

                 //wait 1/2 second 
                 wait_ns(500000);

             }

    //wait 1 second
    wait_us(1000000);
    
    }
    // ***** MODIFY THE CODE ABOVE HERE *****
    leds = 7;

    while (true) {

    }
}

