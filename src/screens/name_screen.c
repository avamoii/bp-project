#include <raylib.h>
#include "screen.h"

#define MAX_INPUT_CHARS 15

int framesCounter = 0;
char name[MAX_INPUT_CHARS + 1] = "\0";
int letterCount = 0;
Rectangle textBox = {960 / 2 - 400, 300, 800, 80};
bool mouseOnText = false;
static bool nameEntered = false;

bool IsAnyKeyPressed() {
    bool keyPressed = false;
    int key = GetKeyPressed();

    if ((key >= 32) && (key <= 126)) keyPressed = true;

    return keyPressed;
}

void InitnamePageScreen(void) {
    nameEntered = false;
}

void UpdatenamePageScreen(void) {
    if (CheckCollisionPointRec(GetMousePosition(), textBox)) mouseOnText = true;
    else mouseOnText = false;

    if (mouseOnText) {
        // Set the window's cursor to the I-Beam
        SetMouseCursor(MOUSE_CURSOR_IBEAM);

        // Get char pressed (unicode character) on the queue
        int key = GetCharPressed();

        // Check if more characters have been pressed on the same frame
        while (key > 0) {
            // NOTE: Only allow keys in range [32..125]
            if ((key >= 32) && (key <= 125) && (letterCount < MAX_INPUT_CHARS)) {
                name[letterCount] = (char) key;
                name[letterCount + 1] = '\0'; // Add null terminator at the end of the string.
                letterCount++;
            }

            key = GetCharPressed(); // Check next character in the queue
        }

        if (IsKeyPressed(KEY_BACKSPACE)) {
            letterCount--;
            if (letterCount < 0) letterCount = 0;
            name[letterCount] = '\0';
        }
    } else SetMouseCursor(MOUSE_CURSOR_DEFAULT);

    if (mouseOnText) framesCounter++;
    else framesCounter = 0;

    if (IsKeyPressed(KEY_ENTER)) {
        AddName(name);
        nameEntered = true;
    }
}

void DrawnamePageScreen(void) {
    DrawText("PLACE MOUSE OVER INPUT BOX!", 230, 250, 30, GRAY);

    DrawRectangleRec(textBox, LIGHTGRAY);
    if (mouseOnText)
        DrawRectangleLines((int) textBox.x, (int) textBox.y, (int) textBox.width, (int) textBox.height,
                           RED);
    else DrawRectangleLines((int) textBox.x, (int) textBox.y, (int) textBox.width, (int) textBox.height, DARKGRAY);

    DrawText(name, (int) textBox.x + 5, (int) textBox.y + 8, 40, MAROON);

    DrawText(TextFormat("INPUT CHARS: %i/%i", letterCount, MAX_INPUT_CHARS), 360, 390, 20, DARKGRAY);

    if (mouseOnText) {
        if (letterCount < MAX_INPUT_CHARS) {
            // Draw blinking underscore char
            if (((framesCounter / 20) % 2) == 0)
                DrawText("_", (int) textBox.x + 8 + MeasureText(name, 40),
                         (int) textBox.y + 12, 40, MAROON);
        } else DrawText("Press BACKSPACE to delete chars...", 230, 440, 20, GRAY);
    }
}

void UnloadnamePageScreen(void) {
}

bool FinishnamePageScreen(void) {
    return nameEntered;
}
