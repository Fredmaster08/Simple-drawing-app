
#include "raylib.h"
#include "draw.h"
#include "raygui.h"

void updateBrushes(Brush* brushes, int* index, int* sizeBrush, Color color) {

    if(IsMouseButtonDown(MOUSE_BUTTON_LEFT)) {
        Brush* brush = &brushes[*index];
        brush->position = GetMousePosition();
        brush->color = color;
        brush->isRectangle = true;
        brush->size = *sizeBrush;
        (*index)++;

    }
    if(IsMouseButtonDown(MOUSE_BUTTON_RIGHT)) {
        Brush* brush = &brushes[*index];
        brush->position = GetMousePosition();
        brush->color = color;
        brush->isRectangle = false;
        brush->size = *sizeBrush;
        (*index)++;
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

