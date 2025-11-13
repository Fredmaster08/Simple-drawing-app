
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
    else if(IsMouseButtonDown(MOUSE_BUTTON_RIGHT)) {
        int i = *index;
        brushes[i].position = mousePos;
        brushes[i].color = BLACK;
        (*index)++;
        for(int i = 0; i <= *index; i++) {
            DrawCircle(brushes[i].position.x, brushes[i].position.y, brushSize, brushes[i].color);
        }
    }
    
    
    //if(IsMouseButtonDown(MOUSE_BUTTON_LEFT)) {
    //    Vector2 mousePos = GetMousePosition();
    //    DrawCircle(mousePos.x, mousePos.y, 10, RED);
    //}
}

void erase(Brush* brushes, int* index, Camera2D* camera){
    Vector2 mousePos = GetScreenToWorld2D(GetMousePosition(), *camera);
    int brushSize = 20;
    if(IsMouseButtonDown(MOUSE_BUTTON_LEFT)) {
        int i = *index;
        brushes[i].position = mousePos;
        brushes[i].color = BLACK;
        (*index)++;
        for(int i = 0; i <= *index; i++) {
            DrawCircle(brushes[i].position.x, brushes[i].position.y, brushSize, brushes[i].color);
        }
    }
}