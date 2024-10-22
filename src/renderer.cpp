#include "renderer.h"
#include <iostream>
#include <cmath>
#include <thread>
#include <vector>

Renderer::Renderer(){
	this->width  = 800;
	this->height = 800;
	this->title = "Renderer";
	this->time = 0.0f;
	this->timer = Timer();
	m_image = GenImageColor(this->width, this->height, BLACK);
	init();
}

Renderer::Renderer(int width, int height, std::string title){
	this->width  = width;
	this->height = height; 
	this->title  = title;
	this->time = 0.0f;
	m_image = GenImageColor(this->width, this->height, BLACK);
	init();
}

void Renderer::init(){
	SetConfigFlags(FLAG_WINDOW_RESIZABLE);
	InitWindow(this->width, this->height, this->title.c_str());
	SetWindowMinSize(250,250);
	this->m_render = LoadTextureFromImage(this->m_image);
}

void Renderer::onResize() {
    this->timer.resetTimer();
    this->width  = GetScreenWidth();
    this->height = GetScreenHeight();

    ImageResizeNN(&this->m_image, this->width, this->height);

    const int numThreads = 10;
    std::vector<std::thread> threads;
    float time = GetTime();

    auto renderTask = [&](int start, int end) {
        for (int w = start; w < end; ++w) {
            for (int h = 0; h < this->height; ++h) {
				Color existingColor = GetImageColor(this->m_image, w, h);
                Color color = this->perPixel(w, h, time);
				if (color.r == existingColor.r && color.g == existingColor.g &&
                color.b == existingColor.b) continue;
				ImageDrawPixel(&this->m_image, w, h, color);
            }
        }
    };

    int workPerThread = this->width / numThreads;
    for (int i = 0; i < numThreads; ++i) {
        int start = i * workPerThread;
        int end = (i == numThreads - 1) ? this->width : start + workPerThread;
        threads.push_back(std::thread(renderTask, start, end));
    }

    for (auto& t : threads) {
        t.join();
    }

	UnloadTexture(this->m_render);
	this->m_render = LoadTextureFromImage(this->m_image);
    this->time = this->timer.getDurationElapsed();
}
void Renderer::render(){

	const int fontSize = 20;
	const int padding  = 10;
	const std::string txt = ("TIME: " + std::to_string(this->time) + "ms");
	const int textSize = MeasureText(txt.c_str(), fontSize);

	BeginDrawing();
	{
		ClearBackground(BLACK);
		DrawTexture(this->m_render, 0, 0, WHITE);
		DrawText(txt.c_str(), width - textSize - padding, padding, fontSize, WHITE);
	}
	EndDrawing();
}

Color Renderer::perPixel(int w, int h, float time) {
    
    float radius = 0.5;
    const float x = (float)w * 2/width  - 1;
    const float y = (float)h * -2/height + 1;
	const Vec3 spherecenter(0.0f, 0.0f, 0.0f);

    Vec3 dir(x, y, 1.0f);
    Vec3 cameraposition(0.0f,0.0f,-2.0f); 
	Vec3 lightdirection(sinf(time), 0.0f, cosf(time));

    float a = dir.dot(dir); 
    float b = 2.0f * dir.dot(cameraposition - spherecenter);
    float c = (cameraposition - spherecenter).dot(cameraposition - spherecenter) - radius * radius;
    float discriminant = b * b - 4 * a * c;


    if (discriminant >= 0) {
		float hitnear = (-b - sqrt(discriminant)) / (2 * a);
		//float hitfar  = (-b + sqrt(discriminant)) / (2 * a);

		Vec3 hitpoint = cameraposition + dir * hitnear;

		float d = (hitpoint).dot(lightdirection);

		Color hitcolor = {static_cast<unsigned char>(Utils::clamp(d * 255, 0, 255)),
						  static_cast<unsigned char>(Utils::clamp(d * 255, 0, 255)),
						  static_cast<unsigned char>(Utils::clamp(d * 255, 0, 255)), 255};
        return hitcolor; 
    }

    return LIME;
}

bool Renderer::isRunning(){
	return !WindowShouldClose();
}

bool Renderer::isResized(){
	return IsWindowResized();
}

Renderer::~Renderer(){
	UnloadTexture(this->m_render);
	CloseWindow(); 
}
