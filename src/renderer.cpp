#include "renderer.h"

Renderer::Renderer(){
	this->width  = 800;
	this->height = 800;
	this->title = "Renderer";
	this->timer = Timer();
	m_image = GenImageColor(this->width, this->height, BLACK);
	init();
}

Renderer::Renderer(int width, int height, std::string title){
	this->width  = width;
	this->height = height; 
	this->title  = title;
	m_image = GenImageColor(this->width, this->height, BLACK);
	init();
}

void Renderer::init(){
	SetConfigFlags(FLAG_WINDOW_RESIZABLE);
	InitWindow(this->width, this->height, this->title.c_str());
	SetWindowMinSize(250,250);
}

void Renderer::onResize(){
	Timer timer;
	this->width  = GetScreenWidth();
	this->height = GetScreenHeight();			
	ImageResizeNN(&this->m_image, this->width, this->height);
	for(int w = 0; w < this->width; w++){
		for(int h = 0; h < this->height; h++){
			ImageDrawPixel(&this->m_image, w, h, this->perPixel(w, h));
		}
	}

	UnloadTexture(this->m_render);
	this->m_render = LoadTextureFromImage(this->m_image);
}

void Renderer::render(){
	BeginDrawing();
	ClearBackground(BLACK);
	DrawTexture(this->m_render, 0, 0, WHITE);

	const int fontSize = 20;
	const int padding  = 10;
	const float timeElapsed = this->timer.getDurationElapsed();
	const std::string txt = ("TIME: " + std::to_string(timeElapsed) + "ms");
	const int textSize = MeasureText(txt.c_str(), fontSize);
	DrawText(txt.c_str(), width - textSize - padding, padding, fontSize, WHITE);

	EndDrawing();
}

Color Renderer::perPixel(int w, int h){
	return PINK;
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
