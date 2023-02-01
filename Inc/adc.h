/*
 * adc.h
 *
 *  Created on: 2023年1月31日
 *      Author: s94009880225
 */

#ifndef ADC_H_
#define ADC_H_

#include "Mydriver.h"

void pa1_adc_init(void);
void pa1_adc_interrupt_init(void);
void start_conversion(int continuous);
uint32_t adc_read(void);


#endif /* ADC_H_ */
