#pragma once
#include "includes.h"
class Timer
{
	sf::Clock m_clock;
	float m_time;
public:
	Timer();
	~Timer();
	bool Timing(int _sec);
};

