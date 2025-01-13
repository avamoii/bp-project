
#ifndef MENU_H
#define MENU_H

#include <raylib.h>

// حالت‌های بازی
enum GameState {
    MENU,
    GAME,
    SCORE,
    EXIT
};

// توابع منو
void DrawMenu(int selectedItem, Texture2D background);
void HandleMenuInput(int *selectedItem, GameState *currentState);

#endif
