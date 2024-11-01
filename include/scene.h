#pragma once
#include "utils.h"
#include "raylib.h"
#include <vector>

namespace chase {
	class Sphere {
		public:
			Sphere(float x, float y, float z, float r);
			Vec3 position;
			float radius;
			Color color;
	};
}

namespace chase {
	class Scene {
		public:
			std::vector<Sphere> spheres;
	};
}
