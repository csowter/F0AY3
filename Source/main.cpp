#include "stm32f0xx.h"
#include "AY3IO.h"
#include "AY3.h"

#include "DebugUART.h"
#include "STMTimer.h"

#include "F0AY3Descriptors.h"
#include "USB.h"

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

PA2 debug uart2 tx

*/

int main()
{
	RCC->AHBENR |= RCC_AHBENR_GPIOAEN | 
				   RCC_AHBENR_GPIOBEN |
				   RCC_AHBENR_GPIOCEN;
				   
	
	RCC->APB1ENR |= RCC_APB1ENR_TIM2EN |
					RCC_APB1ENR_TIM3EN |
					RCC_APB1ENR_USART2EN |
					RCC_APB1ENR_USBEN;
		
	asm("dsb");
	
	//put ay3 in reset
	GPIOC->BRR = 1 << 10;
	GPIOC->MODER = (1 << GPIO_MODER_MODER10_Pos);
	
	//set BC1 and BDIR to 0, to make bus high z
	GPIOC->BRR = (1 << 3) | (1 << 4);
	GPIOC->MODER |= ((1 << GPIO_MODER_MODER3_Pos) | ( 1 << GPIO_MODER_MODER4_Pos));
	
	//pc6 afio for clock
	GPIOC->MODER |= (2 << GPIO_MODER_MODER6_Pos);
	
	STMTimer microSecondTimer(TIM2, 47, 0xFFFFFFFF);
	
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
	AY3 ay3(&ay3IO);
	
	ay3.EnableTone(true, 0);
	ay3.SetAmplitude(0xc, 0);
	ay3.EnableEnvelope(true, 0);

	ay3.EnableNoise(true, 1);
	ay3.SetAmplitude(0x5, 1);
	ay3.EnableEnvelope(true, 1);

	ay3.SetEnvelopePeriod(0xc00);
	ay3.SetEnvelopeMode(0xE);
	ay3.SetTonePeriod(0x80, 0);
	ay3.SetNoisePeriod(0x10);
	
	GPIOA->MODER |= (2 << GPIO_MODER_MODER2_Pos);
	GPIOA->AFR[0] |= (1 << GPIO_AFRL_AFRL2_Pos);
	DebugUART uart(USART2, 48000000, 115200);
	
	GPIOA->MODER |= (3 << GPIO_MODER_MODER11_Pos) | (3 << GPIO_MODER_MODER12_Pos);  //GPIOA 11 & 12 analogue for USB
	
	uart.DebugTx((uint8_t *)"config", 6);
	uart.DebugTx((uint8_t *)&AY3Descriptors::ConfigurationDescriptor, sizeof(AY3Descriptors::ConfigurationDescriptor));
	uart.DebugTx((uint8_t *)"device", 6);
	uart.DebugTx((uint8_t *)&AY3Descriptors::DeviceDescriptor, sizeof(AY3Descriptors::DeviceDescriptor));
	
	USBDevice usb(USB, &microSecondTimer);
	usb.HardwareInit();
	
	while(1)
	{

	}
}
