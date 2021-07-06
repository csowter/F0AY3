#include "AY3IO.h"
#include "stm32f0xx.h"

namespace 
{
void SetDataPinsOut()
{
	GPIOB->MODER |= (0x1 << GPIO_MODER_MODER2_Pos) |
				(0x1 << GPIO_MODER_MODER3_Pos) |
				(0x1 << GPIO_MODER_MODER4_Pos) |
				(0x1 << GPIO_MODER_MODER5_Pos) |
				(0x1 << GPIO_MODER_MODER6_Pos) |
				(0x1 << GPIO_MODER_MODER7_Pos) |
				(0x1 << GPIO_MODER_MODER8_Pos) |
				(0x1 << GPIO_MODER_MODER9_Pos);
}

void SetDataPinsIn()
{
	GPIOB->MODER &= ~(GPIO_MODER_MODER2_Msk | 
					  GPIO_MODER_MODER3_Msk | 
					  GPIO_MODER_MODER4_Msk | 
					  GPIO_MODER_MODER5_Msk | 
					  GPIO_MODER_MODER6_Msk | 
					  GPIO_MODER_MODER7_Msk | 
					  GPIO_MODER_MODER8_Msk | 
					  GPIO_MODER_MODER9_Msk);
}
}

void AY3IO::WriteData(uint8_t data)
{
	
	// set port b2-b9 to have data
	uint16_t lowWord = data << 2;
	uint32_t highWord = ~data;
	highWord &= 0x3FC;
	GPIOB->BSRR = (highWord << 16) | lowWord;
	
	SetDataPinsOut();
	
	//bdir = 1, bc1 = 0 - write data
	//bc1 - pc3
	//bdir - pc4
	
	GPIOC->BSRR = (0x1 << 4) | (0x1 << 19);
	
	uint32_t startCount = TIM2->CNT;
	while(TIM2->CNT < (startCount + 100)); //wait 10 uS
	
	GPIOC->BRR = (0x1 << 4) | (0x1 << 3); //clear bdir and bc1
	SetDataPinsIn(); //make bus high z
}
	
uint8_t AY3IO::ReadData()
{
	return 0;
}
		
void AY3IO::WriteAddress(uint8_t address)
{
// set port b2-b9 to have address
	uint16_t lowWord = address << 2;
	uint16_t highWord = ~address;
	highWord &= 0x3FC;
	GPIOB->BSRR = (highWord << 16) | lowWord;
	
	SetDataPinsOut();
	
	GPIOC->BSRR = (0x1 << 3) | (0x1 << 4);
	
	uint32_t startCount = TIM2->CNT;
	while(TIM2->CNT < (startCount + 100)); //wait 10 uS
	
	GPIOC->BRR = (0x1 << 4) | (0x1 << 3); //clear bdir and bc1
	SetDataPinsIn(); //make bus high z
}
