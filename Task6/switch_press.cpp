#include "uop_msb.h"
#include <cstdint>
#include <cstdio>
#include <functional>
using namespace uop_msb;


// You are to use these ojects to read the switch inputs
static DigitalIn SW1(USER_BUTTON);
static DigitalIn SW2(BTN1_PIN);
static DigitalIn SW3(BTN2_PIN);
static DigitalInOut SW4(BTN3_PIN,PIN_INPUT,PullDown,0);
static DigitalInOut SW5(BTN4_PIN,PIN_INPUT,PullDown,0);


int test_the_buttons()
{
//create function to test the switch state and wait for a press
//int  test_the_switch()
//{
 int buttons_pressed[5] {0};
 int buttons = 0;
//1 second delay to clear switch's between steps
 //wait_us(1000000);

 //ensure all switches are released
 while ((SW1 != 0) || (SW2 != 0) || (SW3 != 0) || (SW4 != 0) || (SW5 != 0)) {} 
wait_us(250000);
 
//solicit input from user
 printf("please press a button\n");
 while ((SW1 == 0) && (SW2 == 0) && (SW3 == 0) && (SW4 == 0) && (SW5 == 0)) {}     //wait for a press

 //confirm reciept of input
 printf("thankyou\n");
    wait_us(250000);
     if (SW1 == 1) {buttons_pressed[0] = 1;}
     if (SW2 == 1) {buttons_pressed[1] = 2;}
     if (SW3 == 1) {buttons_pressed[2] = 4;}
     if (SW4 == 1) {buttons_pressed[3] = 8;}
     if (SW5 == 1) {buttons_pressed[4] = 16;}

    // wait_us(250000);
     for (int x=0; x<5; x++) {
         buttons += buttons_pressed[x];
     }
     //ensure all switches are released
 while ((SW1 != 0) || (SW2 != 0) || (SW3 != 0) || (SW4 != 0) || (SW5 != 0)) {}

 wait_us(250000); 

     printf("buttons = %d\n", buttons);
     
    return buttons;
}     