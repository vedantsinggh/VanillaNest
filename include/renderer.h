#pragma once
#include <string>
#include "raylib.h"
#include "utils.h"
#include "camera.h"
#include <iostream>
#include <cmath>
#include <thread>
#include <vector>

namespace chase {

	class Renderer{
	public:
		int width, height;
		std::string title;
		int inverseResolutionScale = 1;
		Camera mainCamera;
	private:
		const float m_aspectRatio = 16.0f/9.0f; //TODO
		Texture2D m_render;
		Timer timer;
		float time;
		Image m_image;

	public:
		Renderer();
		Renderer(int width, int height, std::string title);
		void onResize();
		void render();
		bool isRunning();
		bool isResized();
		Color perPixel(int w, int h, float time);
		~Renderer();
	private:
		void init();
	};

}
