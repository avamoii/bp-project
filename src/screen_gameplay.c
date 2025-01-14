#include <raylib.h>
#include <stdio.h>
#include <stdlib.h>
#include<stdbool.h>

#define ROWS 24
#define COLS 32
#define TILE_SIZE 25
#define mapWidth 800
#define mapHeight 600

Texture2D cherry;
Texture2D apple;
Texture2D pepper;
Texture2D mushroom;
Texture2D pacmanOpen;
Texture2D pacmanClose;
Texture2D ghost1;
Texture2D ghost2;
Texture2D ghost3;
Texture2D ghost4;
Texture2D ghost5;
bool isMouthOpen = false;

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
//-----------------------------------------------------------------------------------------
//-----------------------------------------------------------------------------------------
// random position for characters
void placeRandomFood(int input1,int input2) {
    int count =0;
    while (count<input1){
        int y = GetRandomValue(0, ROWS-1);
        int x = GetRandomValue(0, COLS-1);
        if (Map[y][x]==0)
        {
            Map[y][x] = input2;
            count++;
        }
    }
}

//-----------------------------------------------------------------------------------------
//-----------------------------------------------------------------------------------------

void InitGameplayScreen(void) {
    //----------------------------------------------------------------------------------------------
    //food items in game
    placeRandomFood(10,2);//for foods
    placeRandomFood(1,3);//for cherry
    placeRandomFood(1,4);//for apple
    placeRandomFood(1,5);// for mushroom
    placeRandomFood(1,6);//for pepper
    cherry=LoadTexture("../assets/items/cherry.png");//3
    apple=LoadTexture("../assets/items/apple1.png");//4
    mushroom=LoadTexture("../assets/items/mushroom.png");//5
    pepper=LoadTexture("../assets/items/pepper.png");//6
    //----------------------------------------------------------------------------------------------
    pacmanOpen = LoadTexture("../pac/pacWide.png");
    pacmanClose = LoadTexture("../pac/pacClosed.png");


    float timer = 0.0f;
    float changeTime = 0.5f;
        timer += GetFrameTime();

        if (timer >= changeTime)
        {
            isMouthOpen = (!isMouthOpen);
            timer = 0.0f;
        }
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
    //-------------------------------------------------------------------------------------
    //-------------------------------------------------------------------------------------
    Color myColor1 = (Color){0, 0, 90, 255};
    Color myColor2 = (Color){173, 216, 230, 255};
    Color yellow = (Color){204, 204, 0, 255};

    for (int y = 0; y < ROWS; y++) {
        for (int x = 0; x < COLS; x++) {
            int posX = x * TILE_SIZE;
            int posY = y * TILE_SIZE;
            Vector2 pos = {posX , posY };

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
                DrawCircle(posX +12.5, posY+12.5, 4, yellow);
            }
            if (Map[y][x] == 3)
            {
                DrawTextureEx(cherry,pos,0.0f,2.0f, WHITE);
            }
            if (Map[y][x] == 4)
            {
                DrawTextureEx(apple,pos,0.0f,1.0f, WHITE);
            }
            if (Map[y][x] == 5)
            {
                DrawTextureEx(mushroom,pos,0.0f,2.0f, WHITE);
            }
            if (Map[y][x] == 6)
            {
                DrawTextureEx(pepper,pos,0.0f,2.0f, WHITE);
            }

        }
    }
    //---------------------------------------------------------------------------------
    //---------------------------------------------------------------------------------
    if (isMouthOpen)
        DrawTexture(pacmanOpen, 100, 100, WHITE);
    else
        DrawTexture(pacmanClose, 100, 100, WHITE);

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
