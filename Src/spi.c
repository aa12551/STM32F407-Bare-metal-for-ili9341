/*
 * spi.c
 *
 *  Created on: 2023年1月31日
 *      Author: s94009880225
 */


#include "spi.h"

//PA5 -> CLK
//PA6 -> MISO
//PA7 -> MOSI

//PA9 -> Slave Select


void spi_gpio_init(SPI_TypeDef* SPI)
{

	switch ((uint32_t) SPI)
	{
		case (uint32_t) SPI1 :
			/* SPI1 Use PA5->CLK , PA6->MISO , PA7->MOSI */
			/*Enable clock access to GPIOA*/
			RCC->AHB1ENR |= RCC_AHB1ENR_GPIOAEN;

			/*Set PA5,PA6,PA7 mode to alternate function*/
			/*PA5*/
			GPIOA->MODER &=~ (PIN5 * PIN5);
			GPIOA->MODER |=  (PIN5 * PIN5) << 1;

			/*PA6*/
			GPIOA->MODER &=~ (PIN6 * PIN6);
			GPIOA->MODER |=  (PIN6 * PIN6) << 1;

			/*PA7*/
			GPIOA->MODER &=~ (PIN7 * PIN7);
			GPIOA->MODER |=  (PIN7 * PIN7) << 1;


			/*Set PA5,PA6,PA7 alternate function type to SPI1*/
			/*PA5*/
			GPIOA->AFR[0] |=  (1U<<20);
			GPIOA->AFR[0] &= ~(1U<<21);
			GPIOA->AFR[0] |=  (1U<<22);
			GPIOA->AFR[0] &= ~(1U<<23);

			/*PA6*/
			GPIOA->AFR[0] |=  (1U<<24);
			GPIOA->AFR[0] &= ~(1U<<25);
			GPIOA->AFR[0] |=  (1U<<26);
			GPIOA->AFR[0] &= ~(1U<<27);

			/*PA7*/
			GPIOA->AFR[0] |=  (1U<<28);
			GPIOA->AFR[0] &= ~(1U<<29);
			GPIOA->AFR[0] |=  (1U<<30);
			GPIOA->AFR[0] &= ~(1U<<31);
		case (uint32_t) SPI2:
			/* SPI2 Use PB13->CLK , PB14->MISO , PB15->MOSI */
			/*Enable clock access to GPIOB*/
			RCC->AHB1ENR |= RCC_AHB1ENR_GPIOBEN;

			/*Set PB13,PB14,PB15 mode to alternate function*/
			/*PB13*/
			GPIOB->MODER &=~ (PIN13 * PIN13);
			GPIOB->MODER |=  (PIN13 * PIN13) << 1;

			/*PB14*/
			GPIOB->MODER &=~ (PIN14 * PIN14);
			GPIOB->MODER |=  (PIN14 * PIN14) << 1;

			/*PB15*/
			GPIOB->MODER &=~ (PIN15 * PIN15);
			GPIOB->MODER |=  (PIN15 * PIN15) << 1;


			/*Set PB13,PB14,PB15 alternate function type to SPI1*/
			/*PB13*/
			GPIOB->AFR[1] |=  (1U<<20);
			GPIOB->AFR[1] &= ~(1U<<21);
			GPIOB->AFR[1] |=  (1U<<22);
			GPIOB->AFR[1] &= ~(1U<<23);

			/*PB14*/
			GPIOB->AFR[1] |=  (1U<<24);
			GPIOB->AFR[1] &= ~(1U<<25);
			GPIOB->AFR[1] |=  (1U<<26);
			GPIOB->AFR[1] &= ~(1U<<27);

			/*PB15*/
			GPIOB->AFR[1] |=  (1U<<28);
			GPIOB->AFR[1] &= ~(1U<<29);
			GPIOB->AFR[1] |=  (1U<<30);
			GPIOB->AFR[1] &= ~(1U<<31);
	}
}

void spi_config(SPI_TypeDef* SPI)
{
	switch ((uint32_t) SPI)
	{
		case (uint32_t) SPI1:
			/*Enable clock access to SPI1 module*/
			RCC->APB2ENR |= RCC_APB2ENR_SPI1EN;
		case (uint32_t) SPI2:
			/*Enable clock access to SPI1 module*/
			RCC->APB1ENR |= RCC_APB1ENR_SPI2EN;

	}

	/*Set clock to fPCLK/4*/
	SPI->CR1 |= SPI_CR1_BR_0;

	/*Set CPOL to 1 and CPHA to 1*/
	SPI->CR1 |= SPI_CR1_CPHA;
	SPI->CR1 |= SPI_CR1_CPOL;

	/*Enable full duplex*/
	SPI->CR1 &=~ SPI_CR1_RXONLY;

	/*Set MSB first*/
	SPI->CR1 &=~ SPI_CR1_LSBFIRST;

	/*Set mode to MASTER*/
	SPI->CR1 |= SPI_CR1_MSTR;

	/*Set 8 bit data mode*/
	SPI->CR1 &=~ SPI_CR1_DFF;

	/*Select software slave management by setting SSM=1 and SSI=1*/
	SPI->CR1 |= SPI_CR1_SSM;
	SPI->CR1 |= SPI_CR1_SSI;

	/*Enable SPI module*/
	SPI->CR1 |= SPI_CR1_SPE;


}

void spi_transmit(SPI_TypeDef* SPI, uint8_t *data,uint32_t size)
{
	uint32_t i=0;
//	uint8_t temp;

	while(i<size)
	{
		/*Wait until TXE is set*/
		while(!(SPI->SR & (SPI_SR_TXE))){}

		/*Write the data to the data register*/
		SPI->DR = data[i];
		i++;
	}
	/*Wait until TXE is set*/
	while(!(SPI->SR & (SPI_SR_TXE))){}

	/*Wait for BUSY flag to reset*/
	while((SPI->SR & (SPI_SR_BSY))){}

//	/*Clear OVR flag*/
//	temp = SPI->DR;
//	temp = SPI->SR;

}

void spi_receive(SPI_TypeDef* SPI, uint8_t *data,uint32_t size)
{
	while(size)
	{
		/*Send dummy data*/
		SPI->DR =0;

		/*Wait for RXNE flag to be set*/
		while(!(SPI->SR & (SPI_SR_RXNE))){}

		/*Read data from data register*/
		*data++ = (SPI->DR);
		size--;
	}
}
