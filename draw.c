
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

void zoom(Camera2D* zoom) {
    Camera2D camera = {0};
    camera.zoom = 1.0f;

    int zoomMode = 0;
    float wheel = GetMouseWheelMove();

    if(zoomMode == 0) {
        Vector2 mouseworlPos = GetScreenToWorld2D(GetMousePosition())
    }
}