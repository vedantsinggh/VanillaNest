#pragma once
#include "utils.h"

namespace chase {
    class Camera {
    public:
        Vec3 position;
        Camera();
        Camera(float x, float y, float z);
    };
}
