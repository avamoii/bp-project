#include "menu.h"

#include "menu.h"

void DrawMenu(int selectedItem, Texture2D background) {
    const char *menuItems[] = {"Start", "Score", "Exit"}; // گزینه‌های منو

    BeginDrawing();
    ClearBackground(BLACK);

    // رسم پس‌زمینه
    DrawTextureEx(background, (Vector2){0, -200}, 0.0f,1.1,WHITE );

    // رسم عنوان منو
    DrawText("Main Menu", 190, 50, 80, RAYWHITE);

    // رسم گزینه‌ها
    for (int i = 0; i < 3; i++) {
        Color color = (i == selectedItem) ? YELLOW : GRAY;
        DrawText(menuItems[i], 300, 150 + i * 50, 60, color);
    }

    EndDrawing();
}


void HandleMenuInput(int *selectedItem, GameState *currentState) {
    if (IsKeyPressed(KEY_DOWN)) {
        *selectedItem = (*selectedItem + 1) % 3;
    } else if (IsKeyPressed(KEY_UP)) {
        *selectedItem = (*selectedItem + 3) % 3;
    } else if (IsKeyPressed(KEY_ENTER)) {
        if (*selectedItem == 0) *currentState = GAME;
        else if (*selectedItem == 1) *currentState = SCORE;
        else if (*selectedItem == 2) *currentState = EXIT;
    }
}