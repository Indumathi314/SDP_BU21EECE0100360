Objective:
The program is designed for an 8051 microcontroller to read the states of two switches and set the output on Port 1 (P1) based on the following conditions:

Both switches off (sw1 and sw2 low): Clear all bits on P1.
Switch 1 off, Switch 2 on (sw1 low and sw2 high): Set P1 to 0xAA (binary pattern 10101010).
Switch 1 on, Switch 2 off (sw1 high and sw2 low): Set P1 to 0x55 (binary pattern 01010101).
Both switches on (sw1 and sw2 high): Toggle P1 between 0x55 and 0xAA with a delay.
Code:
#include <reg51.h>      // Include the header file for 8051-specific definitions and functions

// Define switch pins
sbit sw1 = P2^1;        // Assign pin P2.1 to sw1 (Switch 1)
sbit sw2 = P2^2;        // Assign pin P2.2 to sw2 (Switch 2)

// Function prototype for delay
void delay(unsigned int);  // Declare delay function which takes an unsigned int argument

// Main function
void main(void)
{
    sw1 = 0;              // Initialize sw1 to 0 (switch input pin)
    sw2 = 0;              // Initialize sw2 to 0 (switch input pin)
    
    while(1)              // Infinite loop
    {
        // Check states of sw1 and sw2
        if(sw1 == 0 && sw2 == 0)         // If both switches are off
        {
            P1 = 0x00;                   // Clear all bits of P1
        }
        else if (sw1 == 0 && sw2 == 1)   // If sw1 is off and sw2 is on
        {
            P1 = 0xAA;                   // Set P1 to 0xAA (binary pattern 10101010)
        }
        else if (sw1 == 1 && sw2 == 0)   // If sw1 is on and sw2 is off
        {
            P1 = 0x55;                   // Set P1 to 0x55 (binary pattern 01010101)
        }
        else if (sw1 == 1 && sw2 == 1)   // If both switches are on
        {
            // Toggle P1 between 0x55 and 0xAA
            P1 = 0x55;                   // Set P1 to 0x55 (binary pattern 01010101)
            delay(5000);                 // Call delay function for 5000 time units
            
            P1 = 0xAA;                   // Set P1 to 0xAA (binary pattern 10101010)
            delay(5000);                 // Call delay function for 5000 time units
        }
    }
}

// Delay function definition
void delay(unsigned int time)
{
    unsigned int i, j;   // Declare loop variables
    
    for (i = 0; i < time; i++)   // Outer loop for time units
        for (j = 0; j < 1275; j++); // Inner loop for creating delay
}
