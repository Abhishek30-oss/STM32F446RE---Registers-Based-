#include "stm32f4xx.h"
#include "lcd.h"


unsigned char i,msg[]="STM32F446RE";

int main()
{
	
		GPIO_INIT();			//Hardware Initialization
		LCD_Init();				//LCD_Init Initialization
	    		
	  for(i=0;msg[i]!='\0';i++)
            {
                Busy_check();
								LCD_Out(1,msg[i]);
		        }
	   while(1);  
						
}


