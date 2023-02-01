#include "stm32f4xx.h"
#include "Mydriver.h"
#include "uart.h"
#include "adc.h"
#include "systick.h"
#include "tim.h"
#include "stdio.h"
#include "stdint.h"
#include "screen.h"


int main(void)
{
	ILI9341_Init();
	ILI9341_FillScreen(GREEN);
	ILI9341_DrawFilledCircle(100,100,20,RED);
	while(1)
	{
		systickDelayMs(10);
	}
}





