#pragma once
#include <chrono>

namespace Utils {
	float clamp(float, float, float);
}
struct Timer
{
	std::chrono::time_point<std::chrono::high_resolution_clock> start, end;
	std::chrono::duration<float> duration;

	Timer();
	float getDurationElapsed(); // returns time elapsed in mili-second 
	void resetTimer();
	~Timer();
};

class Vec3 {
public:
    float x, y, z;
    Vec3(float a, float b, float c);
    float dot(const Vec3& b) const;
    float mag() const;
    Vec3 normalize() const;
    Vec3 add(const Vec3& b) const;
    Vec3 subtract(const Vec3& b) const;
    Vec3 scale(float scalar) const;
    Vec3 cross(const Vec3& b) const;
    Vec3 operator+(const Vec3& b) const;
    Vec3 operator-(const Vec3& b) const;  
    Vec3 operator*(float scalar) const;   
    bool operator==(const Vec3& b) const; 
    bool operator!=(const Vec3& b) const; 
};
