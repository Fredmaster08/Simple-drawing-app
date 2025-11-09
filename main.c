
#include <stdio.h>
#include <raylib.h>

int main() {

    //printf("Restart IS REAL!\n");

    const int screenW = 1000;
    const int screenH = 800;

    InitWindow(screenW, screenH, "drawing window");

    SetTargetFPS(60);


    while (!WindowShouldClose()){
        
        BeginDrawing();

            ClearBackground(RAYWHITE);

        EndDrawing();
    }
    
    
    CloseWindow();

    return 0;
}