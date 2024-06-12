Objective:
The objective of this program is to control an LED using a push-button connected to an AVR microcontroller. 
The LED turns on when the push-button is pressed and turns off when the button is released. The internal pull-up resistor 
is used to keep the input pin high when the button is not pressed.
Code:
#include <avr/io.h>     // Include AVR I/O header file
#include <util/delay.h> // Include utility delay functions header file

// Function to initialize I/O pins
void IO_Init() {
    // Set PD2 as input (push-button) and enable internal pull-up resistor
    DDRD &= ~(1 << PD2);
    // DDRD: Data Direction Register for Port D
    // `&= ~(1 << PD2)`: Clear the bit for PD2 to configure it as input

    PORTD |= (1 << PD2);
    // PORTD: Data Register for Port D
    // `|= (1 << PD2)`: Set the bit for PD2 to enable the internal pull-up resistor

    // Set PD3 as output (LED)
    DDRD |= (1 << PD3);
    // DDRD: Data Direction Register for Port D
    // `|= (1 << PD3)`: Set the bit for PD3 to configure it as output
}

int main() {
    IO_Init(); // Call IO_Init to set up input/output pins

    while (1) { // Infinite loop to run continuously
        // Read the state of the push-button
        if (PIND & (1 << PD2)) {
            // Button is not pressed (pull-up resistor makes it high)
            PORTD &= ~(1 << PD3); // Turn off the LED
            // `&= ~(1 << PD3)`: Clear the bit for PD3 to turn off the LED
        } else {
            // Button is pressed (pin is low)
            PORTD |= (1 << PD3); // Turn on the LED
            // `|= (1 << PD3)`: Set the bit for PD3 to turn on the LED
        }

        _delay_ms(50); // Debounce delay
        // `_delay_ms(50)`: Wait for 50 milliseconds to debounce the button press
    }
}
