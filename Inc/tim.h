/*
 * tim.h
 *
 *  Created on: 2023年1月31日
 *      Author: s94009880225
 */

#ifndef TIM_H_
#define TIM_H_
#include "Mydriver.h"

#define TIM2EN		(1U<<0)
#define TIM3EN		(1U<<1)

#define OC_TOGGLE	((1U<<4) | (1U<<5))
#define CCER_CC1E	(1U<<0)


#define GPIOAEN		(1U<<0)
#define AFR5_TIM	(1U<<20)
#define AFR6_TIM	(1U<<25)
#define CCER_CC1S  (1U<<0)


#define GPIO_AFR_PIN12_AF02 			(1U<<17)
#define GPIO_AFR_PIN13_AF02 			(1U<<21)
#define GPIO_AFR_PIN14_AF02 			(1U<<25)
#define GPIO_AFR_PIN15_AF02 			(1U<<29)
#define TIM_CCMR1_OC1M_TOGGLE			((1U<<4) | (1U<<5))
#define TIM_CCMR1_OC2M_TOGGLE			((1U<<12) | (1U<<13))
#define TIM_CCMR2_OC3M_TOGGLE			((1U<<4) | (1U<<5))
#define TIM_CCMR2_OC4M_TOGGLE			((1U<<12) | (1U<<13))

void tim2_1hz_init(void);
void tim4_PDx_output_compare(uint32_t PIN);
void tim2_1hz_interrupt_init(void);

#endif /* TIM_H_ */
