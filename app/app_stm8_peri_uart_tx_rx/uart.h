/*************************************************************************
	> File Name: uart.h
	> Author: 
	> Mail: 
	> Created Time: Mon 02 Aug 2021 14:21:38 CST
 ************************************************************************/

#ifndef _UART_H
#define _UART_H

#define HSIClockFreq 16000000
#define BaudRate  115200
#define UART1_FLAG_TXE  (uint8_t)0x80  /*!< Transmit Data Register Empty flag */
#define UART1_FLAG_RXNE (uint8_t)0x20 /*!< Read Data Register Not Empty flag */
#define RxBufferSize 64
void uart_conf(void);
void uart1_send_byte(unsigned char data);

#endif
