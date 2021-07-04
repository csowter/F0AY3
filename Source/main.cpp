#include "stm32f0xx.h"
/*
d0 - pb2
d1 - pb3
d2 - pb4
d3 - pb5
d4 - pb6
d5 - pb7
d6 - pb8
d7 - pb9

bc1 - pc3
bdir - pc4
nReset - pc10
clk - pa1 - tim2 ch 2

*/

int main()
{
	RCC->AHBENR |= RCC_AHBENR_GPIOAEN | 
				   RCC_AHBENR_GPIOBEN |
				   RCC_AHBENR_GPIOCEN;
	
	RCC->APB1ENR |= RCC_APB1ENR_TIM2EN;
	
	asm("dsb");
	
	//put ay3 in reset
	GPIOC->BRR = 1 << 10;
	GPIOC->MODER = (1 << GPIO_MODER_MODER10_Pos);
	
	//set BC1 and BDIR to 0, to make bus high z
	GPIOC->BRR = (1 << 3) | (1 << 4);
	GPIOC->MODER |= ((1 << GPIO_MODER_MODER3_Pos) | ( 1 << GPIO_MODER_MODER4_Pos));
	
	TIM2->CCMR1 = 3 << TIM_CCMR1_OC2M_Pos; //set to toggle
	TIM2->CCR2 = 15;
	TIM2->ARR = 15;
	TIM2->CCER = TIM_CCER_CC2E;
	TIM2->CR1 = TIM_CR1_CEN; //switch on
	
	GPIOA->MODER |= (2 << GPIO_MODER_MODER1_Pos); //clock out pin af
	GPIOA->AFR[0] |= (2 << GPIO_AFRL_AFRL1_Pos); //make pin af
	
	while(1);
}
