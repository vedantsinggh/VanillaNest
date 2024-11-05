#include "Vanilla/camera.h" 

using namespace Nest;

Camera::Camera(){}

Camera::Camera(float x, float y, float z){
	position.x = x;
	position.y = y;
	position.z = z;
}
