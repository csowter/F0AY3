#ifndef timer_h
#define timer_h
#include <stdint.h>

class Timer
{
public:
	virtual ~Timer(){}
	virtual uint32_t GetTicks() = 0;
	virtual uint32_t TicksToMs(uint32_t ticks) = 0;
	virtual uint32_t MsToTicks(uint32_t ms) = 0;
	virtual uint32_t TicksToUs(uint32_t ticks) = 0;
	virtual uint32_t UsToTicks(uint32_t us) = 0;
};
#endif
