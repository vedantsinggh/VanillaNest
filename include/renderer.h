#pragma once
#include <string>
#include "raylib.h"
#include "utils.h"

class Renderer{
public:
	int width, height;
	std::string title;
private:
	//TODO int m_aspectRatio;
	Texture2D m_render;
	Image m_image;
	Timer timer;

public:
	Renderer();
	Renderer(int width, int height, std::string title);
	void onResize();
	void render();
	bool isRunning();
	bool isResized();
	Color perPixel(int w, int h);
	~Renderer();
private:
	void init();
};
