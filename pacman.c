//
// Created by Aras Computer on 1/14/2025.
//

#include "pacman.h"

// مقداردهی اولیه پک‌من
void InitPacman(Pacman *pacman, float startX, float startY, float speed, const char *openPath, const char *closedPath) {
    pacman->position = (Vector2){startX, startY};
    pacman->speed = speed;
    pacman->frameCounter = 0;
    pacman->openTexture = LoadTexture(openPath);
    pacman->closedTexture = LoadTexture(closedPath);
}

// به‌روزرسانی وضعیت پک‌من
void UpdatePacman(Pacman *pacman) {
    if (IsKeyDown(KEY_UP)) pacman->position.y -= pacman->speed;
    if (IsKeyDown(KEY_DOWN)) pacman->position.y += pacman->speed;
    if (IsKeyDown(KEY_LEFT)) pacman->position.x -= pacman->speed;
    if (IsKeyDown(KEY_RIGHT)) pacman->position.x += pacman->speed;

    // به‌روزرسانی شمارنده فریم
    pacman->frameCounter++;
}

// رسم پک‌من روی صفحه
void DrawPacman(Pacman *pacman) {
    // انتخاب تصویر بر اساس شمارنده فریم
    if ((pacman->frameCounter / 15) % 2 == 0) {
        DrawTextureEx(pacman->openTexture, pacman->position, 0.0f, 0.5f, WHITE);
    } else {
        DrawTextureEx(pacman->closedTexture, pacman->position, 0.0f, 0.5f, WHITE);
    }
}

// آزادسازی منابع تصویری پک‌من
void UnloadPacmanTextures(Pacman *pacman) {
    UnloadTexture(pacman->openTexture);
    UnloadTexture(pacman->closedTexture);
}