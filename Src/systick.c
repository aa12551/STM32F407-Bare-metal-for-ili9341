/*
 * systick.c
 *
 *  Created on: 2023年1月31日
 *      Author: s94009880225
 */

#include "systick.h"
void systickDelayMs(int delay)
{
	/*Reload with number of clocks per millisecond*/
	SysTick->LOAD	= SYST_LOAD_VAL;

	/*Clear systick current value register */
	SysTick->VAL = 0;

	/*Enable systick and select internal clk src*/
	SysTick->CTRL = SYST_CSR_ENABLE | SYST_CSR_CLKSRC;

	for(int i=0; i<delay ; i++){

		/*Wait until the COUNTFLAG is set*/

		while((SysTick->CTRL &  SYST_CSR_COUNTFLAG) == 0){}

	}

	SysTick->CTRL = 0;

}

void systick_1hz_interrupt(void)
{
	/*Reload with number of clocks persecond*/

	SysTick->LOAD  = ONE_SEC_LOAD - 1;

	/*Clear systick current value register */
	SysTick->VAL = 0;

	/*Enable systick and select internal clk src*/
	SysTick->CTRL = CTRL_ENABLE | CTRL_CLKSRC ;

	/*Enable systick interrupt*/
	SysTick->CTRL  |= CTRL_TICKINT;
}

/* If use Systick interrupt, it will run the following answer */
void SysTick_Handler(void)
{
	for(int i = 0;i<100000;i++){}
	GPIO_SET(GPIOD,PIN13,SET);
	for(int i = 0;i<100000;i++){}
	GPIO_SET(GPIOD,PIN13,RESET);
}
