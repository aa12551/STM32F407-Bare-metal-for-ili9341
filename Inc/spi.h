/*
 * spi.h
 *
 *  Created on: 2023年1月31日
 *      Author: s94009880225
 */

#ifndef SPI_H_
#define SPI_H_
#include "Mydriver.h"
void spi_gpio_init(SPI_TypeDef* SPI);
void spi_config(SPI_TypeDef* SPI);
void spi_transmit(SPI_TypeDef* SPI, uint8_t *data,uint32_t size);
void spi_receive(SPI_TypeDef* SPI, uint8_t *data,uint32_t size);

#endif /* SPI_H_ */
