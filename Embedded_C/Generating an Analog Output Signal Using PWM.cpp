Objective:
The objective of this program is to generate a Pulse Width Modulated (PWM) signal on pin PD6 of the AVR microcontroller
to control the brightness of an LED. The PWM duty cycle is varied from 0 to 100% in steps, making the LED gradually increase
in brightness and then decrease, creating a fading effect.
Code:
 #include <avr/io.h>        // Include AVR input/output header file
#include <util/delay.h>    // Include utility delay functions header file

// Initialize PWM on PD6 (OC0A/Arduino pin 6)
void PWM_Init() {
    // Set Fast PWM mode with non-inverting output on OC0A (PD6/Arduino pin 6)
    TCCR0A = (1 << WGM00) | (1 << WGM01) | (1 << COM0A1);
    // TCCR0A: Timer/Counter Control Register A
    // WGM00 and WGM01: Set Fast PWM mode
    // COM0A1: Clear OC0A on compare match, set OC0A at BOTTOM (non-inverting mode)
    
    // Set prescaler to 64 and start the timer
    TCCR0B = (1 << CS01) | (1 << CS00);
    // TCCR0B: Timer/Counter Control Register B
    // CS01 and CS00: Set prescaler to 64 (clock speed divided by 64)

    // Set PD6 (OC0A) as output
    DDRD |= (1 << PD6);
    // DDRD: Data Direction Register for Port D
    // Setting bit PD6 to 1 configures PD6 as an output pin
}

// Set PWM duty cycle
void set_PWM(uint8_t value) {
    OCR0A = value; // Set the PWM duty cycle
    // OCR0A: Output Compare Register A for Timer/Counter 0
    // The value determines the duty cycle of the PWM signal on OC0A (PD6)
}

int main() {
    PWM_Init(); // Initialize PWM settings

    while (1) { // Infinite loop to run continuously
        for (uint8_t duty = 0; duty <= 255; duty++) { // Loop to increase duty cycle
            set_PWM(duty); // Increase duty cycle
            _delay_ms(10); // Small delay to observe gradual brightness change
        }
        
        for (uint8_t duty = 255; duty > 0; duty--) { // Loop to decrease duty cycle
            set_PWM(duty); // Decrease duty cycle
            _delay_ms(10); // Small delay to observe gradual brightness change
        }
    }
}
   
