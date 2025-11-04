
#ifndef DRAW_H
#define DRAW_H

#include "raylib.h"

#include <stdbool.h>
#include <stddef.h>

typedef struct Brush {
    Vector2 position;
    Color color;
    bool isRectangle;
    int size;
} Brush;

void updateBrushes(Brush* brushes, int* index, size_t* capacity, int* sizeBrush, Color color);
void clearScreen(Brush* brushes, size_t* capacity);
void drawGui(int guiOffset, int guiWidth, int guiHeight, Color* color, Color* bgColor, Brush* brushes, size_t* capacity);

#endif
