
#include "raylib.h"
#include "draw.h"
#include "raymath.h"


void draw(Brush* brushes, int* index, Camera2D* camera) {
    Vector2 mousePos = GetScreenToWorld2D(GetMousePosition(), *camera);
    int brushSize = 20;
    if(IsMouseButtonDown(MOUSE_BUTTON_LEFT) && IsKeyDown(KEY_LEFT_CONTROL)) {
        Vector2 delta = GetMouseDelta();
        delta = Vector2Scale(delta, -1.0f/camera->zoom);
        camera->target = Vector2Add(camera->target, delta);
    }
    else if(IsMouseButtonDown(MOUSE_BUTTON_LEFT)) {
        int i = *index;
        brushes[i].position = mousePos;
        brushes[i].color = BLUE;
        (*index)++;
        for(int i = 0; i <= *index; i++) {
            DrawCircle(brushes[i].position.x, brushes[i].position.y, brushSize, brushes[i].color);
        }
    }
}

void erase(Brush* brushes, int* index, Camera2D* camera){
    Vector2 mousePos = GetScreenToWorld2D(GetMousePosition(), *camera);
    int brushSize = 20;
    if(IsMouseButtonDown(MOUSE_BUTTON_RIGHT)) {
        int i = *index;
        brushes[i].position = mousePos;
        brushes[i].color = BLACK;
        (*index)++;
        for(int i = 0; i <= *index; i++) {
            DrawCircle(brushes[i].position.x, brushes[i].position.y, brushSize, brushes[i].color);
        }
    }
}

void wheel(Camera2D* camera) {

    int zoomMode = 0;
    float wheel = GetMouseWheelMove();

    if(zoomMode == 0) {
        Vector2 mouseworldPos = GetScreenToWorld2D(GetMousePosition(), *camera);
        camera->offset = GetMousePosition();
        camera->target = mouseworldPos;
        float scale = 0.2f*wheel;
        camera->zoom = Clamp(expf(logf(camera->zoom)+scale), 0.125f, 64.0f);
    }
}