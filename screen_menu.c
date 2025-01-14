#include "menu.h"
#include <raylib.h>

static int selectedOption = 0;

void InitMenuScreen(void) {
    selectedOption = 0;
}

void UpdateMenuScreen(void) {
    if (IsKeyPressed(KEY_DOWN)) selectedOption++;
    if (IsKeyPressed(KEY_UP)) selectedOption--;
    if (selectedOption < 0) selectedOption = 0;
    if (selectedOption > 2) selectedOption = 2;  // تعداد گزینه‌ها
    if (IsKeyPressed(KEY_ENTER)) {
        if (selectedOption == 0) TransitionToScreen(GAMEPLAY);
        else if (selectedOption == 1) TransitionToScreen(SCORE);
        else if (selectedOption == 2) CloseWindow();  // خروج
    }
}

void DrawMenuScreen(void) {
    BeginDrawing();
    ClearBackground(RAYWHITE);
    DrawText("MENU SCREEN", 500, 100, 40, DARKGRAY);
    DrawText("1. Start Game", 500, 200, 30, (selectedOption == 0) ? RED : BLACK);
    DrawText("2. Score", 500, 250, 30, (selectedOption == 1) ? RED : BLACK);
    DrawText("3. Exit", 500, 300, 30, (selectedOption == 2) ? RED : BLACK);
    EndDrawing();
}

void UnloadMenuScreen(void) {
    // در صورت نیاز منابع صفحه آزاد شوند
}
