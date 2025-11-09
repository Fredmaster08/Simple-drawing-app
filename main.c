
#include <stdio.h>
<<<<<<< HEAD
=======
#include "raylib.h"
#include "draw.h"
>>>>>>> main2

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