// Source code under CC0 1.0
// Src & walkthrough: http://www.colecovision.eu/stm8/HCDVBD0017%20Serial.shtml

#include <string.h>
#include <stdint.h>
#include <stdio.h>
#include "stm8.h"

int uart_write(const char *str) {
	char i;
	for(i = 0; i < strlen(str); i++) {
		while(!(UART1_SR & UART_SR_TXE));
		UART1_DR = str[i];
	}
	return(i); // Bytes sent
}

void main(void) {
  unsigned long i = 0;

  CLK_CKDIVR = 0x00;   // Set the frequency to 16 MHz
  CLK_PCKENR1 = 0xFF;  // Enable peripherals

  UART1_CR2 = UART_CR2_TEN;                         // Allow TX and RX
  UART1_CR3 &= ~(UART_CR3_STOP1 | UART_CR3_STOP2);  // 1 stop bit
  UART1_BRR2 = 0x03;
  UART1_BRR1 = 0x68;  // 9600 baud

  do {
      uart_write("Hello World!\n");
      for(i = 0; i < 147456; i++) { } // Sleep
  } while(1);
}
