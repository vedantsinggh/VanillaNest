#include "utils.h"
#include <cmath>

float Utils::clamp(float x, float a, float b){
	if (x < a) return a;
	if (x > b) return b;
	return x;
}

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

Vec3::Vec3(float a, float b, float c) {
    this->x = a;
    this->y = b;
    this->z = c;
}

float Vec3::dot(const Vec3& b) const {
    return this->x * b.x + this->y * b.y + this->z * b.z;
}

float Vec3::mag() const {
    return sqrt(x * x + y * y + z * z);
}

Vec3 Vec3::normalize() const {
    float magnitude = mag();
    if (magnitude == 0) {
        return Vec3(0.0f, 0.0f, 0.0f); 
    }
    return Vec3(x / magnitude, y / magnitude, z / magnitude);
}

Vec3 Vec3::add(const Vec3& b) const {
    return Vec3(this->x + b.x, this->y + b.y, this->z + b.z);
}

Vec3 Vec3::subtract(const Vec3& b) const {
    return Vec3(this->x - b.x, this->y - b.y, this->z - b.z);
}

Vec3 Vec3::scale(float scalar) const {
    return Vec3(this->x * scalar, this->y * scalar, this->z * scalar);
}

Vec3 Vec3::cross(const Vec3& b) const {
    return Vec3(
        this->y * b.z - this->z * b.y,  
        this->z * b.x - this->x * b.z,  
        this->x * b.y - this->y * b.x  
    );
}

Vec3 Vec3::operator+(const Vec3& b) const {
    return Vec3(this->x + b.x, this->y + b.y, this->z + b.z);
}

Vec3 Vec3::operator-(const Vec3& b) const {
    return Vec3(this->x - b.x, this->y - b.y, this->z - b.z);
}

Vec3 Vec3::operator*(float scalar) const {
    return Vec3(this->x * scalar, this->y * scalar, this->z * scalar);
}

bool Vec3::operator==(const Vec3& b) const {
    return (this->x == b.x && this->y == b.y && this->z == b.z);
}

bool Vec3::operator!=(const Vec3& b) const {
    return !(*this == b);  // Using the equality operator to simplify
}
