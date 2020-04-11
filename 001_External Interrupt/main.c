/*    LED TOGGLE USING EXTERNAL INTERRUPT   
* STM32NUCLEO F446RE Board
* LED -PA5
* PUSH BUTTON - PC13

Procedure to use pin as External Interrupt
1) Configure Pin in Input mode
2) Enable SYSCNFG in APB2ENR Register
3) Enable particular EXTI line in SYSCNFG register to activate external interrupt line 
4) Enable IMR and Configure Falling edge or Rising edge depending on your pin
5) Enable the Interrupt
*/


#include "stm32f4xx.h"

void EXTI15_10_IRQHandler(void)
{
   if(EXTI->PR & (1<<13))
	 {
	   EXTI->PR |=(1<<13);									//Clear Pending Register
	 }		 
	 
	GPIOA->ODR = ~(GPIOA->ODR) ;						//LED Toggle
}

int main()
{
	
		RCC->AHB1ENR |= ((1<<0) | (1<<2));		//COnfigure clock for PORT A and PORT C
	
		//Configuring  PA5 as OUTPUT
      GPIOA->MODER &= ~(1<<11);	
      GPIOA->MODER |= (1<<10);
	
	//IN STM32F446RE to use line as interrupt configure it in input mode.
	//Configuring  PC5 as INPUT
	    GPIOC->MODER  &= ~(1<<26) ;
	    GPIOC->MODER &= ~(1<<27);
	
	//Configure EXTI Line
			RCC->APB2ENR 			|= 0x00004000;
			SYSCFG->EXTICR[3]	 = 0x00000020;
  
	 
			 EXTI->FTSR |= (1<<13);			//Falling Edge
       EXTI->IMR  |= (1<<13);      //Unmask PC13 -set 1
	    
	     NVIC_SetPriority(EXTI15_10_IRQn,0);
	     NVIC_EnableIRQ( EXTI15_10_IRQn);
      
      while(1);
			
}


