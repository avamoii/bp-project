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
Texture2D ghost11;
Texture2D ghost12;
Texture2D ghost13;
Texture2D ghost14;
Texture2D ghost15;
//------------------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------------------
typedef struct {
    int x;
    int y;
    int dx;
    int dy;
    int lives;
    bool isMouthOpen;
    int frameCounter;
} Pacman;

typedef struct {
    int x;
    int y;
    int dx;
    int dy;
} Ghost;

Pacman pacman;
Ghost ghost1, ghost2, ghost3, ghost4, ghost5;
//-------------------------------------------------------------------------------------------------
//-------------------------------------------------------------------------------------------------


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
void placeRandomFoods(int input1, int input2) {
    int count = 0;
    while (count < input1) {
        int y = GetRandomValue(0, ROWS - 1);
        int x = GetRandomValue(0, COLS - 1);
        if (Map[y][x] == 0) {
            Map[y][x] = input2;
            count++;
        }
    }
}

//-----------------------------------------------------------------------------------------
//-----------------------------------------------------------------------------------------
//pacman random location
void pacmanRandomlocation(int map[ROWS][COLS], Pacman *ptr) {
    while (1) {
        int x = GetRandomValue(0, COLS - 1);
        int y = GetRandomValue(0, ROWS - 1);
        if (map[y][x] == 0) {
            ptr->x = x;
            ptr->y = y;
            break;
        }
    }
}

//--------------------------------------------------------------------------------------------
//--------------------------------------------------------------------------------------------
//ghosts random location
void ghostRandomlocation(int map[ROWS][COLS], Ghost *ptr) {
    while (1) {
        int x = GetRandomValue(0, COLS - 1);
        int y = GetRandomValue(0, ROWS - 1);
        if (map[y][x] == 0) {
            ptr->x = x;
            ptr->y = y;
            break;
        }
    }
}

//-------------------------------------------------------------------------------------------------
//-------------------------------------------------------------------------------------------------
// pacman movement
void MovePacman(Pacman *pacman) {
    int nextX = pacman->x / TILE_SIZE + pacman->dx;
    int nextY = pacman->y / TILE_SIZE + pacman->dy;

    // بررسی اینکه مختصات بعدی خارج از محدوده نقشه نباشد
    if (nextX >= 0 && nextX < COLS && nextY >= 0 && nextY < ROWS) {
        if (Map[nextY][nextX] != 1) {
            // بررسی دیوار
            pacman->x += pacman->dx * TILE_SIZE;
            pacman->y += pacman->dy * TILE_SIZE;
        }
    }
    pacman->dx = 0;
    pacman->dy = 0;
}

//--------------------------------------------------------------------------------------------------
//--------------------------------------------------------------------------------------------------
void InitGameplayScreen(void) {
    //----------------------------------------------------------------------------------------------
    //food items in game
    placeRandomFoods(10, 2); //for foods
    placeRandomFoods(1, 3); //for cherry
    placeRandomFoods(1, 4); //for apple
    placeRandomFoods(1, 5); // for mushroom
    placeRandomFoods(1, 6); //for pepper
    cherry = LoadTexture("../assets/items/cherry.png"); //3
    apple = LoadTexture("../assets/items/apple1.png"); //4
    mushroom = LoadTexture("../assets/items/mushroom.png"); //5
    pepper = LoadTexture("../assets/items/pepper.png"); //6
    //----------------------------------------------------------------------------------------------
    //all characters pictures
    pacmanOpen = LoadTexture("../assets/sprites/pac/pacClosed.png");
    pacmanClose = LoadTexture("../assets/sprites/pac/pacWide.png");
    ghost11 = LoadTexture("../assets/sprites/ghosts/blue/blue0.png");
    ghost12 = LoadTexture("../assets/sprites/ghosts/clyde/clyde4.png");
    ghost13 = LoadTexture("../assets/sprites/ghosts/inky/inky2.png");
    ghost14 = LoadTexture("../assets/sprites/ghosts/pinky/pinky1.png");
    ghost15 = LoadTexture("../assets/sprites/ghosts/blue/blue3.png");
    //-----------------------------------------------------------------------------------------------
    //initializing pacman
    Pacman pacman;
    pacmanRandomlocation(Map, &pacman);
    pacman.dx = 0;
    pacman.dy = 0;
    pacman.lives = 3;
    pacman.isMouthOpen = true;
    pacman.frameCounter = 0;
    // initializing ghosts
    Ghost ghost1;
    ghostRandomlocation(Map, &ghost1);
    ghost1.dx = 0;
    ghost1.dy = 0;
    Ghost ghost2;
    ghostRandomlocation(Map, &ghost2);
    ghost2.dx = 0;
    ghost2.dy = 0;
    Ghost ghost3;
    ghostRandomlocation(Map, &ghost3);
    ghost3.dx = 0;
    ghost3.dy = 0;
    Ghost ghost4;
    ghostRandomlocation(Map, &ghost4);
    ghost4.dx = 0;
    ghost4.dy = 0;
    Ghost ghost5;
    ghostRandomlocation(Map, &ghost5);
    ghost5.dx = 0;
    ghost5.dy = 0;
}

