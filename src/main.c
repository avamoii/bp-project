#include <raylib.h>
#include "screen.h"


//----------------------------------------------------------------------------------
// Shared Variables Definition (global)
//----------------------------------------------------------------------------------
GameScreen currentScreen = MENU;
int screenWidth = 800;
int screenHeight = 600;

//----------------------------------------------------------------------------------
// Module Variables Definition (local)
//----------------------------------------------------------------------------------

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
int main()
{
    InitWindow(screenWidth, screenHeight, "PacMan Game - Ava");

    // Set window to full screen mode
    // ToggleFullscreen();

    SetTargetFPS(60);

    // Load global data here (assets that must be available in all screens, i.e. fonts)

    // Define and init first screen
    // NOTE: currentScreen is defined in screens.h as a global variable
    currentScreen = MENU;
    InitMenuScreen();

    // Texture2D background = LoadTexture("../tools/background4.jpg");

    // Main game loop
    // Main game loop
    while (!WindowShouldClose()) {
        switch (currentScreen) {
        case MENU:
            UpdateMenuScreen();
            if (FinishMenuScreen()) ChangeToScreen(GAMEPLAY);
            break;
        case GAMEPLAY:
            UpdateGameplayScreen();
            if (FinishGameplayScreen()) ChangeToScreen(SCORE);
            break;
        case SCORE:
            UpdateScoreScreen();
            if (FinishScoreScreen()) ChangeToScreen(MENU);
            break;
        case ENDING:
            UpdateEndingScreen();
            if (FinishEndingScreen()) ChangeToScreen(MENU);
            break;
        default:
            break;
        }

        BeginDrawing();
        ClearBackground(RAYWHITE);

        switch (currentScreen) {
        case MENU: DrawMenuScreen(); break;
        case GAMEPLAY: DrawGameplayScreen(); break;
        case SCORE: DrawScoreScreen(); break;
        case ENDING: DrawEndingScreen(); break;
        default: break;
        }

        EndDrawing();
    }
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

                if (FinishMenuScreen() != MENU) {
                    ChangeToScreen(FinishMenuScreen());
                }

            } break;
            case SCORE:
            {
                UpdateScoreScreen();

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
    EndDrawing();
    //----------------------------------------------------------------------------------
}
bool FinishScoreScreen(void) {
    if (IsKeyPressed(KEY_ENTER)) {
        return true;
    }
    return false;
}

