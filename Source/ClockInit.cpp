#include "stm32f0xx.h"
/*
clock source is internal 48MHz
AHBPrescaler = 1 
				HCLK out = 48MHz
APBPrescaler = 1
				APBCLK out = 48MHz

*/

extern "C" void InitialiseCoreClock()
{	
	RCC->CR2 |= RCC_CR2_HSI48ON;				//turn 48MHz oscillator on 
	
	FLASH->ACR = FLASH_ACR_PRFTBE |  			//ENABLE prefetch buffer
			     (1 << FLASH_ACR_LATENCY_Pos);  //one wait state
	
	while(!(RCC->CR2 & RCC_CR2_HSI48RDY));			//wait for hsi48 to stabilise
	
	RCC->CFGR |= RCC_CFGR_SW_HSI48;				//switch to hsi48 for system clock
	while(!(RCC->CFGR & RCC_CFGR_SWS_HSI48));		//wait for switch
	
	RCC->CR &= ~RCC_CR_HSION; //switch off internal 8MHz
}
