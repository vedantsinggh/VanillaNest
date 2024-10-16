#include <chrono>
#include <iostream>

struct Timer
{
	std::chrono::time_point<std::chrono::high_resolution_clock> start, end;
	std::chrono::duration<float> duration;

	Timer();
	float GetDurationElapsed(); // returns time elapsed in mili-second 
	~Timer();
};
