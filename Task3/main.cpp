#include "uop_msb.h"
using namespace uop_msb;

DigitalIn BlueButton(USER_BUTTON);
BusOut leds(TRAF_RED1_PIN, TRAF_YEL1_PIN, TRAF_GRN1_PIN);
LCD_16X2_DISPLAY display;

int main()
{

    // ***** MODIFY THE CODE BELOW HERE *****
    leds = 0;
    //1. Use a while loop to wait for the blue button to be pressed, then released. For full marks, account for switch bounce.
    while (leds == 0) {

        while (BlueButton == 0) {}

        while (BlueButton == 1) {}

        wait_us(100000);

        leds = leds = 1;
    }
    wait_us(2000000);
    leds = 0;

    //2. Using a while-loop, flash the yellow LED on and off 5 times. Each flash should last 0.5s. 

    int count = 0;

    while ( count < 5 ) {

        count = count + 1;

        leds = 2;

        wait_us(500000);

        leds = 0;

    }

    leds = 0;
    //3. Using a while-loop, flash the green LED on and off 10 times. Each flash should last 0.25s. 
    count = 0;

    while ( count < 10){

        count = count +  1; 

        leds = 4;

        wait_us(250000);

        leds = 0;
    }
    
    leds = 0;
    //4. Using a while-loop, flash the red LED on and off 20 times. Each flash should last 0.125s. 
    count = 0;
    while (count < 20) {

        count = count + 1;

        leds = 1;

        wait_us(125000);

        leds = 0;
    }
    //5. Using a while-loop, count from 50 down to -50 in steps of 10 - print the results on row 1 of the LCD screen every 0.5 second 
    short No = 50;

    display.cls();

    while (No >= -50 ) {

        display.locate(1, 7);

        display.printf("%d", No);

        No = No - 10;

        wait_us(500000);
    }
    // ***** MODIFY THE CODE ABOVE HERE *****

    while (true) {

    }
}


