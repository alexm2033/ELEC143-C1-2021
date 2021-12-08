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

//create function to test the switch state and wait for a press
int test_the_buttons()
{

 //declare and initialise array and variable
 int buttons_pressed[5] {0}, buttons = 0;

 //ensure all switches are released
 while ((SW1 != 0) || (SW2 != 0) || (SW3 != 0) || (SW4 != 0) || (SW5 != 0)) {} 

 wait_us(100000);        //debounce switch
 
 //solicit input from user
 printf("please press a button\n");

 while ((SW1 == 0) && (SW2 == 0) && (SW3 == 0) && (SW4 == 0) && (SW5 == 0)) {}     //wait for a switch to be pressed

 //confirm reciept of input
 printf("thankyou\n");

 wait_us(50000);         //debounce but not for too long otherwise a press can be missed, too short and if 2 switches need to be pressed only the first to close is captured

     //read the switches and allocate values to the array, values set to avoid accidental positives
     if (SW1 == 1) {buttons_pressed[0] = 1;}
     if (SW2 == 1) {buttons_pressed[1] = 2;}
     if (SW3 == 1) {buttons_pressed[2] = 4;}
     if (SW4 == 1) {buttons_pressed[3] = 8;}
     if (SW5 == 1) {buttons_pressed[4] = 16;}

    //sum elements of array and record result in buttons
     for (int x=0; x<5; x++) {

         buttons += buttons_pressed[x];
     }

 //ensure all switches are released
 while ((SW1 != 0) || (SW2 != 0) || (SW3 != 0) || (SW4 != 0) || (SW5 != 0)) {}

 wait_us(100000);       //debounce
     
 return buttons;
 
}     