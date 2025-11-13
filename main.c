
#include "raylib.h"
#include "draw.h"
#include "raymath.h"

int main() {

    const int screenW = 1000;
    const int screenH = 800;

    InitWindow(screenW, screenH, "drawing window");

    SetTargetFPS(60);

    Brush brushes[10000];
    Camera2D camera = {0};
 

    
    int index = 0;

    while (!WindowShouldClose()){
        
        BeginDrawing();
        BeginMode2D(camera);

        ClearBackground(BLACK);
        draw(brushes, &index, &camera);


        //for(int i = 0; i <= index; i++) {
        //    DrawCircle(brushes[i].position.x, brushes[i].position.y, 5, BLUE);
        //}


        EndMode2D();
        EndDrawing();
    }
    
    
    CloseWindow();

    return 0;
}