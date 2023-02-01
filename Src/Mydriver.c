#include "Mydriver.h"


// For USART

#define SR_TXE			(1U<<7)


#define GPIOAEN		    (1U<<0)
#define ADC1EN			(1U<<8)
#define ADC_CH1			(1U<<0)
#define ADC_SEQ_LEN_1	 0x00
#define CR2_AD0N		(1U<<0)
#define CR2_SWSTART		(1U<<30)
#define SR_EOC			(1U<<1)


void GPIO_SET(GPIO_TypeDef * port,uint32_t pin, uint8_t value)
{
	// Connect clock to port
	switch((uint32_t) port){
	case (uint32_t) GPIOA:
		RCC->AHB1ENR |= RCC_AHB1ENR_GPIOAEN;
		break;
	case (uint32_t) GPIOB:
		RCC->AHB1ENR |= RCC_AHB1ENR_GPIOBEN;
		break;
	case (uint32_t) GPIOC:
		RCC->AHB1ENR |= RCC_AHB1ENR_GPIOCEN;
		break;
	case (uint32_t) GPIOD:
		RCC->AHB1ENR |= RCC_AHB1ENR_GPIODEN;
		break;
	}

	// Set the pin is output type
	port->MODER |= pin * pin;
	port->MODER &=~ pin * pin * 2;
	// Set the pin value
	if(value)
		port->BSRR |= pin;
	else
		port->BSRR |= pin << 16;
}




void pa0_exti_init(void)
{
	/*Disable global interrupts*/
	__disable_irq();

	/*Enable clock access for GPIOA*/
	RCC->AHB1ENR |= RCC_AHB1ENR_GPIOAEN;

	/*Set PA0 as input*/
	GPIOC->MODER &=~ (PIN0 * PIN0);
	GPIOC->MODER &=~ (PIN0 * PIN0) << 1;

	/*Enable clock access to SYSCFG*/
	RCC->APB2ENR |= RCC_APB2ENR_SYSCFGEN;

	/*Select PORTA for EXTI0*/
	SYSCFG->EXTICR[0] &=~ (1U<<0);
	SYSCFG->EXTICR[0] &=~ (1U<<1);
	SYSCFG->EXTICR[0] &=~ (1U<<2);
	SYSCFG->EXTICR[0] &=~ (1U<<3);

	/*Unmask EXTI13*/
	EXTI->IMR |= PIN0;

	/*Select falling edge trigger*/
	EXTI->FTSR |= (PIN0);

	/*Enable EXTI13 line in NVIC*/
	NVIC_EnableIRQ(EXTI0_IRQn);

	/*Enable global interrupts*/
	__enable_irq();


}
static void exti_callback(void)
{
	printf("BTN Pressed...\n\r");
	GPIO_SET(GPIOD,PIN13,SET);
}


void EXTI0_IRQHandler(void) {
	if((EXTI->PR & PIN0)!=0)
	{
		/*Clear PR flag*/
		EXTI->PR |= PIN0;
		//Do something...
		exti_callback();
	}

}
