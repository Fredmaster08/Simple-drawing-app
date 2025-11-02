
#include <stdio.h>
#include "raylib.h"
#include <stdlib.h>

void draw(Vector2* positions, int* index);

int main() {

    int screenwidth = 800;
    int screenHeight = 450;

    InitWindow(screenwidth, screenHeight, "Fredmaster08 & arina1431");

    SetTargetFPS(60);

    Vector2 positions[10000];
    int index = 0;

    while(!WindowShouldClose()) {
        
        BeginDrawing();
        
        ClearBackground(BLACK);
        int textWidth = MeasureText("Simple Drawing App", 20);
        DrawText("Simple Drawing App",(screenwidth / 2) - textWidth / 2, screenHeight / 2 - 10, 20, LIGHTGRAY);
        draw(positions, &index);

        int size_brush = 25;

        for(int i = 0; i <= index; i++) {
            Color color;
            color.a = 255;
            
            color.r = rand() % 256;
            color.g = rand() % 256;
            color.b = rand() % 256;

            DrawRectangle(positions[i].x - 0.5 * size_brush, positions[i].y - 0.5 * size_brush, size_brush, size_brush, color);
        }

        EndDrawing();
    }
    CloseWindow();

    return 0;
}
