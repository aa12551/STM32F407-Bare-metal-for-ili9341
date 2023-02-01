/*
 * uart.h
 *
 *  Created on: 2023年1月30日
 *      Author: s94009880225
 */

#ifndef UART_H_
#define UART_H_
#include "Mydriver.h"

void uart_tx_init(USART_TypeDef * USART);
void uart_rx_init(USART_TypeDef * USART);
void uart_write(USART_TypeDef * USART, int ch);
char uart_read(USART_TypeDef * USART);
void uart2_rx_interrupt_init();
void dma1_stream6_init(uint32_t src, uint32_t dst, uint32_t len);
#endif /* UART_H_ */
