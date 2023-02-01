/*
 * screen.h
 *
 *  Created on: 2023年1月31日
 *      Author: s94009880225
 */

#ifndef SCREEN_H_
#define SCREEN_H_


#include "stm32f4xx.h"
#include "Mydriver.h"

#define ILI9341_SCREEN_HEIGHT 	240
#define ILI9341_SCREEN_WIDTH 	320

/* PIN Configuration */
#define LCD_CS_PORT				GPIOC
#define LCD_CS_PIN				PIN1
#define LCD_DC_PORT				GPIOC
#define LCD_DC_PIN				PIN2
#define	LCD_RST_PORT			GPIOC
#define	LCD_RST_PIN				PIN3


#define BURST_MAX_SIZE 			500
#define BLACK      				0x0000
#define RED        				0x001F
#define GREEN       			0x07E0
#define BLUE         			0xF800
#define WRITE					0xFFFF


#define SCREEN_VERTICAL_1		0
#define SCREEN_HORIZONTAL_1		1
#define SCREEN_VERTICAL_2		2
#define SCREEN_HORIZONTAL_2		3

void ILI9341_WriteCommand(uint8_t cmd);
void ILI9341_WriteData(uint8_t data);
void ILI9341_Reset(void);
void ILI9341_Enable(void);
void ILI9341_SetRotation(uint8_t rotation);
void ILI9341_Init(void);
void ILI9341_DrawColor(uint16_t color);
void ILI9341_DrawColorBurst(uint16_t color, uint32_t size);
void ILI9341_SetAddress(uint16_t x1, uint16_t y1, uint16_t x2, uint16_t y2);
void ILI9341_FillScreen(uint16_t color);
void ILI9341_DrawPixel(uint16_t x,uint16_t y,uint16_t color);
void ILI9341_DrawRectangle(uint16_t x, uint16_t y, uint16_t width, uint16_t height, uint16_t color);
void ILI9341_DrawHLine(uint16_t x, uint16_t y, uint16_t width, uint16_t color);
void ILI9341_DrawVLine(uint16_t x, uint16_t y, uint16_t height, uint16_t color);
void ILI9341_DrawFilledCircle(uint16_t X, uint16_t Y, uint16_t radius, uint16_t color);
void ILI9341_DrawHollowRectangleCoord(uint16_t X0, uint16_t Y0, uint16_t X1, uint16_t Y1, uint16_t color);
void ILI9341_DrawChar(char ch, const uint8_t font[], uint16_t X, uint16_t Y, uint16_t color, uint16_t bgcolor);
void ILI9341_DrawText(const char* str,int num, const uint8_t font[], uint16_t X, uint16_t Y, uint16_t color, uint16_t bgcolor);
void ILI9341_DrawImage(const uint8_t* image, uint8_t orientation);
#endif /* SCREEN_H_ */
