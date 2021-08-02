/*************************************************************************
	> File Name: uart.h
	> Author: 
	> Mail: 
	> Created Time: Mon 02 Aug 2021 14:21:38 CST
 ************************************************************************/

#ifndef _UART_H
#define _UART_H

#define HSIClockFreq 16000000
void uart_conf(unsigned long baud);
int uart_write(const char *str);
int uart_read(unsigned char *pdata);

#endif
