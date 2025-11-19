
#include "raylib.h"
#include "draw.h"
#include "raymath.h"
#include <stdio.h>


void draw(Brush* brushes, int* index, Camera2D* camera, Color color) {
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
        brushes[i].color = color;
        (*index)++;
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

void selectBrushColor(int* r, int* g, int* b) {
    printf("Enter R G B values:\n");
    
    printf("R: ");
    scanf("%d", r);

    printf("G: ");
    scanf("%d", g);

    printf("B: ");
    scanf("%d", b);

    *r = Clamp(*r, 0, 255);
    *g = Clamp(*g, 0, 255);
    *b = Clamp(*b, 0, 255);

    
}