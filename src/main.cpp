#include <string>
#include <iostream>

#include "renderer.h"

int main(void)
{
	Renderer renderer(500,500, "Chase");
	renderer.onResize();

	while(renderer.isRunning()){
		if (renderer.isResized())
			renderer.onResize();
		renderer.render();
	}

    return 0;
}
