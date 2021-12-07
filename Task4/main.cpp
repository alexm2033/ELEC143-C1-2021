#include "uop_msb.h"
using namespace uop_msb;

// You are to use these ojects to read the switch inputs
DigitalIn sw1(BTN1_PIN);
DigitalIn sw2(BTN2_PIN);


// You are to use this object to control the LEDs
BusOut leds(TRAF_RED1_PIN, TRAF_YEL1_PIN, TRAF_GRN1_PIN);

int main()
{
    while (true)
    {
    // ***** MODIFY THE CODE BELOW HERE *****
    // For full marks, debounce the switches with suitable delays
    short sw11, sw22;
    // 1. Wait for sw1 to be pressed and released
    do {
        sw11 = sw1;         //read switch 1
    } while (sw11 == 0);    //wait for it to be pressed
    
    wait_us(100000);         //debounce

    do {
        sw11 = sw1;         //read 
    } while (sw11 == 1);    //wait

    wait_us(100000);         //debounce

    leds = 7;               //leds lit to show its worked


    // 2. Wait for sw2 to be pressed and released
    do {
        sw22 = sw2;         //read switch 2
    } while(sw22 == 0);     //wait

    wait_us(100000);         //debounce

    do {
        sw22 = sw2;         //read
    } while (sw22 == 1);    //wait (again)

    wait_us(100000);         //debounce (you will tell me if this is getting repetitive wont you)

    leds = 0;               //turn off leds to show its time to move on


    // 3. Wait for sw1 and sw2 to be pressed (together)
    do {
        sw11 = sw1;         //read 
        sw22 = sw2;         //read
    } while ((sw11 == 0) || (sw22 == 0));   //wait

    wait_us(100000);         // debounce

    leds = 7;               // leds to test


    // 4. Wait for either sw1 or sw2 to be released
    do {
        sw11 = sw1;         //read
        sw22 = sw2;         //read
    }while((sw11 == 1) && (sw22 == 1));     //wait for it

    wait_us(100000);         //debounce 

    leds = 0;       //leds off


    // 5. Turn on only the yellow and green LEDs

    leds = 6;       //leds binary 110

    // 6. Wait for 1s

    wait_us(1000000);


    // 7. Turn on only the red LEDs

    leds = 1;       //leds binary 001
    

    

    // ***** MODIFY THE CODE ABOVE HERE *****
    }

    while(true);
}


