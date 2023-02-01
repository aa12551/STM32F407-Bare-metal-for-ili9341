/*
 * adc.c
 *
 *  Created on: 2023年1月31日
 *      Author: s94009880225
 */
#include "adc.h"
#include <stdio.h>
void pa1_adc_init(void)
{
	/***Configure the ADC GPIO pin ***/

	/*Enable clock access to GPIOA*/
	RCC->AHB1ENR |= RCC_AHB1ENR_GPIOAEN;

	/*Set the mode of PA1 to analog (We can find additional function) */
	GPIOA->MODER |= (PIN1 * PIN1);
	GPIOA->MODER |= ((PIN1 * PIN1) << 1);

	/***Configure the ADC module***/
	/*Enable clock access to ADC */
	RCC->APB2ENR |= RCC_APB2ENR_ADC1EN;

	/*Conversion sequence start (Choose which channel we want to use) */
	ADC1->SQR3 = ADC_SQR3_SQ1_0;

	/*Conversion sequence length (Set How many channel we used) */
	ADC1->SQR1 = ADC_SQR1_L_0;

	/*Enable ADC module*/
	ADC1->CR2 |= ADC_CR2_ADON;
}

void pa1_adc_interrupt_init(void)
{
	/***Configure the ADC GPIO pin ***/

	/*Enable clock access to GPIOA*/
	RCC->AHB1ENR |= RCC_AHB1ENR_GPIOAEN;

	/*Set the mode of PA1 to analog*/
	GPIOA->MODER |= (PIN1 * PIN1);
	GPIOA->MODER |= (PIN1 * PIN1) << 1;

	/***Configure the ADC module***/
	/*Enable clock access to ADC */
	RCC->APB2ENR |= RCC_APB2ENR_ADC1EN;

	/*Enable ADC end-of-conversion interrupt*/
	ADC1->CR1 |= ADC_CR1_EOCIE;

	/*Enable ADC interrupt in NVIC*/
	NVIC_EnableIRQ(ADC_IRQn);

	/*Conversion sequence start*/
	ADC1->SQR3 = ADC_SQR3_SQ1_0;

	/*Conversion sequence length*/
	ADC1->SQR1 = ADC_SQR1_L_0;

	/*Enable ADC module*/
	ADC1->CR2 |= ADC_CR2_ADON;
}

void start_conversion(int continuous)
{
	if(continuous)
		ADC1->CR2 |= ADC_CR2_CONT; // We just need to start one time
	/*Start adc conversion*/
	ADC1->CR2 |= ADC_CR2_SWSTART;
}

uint32_t adc_read(void)
{
	/*Wait for conversion to be complete*/
	while(!(ADC1->SR & ADC_SR_EOC)){}

	/*Read converted result*/
	return (ADC1->DR);
}


static void adc_callback(void)
{
	int sensor_value = ADC1->DR;
	printf("Sensor value : %d \n\r",(int)sensor_value);
	for(int i = 0;i<100000;i++){}

}
void ADC_IRQHandler(void)
{
	/*Check for eoc in SR*/
	if((ADC1->SR & ADC_SR_EOC) !=0)
	{
		/*Clear EOC*/
		ADC1->SR &=~ ADC_SR_EOC;

		//Do something
		adc_callback();
	}
}
