#ifndef stmtimer_h
#define stmtimer_h

#include "Timer.h"
#include "stm32f0xx.h"

class STMTimer : public Timer
{
	TIM_TypeDef *mTimer;
	
public:
	STMTimer(TIM_TypeDef *timer, uint32_t prescaler, uint32_t reload);
	virtual uint32_t GetTicks();
	virtual uint32_t TicksToMs(uint32_t ticks);
	virtual uint32_t MsToTicks(uint32_t ms);
	virtual uint32_t TicksToUs(uint32_t ticks);
	virtual uint32_t UsToTicks(uint32_t us);
};

#endif
