Objective
The objective of this program is to toggle an LED connected to pin PD6 of the AVR microcontroller at regular
intervals (every 500 milliseconds). This example demonstrates basic GPIO (General-Purpose Input/Output) manipulation 
and the use of delay functions to control the timing of the toggling.
Code:
#include <avr/io.h>        // Include AVR input/output header file
#include <util/delay.h>    // Include utility delay functions header file

int main() {
    // Set PD6 as output
    DDRD |= (1 << PD6);    // Set the Data Direction Register for Port D (DDRD) to configure PD6 as an output
    
    while (1) {            // Infinite loop to run continuously
        // Toggle the LED
        PORTD ^= (1 << PD6);  // Toggle the state of the LED connected to PD6 by using the XOR bitwise operation on PORTD
        
        // Delay for a short time
        _delay_ms(500);       // Delay for 500 milliseconds using the _delay_ms function
    }

    return 0;               // Return 0 from main (typically never reached in embedded applications)
}
