#include "Vanilla/renderer.h"
#include "Vanilla/scene.h"

using namespace Nest;

int main(void)
{
	Scene scene;
	scene.spheres.push_back( Sphere {0.0f, 0.0f, 0.0f, 1.0f} );
	scene.spheres[0].color = GREEN;
	scene.spheres.push_back( Sphere {0.0f, 0.0f, -1.0f, 0.3f} );
	scene.spheres[1].color = BEIGE;
	Renderer renderer(900,900, "Chase", scene);

	while(renderer.isRunning()){
		renderer.reframe();
		renderer.render();
	}

    return 0;
}
