/*
 * uart.c
 *
 *  Created on: 2023年1月30日
 *      Author: s94009880225
 */
#include "uart.h"

#define BaudRate 115200

// For printf
int __io_putchar(int ch)
{
	uart_write(USART2,ch);
	return ch;
}



void uart_tx_init(USART_TypeDef * USART)
{
	switch((uint32_t) USART)
	{
		case (uint32_t) USART1:
			/* Enable the clock to GPIOA */
			RCC->AHB1ENR |= RCC_AHB1ENR_GPIOAEN;
			/*Set PA9 mode to alternate function mode*/
			GPIOA->MODER &=~ PIN9 * PIN9;
			GPIOA->MODER |= ((PIN9 * PIN9) << 1);
			/*Set PA9 alternate function type to USART1_TX (AF07)*/
			GPIOA->AFR[1] |= (1U<<4);
			GPIOA->AFR[1] |= (1U<<5);
			GPIOA->AFR[1] |= (1U<<6);
			GPIOA->AFR[1] &=~ (1U<<7);
			/* Enable the clock to USART1 */
			RCC->APB2ENR |= RCC_APB2ENR_USART1EN;
			break;
		case (uint32_t) USART2:
			/* Enable the clock to GPIOA */
			RCC->AHB1ENR |= RCC_AHB1ENR_GPIOAEN;
			/*Set PA2 mode to alternate function mode*/
			GPIOA->MODER &=~ PIN2 * PIN2;
			GPIOA->MODER |= ((PIN2 * PIN2) << 1);
			/*Set PA2 alternate function type to USART2_TX (AF07)*/
			GPIOA->AFR[0] |= (1U<<8);
			GPIOA->AFR[0] |= (1U<<9);
			GPIOA->AFR[0] |= (1U<<10);
			GPIOA->AFR[0] &=~ (1U<<11);
			/*Enable clock access to uart2 */
			RCC->APB1ENR |= RCC_APB1ENR_USART2EN;
			break;
		case (uint32_t) USART3:
			/* Enable the clock to GPIOB */
			RCC->AHB1ENR |= RCC_AHB1ENR_GPIOBEN;
			/*Set PB10 mode to alternate function mode*/
			GPIOB->MODER &=~ (PIN10 * PIN10);
			GPIOB->MODER |= ((PIN10 * PIN10) << 1);
			/*Set PB10 alternate function type to USART3_TX (AF07)*/
			GPIOB->AFR[1] |= (1U<<8);
			GPIOB->AFR[1] |= (1U<<9);
			GPIOB->AFR[1] |= (1U<<10);
			GPIOB->AFR[1] &=~ (1U<<11);
			/* Enable the clock to USART3 */
			RCC->APB1ENR |= RCC_APB1ENR_USART3EN;
			break;
		case (uint32_t) USART6:
			/* Enable the clock to GPIOC */
			RCC->AHB1ENR |= RCC_AHB1ENR_GPIOCEN;
			/*Set PC6 mode to alternate function mode*/
			GPIOC->MODER &=~ (PIN6 * PIN6);
			GPIOC->MODER |= ((PIN6 * PIN6) << 1);
			/*Set PA2 alternate function type to USART2_TX (AF08)*/
			GPIOC->AFR[0] &=~ (1U<<24);
			GPIOC->AFR[0] &=~ (1U<<25);
			GPIOC->AFR[0] &=~ (1U<<26);
			GPIOC->AFR[0] |= (1U<<27);
			/* Enable the clock to USART6 */
			RCC->APB2ENR |= RCC_APB2ENR_USART6EN;
			break;
	}

	/*Configure baudrate*/
	USART->BRR = ((SYS_FREQ + (BaudRate/2U))/BaudRate);

	/*Configure the transfer direction*/
	USART->CR1 |=  USART_CR1_TE;

	/*Enable uart module*/
	USART->CR1 |=  USART_CR1_UE;
}
void uart_rx_init(USART_TypeDef * USART)
{
	switch((uint32_t) USART)
	{
		case (uint32_t) USART1:
			/* Enable the clock to GPIOA */
			RCC->AHB1ENR |= RCC_AHB1ENR_GPIOAEN;
			/*Set PA10 mode to alternate function mode*/
			GPIOA->MODER &=~ PIN10 * PIN10;
			GPIOA->MODER |= ((PIN10 * PIN10) << 1);
			/*Set PA10 alternate function type to USART1_RX (AF07)*/
			GPIOA->AFR[1] |= (1U<<8);
			GPIOA->AFR[1] |= (1U<<9);
			GPIOA->AFR[1] |= (1U<<10);
			GPIOA->AFR[1] &=~ (1U<<11);
			/* Enable the clock to USART1 */
			RCC->APB2ENR |= RCC_APB2ENR_USART1EN;
			break;
		case (uint32_t) USART2:
			/* Enable the clock to GPIOA */
			RCC->AHB1ENR |= RCC_AHB1ENR_GPIOAEN;
			/*Set PA3 mode to alternate function mode*/
			GPIOA->MODER &=~ PIN3 * PIN3;
			GPIOA->MODER |= ((PIN3 * PIN3) << 1);
			/*Set PA3 alternate function type to USART2_RX (AF07)*/
			GPIOA->AFR[0] |= (1U<<12);
			GPIOA->AFR[0] |= (1U<<13);
			GPIOA->AFR[0] |= (1U<<14);
			GPIOA->AFR[0] &=~ (1U<<15);
			/*Enable clock access to uart2 */
			RCC->APB1ENR |= RCC_APB1ENR_USART2EN;
			break;
		case (uint32_t) USART3:
			/* Enable the clock to GPIOB */
			RCC->AHB1ENR |= RCC_AHB1ENR_GPIOBEN;
			/*Set PB11 mode to alternate function mode*/
			GPIOB->MODER &=~ (PIN11 * PIN11);
			GPIOB->MODER |= ((PIN11 * PIN11) << 1);
			/*Set PB11 alternate function type to USART3_RX (AF07)*/
			GPIOB->AFR[1] |= (1U<<12);
			GPIOB->AFR[1] |= (1U<<13);
			GPIOB->AFR[1] |= (1U<<14);
			GPIOB->AFR[1] &=~ (1U<<15);
			/* Enable the clock to USART3 */
			RCC->APB1ENR |= RCC_APB1ENR_USART3EN;
			break;
		case (uint32_t) USART6:
			/* Enable the clock to GPIOA */
			RCC->AHB1ENR |= RCC_AHB1ENR_GPIOCEN;
			/*Set PC7 mode to alternate function mode*/
			GPIOC->MODER &=~ (PIN7 * PIN7);
			GPIOC->MODER |= ((PIN7 * PIN7) << 1);
			/*Set PC7 alternate function type to USART6_RX (AF08)*/
			GPIOC->AFR[0] &=~ (1U<<28);
			GPIOC->AFR[0] &=~ (1U<<29);
			GPIOC->AFR[0] &=~ (1U<<30);
			GPIOC->AFR[0] |= (1U<<31);
			/* Enable the clock to USART6 */
			RCC->APB2ENR |= RCC_APB2ENR_USART6EN;
			break;
		}

		/*Configure baudrate*/
		USART->BRR = ((SYS_FREQ + (BaudRate/2U))/BaudRate);

		/*Configure the transfer direction*/
		USART->CR1 |=  USART_CR1_RE;

		/*Enable uart module*/
		USART->CR1 |=  USART_CR1_UE;
}
void uart_write(USART_TypeDef * USART, int ch)
{
  /*Make sure the transmit data register is empty*/
	while(!(USART->SR & USART_SR_TXE)){}

  /*Write to transmit data register*/
	USART->DR	=  (ch & 0xFF);
}
char uart_read(USART_TypeDef * USART)
{
  /*Make sure the read data register is not empty*/
	while(!(USART->SR & USART_SR_RXNE)){}

	return USART->DR;

}

