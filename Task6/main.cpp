#include "uop_msb.h"
#include <cstdio>
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
      

        wait_us(2000000);
        int SW1_B = SW1;
        int SW2_B = SW2; 
        int SW3_B = SW3;
        int SW4_B = SW4;
        int SW5_B = SW5;
        int switches[5];
        switches[0] = SW1;
        switches[1] = SW2;
        switches[2] = SW3;
        switches[3] = SW4;
        switches[4] = SW5;
        void test_the_buttons();
        
            
        while (true) {

        int count = 0;    

         printf("press a button\n");

            while ((SW1 == 0) && (SW2 == 0) && (SW3 == 0) && (SW4 == 0) && (SW5 == 0)) {} //wait for a switch to be presed
            printf("button pressed\n");
            if ((SW1 == 1) || (SW2 == 1) || (SW3 == 1) || (SW4 == 1) || (SW5 == 1)) {

                wait_us(100000);

                if (((SW1 == 1) && (SW2 ==1)) && ((SW3 ==0) && (SW4 ==0) &&(SW5 ==0))) {
                    while  ((SW1 == 1) || (SW2 == 1)){}
                    wait_us(250000);               
                    count = count + 20;
                }
            
            }
            wait_us(1000000);
            test_the_buttons();
             //while ((SW1 != 0) && (SW2 != 0) && (SW3 != 0) && (SW4 != 0) && (SW5 != 0)) {}  

           //printf("press a button\n");
                 
           // while ((SW1 == 0) && (SW2 == 0) && (SW3 == 0) && (SW4 == 0) && (SW5 == 0)) {}

           // printf("button pressed\n");

                 if ((SW1 ==1) || (SW2 ==1) || (SW3 ==1) ||(SW4 ==1) || (SW5 ==1)) {
                    
                    wait_us(100000);

                     if ((SW5 ==1) && ((SW1 ==0) && (SW2 ==0) && (SW3 ==0) && (SW4 ==0))) {

                         while (SW5 == 1); {}
                         wait_us(250000);
                         count = count + 1;
                     }
                 }

            wait_us(1000000);

            while ((SW1 != 0) && (SW2 != 0) && (SW3 != 0) && (SW4 != 0) && (SW5 != 0)) {} 

            printf("press a buttom\n");

            while ((SW1 == 0) && (SW2 == 0) && (SW3 == 0) && (SW4 == 0) && (SW5 == 0)) {}

            printf("button pressed\n");

                if ((SW1 ==1) || (SW2 ==1) || (SW3 ==1) ||(SW4 ==1) || (SW5 ==1)) {

                    wait_us(100000);

                    if ((SW4 ==1) && ((SW1 ==0) && (SW2 ==0) && (SW3 ==0) && (SW5 ==0))) {

                        while (SW4 == 1){}
                        wait_us(250000);
                        count = count +1;
                    }
                }

            wait_us(1000000);

             while ((SW1 != 0) && (SW2 != 0) && (SW3 != 0) && (SW4 != 0) && (SW5 != 0)) {} 

             printf("press a button\n");

             while ((SW1 == 0) && (SW2 == 0) && (SW3 == 0) && (SW4 == 0) && (SW5 == 0)) {}

             printf("button pressed\n");

                if ((SW1 ==1) || (SW2 ==1) || (SW3 ==1) ||(SW4 ==1) || (SW5 ==1)) {

                    wait_us(100000);

                     if (((SW2 == 1) && (SW3 ==1)) && ((SW1 == 0) && (SW4 == 0) && (SW5 == 0))) {

                         while ((SW2 == 1) || (SW3 == 1)) {}
                         wait_us(250000);
                         count = count + 1;
                    }
                }

                         

                if (count == 4){
                    
                    for (int n =0; n<3; n++) {

                        leds = 4;
                        wait_us(500000);
                        leds = 0;
                        wait_us(500000);

                    }
                }

                else {

                    leds = 1;
                    alarm.playTone("A", Buzzer::HIGHER_OCTAVE);
                    wait_us(5000000);
                    alarm.rest();

                }

            leds = 0;
           
            wait_us(2000000);
        }

        // ***** MODIFY THE CODE ABOVE HERE *****
    }
}

void test_the_buttons()
{
 while ((SW1 != 0) && (SW2 != 0) && (SW3 != 0) && (SW4 != 0) && (SW5 != 0)) {} 

            printf("press a buttom\n");

            while ((SW1 == 0) && (SW2 == 0) && (SW3 == 0) && (SW4 == 0) && (SW5 == 0)) {}

            printf("button pressed\n");
}

