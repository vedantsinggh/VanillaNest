#pragma once
#include <string>
#include "raylib.h"
#include "Vanilla/utils.h"
#include "Vanilla/camera.h"
#include <thread>
#include "Vanilla/scene.h"

namespace Nest {

	class Renderer{
	public:
		int width, height;
		std::string title;
		int inverseResolutionScale = 1;
		Camera mainCamera;
		Scene scene;
	private:
		const float m_aspectRatio = 16.0f/9.0f; //TODO
		Texture2D m_render;
		Timer timer;
		float time;
		Image m_image;

	public:
		Renderer();
		Renderer(int width, int height, std::string title, Scene scene);
		void reframe();
		void render();
		bool isRunning();
		bool isResized();
		Color perPixel(int w, int h, float time);
		~Renderer();
	private:
		void init();
	};

}
