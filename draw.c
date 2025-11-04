
#include "raylib.h"
#include "draw.h"
#include "raymath.h"

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


