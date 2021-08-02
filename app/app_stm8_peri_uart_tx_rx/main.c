// Source code under CC0 1.0
// Src & walkthrough: http://www.colecovision.eu/stm8/HCDVBD0017%20Serial.shtml

#include <string.h>
#include <stdint.h>
#include <stdio.h>
#include "stm8.h"
#include "uart.h"

void main(void) {
    unsigned long i = 0;
    unsigned char rx_buf;
    unsigned char tx_buf[30];
        
    CLK_CKDIVR = 0x00;   // Set the frequency to 16 MHz
    CLK_PCKENR1 = 0xFF;  // Enable peripherals

    uart_conf(115200);


    do {
        if(uart_read(&rx_buf) == 1){
            memset(tx_buf,0,30);

            sprintf(tx_buf,"input:%c\n",rx_buf);
            uart_write(tx_buf);
        }
        for(i = 0; i < 147456; i++) { } // Sleep
    } while(1);
}
