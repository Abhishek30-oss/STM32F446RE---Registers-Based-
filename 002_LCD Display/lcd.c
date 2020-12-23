#include "stm32f4xx.h"
#include "lcd.h"


void LCD_Init(void)
	{
			//ADD code here for extra LCD Init functions.
		
			Busy_check();
			LCD_Out(0,0x38);						// 8-Bit 2 Line 
			Busy_check();
			LCD_Out(0,0x0E);						// Dsiplay on Cursor on
			Busy_check();
			LCD_Out(0,0x01);						// Clear Display Screen
		
	}	




void GPIO_INIT(void)
	{
		
			 RCC->AHB1ENR |= (1<<1);		//GPIOB clock Configure
			 RCC->AHB1ENR |= (1<<2);		//GPIOC clock Configure
		
			 GPIOB->MODER |= ((1<<26) | (1<<28) |(1<<30));   //RS RW EN Comfigured as output
			 GPIOC->MODER |= ((1<<0) | (1<<2) | (1<<4) | (1<<6) | (1<<8) | (1<<10)| (1<<12) | (1<<14));		//DATA PORT C Configured as output

	}




void Busy_check(void)
  {
		/*Note : Always give slight delay of few ns to us in case of very fast Microcontrollers 
						while reading, between low to high EN pulse.
		*/
		  unsigned int delay;
			RS &= RS_RESET;
			RW |= RW_SET	;
			BUSY &= BUSY_IPMODE ;											//Making Bit 7 as Input
			do
			{
					EN &=EN_RESET;
				  for(delay=0;delay<30000;delay++);			//delay for reading
					EN |= EN_SET;
				  for(delay=0;delay<30000;delay++);
			}while((BUSY_STATUS & (1<<7))==1);
			
			//DATA PORT C Configured as output
			GPIOC->MODER |= ((1<<0) | (1<<2) | (1<<4) | (1<<6) | (1<<8) | (1<<10)| (1<<12) | (1<<14));		
   
  }

 
  void LCD_Out(unsigned char Command,unsigned char DATA)
     {
		 
			RW &= RW_RESET;
			if(Command == 0)
			 	RS &= RS_RESET;
			else 
                        	RS |= RS_SET;
	                __LCDDISPLAY__ = DATA;
			EN |= EN_SET;
			EN &= EN_RESET;
	
	}	
	
	
