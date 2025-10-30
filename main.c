
#include <stdio.h>
#include "raylib.h"

int main() {

    int screenwidth = 800;
    int screenHeight = 450;

    InitWindow(screenwidth, screenHeight, "Fredmaster08 & arina1431");

    SetTargetFPS(60);

    while(!WindowShouldClose()) {
        
        BeginDrawing();

        ClearBackground(RAYWHITE);
        DrawText("Jo wsp!", 190, 200, 20, LIGHTGRAY);

        EndDrawing();
    }
    CloseWindow();

    return 0;
}
