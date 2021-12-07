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
      

       
        
        int switches[5];
        switches[0] = SW1;
        switches[1] = SW2;
        switches[2] = SW3;
        switches[3] = SW4;
        switches[4] = SW5;

        //declare function "test the switch"
        void test_the_switch();
        
            
        while (true) {

        int count = 0;    

             test_the_switch();
                //code will move on even if the wrong buttons are pressed, incorrect entry will only be confirmed when sequence is complete
                
                //check that only switch's 1 & 2 have been pressed
                if (((SW1 == 1) && (SW2 ==1)) && ((SW3 ==0) && (SW4 ==0) &&(SW5 ==0))) {

                     while ((SW1 == 1) || (SW2 == 1)) {}        //wait for both to be released
                     wait_us(100000);                           //debounce
                     count = count + 1;                         //increment count
                }
            
            test_the_switch();

                //check that only switch 5 has been pressed
                if ((SW5 ==1) && ((SW1 ==0) && (SW2 ==0) && (SW3 ==0) && (SW4 ==0))) {

                     while (SW5 == 1) {}                        //wait for switch to be released
                     wait_us(100000);                           //debounce
                     count = count + 1;                         //increment count
                  }
        
            test_the_switch();

                //check that only switch 4 has been pressed
                if ((SW4 ==1) && ((SW1 ==0) && (SW2 ==0) && (SW3 ==0) && (SW5 ==0))) {

                     while (SW4 == 1) {}                       //wait for switch to be released
                     wait_us(100000);                          //debounce
                     count = count +1;                         //increment count
                }         

            test_the_switch();

                //check that only switches 2 & 3 have been pressed
                if (((SW2 == 1) && (SW3 ==1)) && ((SW1 == 0) && (SW4 == 0) && (SW5 == 0))) {

                     while ((SW2 == 1) || (SW3 == 1)) {}        //wait for both switch's to be released  
                     wait_us(100000);                           //debounce
                     count = count + 1;                         //increment count
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
    }
}

//create function to test the switch state and wait for a press
void test_the_switch()
{
 //1 second delay to clear switch's between steps
 wait_us(1000000);

 //ensure all switches are released
 while ((SW1 != 0) && (SW2 != 0) && (SW3 != 0) && (SW4 != 0) && (SW5 != 0)) {} 

 //ask user to press a button
 printf("please press a button\n");

 //wait for a button to be pressed
 while ((SW1 == 0) && (SW2 == 0) && (SW3 == 0) && (SW4 == 0) && (SW5 == 0)) {}

 //confirm reciept of input
 printf("thankyou\n");

 //has a switch been pressed
 if ((SW1 == 1) || (SW2 == 1) || (SW3 == 1) || (SW4 == 1) || (SW5 == 1)) {

      wait_us(100000);          //debounce the switch

  }

}

        // ***** MODIFY THE CODE ABOVE HERE *****
    




