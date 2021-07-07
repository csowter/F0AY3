#include "stm32f0xx.h"
#include "AY3IO.h"
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
clk - pc6 - tim3 ch 1

*/

namespace{
void usDelay(uint32_t us)
{
	uint32_t now = TIM2->CNT;
	while(TIM2->CNT < (now + us));
}
}

int main()
{
	RCC->AHBENR |= RCC_AHBENR_GPIOAEN | 
				   RCC_AHBENR_GPIOBEN |
				   RCC_AHBENR_GPIOCEN;
	
	RCC->APB1ENR |= RCC_APB1ENR_TIM2EN |
					RCC_APB1ENR_TIM3EN;

	
	asm("dsb");
	
	//put ay3 in reset
	GPIOC->BRR = 1 << 10;
	GPIOC->MODER = (1 << GPIO_MODER_MODER10_Pos);
	
	//set BC1 and BDIR to 0, to make bus high z
	GPIOC->BRR = (1 << 3) | (1 << 4);
	GPIOC->MODER |= ((1 << GPIO_MODER_MODER3_Pos) | ( 1 << GPIO_MODER_MODER4_Pos));
	
	//pc6 afio for clock
	GPIOC->MODER |= (2 << GPIO_MODER_MODER6_Pos);
	
	TIM2->PSC = 47;
	TIM2->ARR = 0xFFFFFFFF;
	TIM2->EGR = TIM_EGR_UG; //generate an update event
	TIM2->CNT = 0;
	TIM2->CR1 = TIM_CR1_CEN; //switch on
	
	//tim 3 used for AY3 clock, 1.5 MHz
	TIM3->CCMR1 = 3 << TIM_CCMR1_OC1M_Pos; //set to toggle
	TIM3->CCR1 = 15;
	TIM3->ARR = 15;
	TIM3->CCER = TIM_CCER_CC1E;
	TIM3->CR1 = TIM_CR1_CEN; //switch on
	
	//take ay out of reset
	GPIOC->BSRR = 1 << 10;
	
	uint32_t now = TIM2->CNT;
	while(TIM2->CNT < (now + 500000)); //wait 0.5 s
	
	AY3IO ay3IO;
	
	ay3IO.WriteAddress(7); //register 7 - mixer
	usDelay(2);
	ay3IO.WriteData(0xF8); // turn on tone A & B
	usDelay(2);
	ay3IO.WriteAddress(8); //channel a amplitude
	usDelay(2);
	ay3IO.WriteData(0xF);
	usDelay(2);
	ay3IO.WriteAddress(9); //channel b amplitude
	usDelay(2);
	ay3IO.WriteData(0x0);
	usDelay(2);
	ay3IO.WriteAddress(10); //channel c amplitude
	usDelay(2);
	ay3IO.WriteData(0x0);
	usDelay(2);
	ay3IO.WriteAddress(0);
	usDelay(2);
	ay3IO.WriteData(0xff);
	usDelay(2);
	ay3IO.WriteAddress(1);
	usDelay(2);
	ay3IO.WriteData(0xf);
	usDelay(2);
	
	ay3IO.WriteAddress(2);
	usDelay(2);
	ay3IO.WriteData(0x55);
	usDelay(2);
	
	ay3IO.WriteAddress(4);
	usDelay(2);
	ay3IO.WriteData(0x33);
	usDelay(2);
	
	ay3IO.WriteAddress(0xE);
	while(1)
	{
		ay3IO.WriteData(0x01);
		uint32_t now = TIM2->CNT;
		while(TIM2->CNT < (now + 1000000));
		ay3IO.WriteData(0x0);
		now = TIM2->CNT;
		while(TIM2->CNT < (now + 500000));
	}
}
