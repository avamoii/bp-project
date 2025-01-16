#include <raylib.h>
#include "screen.h"
#include <string.h>

static char playerName[50] = "";  // نام بازیکن
static int charIndex = 0;         // اندیس کاراکتر
static bool nameEntered = false;  // بررسی ورود نام

// مقداردهی اولیه صفحه
void InitnamePageScreen(void) {
    memset(playerName, 0, sizeof(playerName));
    charIndex = 0;
    nameEntered = false;
}

// بروزرسانی صفحه
void UpdatenamePageScreen(void) {
    int key = GetKeyPressed();

    // اضافه کردن کاراکتر به نام
    if (key >= 32 && key <= 126 && charIndex < (sizeof(playerName) - 1)) {
        playerName[charIndex++] = (char)key;
        playerName[charIndex] = '\0';
    }

    // حذف کاراکتر
    if (IsKeyPressed(KEY_BACKSPACE) && charIndex > 0) {
        playerName[--charIndex] = '\0';
    }

    // پایان صفحه با زدن اینتر
    if (IsKeyPressed(KEY_ENTER) && charIndex > 0) {
        nameEntered = true;
    }
}

// رسم صفحه
void DrawnamePageScreen(void) {
    ClearBackground(DARKGRAY);

    DrawText("Enter Your Name:", 300, 200, 30, WHITE);
    DrawRectangle(300, 250, 360, 50, LIGHTGRAY);
    DrawText(playerName, 310, 260, 30, BLACK);

    DrawText("Press ENTER to continue", 300, 320, 20, GRAY);
}

// آزادسازی منابع
void UnloadnamePageScreen(void) {
    // اگر منبعی نیاز به آزادسازی دارد اینجا انجام دهید
}

// بررسی پایان صفحه
bool FinishnamePageScreen(void) {
    return nameEntered;
}
