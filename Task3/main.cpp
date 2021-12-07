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
    while (leds == 0) {                 //leds == 0 condition is to allow the code to move on to the next part of the task when run

        while (BlueButton == 0) {}      //wait for button to be pressed

        wait_us(100000);

        while (BlueButton == 1) {}      //wait for button to be released

        wait_us(100000);                //debounce delay

        leds = 1;                       //visual confirmation of success
    }
    wait_us(2000000);                   //separation between elements 
    leds = 0;

    //2. Using a while-loop, flash the yellow LED on and off 5 times. Each flash should last 0.5s. 

    int count = 0;                      //create and initialise variable

    while ( count < 5 ) {               //set condition to enter loop

        count = count + 1;              // increment count

        leds = 2;                       //flash led

        wait_us(500000);                //duration of flash

        leds = 0;                       //led off

        wait_us(500000);                //off period

    }

    //3. Using a while-loop, flash the green LED on and off 10 times. Each flash should last 0.25s. 
    count = 0;                          //reinitialise count variable

    while ( count < 10){                //set condition

        count = count +  1;             //increment

        leds = 4;                       //flash

        wait_us(250000);                //duration of flash

        leds = 0;                       //led off

        wait_us(250000);                //duration of off period
    }
    
    //4. Using a while-loop, flash the red LED on and off 20 times. Each flash should last 0.125s. 
    count = 0;                          //reinitialise

    while (count < 20) {                //condition

        count = count + 1;              //increment

        leds = 1;                       //flash

        wait_us(125000);                //duration of flash

        leds = 0;                       //led off

        wait_us(125000);                //off period
    }
    //5. Using a while-loop, count from 50 down to -50 in steps of 10 - print the results on row 1 of the LCD screen every 0.5 second 
    short Num = 50;                      //declare and initialise variable                    

    display.cls();                      //clear lcd display

    while (Num >= -50 ) {                //set entry conditions

        display.locate(1, 7);           //tell display where to put numbers

        display.printf("%d", Num);       //print value of variable (Num) on lcd

        Num = Num - 10;                   //decrement variable

        wait_us(500000);                //interval
    }
    // ***** MODIFY THE CODE ABOVE HERE *****

    while (true) {

    }
}


