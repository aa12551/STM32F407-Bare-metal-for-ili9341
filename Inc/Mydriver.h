#include "stm32f4xx.h"
#include "stdint.h"
#include <stdio.h>
/* For GPIO PIN */
#define PIN0 		(1U<<0)
#define PIN1 		(1U<<1)
#define PIN2 		(1U<<2)
#define PIN3 		(1U<<3)
#define PIN4 		(1U<<4)
#define PIN5 		(1U<<5)
#define PIN6 		(1U<<6)
#define PIN7 		(1U<<7)
#define PIN8 		(1U<<8)
#define PIN9 		(1U<<9)
#define PIN10 		(1U<<10)
#define PIN11 		(1U<<11)
#define PIN12 		(1U<<12)
#define PIN13 		(1U<<13)
#define PIN14 		(1U<<14)
#define PIN15 		(1U<<15)
#define PIN_SET 	(uint8_t) 1
#define PIN_RESET 	(uint8_t) 0
#define SYS_FREQ	16000000

void GPIO_SET(GPIO_TypeDef * port,uint32_t pin, uint8_t value);
void systickDelayMs(int delay);
void pa0_exti_init(void);
