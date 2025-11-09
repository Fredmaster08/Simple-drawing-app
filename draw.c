
#include "raylib.h"
#include "draw.h"
#include "raymath.h"
#define RAYGUI_IMPLEMENTATION
#include "vendor/raygui/src/raygui.h"

void draw(Brush* brushes, int* index, Camera2D* camera) {
    Vector2 mousePos = GetScreenToWorld2D(GetMousePosition(), *camera);
    if(IsMouseButtonDown(MOUSE_BUTTON_LEFT) && IsKeyDown(KEY_LEFT_CONTROL)) {
        Vector2 delta = GetMouseDelta();
        delta = Vector2Scale(delta, -1.0f/camera->zoom);
        camera->target = Vector2Add(camera->target, delta);
    }
    else if(IsMouseButtonDown(MOUSE_BUTTON_LEFT)) {
        brushes[*index].position = mousePos;
        brushes[*index].color = RED;
        (*index)++;
    }
    else if(IsMouseButtonDown(MOUSE_BUTTON_RIGHT)) {
        brushes[*index].position = mousePos;
        brushes[*index].color = BLACK;
        (*index)++;
    }

    float wheel = GetMouseWheelMove();
    if(wheel != 0.0f) {
        camera->offset = GetMousePosition();
        camera->target = mousePos;
        float scale = 0.2f*wheel;
        camera->zoom = Clamp(expf(logf(camera->zoom)+scale), 0.125f, 64.0f);
    }
}

void drawGui(Camera2D* camera) {
    
    Rectangle sliderBounds = {
        .x = 10,
        .y = 10,
        .width = 100,
        .height = 30,
    };

    Vector2 mousePos = GetMousePosition();


    if(sliderBounds.x) {
        camera->offset.x = GetScreenWidth() / 2;
        camera->offset.y = GetScreenHeight() / 2;
    }
    GuiSlider(sliderBounds, "left", "right", &camera->zoom, 0.4f, 16.0f);
}