//-------------------------------------------------------------------------------------------------

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
            Vector2 pos = {posX, posY};

            if (Map[y][x] == 1) {
                DrawRectangle(posX, posY, TILE_SIZE, TILE_SIZE, myColor2);
            } else if (Map[y][x] != 1 && Map[y][x] != 9) {
                DrawRectangle(posX, posY, TILE_SIZE, TILE_SIZE, myColor1);
            } else if (Map[y][x] == 9) {
                DrawRectangle(posX, posY, TILE_SIZE,TILE_SIZE,BLACK);
            }
            if (Map[y][x] == 2) {
                DrawCircle(posX + 12.5, posY + 12.5, 4, yellow);
            }
            if (Map[y][x] == 3) {
                DrawTextureEx(cherry, pos, 0.0f, 2.0f, WHITE);
            }
            if (Map[y][x] == 4) {
                DrawTextureEx(apple, pos, 0.0f, 1.0f, WHITE);
            }
            if (Map[y][x] == 5) {
                DrawTextureEx(mushroom, pos, 0.0f, 2.0f, WHITE);
            }
            if (Map[y][x] == 6) {
                DrawTextureEx(pepper, pos, 0.0f, 1.8f, WHITE);
            }
        }
    }
    //---------------------------------------------------------------------------------
    //---------------------------------------------------------------------------------
    // drawing characters
    if (pacman.isMouthOpen) {
        DrawTexture(pacmanOpen, pacman.x, pacman.y,WHITE);
    } else {
        DrawTexture(pacmanClose, pacman.x, pacman.y,WHITE);
    }
    DrawTexture(ghost11, ghost1.x, ghost1.y,WHITE);
    DrawTexture(ghost12, ghost2.x, ghost2.y,WHITE);
    DrawTexture(ghost13, ghost3.x, ghost3.y,WHITE);
    DrawTexture(ghost14, ghost4.x, ghost4.y,WHITE);
    DrawTexture(ghost15, ghost5.x, ghost5.y,WHITE);
}

static void UpdatePlayer(void) {
    pacman.frameCounter++;
    if (pacman.frameCounter >= 10) {
        pacman.isMouthOpen = !pacman.isMouthOpen;
        pacman.frameCounter = 0;
    }

    if (IsKeyPressed(KEY_UP)) {
        pacman.dy = -1;
        pacman.dx = 0;
    } else if (IsKeyPressed(KEY_DOWN)) {
        pacman.dy = 1;
        pacman.dx = 0;
    } else if (IsKeyPressed(KEY_LEFT)) {
        pacman.dx = -1;
        pacman.dy = 0;
    } else if (IsKeyPressed(KEY_RIGHT)) {
        pacman.dx = 1;
        pacman.dy = 0;
    }

    MovePacman(&pacman);
}


void UpdateGameplayScreen(void) {
    UpdatePlayer();
}


void UnloadGameplayScreen(void) {
    // آزادسازی منابع در صورت نیاز
}

bool FinishGameplayScreen(void) {
    return false; // منطق اتمام بازی را اضافه کنید
}
