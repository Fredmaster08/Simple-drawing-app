
#ifndef DRAW_H
#define DRAW_H

#include "raylib.h"

#include <stdbool.h>

typedef struct Brush {
    Vector2 position;
    Color color;
    bool isRectangle;
    int size;
} Brush;

void updateBrushes(Brush* brushes, int* index, int* sizeBrush, Color color);
void clearScreen(Brush* brushes, int* index);
void drawGui(int guiOffset, int guiWidth, int guiHeight, Color* color, Color* bgColor, Brush* brushes, int* index);

#endif
