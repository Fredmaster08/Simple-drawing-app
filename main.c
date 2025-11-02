
#include <stdio.h>
#include "raylib.h"
#include <stdlib.h>
#include "draw.h"

int main() {

    int windowWidth = 1200;
    int windowHeight = 800;
    int drawWidth = 950;
    int drawHeight = 800;
    int guiWidth = 250;
    int guiHeight = 800;

    InitWindow(windowWidth, windowHeight, "Fredmaster08 & arina1431");

    SetTargetFPS(60);

    Brush brushes[10000];
    int index = 0;

    int sizeBrush = 25;
    Color strokeColor = {
        .r = 255,
        .a = 255,
    };

    Color backgroundColor = {
        .a = 255,
    };

    while(!WindowShouldClose()) {
        
        BeginDrawing();
        
        ClearBackground(BLACK);

        DrawRectangle(0, 0, drawWidth, drawHeight, backgroundColor);

        // Centered Text
        int textWidth = MeasureText("Simple Drawing App", 20);
        DrawText("Simple Drawing App",(drawWidth / 2) - textWidth / 2, drawHeight / 2 - 10, 20, LIGHTGRAY);

        updateBrushes(brushes, &index, &sizeBrush, strokeColor);

        for(int i = 0; i <= index; i++) {
            Brush brush = brushes[i];
            if (brush.isRectangle) {
                DrawRectangle(brush.position.x - 0.5 * brush.size, brush.position.y - 0.5 * brush.size, brush.size, brush.size, brush.color);
            }
            else {
                DrawCircle(brush.position.x, brush.position.y, brush.size, brush.color);
            }
        }

        drawGui(drawWidth, guiWidth, guiHeight, &strokeColor, &backgroundColor, brushes, &index);

        EndDrawing();
    }
    CloseWindow();

    return 0;
}
