#include <string>
#include <iostream>

#include "renderer.h"

using namespace chase;

int main(void)
{
	Renderer renderer(900,900, "Chase");
	renderer.onResize();

	while(renderer.isRunning()){
		//if (renderer.isResized())
			renderer.onResize();
		renderer.render();
	}

    return 0;
}
