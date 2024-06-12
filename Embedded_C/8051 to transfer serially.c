
Objective:
The program is designed to configure the 8051 microcontroller to transmit the character 'B' repeatedly at a baud rate 
of 4800 using UART (Universal Asynchronous Receiver/Transmitter) communication. The Timer 1 is set up in
Mode 2 (8-bit auto-reload) to generate the baud rate for serial communication.
Code:
#include <reg51.h>  // Include header file for 8051 microcontroller definitions

void main(void)
{
    TMOD = 0x20;    // Configure Timer 1 in Mode 2 (8-bit auto-reload)
    TH1 = 0xFA;     // Load TH1 to set the baud rate to 4800 bps
    SCON = 0x50;    // Configure serial control register for 8-bit data and enable receiver
    TR1 = 1;        // Start Timer 1 to generate the baud rate
    
    while(1)        // Infinite loop to run continuously
    {
        SBUF = 'B';     // Load character 'B' into Serial Buffer (SBUF) for transmission
        while(TI == 0); // Wait until the Transmit Interrupt (TI) flag is set, indicating transmission complete
        TI = 0;         // Clear the TI flag for the next transmission
    }
}
