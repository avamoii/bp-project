#include <raylib.h>
#include <stdio.h>
#include <stdlib.h>

#define ROWS 24
#define COLS 32
#define TILE_SIZE 25
#define mapWidth 800
#define mapHeight 600

int Map[24][32] = {
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 1},
    {1, 0, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 0, 1},
    {1, 0, 1, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 1, 0, 0, 0, 0, 0, 1, 0, 1},
    {1, 0, 1, 0, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 0, 1, 0, 1, 1, 1, 1, 1, 0, 1, 0, 1},
    {1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1},
    {1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 0, 1},
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
    {1, 0, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1},
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
    {1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1},
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
    {1, 0, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 0, 1},
    {1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1},
    {1, 0, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 0, 1},
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
    {1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1},
    {1, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 1},
    {1, 0, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 0, 1},
    {1, 0, 1, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 1, 0, 0, 0, 0, 0, 1, 0, 1},
    {1, 0, 1, 0, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 0, 1, 0, 1, 1, 1, 1, 1, 0, 1, 0, 1},
    {1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9}
};

void placeRandomFood(int input) {
    int count =0;
    while (count<input){
        int y = GetRandomValue(0, ROWS-1);
        int x = GetRandomValue(0, COLS-1);
        if (Map[y][x]==0)
        {
            Map[y][x] = 2;
            count++;
        }
    }
}

static int playerX = 1, playerY = 1;

void InitGameplayScreen(void) {
    placeRandomFood(10);
}

void UpdateGameplayScreen(void) {
    // static void UpdatePlayer(void) {
    //     int nextX = playerX;
    //     int nextY = playerY;
    //
    //     if (IsKeyPressed(KEY_UP)) nextY--;
    //     if (IsKeyPressed(KEY_DOWN)) nextY++;
    //     if (IsKeyPressed(KEY_LEFT)) nextX--;
    //     if (IsKeyPressed(KEY_RIGHT)) nextX++;
    //
    //     // بررسی برخورد با دیوارها
    //     if (Map[nextY][nextX] != 1) {
    //         // بروزرسانی نقشه
    //         Map[playerY][playerX] = 0;  // حذف بازیکن از مکان قبلی
    //         playerX = nextX;
    //         playerY = nextY;
    //         Map[playerY][playerX] = 3;  // قرار دادن بازیکن در مکان جدید
    //     }
    // }
}

void DrawGameplayScreen(void) {
    Color myColor1 = (Color){0, 0, 90, 255};
    Color myColor2 = (Color){173, 216, 230, 255};
    Color yellow = (Color){204, 204, 0, 255};

    for (int y = 0; y < ROWS; y++) {
        for (int x = 0; x < COLS; x++) {
            int posX = x * TILE_SIZE;
            int posY = y * TILE_SIZE;

            if (Map[y][x] == 1) {
                DrawRectangle(posX, posY, TILE_SIZE, TILE_SIZE, myColor2);
            }
            else if (Map[y][x] == 0 || Map[y][x] == 2)
            {
                DrawRectangle(posX, posY, TILE_SIZE, TILE_SIZE, myColor1);
            }
             else if (Map[y][x] == 9)
             {
                DrawRectangle(posX, posY, TILE_SIZE,TILE_SIZE,BLACK);
             }
            if (Map[y][x] == 2)
            {
                DrawCircle(posX +12.5, posY+12.5, 3, YELLOW);
            }

        }
    }
}


void UnloadGameplayScreen(void) {
    // آزادسازی منابع در صورت نیاز
}

bool FinishGameplayScreen(void) {
    return false; // منطق اتمام بازی را اضافه کنید
}

//static void UpdatePlayer(void)
//     {
// int nextX = playerX, nextY = playerY;
// if (IsKeyPressed(KEY_UP)) nextY--;
// if (IsKeyPressed(KEY_DOWN)) nextY++;
// if (IsKeyPressed(KEY_LEFT)) nextX--;
// if (IsKeyPressed(KEY_RIGHT)) nextX++;
// if (Map[nextY][nextX] != 1) {
//     Map[playerY][playerX] = 0;
//     playerX = nextX;
//     playerY = nextY;
//     Map[playerY][playerX] = 3;
// }
//    }
