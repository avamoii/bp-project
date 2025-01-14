#include <raylib.h>
#include "menu.h"
#include "screen.h"
int currentScreen = 0;
//----------------------------------------------------------------------------------
// Change to screen, no transition effect
static void ChangeToScreen(int screen)
{
    switch (currentScreen)
    {
    case TITLE: UnloadTitleScreen(); break;
    case GAMEPLAY: UnloadGameplayScreen(); break;
    default: break;
    }

    switch (screen)
    {
    case LOGO: InitLogoScreen(); break;
    case TITLE: InitTitleScreen(); break;
    case GAMEPLAY: InitGameplayScreen(); break;
    default: break;
    }

    currentScreen = screen;
}
int main() {
    const int SCREEN_WIDTH = 800;
    const int SCREEN_HEIGHT = 600;

    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Simple Menu");
    SetTargetFPS(60);


    Texture2D background = LoadTexture("../tools/background4.jpg");

    GameState currentState = MENU;
    int selectedItem = 0;

    while (!WindowShouldClose()) {

        if (currentState == MENU) {
            HandleMenuInput(&selectedItem, &currentState);
        } else if (currentState == GAME || currentState == SCORE) {
            if (IsKeyPressed(KEY_ESCAPE)) currentState = MENU;
        } else if (currentState == EXIT) {
            break;
        }


        if (currentState == MENU) {
            DrawMenu(selectedItem, background);
        } else if (currentState == GAME) {
            BeginDrawing();
            ClearBackground(DARKGRAY);
            DrawText("Game Started! Press ESC to return to menu.", 100, 200, 20, RAYWHITE);
            EndDrawing();
        } else if (currentState == SCORE) {
            BeginDrawing();
            ClearBackground(DARKGRAY);
            DrawText("Score Screen! Press ESC to return to menu.", 100, 200, 20, RAYWHITE);
            EndDrawing();
        }
    }

    UnloadTexture(background);
    CloseWindow();
    return 0;
}