#include "renderer.h"
#include "scene.h"

using namespace chase;

int main(void)
{
	Scene scene;
	scene.spheres.push_back( Sphere {0.0f, 0.0f, -1.0f, 0.1f} );
	scene.spheres[0].color = RED;
	scene.spheres.push_back( Sphere {0.0f, 0.0f, 0.0f, 0.5f} );
	scene.spheres[1].color = BEIGE;
	Renderer renderer(900,900, "Chase", scene);

	while(renderer.isRunning()){
		renderer.reframe();
		renderer.render();
	}

    return 0;
}
