// #include "score.h"
// #include <raylib.h>
//
// static int score = 0;
//
// void InitScoreScreen(void) {
//     // مقداردهی اولیه صفحه امتیاز (مثلاً خواندن امتیازات ذخیره‌شده)
//     score = 100;  // نمونه امتیاز
// }
//
// void UpdateScoreScreen(void) {
//     if (IsKeyPressed(KEY_ENTER)) TransitionToScreen(MENU);  // بازگشت به منو
// }
//
// void DrawScoreScreen(void) {
//     BeginDrawing();
//     ClearBackground(BEIGE);
//     DrawText("SCORE SCREEN", 400, 100, 40, DARKBROWN);
//     DrawText(TextFormat("Your Score: %d", score), 400, 200, 30, DARKGRAY);
//     DrawText("Press ENTER to return to menu.", 400, 300, 20, GRAY);
//     EndDrawing();
// }
//
// void UnloadScoreScreen(void) {
//     // آزادسازی منابع استفاده‌شده در صفحه امتیاز
// }