void uart2_rx_interrupt_init(void)
{
	/****************Configure uart gpio pin***************/
	/*Enable clock access to gpioa */
	RCC->AHB1ENR |= RCC_AHB1ENR_GPIOAEN;

	/*Set PA2 mode to alternate function mode*/
	GPIOA->MODER &=~(1U<<4);
	GPIOA->MODER |= (1U<<5);

	/*Set PA2 alternate function type to UART_TX (AF07)*/
	GPIOA->AFR[0] |= (1U<<8);
	GPIOA->AFR[0] |= (1U<<9);
	GPIOA->AFR[0] |= (1U<<10);
	GPIOA->AFR[0] &= ~(1U<<11);

	/*Set PA3 mode to alternate function mode*/
	GPIOA->MODER &=~(1U<<6);
	GPIOA->MODER |= (1U<<7);

	/*Set PA3 alternate function type to UART_RX (AF07)*/
	GPIOA->AFR[0] |= (1U<<12);
	GPIOA->AFR[0] |= (1U<<13);
	GPIOA->AFR[0] |= (1U<<14);
	GPIOA->AFR[0] &= ~(1U<<15);

	/****************Configure uart module ***************/
	/*Enable clock access to uart2 */
	RCC->APB1ENR |= RCC_APB1ENR_USART2EN;

	/*Configure baudrate*/
	USART2->BRR = ((SYS_FREQ + (BaudRate/2U))/BaudRate);

	/*Configure the transfer direction*/
	USART2->CR1 = USART_CR1_RE;

	/*Enable RXNE inteerupt*/
	USART2->CR1 |= USART_CR1_RXNEIE;

	/*Enable UART2 interrupt in NVIC*/
	NVIC_EnableIRQ(USART2_IRQn);

	/*Enable uart module*/
	USART2->CR1 |= USART_CR1_UE;
}
void dma1_stream6_init(uint32_t src, uint32_t dst, uint32_t len)
{
	/* We need to find "DMA1 request map" to know that which DMA and stream we want to us */

	/*Enable clock access to DMA*/
	RCC->AHB1ENR |=RCC_AHB1ENR_DMA1EN;

	/*Disable DMA1 Stream6*/
	DMA1_Stream6->CR &=~ DMA_SxCR_EN;

    /*Wait until DMA1 Stream 6 is disabled */
    while(DMA1_Stream6->CR & DMA_SxCR_EN){}

	/*Clear all interrupt flags of Stream6*/

	DMA1->HIFCR |= DMA_HIFCR_CFEIF6;
	DMA1->HIFCR |= DMA_HIFCR_CDMEIF6;
	DMA1->HIFCR |= DMA_HIFCR_CTEIF6;
	DMA1->HIFCR |= DMA_HIFCR_CHTIF6;
	DMA1->HIFCR |= DMA_HIFCR_CTCIF6;

	/*Set the destination buffer*/
	DMA1_Stream6->PAR = dst;

	/*Set the source buffer*/
	DMA1_Stream6->M0AR = src;

	/*Set length*/
	DMA1_Stream6->NDTR = len;

	/*Select Stream6 CH4*/ // According to "DMA1 request map" to choose the channel.
	DMA1_Stream6->CR = DMA_SxCR_CHSEL_2;

	/*Enable memory increment*/
	DMA1_Stream6->CR |= DMA_SxCR_MINC;

	/*Configure transfer direction*/
	DMA1_Stream6->CR |= DMA_SxCR_DIR_0;

	/*Enable DMA transfer complete interrupt*/
	DMA1_Stream6->CR |= DMA_SxCR_TCIE;

	/*Enable direct mode and disable FIFO*/
	DMA1_Stream6->FCR = 0;

	/*Enable DMA1 Stream6*/
	DMA1_Stream6->CR |= DMA_SxCR_EN;

	/*Enable UART2 transmitter DMA*/
	USART2->CR3 |= USART_CR3_DMAT;

	/*DMA Interrupt enable in NVIC*/
	NVIC_EnableIRQ(DMA1_Stream6_IRQn);
}
void USART2_IRQHandler(void){
	if(USART2->SR & USART_SR_RXNE)
	{
	}
}
static void dma_callback(void)
{
	GPIO_SET(GPIOD,PIN13,SET);
	systickDelayMs(500);
	GPIO_SET(GPIOD,PIN13,RESET);
	systickDelayMs(500);
}

void DMA1_Stream6_IRQHandler(void)
{
	/*Check for transfer complete interrupt*/
	if(DMA1->HISR & DMA_HISR_TCIF6)
	{
		/*Clear flag*/
		DMA1->HIFCR |= DMA_HIFCR_CTCIF6;

		/*Do something*/
		dma_callback();
	}
}
