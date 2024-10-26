#pragma once
#include "utils.h"

namespace chase {
    class Camera {
    public:
        Vec3 position;
        Vec3 rotation; // Rotation angles in radians

        Camera();
        Camera(float x, float y, float z);

        void move(const Vec3& offset);
        void rotate(float pitch, float yaw, float roll);
        Vec3 getForward() const;
        Vec3 getRight() const;
        Vec3 getUp() const;
    };
}
