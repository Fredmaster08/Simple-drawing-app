
#ifndef DRAW_H
#define DRAW_H

#include "raylib.h"
#include <stdio.h>

typedef struct Brush {
    Vector2 position;
    Color color;
}Brush;

void draw(Brush* brushes, int* index, Camera2D* camera);
void erase(Brush* brushes, int* index, Camera2D* camera);
void wheel(Camera2D* camera);
Color selectBrushColor();

#endif