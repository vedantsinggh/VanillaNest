#pragma once
#include <string>
#include "raylib.h"
#include "utils.h"

class Renderer{
public:
	int width, height;
	std::string title;
	int inverseResolutionScale = 1;
private:
	const float m_aspectRatio = 16.0f/9.0f;
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
