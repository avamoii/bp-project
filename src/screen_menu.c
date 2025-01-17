#include <raylib.h>

#include "screen.h"

//----------------------------------------------------------------------------------
// Module Variables Definition (local)
//----------------------------------------------------------------------------------
static int selectedOption = 0;
static int finalOption = 0;
static int finishScreen = 0;
static Texture2D background;

//----------------------------------------------------------------------------------
// Menu Screen Functions Definition
//----------------------------------------------------------------------------------

// Menu Screen Initialization logic
void InitMenuScreen(void) {
    background = LoadTexture("../tools/background4.jpg");
    selectedOption = 0;
    finalOption = MENU;
}

// Menu Screen Update logic
void UpdateMenuScreen(void)
{
    if (IsKeyPressed(KEY_DOWN)) selectedOption++;
    if (IsKeyPressed(KEY_UP)) selectedOption--;
    if (selectedOption < 0) selectedOption = 0;
    if (selectedOption > 2) selectedOption = 2;  // تعداد گزینه‌ها
    if (IsKeyPressed(KEY_ENTER)) {
        switch (selectedOption) {
        case 0:finalOption = NAME;
            break;
        case 1:finalOption = SCORE;
            break;
        case 2: CloseWindow();
            break;
        default:finalOption = MENU;
        }
    }
}

// Menu Screen Draw logic
void DrawMenuScreen(void) {
    ClearBackground(RAYWHITE);
    DrawTextureEx(background, (Vector2){-40, -250}, 0.0f, 1.4, WHITE);
    DrawText("< PAC-MAN >", 230, 100, 80, WHITE);
    DrawText("1. Start Game", 380, 200, 35, (selectedOption == 0) ? YELLOW : GRAY);
    DrawText("2. Score", 380, 250, 35, (selectedOption == 1) ? YELLOW : GRAY);
    DrawText("3. Exit", 380, 300, 35, (selectedOption == 2) ? YELLOW : GRAY);
}

// Menu Screen Unload logic
void UnloadMenuScreen(void) {
    // Unload MENU screen variables here!
    UnloadTexture(background);
}

// Logo Screen should finish?
int  FinishMenuScreen(void)
{
    return finalOption;
}