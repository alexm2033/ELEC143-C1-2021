#include "uop_msb.h"
using namespace uop_msb;

// You are to ONLY use this object to control the LEDs
PortOut traffic(PortC, 0b0000000001001100);

//The default flash rate is once per second for all tasks

int main()
{
    traffic = 0;

    int n = 0;

    //1. Flash the red led 3 times

    for (n=0; n<3; n=n+1) {

         traffic = 4;
         wait_us(500000);
        traffic = 0;
        wait_us(500000);
    }

     //2. Using the bitwise OR and AND operators (|,&), flash the green LED on and off 3 times

    for (int n=0; n<3; n++) {
    traffic = traffic | 64;
     wait_us(500000);
    traffic = traffic & 0;
     wait_us(500000);
    }
    
     //3. Using the bitwise XOR operator (^), flash the yellow LED on and off 3 times

     for (n=0; n<6; n++) {

         traffic = traffic ^ 8;

         wait_us(500000);
     }

    //4. Using only bitwise operators, display the traffic light sequence red, red+yellow, green, yellow. Leave a 1s gap between each

    traffic = traffic ^ 4;
    wait_us(1000000);
    traffic = traffic ^ 8;
    wait_us(1000000);
    traffic = traffic ^ 76;
    wait_us(1000000);
    traffic = traffic ^ 72;
    wait_us(1000000);
    traffic = traffic ^ 8;
    
    

    while (true);
}


