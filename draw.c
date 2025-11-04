
#include "raylib.h"
#include "raymath.h"
#include "draw.h"

#define RAYGUI_IMPLEMENTATION
#include "raygui.h"

#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

static Vector2 currentMousePos = (Vector2){0};
static Vector2 previousMousePos = (Vector2){0};

void addBrush(Brush** brushes, int* index, size_t* capacity, Brush* brush) {
    Brush* dest = &(*brushes)[*index];
    memcpy(dest, brush, sizeof(Brush));

    (*index)++;

    if (*index >= *capacity) {
        *capacity *= 2;
        printf("Capacity: %zu\n", *capacity);
        Brush* tmp = realloc(*brushes, sizeof(Brush) * *capacity);
        if (!tmp) {
            fprintf(stderr, "Failed to realloc brushes array! Capacity: %zu\n", *capacity);
            return;
        }
        *brushes = tmp;
    }
}

void updateBrushes(Brush* brushes, int* index, size_t* capacity, int* sizeBrush, Color color) {
    previousMousePos = currentMousePos;
    currentMousePos = GetMousePosition();

    float mouseDist = Vector2Length(GetMouseDelta());
    int32_t lerpCount = 0;
    float lerp = 0.0f;

    if (mouseDist >= (*sizeBrush * 0.1)) {
        lerpCount = (mouseDist / *sizeBrush) * 2.0f;
        if (lerpCount > 1000) lerpCount = 1000;
    }

    if(IsMouseButtonDown(MOUSE_BUTTON_LEFT)) {
        Brush brush = {
            .position = GetMousePosition(),
            .color = color,
            .isRectangle = true,
            .size = *sizeBrush,
        };

        addBrush(&brushes, index, capacity, &brush);
        
        if (lerpCount != 0) {
            while (lerp != 1.0f) {
                brush.position = Vector2Lerp(previousMousePos, currentMousePos, lerp);
                brush.color = GREEN; // tmp
                addBrush(&brushes, index, capacity, &brush);
                lerp += 1.0f / lerpCount;
            }
        }
        
    }
    if(IsMouseButtonDown(MOUSE_BUTTON_RIGHT)) {
        Brush brush = {
            .position = GetMousePosition(),
            .color = color, 
            .isRectangle = false,
            .size = *sizeBrush,
        };

        addBrush(&brushes, index, capacity, &brush);

         if (lerpCount != 0) {
            while (lerp != 1.0f) {
                brush.position = Vector2Lerp(previousMousePos, currentMousePos, lerp);
                brush.color = GREEN; // tmp
                addBrush(&brushes, index, capacity, &brush);
                lerp += 1.0f / lerpCount;
            }
        }
    }

    *sizeBrush += GetMouseWheelMove();
}

void clearScreen(Brush *brushes, size_t* capacity) {
    memset(brushes, 0, sizeof(Brush) * *capacity);
}

void drawGui(int guiOffset, int guiWidth, int guiHeight, Color* color, Color* bgColor, Brush* brushes, size_t* capacity) {
    DrawRectangle(guiOffset, 0, guiWidth, guiHeight, DARKGRAY);

    int paddingX = 15;
    int paddingY = 15;
    int objectWidth = guiWidth - 2 * paddingX;
    int objectXBegin = guiOffset + paddingX;
    int currentY = paddingY;

    GuiColorPicker((Rectangle){objectXBegin, currentY, objectWidth, objectWidth}, "Yoo", color);
    currentY += objectWidth + paddingY;

    GuiColorPicker((Rectangle){objectXBegin, currentY, objectWidth, objectWidth}, "Yoo", bgColor);
    currentY += objectWidth + paddingY;

    int buttonHeight = 40;
    if (GuiButton((Rectangle){objectXBegin, currentY, objectWidth, buttonHeight}, "Clear Screen")) {
        clearScreen(brushes, capacity);
    }
    currentY += buttonHeight + paddingY;
}

