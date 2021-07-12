#ifndef softtimer_h
#define softtimer_h

#include "Timer.h"

class SoftTimer
{
	Timer *m_Timer;
	uint32_t m_Durationms;
	uint32_t m_StartTicks;
	
public:
	SoftTimer(Timer *timer, uint32_t duration);
	bool Elapsed();
	void Restart();
};

#endif
