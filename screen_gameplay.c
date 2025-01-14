// #include "gameplay.h"
// #include <raylib.h>
//
// #define ROWS 24
// #define COLS 32
// #define TILE_SIZE 25
// #define mapWidth 800
// #define mapHeight 600
//
//
// int Map[ROWS][COLS] = {
//     {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
//     {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
//     {1,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,1},
//     {1,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,1},
//     {1,0,1,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,1,0,1},
//     {1,0,1,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,1,0,1},
//     {1,0,1,0,1,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,1,0,1,0,1},
//     {1,0,1,0,1,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,1,0,1,0,1,0,1},
//     {1,0,1,0,1,0,1,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,1,0,1,0,1,0,1,0,1},
//     {1,0,1,0,1,0,1,0,1,0,0,0,0,0,0,0,0,0,0,0,0,1,0,1,0,1,0,1,0,1,0,1},
//     {1,0,1,0,1,0,1,0,1,0,1,1,1,1,1,1,1,1,1,1,0,1,0,1,0,1,0,1,0,1,0,1},
//     {1,0,1,0,1,0,1,0,1,0,1,0,0,0,0,0,0,0,0,1,0,1,0,1,0,1,0,1,0,1,0,1},
//     {1,0,1,0,1,0,1,0,1,0,1,0,1,1,1,1,1,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1},
//     {1,0,1,0,1,0,1,0,1,0,1,0,1,0,0,0,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1},
//     {1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1},
//     {1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1},
//     {1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,1,0,1,0,1,0,1,0,1,0,1,0,1},
//     {1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,1,0,1,0,1,0,1,0,1,0,1},
//     {1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,1,0,1,0,1,0,1,0,1},
//     {1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,1,0,1,0,1,0,1},
//     {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}
// };
//
//
// static int playerX = 1, playerY = 1;
//
// void InitGameplayScreen(void) {
//     playerX = 1;
//     playerY = 1;
//     Map[playerY][playerX] = 3;
// }
//
// void UpdateGameplayScreen(void) {
//     static void UpdatePlayer(void) {
//         int nextX = playerX;
//         int nextY = playerY;
//
//         if (IsKeyPressed(KEY_UP)) nextY--;
//         if (IsKeyPressed(KEY_DOWN)) nextY++;
//         if (IsKeyPressed(KEY_LEFT)) nextX--;
//         if (IsKeyPressed(KEY_RIGHT)) nextX++;
//
//         // بررسی برخورد با دیوارها
//         if (Map[nextY][nextX] != 1) {
//             // بروزرسانی نقشه
//             Map[playerY][playerX] = 0;  // حذف بازیکن از مکان قبلی
//             playerX = nextX;
//             playerY = nextY;
//             Map[playerY][playerX] = 3;  // قرار دادن بازیکن در مکان جدید
//         }
//     }
//
// }
//
// void DrawGameplayScreen(void) {
//     static void DrawMap(void) {
//
//         for (int y = 0; y < mapWidth; y++) {
//             for (int x = 0; x < mapHeight; x++) {
//                 switch (Map[y][x]) {
//                 case 1:  // دیوار
//                     DrawRectangle(x * TILE_SIZE, y * TILE_SIZE, TILE_SIZE, TILE_SIZE, DARKGRAY);
//                     break;
//                 case 2:  // نقطه
//                     DrawCircle(x * TILE_SIZE + TILE_SIZE / 2, y * TILE_SIZE + TILE_SIZE / 2, 5, GOLD);
//                     break;
//                 case 3:  // بازیکن
//                     DrawCircle(x * TILE_SIZE + TILE_SIZE / 2, y * TILE_SIZE + TILE_SIZE / 2, 12, BLUE);
//                     break;
//                 }
//             }
//         }
//     }
//
// }
//
// void UnloadGameplayScreen(void) {
//     // آزادسازی منابع در صورت نیاز
// }
//
// bool FinishGameplayScreen(void) {
//     return false;  // منطق اتمام بازی را اضافه کنید
// }
//
// static void UpdatePlayer(void) {
//     int nextX = playerX, nextY = playerY;
//     if (IsKeyPressed(KEY_UP)) nextY--;
//     if (IsKeyPressed(KEY_DOWN)) nextY++;
//     if (IsKeyPressed(KEY_LEFT)) nextX--;
//     if (IsKeyPressed(KEY_RIGHT)) nextX++;
//     if (Map[nextY][nextX] != 1) {
//         Map[playerY][playerX] = 0;
//         playerX = nextX;
//         playerY = nextY;
//         Map[playerY][playerX] = 3;
//     }
// }
//
