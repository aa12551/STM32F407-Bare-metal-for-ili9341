/*
 * systick.h
 *
 *  Created on: 2023年1月31日
 *      Author: s94009880225
 */

#ifndef SYSTICK_H_
#define SYSTICK_H_

#include "Mydriver.h"

#define SYST_LOAD_VAL	  	16000
#define SYST_CSR_ENABLE		(1U<<0)
#define SYST_CSR_CLKSRC		(1U<<2)
#define SYST_CSR_COUNTFLAG  (1U<<16)

#define	CTRL_ENABLE					(1U<<0)
#define CTRL_CLKSRC					(1U<<2)
#define CTRL_COUNTFLAG				(1U<<16)
#define CTRL_TICKINT				(1U<<1)
#define ONE_SEC_LOAD				16000000

void systickDelayMs(int delay);
void systick_1hz_interrupt(void);

#endif /* SYSTICK_H_ */
