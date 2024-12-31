#include <stdio.h>
#include "raylib/include/raylib.h"

#define SNOWFLAKES_QTY 200

int main(void)
{
    SetRandomSeed(123);
    InitWindow(800, 450, "2024 Snowflakes");

    // Prepare background
    Image background = LoadImage("background.jpg");
    ImageResize(&background, 800, 450);
    ImageColorBrightness(&background, -50);
    ImageBlurGaussian(&background, 2);
    Texture2D texture = LoadTextureFromImage(background);

    // Prepare snowflakes
    int snowflakes[3 * SNOWFLAKES_QTY]; // { x1, y1, r1, x2, y2, r2, ... }
    for (int idx = 0; idx < 3 * SNOWFLAKES_QTY; idx += 3)
    {
        snowflakes[idx] = GetRandomValue(0, 800);
        snowflakes[idx + 1] = GetRandomValue(0, 450);
        snowflakes[idx + 2] = GetRandomValue(1, 5);
    }

    char frame = 1;

    SetTargetFPS(30);

    while (!WindowShouldClose())
    {
        BeginDrawing();

        for (int idx = 0; idx < 3 * SNOWFLAKES_QTY; idx += 3)
        {
            if (frame == 0)
            {
                snowflakes[idx] = snowflakes[idx] + GetRandomValue(-1, 1);
                if (snowflakes[idx] >= 800)
                {
                    snowflakes[idx] -= 800;
                }
            }
            snowflakes[idx + 1] = snowflakes[idx + 1] + 2;
            if (snowflakes[idx + 1] >= 450)
            {
                snowflakes[idx + 1] -= 450;
            }
        }
        frame++;
        frame = frame % 4;

        ClearBackground(RAYWHITE);
        DrawTexture(texture, 0, 0, WHITE);
        for (int idx = 0; idx < 3 * SNOWFLAKES_QTY; idx += 3)
        {
            DrawCircle(snowflakes[idx], snowflakes[idx + 1], snowflakes[idx + 2], LIGHTGRAY);
        }
        // DrawText("Happy New Year!", 190, 200, 32, LIGHTGRAY);
        EndDrawing();
    }

    UnloadTexture(texture);
    UnloadImage(background);
    CloseWindow();

    return 0;
}