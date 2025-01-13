#include "menu.h"

void DrawMenu(int selectedItem, Texture2D background) {
    const char *menuItems[] = {"Start", "Score", "Exit"}; // گزینه‌های منو

    BeginDrawing();
    ClearBackground(BLACK);

    // رسم پس‌زمینه
    DrawTexture(background, 0, 0, WHITE);

    // رسم عنوان منو
    DrawText("Main Menu", 300, 50, 40, RAYWHITE);

    // رسم گزینه‌ها
    for (int i = 0; i < 3; i++) {
        Color color = (i == selectedItem) ? YELLOW : WHITE;
        DrawText(menuItems[i], 350, 150 + i * 50, 30, color);
    }

    EndDrawing();
}

void HandleMenuInput(int *selectedItem, GameState *currentState) {
    if (IsKeyPressed(KEY_DOWN)) {
        *selectedItem = (*selectedItem + 1) % 3; // گزینه بعدی
    } else if (IsKeyPressed(KEY_UP)) {
        *selectedItem = (*selectedItem - 1 + 3) % 3; // گزینه قبلی
    } else if (IsKeyPressed(KEY_ENTER)) {
        if (*selectedItem == 0) *currentState = GAME;
        else if (*selectedItem == 1) *currentState = SCORE;
        else if (*selectedItem == 2) *currentState = EXIT;
    }
}