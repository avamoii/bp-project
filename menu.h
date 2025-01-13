
#ifndef MENU_H
#define MENU_H

#include <raylib.h>

typedef enum GameState {
    MENU,
    GAME,
    SCORE,
    EXIT
} GameState;

void DrawMenu(int selectedItem, Texture2D background);
void HandleMenuInput(int *selectedItem, GameState *currentState);

#endif
