#include "uop_msb.h"
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
      

        
        int SW1_B = SW1;
        int SW2_B = SW2; 
        int SW3_B = SW3;
        int SW4_B = SW4;
        int SW5_B = SW5;
        int SW1_C, SW2_C, SW3_C, SW4_C, SW5_C;
        int count = 0;
            
        while (true) {
            

          //  SW1_C = SW1;
           // SW3_C = SW3;
           // SW4_C = SW4;
           // SW5_C = SW5;

            while ((SW1 == 0) && (SW2 == 0) && (SW3 == 0) && (SW4 == 0) && (SW5 == 0)) {}

            if ((SW1 ==1) || (SW2 ==1) || (SW3 ==1) ||(SW4 ==1) || (SW5 ==1)) {

                wait_us(250000);

                if ((SW1 == 1) && (SW2 ==1)) {

                    count = count + 1;
                }
                else count = 0;
            
            }

                  while ((SW1 == 0) && (SW2 == 0) && (SW3 == 0) && (SW4 == 0) && (SW5 == 0)) {}

                 if ((SW1 ==1) || (SW2 ==1) || (SW3 ==1) ||(SW4 ==1) || (SW5 ==1)) {

                     if (SW5 == 1) {

                         count = count + 1;
                     }
                     else count = 0;
                 }
                      while ((SW1 == 0) && (SW2 == 0) && (SW3 == 0) && (SW4 == 0) && (SW5 == 0)) {}

                     if ((SW1 ==1) || (SW2 ==1) || (SW3 ==1) ||(SW4 ==1) || (SW5 ==1)) {

                         if (SW4 == 1) {

                             count = count +1;
                         }
                         else count = 0;
                     }

                          while ((SW1 == 0) && (SW2 == 0) && (SW3 == 0) && (SW4 == 0) && (SW5 == 0)) {}

                         if ((SW1 ==1) || (SW2 ==1) || (SW3 ==1) ||(SW4 ==1) || (SW5 ==1)) {

                             if ((SW2 == 1) && (SW3 == 1)) {

                                 count = count + 1;
                             }
                             else count = 0;
                         }

                         

                  if (count != 0){
                    leds = 1;
                    }
                     else leds = 7;

            wait_us(2000000);

            leds = 0;
            
        }

        // ***** MODIFY THE CODE ABOVE HERE *****
    }
}


