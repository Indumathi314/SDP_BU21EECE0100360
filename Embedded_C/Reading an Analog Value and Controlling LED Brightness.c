Objective:
The objective of this program is to read an analog input (e.g., from a potentiometer) using the ADC (Analog-to-Digital Converter)
of an AVR microcontroller and use this value to control the brightness of an LED through PWM (Pulse Width Modulation). 
The ADC reads a 10-bit value which is then scaled to an 8-bit value to set the PWM duty cycle.
Code:
#include <avr/io.h>     // Include AVR I/O header file for I/O operations
#include <util/delay.h> // Include utility delay functions header file

// Function to initialize ADC (Analog-to-Digital Converter)
void ADC_Init() {
    // Set the reference voltage to AVcc (5V)
    ADMUX = (1 << REFS0);
    // ADMUX: ADC Multiplexer Selection Register
    // (1 << REFS0): Set REFS0 bit to select AVcc as the reference voltage

    // Set the ADC prescaler to 128 for 125kHz ADC clock (assuming 16MHz system clock)
    ADCSRA = (1 << ADPS2) | (1 << ADPS1) | (1 << ADPS0);
    // ADCSRA: ADC Control and Status Register A
    // ADPS2, ADPS1, ADPS0: Set ADC prescaler to 128

    // Enable the ADC
    ADCSRA |= (1 << ADEN);
    // ADEN: Enable the ADC by setting the ADEN bit
}

// Function to read from ADC channel
uint16_t ADC_Read(uint8_t channel) {
    // Select the ADC channel (must be between 0 and 7)
    channel &= 0x07; // Ensure channel is in range
    // Masking channel to ensure it's within 0-7

    ADMUX = (ADMUX & 0xF8) | channel;
    // Clear the lower 3 bits of ADMUX and set them to the channel number

    // Start the conversion
    ADCSRA |= (1 << ADSC);
    // ADSC: ADC Start Conversion; setting this bit starts the conversion

    // Wait for the conversion to complete
    while (ADCSRA & (1 << ADSC));
    // Polling the ADSC bit; it will remain high until the conversion is complete

    // Read the ADC value
    return ADC;
    // Return the converted value from the ADC Data Register
}

// Function to initialize PWM (Pulse Width Modulation) on OC0A (PD6)
void PWM_Init() {
    // Set Fast PWM mode with non-inverting output on OC0A (PD6/Arduino pin 6)
    TCCR0A = (1 << WGM00) | (1 << WGM01) | (1 << COM0A1);
    // TCCR0A: Timer/Counter Control Register A
    // WGM00, WGM01: Set to enable Fast PWM mode
    // COM0A1: Set to enable non-inverting output on OC0A (PD6)

    // Set prescaler to 64 and start the timer
    TCCR0B = (1 << CS01) | (1 << CS00);
    // TCCR0B: Timer/Counter Control Register B
    // CS01, CS00: Set to 64 prescaler to start the timer

    // Set PD6 (OC0A) as output
    DDRD |= (1 << PD6);
    // DDRD: Data Direction Register for Port D
    // (1 << PD6): Set PD6 as output
}

// Function to set the PWM duty cycle
void set_PWM(uint8_t value) {
    OCR0A = value; // Set the PWM duty cycle
    // OCR0A: Output Compare Register for Timer/Counter 0, Channel A
    // Set to `value` to adjust the PWM duty cycle
}

// Main function
int main() {
    uint16_t adc_result; // Variable to store ADC result
    uint8_t pwm_value;   // Variable to store scaled PWM value
    
    ADC_Init(); // Initialize ADC
    PWM_Init(); // Initialize PWM

    while (1) { // Infinite loop
        adc_result = ADC_Read(0); // Read from ADC channel 0

        // Map the 10-bit ADC value to an 8-bit PWM value
        pwm_value = adc_result >> 2; // Dividing by 4 to fit 10-bit value into 8-bit
        // Right shift by 2 to convert 10-bit ADC value to 8-bit PWM value

        set_PWM(pwm_value); // Set the PWM duty cycle

        _delay_ms(100); // Small delay to debounce and stabilize reading
        // Delay for 100 milliseconds to stabilize readings
    }
}
