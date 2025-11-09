
#ifndef DRAW_H
#define DRAW_H

#include "raylib.h"

typedef struct Brush {
    Vector2 position;
    Color color;
}Brush;

void draw(Brush* brushes, Color* color, int* index, Camera2D* camera);

#endif