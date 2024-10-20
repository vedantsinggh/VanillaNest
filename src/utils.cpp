#include "utils.h"

Timer::Timer(){	
	start = std::chrono::high_resolution_clock::now();
}

float Timer::getDurationElapsed(){
	end = std::chrono::high_resolution_clock::now();
	duration = end - start;
	return (duration.count() * 1000.0f);
}

void Timer::resetTimer(){
	start = std::chrono::high_resolution_clock::now();
}

Timer::~Timer(){	
}
