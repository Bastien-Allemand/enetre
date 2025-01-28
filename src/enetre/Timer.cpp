#include "pch.h"
#include "Timer.h"

bool Timer::Timing(int _sec)
{
	if (m_time >= _sec)
	{
		return true;
		m_time = 0;
	}
	m_time += m_clock.getElapsedTime().asSeconds();
	return false;
}
