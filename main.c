#include <raylib.h>
#include "menu.h"
#include "screen.h"

//----------------------------------------------------------------------------------
// Shared Variables Definition (global)
//----------------------------------------------------------------------------------
GameScreen currentScreen = MENU;


//----------------------------------------------------------------------------------
// Module Variables Definition (local)
//----------------------------------------------------------------------------------
static const int screenWidth = 1280;
static const int screenHeight = 720;

static float transAlpha = 0;
static bool onTransition = false;
static bool transFadeOut = false;
static int transFromScreen = -1;
static int transToScreen = -1;
static int framesCounter = 0;

//----------------------------------------------------------------------------------
// Module Functions Declaration (local)
//----------------------------------------------------------------------------------
static void ChangeToScreen(int screen);     // Change to screen, no transition effect

static void TransitionToScreen(int screen); // Request transition to next screen
static void UpdateTransition(void);         // Update transition effect
static void DrawTransition(void);           // Draw transition effect (full-screen rectangle)

static void UpdateDrawFrame(void);          // Update and draw one frame



//----------------------------------------------------------------------------------
// Main entry point
//----------------------------------------------------------------------------------
int main() {
    InitWindow(screenWidth, screenHeight, "Simple Menu");
    SetTargetFPS(60);

    // Load global data here (assets that must be available in all screens, i.e. fonts)

    // Define and init first screen
    // NOTE: currentScreen is defined in screens.h as a global variable
    currentScreen = MENU;
    InitMenuScreen();

    Texture2D background = LoadTexture("../tools/background4.jpg");

    int selectedItem = 0;

    // Main game loop
    while (!WindowShouldClose()) UpdateDrawFrame();

    // while (!WindowShouldClose()) {
    //
    //     if (currentState == MENU) {
    //         HandleMenuInput(&selectedItem, &currentState);
    //     } else if (currentState == GAME || currentState == SCORE) {
    //         if (IsKeyPressed(KEY_ESCAPE)) currentState = MENU;
    //     } else if (currentState == EXIT) {
    //         break;
    //     }
    //
    //
    //     if (currentState == MENU) {
    //         DrawMenu(selectedItem, background);
    //     } else if (currentState == GAME) {
    //         BeginDrawing();
    //         ClearBackground(DARKGRAY);
    //         DrawText("Game Started! Press ESC to return to menu.", 100, 200, 20, RAYWHITE);
    //         EndDrawing();
    //     } else if (currentState == SCORE) {
    //         BeginDrawing();
    //         ClearBackground(DARKGRAY);
    //         DrawText("Score Screen! Press ESC to return to menu.", 100, 200, 20, RAYWHITE);
    //         EndDrawing();
    //     }
    // }

    // De-Initialization
    //--------------------------------------------------------------------------------------
    UnloadTexture(background);
    // CloseAudioDevice();         // Close audio device
    CloseWindow();              // Close window and OpenGL context
    //--------------------------------------------------------------------------------------
    return 0;
}

//----------------------------------------------------------------------------------
// Module Functions Definition (local)
//----------------------------------------------------------------------------------
// Change to screen, no transition effect
static void ChangeToScreen(int screen)
{
    switch (currentScreen)
    {
    case MENU: UnloadMenuScreen(); break;
    case SCORE: UnloadScoreScreen(); break;
    case ENDING: UnloadEndingScreen(); break;
    case GAMEPLAY: UnloadGameplayScreen(); break;
    default: break;
    }

    switch (screen)
    {
    case MENU: InitMenuScreen(); break;
    case SCORE: InitScoreScreen(); break;
    case ENDING: InitEndingScreen(); break;
    case GAMEPLAY: InitGameplayScreen(); break;
    default: break;
    }

    currentScreen = screen;
}

// Request transition to next screen
static void TransitionToScreen(int screen)
{
    onTransition = true;
    transFromScreen = currentScreen;
    transToScreen = screen;
}

// Update transition effect
static void UpdateTransition(void)
{
    if (!transFadeOut)
    {
        transAlpha += 0.05f;

        if (transAlpha >= 1.0)
        {
            transAlpha = 1.0;
            currentScreen = transToScreen;
            transFadeOut = true;
            framesCounter = 0;
        }
    }
    else  // Transition fade out logic
    {
        transAlpha -= 0.05f;

        if (transAlpha <= 0)
        {
            transAlpha = 0;
            transFadeOut = false;
            onTransition = false;
            transFromScreen = -1;
            transToScreen = -1;
        }
    }
}

// Draw transition effect (full-screen rectangle)
static void DrawTransition(void)
{
    DrawRectangle(0, 0, GetScreenWidth(), GetScreenHeight(), Fade(BLACK, transAlpha));
}

// Update and draw one frame
void UpdateDrawFrame(void)
{
    // Update
    //----------------------------------------------------------------------------------
    if (!onTransition)
    {
        switch (currentScreen)
        {
            case MENU:
            {
                UpdateMenuScreen();

                // if (FinishMenuScreen()) ChangeToScreen(TITLE);
                //
            } break;
            case SCORE:
            {
                UpdateScoreScreen();

                // NOTE: FinishTitleScreen() return an int defining the screen to jump to
                // if (FinishScoreScreen() == 1)
                // {
                //     UnloadTitleScreen();
                //     //currentScreen = OPTIONS;
                //     //InitOptionsScreen();
                // }
                // else if (FinishTitleScreen() == 2)
                // {
                //     UnloadTitleScreen();
                //
                //     InitGameplayScreen();
                //     TransitionToScreen(GAMEPLAY);
                // }
            } break;
            case GAMEPLAY:
            {
                UpdateGameplayScreen();

                if (FinishGameplayScreen())
                {
                    UnloadGameplayScreen();

                    InitEndingScreen();
                    TransitionToScreen(ENDING);
                }
            } break;
            case ENDING:
            {
                UpdateEndingScreen();

                if (FinishEndingScreen())
                {
                    UnloadEndingScreen();

                    InitGameplayScreen();
                    TransitionToScreen(GAMEPLAY);
                }
            } break;
            default: break;
        }
    }
    else UpdateTransition();

    // UpdateMusicStream(music);
    //----------------------------------------------------------------------------------

    // Draw
    //----------------------------------------------------------------------------------
    BeginDrawing();

        ClearBackground(WHITE);

        switch (currentScreen)
        {
            case MENU: DrawMenuScreen(); break;
            case SCORE: DrawScoreScreen(); break;
            case GAMEPLAY: DrawGameplayScreen(); break;
            case ENDING: DrawEndingScreen(); break;
            default: break;
        }

        if (onTransition) DrawTransition();

        DrawRectangle(GetScreenWidth() - 200, GetScreenHeight() - 50, 200, 40, Fade(WHITE, 0.6f));
        DrawText("ALPHA VERSION", GetScreenWidth() - 180, GetScreenHeight() - 40, 20, DARKGRAY);

    EndDrawing();
    //----------------------------------------------------------------------------------
}
