
#include "raylib.h"

void draw(Vector2* positions, int* index) {
    if(IsMouseButtonDown(MOUSE_BUTTON_LEFT)) {
        //DrawRectangle(GetMouseX(), GetMouseY(), 25, 25, WHITE);
        positions[*index] = GetMousePosition();
        (*index)++;
    }
}