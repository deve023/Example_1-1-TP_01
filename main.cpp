/*! @mainpage Example 1.1 Activate the alarm when gas is detected
 * @date Thursday, March 23, 2023
 * @authors Agustin de Vedia & Ulises Montenegro
 *
 * @note TP02 Implemented in C in class.
 * When input D2 is ON, alarm output is turned ON and viceversa.
 * Gas detector: D2
 * Alarm: LED1
 *
 */

#include "mbed.h"
#include "arm_book_lib.h"

int main()
{
    //----C++-----
    //DigitalIn gasDetector(D2);
    //  gasDetector.mode(PullDown);
    //-----PseudoCodigo-----
    // Set pin D2 (PF_15) as input
    // Set PF_15 as PullDown
 
    gpio_t gasDetector;
    gpio_init_in_ex(&gasDetector, D2, PullDown);

    //------C++--------
    //DigitalOut alarmLed(LED1); 
    //-------PseudoCodigo------
    // Set pin LED1 (PB_0) as output

    gpio_t led1;
    gpio_init_out(&led1, LED1);


    //-----C++-------
    //alarmLed = OFF;
    //-----PseudoCodigo-------
    // Clear PB_0
    gpio_write(&led1, 0);

    printf("%s\n","Hello World");

    while (true) {
       //------C++-------- 
    /*  if ( gasDetector == ON ) { 
            alarmLed = ON; //*
            printf("%s\n","Alarm ON.");
        }*/
        
        if(gpio_read(&gasDetector) == 1){
            gpio_write(&led1, 1);
            printf("%s\n","Alarm ON.");
        }
        
        //-------C++----------
        /*if ( gasDetector == OFF ) { 
            alarmLed = OFF; 
            printf("%s\n","Alarm OFF.");
        }*/

        if(gpio_read(&gasDetector) == 0){
            gpio_write(&led1, 0);
            printf("%s\n","Alarm OFF.");
        }

    }
}