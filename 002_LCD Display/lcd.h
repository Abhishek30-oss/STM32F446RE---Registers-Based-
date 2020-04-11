#include "stm32f4xx.h"


#define RS										(GPIOB->ODR)
#define RW										(GPIOB->ODR)
#define EN										(GPIOB->ODR)

#define RS_SET								((1<<13))
#define RS_RESET							(~(1<<13))

#define RW_SET								((1<<14))
#define RW_RESET							(~(1<<14))

#define EN_SET								((1<<15))
#define EN_RESET							(~(1<<15))

#define BUSY 									(GPIOC->MODER)
#define BUSY_IPMODE 					(~((1<<14)|(1<<15)))
#define BUSY_STATUS       		(GPIOC->IDR)

#define __LCDDISPLAY__  			(GPIOC->ODR)

void GPIO_INIT(void);
void LCD_Init(void);
void Busy_check(void);
void LCD_Out(unsigned char x,unsigned char y);
