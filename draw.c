
#include "raylib.h"
#include "draw.h"

void draw(Brush* brushes, int* index) {
    if(IsMouseButtonDown(MOUSE_BUTTON_LEFT)) {
        brushes[*index].position = GetMousePosition();
        brushes[*index].color = RED;
        (*index)++;
    }
    if(IsMouseButtonDown(MOUSE_BUTTON_RIGHT)) {
        brushes[*index].position = GetMousePosition();
        brushes[*index].color = GREEN;
        (*index)++;
    }
}

