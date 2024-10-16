#include "raylib.h"
#include "utils.h"

#define WIDTH  500
#define HEIGHT 500

int main(void)
{
	SetConfigFlags(FLAG_WINDOW_RESIZABLE);
    InitWindow(WIDTH, HEIGHT, "Chase");
	SetWindowMinSize(500,500);
	SetTargetFPS(60);
	int counter = 0;


    while (!WindowShouldClose())
    {
		Timer timer;
		int width  = GetScreenWidth();
		int height = GetScreenHeight();
		Image image = GenImageColor(std::max(0.7 * width, 350.0), height, PINK);
		Texture2D target = LoadTextureFromImage(image);

		if(IsWindowResized()){
			TraceLog(LOG_INFO, " Re-sized counter: %i", counter);
			counter++;
		}
        BeginDrawing();
            ClearBackground(RAYWHITE);
			SetWindowTitle("New title!");

 			DrawRectangle(std::max(.7 * width, 150.0), 0, 0.31 * width, height, DARKGREEN);
			DrawTexture(target,0,0, WHITE);
        EndDrawing();
		float timeElapsed = timer.GetDurationElapsed();
		float FPS = 1000.0f/timeElapsed;
		TraceLog(LOG_INFO, "FPS: %f", FPS);
    }

    CloseWindow();
    return 0;
}
