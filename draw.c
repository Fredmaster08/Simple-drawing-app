
#include "raylib.h"
#include "draw.h"
#include "raymath.h"


void draw(Brush* brushes, int* index, Camera2D* camera) {
    Vector2 mousePos = GetScreenToWorld2D(GetMousePosition(), *camera);
    int brushSize = 20;
    if(IsMouseButtonDown(MOUSE_BUTTON_LEFT)) {
        int i = *index;
        brushes[i].position = mousePos;
        brushes[i].color = BLUE;
        (*index)++;
        for(int i = 0; i <= *index; i++) {
            DrawCircle(brushes[i].position.x, brushes[i].position.y, brushSize, brushes[i].color);
        }
    }
}

void erase(){

}