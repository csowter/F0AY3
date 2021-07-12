#include "SoftTimer.h"

SoftTimer::SoftTimer(Timer *timer, uint32_t durationms)
: m_Timer(timer)
, m_Durationms(durationms)
, m_StartTicks(timer->GetTicks())
{
}

bool SoftTimer::Elapsed()
{
	return (m_Timer->GetTicks() - m_StartTicks) > m_Timer->MsToTicks(m_Durationms);
}

void SoftTimer::Restart()
{
	m_StartTicks = m_Timer->GetTicks();
}
