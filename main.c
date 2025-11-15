
#include "raylib.h"
#include "draw.h"
#include "raymath.h"
#include <stdio.h>

int main() {

    const int screenW = 1000;
    const int screenH = 800;

    int sizeBrush;
    int r, g, b;
    Color brushColor = {r, g, b, 255};

    printf("Sizebrush: ");
    scanf("%d", &sizeBrush);

    selectBrushColor();

    InitWindow(screenW, screenH, "drawing window");
    SetTargetFPS(60);

    Brush brushes[10000];
    Camera2D camera = {0};
    Camera2D zoom = {0};
    camera.zoom = 1.0f;

    printf("Mattef");

    int index = 0;

    while (!WindowShouldClose()){
        
        BeginDrawing();
        BeginMode2D(camera);

        ClearBackground(BLACK);
        draw(brushes, &index, &camera);
        erase(brushes, &index, &camera);
        wheel(&camera);

        for(int i = 0; i <= index; i++) {
            DrawCircle(brushes[i].position.x, brushes[i].position.y, sizeBrush, brushColor);
        }
        EndMode2D();
        EndDrawing();
    }

    CloseWindow();

    return 0;
}