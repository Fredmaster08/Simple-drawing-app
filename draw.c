
#include "raylib.h"
#include "draw.h"

void draw(Brush* brushes, Color* color, int* index, Camera2D* camera) {
    Vector2 mousePos;
    if(IsMouseButtonDown(MOUSE_BUTTON_LEFT)) {
        int i = *index;
        brushes[i].position = mousePos;
        brushes[i].color = BLUE;
        (*index)++;
    }
}