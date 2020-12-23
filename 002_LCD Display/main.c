#include "stm32f4xx.h"
#include "lcd.h"


unsigned char cnt,msg[]="STM32F446RE";

int main()
{
	
		GPIO_INIT();				//Hardware Initialization
		LCD_Init();				//LCD_Init Initialization
	    		
	  for(cnt=0;msg[cnt]!='\0';cnt++)
            {
                Busy_check();
                LCD_Out(1,msg[cnt]);
	    }
	   while(1);  
						
}


