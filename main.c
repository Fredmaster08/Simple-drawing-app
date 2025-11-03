
#include <stdio.h>
#include "raylib.h"
#include <stdlib.h>
#include "draw.h"

int main() {

    int screenwidth = 800;
    int screenHeight = 450;

    InitWindow(screenwidth, screenHeight, "Fredmaster08 & arina1431");

    SetTargetFPS(60);

    Brush brushes[10000];
    int index = 0;
    
    Camera2D camera = {0};
    camera.zoom = 1.0f;

    while(!WindowShouldClose()) {
        
        BeginDrawing();
        
        ClearBackground(BLACK);

        BeginMode2D(camera);
        int textWidth = MeasureText("Simple Drawing App", 20);
        DrawText("Simple Drawing App",(screenwidth / 2) - textWidth / 2, screenHeight / 2 - 10, 20, LIGHTGRAY);
        draw(brushes, &index, &camera);

        int size_brush = 25;

        for(int i = 0; i <= index; i++) {
        
            //DrawRectangle(brushes[i].position.x - 0.5 * size_brush, brushes[i].position.y - 0.5 * size_brush, size_brush, size_brush, brushes[i].color);
            DrawCircle(brushes[i].position.x, brushes[i].position.y, size_brush, brushes[i].color);
        }

        EndMode2D();
        EndDrawing();
    }
    CloseWindow();

    return 0;
}
