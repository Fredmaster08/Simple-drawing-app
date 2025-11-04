
#include "raylib.h"
#include "raymath.h"
#include "draw.h"

#define RAYGUI_IMPLEMENTATION
#include "raygui.h"

#include <stdint.h>

static Vector2 currentMousePos = (Vector2){0};
static Vector2 previousMousePos = (Vector2){0};

void updateBrushes(Brush* brushes, int* index, int* sizeBrush, Color color) {
    previousMousePos = currentMousePos;
    currentMousePos = GetMousePosition();

    float mouseDist = Vector2Length(GetMouseDelta());
    int32_t lerpCount = 0;
    float lerp = 0.0f;

    if (mouseDist >= (*sizeBrush * 0.1)) {
        lerpCount = (mouseDist / *sizeBrush) * 2.0f;
    }

    if(IsMouseButtonDown(MOUSE_BUTTON_LEFT)) {
        Brush* brush = &brushes[*index];
        brush->position = GetMousePosition();
        brush->color = color;
        brush->isRectangle = true;
        brush->size = *sizeBrush;
        (*index)++;
        
        if (lerpCount != 0) {
            while (lerp != 1.0f) {
                Brush* brush = &brushes[*index];
                brush->position = Vector2Lerp(previousMousePos, currentMousePos, lerp);
                brush->color = GREEN;
                brush->isRectangle = true;
                brush->size = *sizeBrush;
                (*index)++;
                lerp += 1.0f / lerpCount;
            }
        }
        
    }
    if(IsMouseButtonDown(MOUSE_BUTTON_RIGHT)) {
        Brush* brush = &brushes[*index];
        brush->position = GetMousePosition();
        brush->color = color;
        brush->isRectangle = false;
        brush->size = *sizeBrush;
        (*index)++;

        if (lerpCount != 0) {
            while (lerp != 1.0f) {
                Brush* brush = &brushes[*index];
                brush->position = Vector2Lerp(previousMousePos, currentMousePos, lerp);
                brush->color = GREEN;
                brush->isRectangle = false;
                brush->size = *sizeBrush;
                (*index)++;
                lerp += 1.0f / lerpCount;
            }
        }
    }

    *sizeBrush += GetMouseWheelMove();
}

void clearScreen(Brush *brushes, int *index) {
    for (int i = 0; i < *index; i++) {
        brushes[i] = (Brush){0};
    }
}

void drawGui(int guiOffset, int guiWidth, int guiHeight, Color* color, Color* bgColor, Brush* brushes, int* index) {
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
        clearScreen(brushes, index);
    }
    currentY += buttonHeight + paddingY;
}

