/*! @mainpage Example 1.1 Activate the alarm when gas is detected
 * @date Thursday, March 16, 2023
 * @authors Agustin de Vedia & Ulises Montenegro
 *
 * @note TP01 Implemented in class.
 * When input D2 is ON, alarm output is turned ON and viceversa.
 * Gas detector: D2
 * Alarm: LED1
 *
 */

#include "mbed.h"
#include "arm_book_lib.h"

int main()
{
    DigitalIn gasDetector(D2);

    DigitalOut alarmLed(LED1);

    gasDetector.mode(PullDown);

    alarmLed = OFF;

    printf("%s\n","Hello World");

    while (true) {
        if ( gasDetector == ON ) {
            alarmLed = ON;
            printf("%s\n","Alarm ON.");
        }
        
        if ( gasDetector == OFF ) {
            alarmLed = OFF;
            printf("%s\n","Alarm OFF.");
        }

    }
}