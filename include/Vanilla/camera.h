#pragma once
#include "Vanilla/utils.h"

namespace Nest {
    class Camera {
    public:
        Vec3 position;
        Camera();
        Camera(float x, float y, float z);
    };
}
