Objective:
The objective of this program is to demonstrate how to control an LED using an AVR microcontroller. 
The LED is turned on and off at regular intervals to create a blinking effect.
Code:
#include <avr/io.h>     // Include AVR I/O header file for I/O operations
#include <util/delay.h> // Include utility delay functions header file

// Function to initialize the output pin
void IO_Init() {
    // Set PD3 as output (LED)
    DDRD |= (1 << PD3);
    // DDRD: Data Direction Register for Port D
    // (1 << PD3): Set PD3 as output
}

// Main function
int main() {
    IO_Init(); // Call the function to initialize I/O

    while (1) { // Infinite loop
        // Turn on the LED
        PORTD |= (1 << PD3);
        // PORTD: Data Register for Port D
        // (1 << PD3): Set PD3 (LED pin) to HIGH, turning on the LED

        _delay_ms(500); // Wait for 500 milliseconds

        // Turn off the LED
        PORTD &= ~(1 << PD3);
        // PORTD: Data Register for Port D
        // ~(1 << PD3): Clear PD3 (LED pin), turning off the LED

        _delay_ms(500); // Wait for 500 milliseconds
    }
}
