#include "STMTimer.h"

STMTimer::STMTimer(TIM_TypeDef *timer, uint32_t prescaler, uint32_t reload)
: mTimer(timer)
{
	mTimer->ARR = reload;
	mTimer->PSC = prescaler;	
	mTimer->EGR = TIM_EGR_UG; //generate an update
	
	mTimer->CR1 = TIM_CR1_CEN; //enable
}
	
uint32_t STMTimer::GetTicks()
{
	return mTimer->CNT;
}

uint32_t STMTimer::TicksToMs(uint32_t ticks)
{
	return ticks / 1000;
}
	
uint32_t STMTimer::MsToTicks(uint32_t ms)
{
	return ms * 1000;
}
	
uint32_t STMTimer::TicksToUs(uint32_t ticks)
{
	return ticks;
}
	
uint32_t STMTimer::UsToTicks(uint32_t us)
{
	return us;
}
