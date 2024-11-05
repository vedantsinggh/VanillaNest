#pragma once
#include "Vanilla/utils.h"
#include "raylib.h"
#include <vector>

namespace Nest {
	class Sphere {
		public:
			Sphere(float x, float y, float z, float r);
			Vec3 position;
			float radius;
			Color color;
	};
}

namespace Nest {
	class Scene {
		public:
			std::vector<Sphere> spheres;
	};
}
