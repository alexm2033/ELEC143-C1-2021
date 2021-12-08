#include "uop_msb.h"
#include <cstdint>
#include <cstdio>
#include <functional>
using namespace uop_msb;
 

// You are to use these ojects to read the switch inputs
DigitalIn SW1(USER_BUTTON);
DigitalIn SW2(BTN1_PIN);
DigitalIn SW3(BTN2_PIN);
DigitalInOut SW4(BTN3_PIN,PIN_INPUT,PullDown,0);
DigitalInOut SW5(BTN4_PIN,PIN_INPUT,PullDown,0);

// You are to use this object to control the LEDs
BusOut leds(TRAF_RED1_PIN, TRAF_YEL1_PIN, TRAF_GRN1_PIN);

//Use this to sound an error
Buzzer alarm;

int main()
{
    while (true)
    {
        leds = 0;

        //Beep
        alarm.playTone("A", Buzzer::HIGHER_OCTAVE);
        wait_us(250000);
        alarm.rest();

        //Wait for the blue button using a while loop
        while (SW1==0);

        
        // For full marks, debounce the switches with suitable delays

        // This is a "combination lock" activity. Write some code to detect the following sequence of press-and-release inputs
        // SW1 and SW2, SW5, SW4, SW2 and SW3
        // If the full sequence is entered, correctly, the green LED should flash 3 times
        // If a sequence of inputs was entered incorrectly, the red LED should light and the buzzer should sound for 5 seconds
        // For full marks, debounce the switches and use flow control structures and arrays to avoid deep nesting of code

        // ***** MODIFY THE CODE BELOW HERE *****
      

        //declare and initialise variables
        int buttons = 0, count = 0; 
       
        //declare external function "test_the_buttons"
        extern int test_the_buttons();
        
                    
        while (true) {

            //call function and write returned value into buttons
            buttons = test_the_buttons();

            //check that the returned value is correct, this comment is valid for the following 4 if statements
            //code will move on even if the wrong buttons are pressed, incorrect entry will only be announced when sequence is complete            
            if (buttons == 3){
                     
                   count = count + 1;             //increment count if correct buttons pressed
            }
        
            buttons = test_the_buttons();

            if (buttons == 16){
                
                    count = count + 1;             //increment count if correct buttons pressed
            }
    

            buttons = test_the_buttons();

            if (buttons == 8){
                
                    count = count +1;              //increment count if correct buttons pressed
            }         

         
            buttons = test_the_buttons();

            if (buttons == 6){
                
                    count = count + 1;              //increment count if correct buttons pressed
            }

            //check that count is correct it should be four                
            if (count == 4){
                
                printf("congratulations successful entry\n");       //mission accomplished message 

                for (int n =0; n<3; n++) {                          //for loop to flash the green LED
                
                    leds = 4;                                       //green LED on
                    wait_us(500000);                                //half second flash
                    leds = 0;                                       //LED off
                    wait_us(500000);                                //half second delay
                }

                break;
            }

            //if count has any value other than four
            else {

                printf("incorrect combination entered\n");          //inform user of error
                leds = 1;                                           //red LED on
                alarm.playTone("A", Buzzer::HIGHER_OCTAVE);         //play warning tone
                wait_us(5000000);                                   //for 5 seconds
                alarm.rest();                                       //buzzer off
                leds = 0;                                           //LED off

            }

        }
        // ***** MODIFY THE CODE ABOVE HERE *****
    }
}


       
    




