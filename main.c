
#include "raylib.h"
#include "draw.h"
#include "raymath.h"
#include <stdio.h>

int main() {

    const int screenW = 1000;
    const int screenH = 800;

    InitWindow(screenW, screenH, "drawing window");
    SetTargetFPS(60);

    Brush brushes[10000];
    Camera2D camera = {0};
    Camera2D zoom = {0};
    camera.zoom = 1.0f;

    int index = 0;
    int sizeBrush;
    int r, g, b;

    printf("Sizebrush?: ");
    scanf("%d", &sizeBrush);
    printf("Enter R G B values:\n");
    
    printf("R: ");
    scanf("%d", &r);

    printf("G: ");
    scanf("%d", &g);

    printf("B: ");
    scanf("%d", &b);

    r = Clamp(r, 0, 255);
    g = Clamp(g, 0, 255);
    b = Clamp(b, 0, 255);

    Color brushColor = {r, g, b, 255};
 
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