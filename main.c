
#include <stdio.h>
#include "raylib.h"
#include "draw.h"

int main() {

    const int screenW = 1000;
    const int screenH = 800;

    InitWindow(screenW, screenH, "drawing window");

    SetTargetFPS(60);

    Brush brushes[10000];
    Camera2D camera = {0};
    Vector2 mousePos;
    Color color;

    int index = 0;

    while (!WindowShouldClose()){
        
        BeginDrawing();

        draw(brushes, &color, &index, &camera);

        ClearBackground(BLACK);

        EndDrawing();
    }
    
    
    CloseWindow();

    return 0;
}