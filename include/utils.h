#pragma once
#include <chrono>

struct Timer
{
	std::chrono::time_point<std::chrono::high_resolution_clock> start, end;
	std::chrono::duration<float> duration;

	Timer();
	float getDurationElapsed(); // returns time elapsed in mili-second 
	void resetTimer();
	~Timer();
};
