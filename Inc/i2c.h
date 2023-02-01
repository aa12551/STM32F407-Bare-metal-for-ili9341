/*
 * i2c.h
 *
 *  Created on: 2023年1月31日
 *      Author: s94009880225
 */

#ifndef I2C_H_
#define I2C_H_
#include "Mydriver.h"

void I2C1_init(void);
void I2C1_byteRead(char saddr, char maddr, char* data);
void I2C1_burstWrite(char saddr, char maddr, int n, char* data);
#endif /* I2C_H_ */
