// Source code under CC0 1.0
// Src & walkthrough: http://www.colecovision.eu/stm8/HCDVBD0017%20Serial.shtml

#include <string.h>
#include <stdint.h>
#include <stdio.h>
#include "stm8.h"
#include "uart.h"

void main(void) {
    unsigned long i = 0;

    CLK_CKDIVR = 0x00;   // Set the frequency to 16 MHz
    CLK_PCKENR1 = 0xFF;  // Enable peripherals

    uart_conf();

    do {
        uart1_send_byte('a');
        for(i = 0; i < 147456; i++) { } // Sleep
    } while(1);
}
