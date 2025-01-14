// #include "ending.h"
// #include <raylib.h>
//
// static bool restartGame = false;
//
// void InitEndingScreen(void) {
//     restartGame = false;
// }
//
// void UpdateEndingScreen(void) {
//     if (IsKeyPressed(KEY_R)) restartGame = true;  // شروع مجدد
//     if (IsKeyPressed(KEY_ENTER)) TransitionToScreen(MENU);  // بازگشت به منو
// }
//
// void DrawEndingScreen(void) {
//     BeginDrawing();
//     ClearBackground(SKYBLUE);
//     DrawText("ENDING SCREEN", 400, 100, 40, DARKBLUE);
//     DrawText("Press R to restart the game.", 400, 200, 20, DARKGRAY);
//     DrawText("Press ENTER to return to menu.", 400, 250, 20, DARKGRAY);
//     EndDrawing();
// }
//
// void UnloadEndingScreen(void) {
//     // آزادسازی منابع استفاده‌شده در صفحه پایانی
// }
//
// bool FinishEndingScreen(void) {
//     return restartGame;
// }
