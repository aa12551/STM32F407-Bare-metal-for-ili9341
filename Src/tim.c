/*
 * tim.c
 *
 *  Created on: 2023年1月31日
 *      Author: s94009880225
 */

#include "tim.h"

void tim4_PDx_output_compare(uint32_t PIN)
{
	/* Connect tim4 to LED PIN to make LED toggle */
	/* We need to look at "Alternate function mapping" to know which peripherals we need to use */

	/*Enable clock access to GPIOD*/
	RCC->AHB1ENR |= RCC_AHB1ENR_GPIODEN;

	/*Set PDx mode to alternate function*/
	GPIOD->MODER &=~ (PIN * PIN);
	GPIOD->MODER |= ((PIN * PIN) << 1);

	/*Enable clock access to tim4*/
	RCC->APB1ENR |= RCC_APB1ENR_TIM4EN;

	/*Set prescaler value*/
	TIM4->PSC =  1600 - 1 ;  //  16 000 000 / 1 600 = 10 000
	/*Set auto-reload value*/
	TIM4->ARR =  10000 - 1;  // 10 000 / 10 000 = 1


	switch (PIN)
	{
		case PIN12:
			//*Set PD12 alternate function type to TIM4_CH1 (AF02)*/
			GPIOD->AFR[1] |= GPIO_AFR_PIN12_AF02;
			/*Set output compare toggle mode (if count to reload value, it will toggle.) */
			TIM4->CCMR1 |=  TIM_CCMR1_OC1M_TOGGLE;
			/*Enable tim4 ch1 in compare mode*/
			TIM4->CCER |= (1U<<0);
			break;
		case PIN13:
			//*Set PD13 alternate function type to TIM4_CH2 (AF02)*/
			GPIOD->AFR[1] |= GPIO_AFR_PIN13_AF02;
			/*Set output compare toggle mode (if count to reload value, it will toggle.) */
			TIM4->CCMR1 |=  TIM_CCMR1_OC2M_TOGGLE;
			/*Enable tim4 ch2 in compare mode*/
			TIM4->CCER |= (1U<<4);
			break;
		case PIN14:
			//*Set PD14 alternate function type to TIM4_CH3 (AF02)*/
			GPIOD->AFR[1] |= GPIO_AFR_PIN14_AF02;
			/*Set output compare toggle mode (if count to reload value, it will toggle.) */
			TIM4->CCMR2 |=  TIM_CCMR2_OC3M_TOGGLE;
			/*Enable tim4 ch3 in compare mode*/
			TIM4->CCER |= (1U<<8);
			break;
		case PIN15:
			//*Set PD15 alternate function type to TIM4_CH4 (AF02)*/
			GPIOD->AFR[1] |= GPIO_AFR_PIN15_AF02;
			/*Set output compare toggle mode (if count to reload value, it will toggle.) */
			TIM4->CCMR2 |=  TIM_CCMR2_OC4M_TOGGLE;
			/*Enable tim4 ch4 in compare mode*/
			TIM4->CCER |= (1U<<12);
			break;
	}

	/*Clear counter*/
	TIM4->CNT = 0;
	/*Enable timer*/
	TIM4->CR1 = (1U<<0);
}

void tim2_1hz_init(void)
{
	/*Enable clock access to tim2*/
	RCC->APB1ENR |=TIM2EN;

	/*Set prescaler value*/
	TIM2->PSC =  1600 - 1 ;  //  16 000 000 / 1 600 = 10 000
	/*Set auto-reload value*/
	TIM2->ARR =  10000 - 1;  // 10 000 / 10 000 = 1
	/*Clear counter*/
	TIM2->CNT = 0;

	/*Enable timer*/
	TIM2->CR1 = TIM_CR1_CEN;
}


void tim2_pa5_output_compare(void)
{

	 /*Enable clock access to GPIOA*/
	RCC->AHB1ENR |=GPIOAEN;

	/*Set PA5 mode to alternate function*/
	GPIOA->MODER &=~(1U<<10);
	GPIOA->MODER |=(1U<<11);

	/*Set PA5 alternate function type to TIM2_CH1 (AF01)*/
	GPIOA->AFR[0] |=AFR5_TIM;

	/*Enable clock access to tim2*/
	RCC->APB1ENR |=TIM2EN;

	/*Set prescaler value*/
	TIM2->PSC =  1600 - 1 ;  //  16 000 000 / 1 600 = 10 000

	/*Set auto-reload value*/
	TIM2->ARR =  10000 - 1;  // 10 000 / 10 000 = 1

	/*Set output compare toggle mode*/
	TIM2->CCMR1 =  OC_TOGGLE;

	/*Enable tim2 ch1 in compare mode*/
	TIM2->CCER |= CCER_CC1E;

	/*Clear counter*/
	TIM2->CNT = 0;

	/*Enable timer*/
	TIM2->CR1 = TIM_CR1_CEN;
}


void tim3_pa6_input_capture(void)
{

	 /*Enable clock access to GPIOA*/
	RCC->AHB1ENR |=GPIOAEN;

	/*Set PA6 mode to alternate function*/
	GPIOA->MODER &=~(1U<<12);
	GPIOA->MODER |=(1U<<13);

	/*Set PA6 alternate function type to TIM3_CH1 (AF02)*/
	GPIOA->AFR[0]|=AFR6_TIM;

	/*Enable clock access to tim3*/
	RCC->APB1ENR |=TIM3EN;

	/*Set Prescaler*/
	TIM3->PSC = 16000 -1; // 16 000 000 /16 000

	/*Set CH1 to input capture*/
	TIM3->CCMR1  = CCER_CC1S;

	/*Set CH1 to capture at rising edge*/
	TIM3->CCER  = CCER_CC1E;

	/*Enable TIM3*/
	TIM3->CR1 = TIM_CR1_CEN;

}
void tim2_1hz_interrupt_init(void)
{
	/*Enable clock access to tim2*/
	RCC->APB1ENR |= RCC_APB1ENR_TIM2EN;

	/*Set prescaler value*/
	TIM2->PSC =  1600 - 1 ;  //  16 000 000 / 1 600 = 10 000
	/*Set auto-reload value*/
	TIM2->ARR =  10000 - 1;  // 10 000 / 10 000 = 1
	/*Clear counter*/
	TIM2->CNT = 0;

	/*Enable timer*/
	TIM2->CR1 = TIM_CR1_CEN;

	/*Enable TIM interrupt*/
	TIM2->DIER |= TIM_DIER_UIE;

	/*Enable TIM interrupt in NVIC*/
	 NVIC_EnableIRQ(TIM2_IRQn);
}


void TIM2_IRQHandler(void)
{
	for(int i = 0;i<100000;i++){}
	GPIO_SET(GPIOD,PIN13,SET);
	for(int i = 0;i<100000;i++){}
	GPIO_SET(GPIOD,PIN13,RESET);
}
