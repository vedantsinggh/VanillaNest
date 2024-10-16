#include "raylib.h"
#include <string>
#include <iostream>
#include "utils.h"

#define WIDTH  500
#define HEIGHT 500

int main(void)
{
	SetConfigFlags(FLAG_WINDOW_RESIZABLE);
    InitWindow(WIDTH, HEIGHT, "Chase");
	SetWindowMinSize(250,250);
	Texture2D target;
	bool firstRun = true;
	int height = HEIGHT, width = WIDTH;
	float timeElapsed = 0;

    while (!WindowShouldClose())
    {
		if(IsWindowResized() || firstRun){
			firstRun = false;
			Timer timer;
			width  = GetScreenWidth();
			height = GetScreenHeight();			

			UnloadTexture(target);
			Image image = GenImageColor(width, height, WHITE);

			{
				for(int w = 0; w < width; ++w){
					for(int h = 0; h < height; ++h){
						int r = w/(float)width * 255;
						int g = (float)h/height * 255;
						ImageDrawPixel(&image, w, h,
								(Color){r, g, 0, 255}); 
					}
				}
			}

			target = LoadTextureFromImage(image);
			timeElapsed = timer.GetDurationElapsed();
		}

        BeginDrawing();
		{
            ClearBackground(BLACK);
			DrawTexture(target,0,0, WHITE);
			std::string txt = ("TIME: " + std::to_string(timeElapsed) + "ms");
			int size = MeasureText(txt.c_str(), 20);
			DrawText(txt.c_str(), width - size - 10, 10, 20, WHITE);
		}
        EndDrawing();

    }

	UnloadTexture(target);
    CloseWindow();
    return 0;
}
