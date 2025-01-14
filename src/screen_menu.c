#include <raylib.h>

//----------------------------------------------------------------------------------
// Module Variables Definition (local)
//----------------------------------------------------------------------------------
static int selectedOption = 0;
static int finishScreen = 0;
static Texture2D background;

//----------------------------------------------------------------------------------
// Menu Screen Functions Definition
//----------------------------------------------------------------------------------

// Menu Screen Initialization logic
void InitMenuScreen(void) {
    background = LoadTexture("../tools/background4.jpg");
    selectedOption = 0;
}

// Menu Screen Update logic
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

// Menu Screen Draw logic
void DrawMenuScreen(void) {
    ClearBackground(RAYWHITE);
    DrawTextureEx(background, (Vector2){0, -200}, 0.0f, 1.1, WHITE);
    DrawText("Ava-Nom-Nom", GetScreenHeight() / 2 - 150, 100, 80, WHITE);
    DrawText("1. Start Game", 300, 200, 30, (selectedOption == 0) ? YELLOW : GRAY);
    DrawText("2. Score", 300, 250, 30, (selectedOption == 1) ? YELLOW : GRAY);
    DrawText("3. Exit", 300, 300, 30, (selectedOption == 2) ? YELLOW : GRAY);
}

// Menu Screen Unload logic
void UnloadMenuScreen(void) {
    // Unload MENU screen variables here!
    UnloadTexture(background);
}

// Logo Screen should finish?
int FinishMenuScreen(void)
{
    return finishScreen;
}