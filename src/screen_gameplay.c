#include <raylib.h>
#include <stdio.h>
#include <stdlib.h>
#include<stdbool.h>
#include <time.h>
#include "screen.h"

static int finalScore = 0;
#define ROWS 24
#define COLS 32
#define TILE_SIZE 30
#define mapWidth 960
#define mapHeight 720
//==========================================================================
bool isCherryEaten = false;
time_t cherryTimeStart;
bool isPepperEaten = false;
time_t pepperTimeStart;
int remainingFoods = 10;
time_t lastCollisionTime = 0;

//==========================================================================
bool isGameOver;
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
    int score;
    int speed;
} Pacman;

typedef struct {
    int x;
    int y;
    int dx;
    int dy;
    int frameCounter;
    bool isVisible;
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
    int nextX = (pacman->x + pacman->dx);
    int nextY = (pacman->y + pacman->dy);


    if (nextX >= 0 && nextX < COLS && nextY >= 0 && nextY < ROWS) {
        if (Map[nextY][nextX] != 1) {
            pacman->x += pacman->dx;
            pacman->y += pacman->dy;
        }
    }
    pacman->dx = 0;
    pacman->dy = 0;
}

void MoveGhost(Ghost *ghost, int map[ROWS][COLS]) {
    ghost->frameCounter++;


    if (ghost->frameCounter >= 17) {
        int directions[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};


        int directionIndex = GetRandomValue(0, 3);
        int newDx = directions[directionIndex][0];
        int newDy = directions[directionIndex][1];


        int nextX = ghost->x + newDx;
        int nextY = ghost->y + newDy;


        if (nextX >= 0 && nextX < COLS && nextY >= 0 && nextY < ROWS) {
            if (map[nextY][nextX] != 1) {
                ghost->x += newDx;
                ghost->y += newDy;
            }
        }

        ghost->frameCounter = 0;
    }
}

void checkFoods(Pacman *pacman) {
    if (Map[pacman->y][pacman->x] == 2) {
        pacman->score += 10;
        Map[pacman->y][pacman->x] = 0;
        remainingFoods--;
        if (remainingFoods == 0) {
            remainingFoods = 10;
            placeRandomFoods(10, 2);
        }
    } else if (Map[pacman->y][pacman->x] == 3) {
        isCherryEaten = true;
        cherryTimeStart = time(NULL);
        Map[pacman->y][pacman->x] = 0;
        pacman->isMouthOpen = true;
    } else if (Map[pacman->y][pacman->x] == 4) {
        pacman->lives++;
        Map[pacman->y][pacman->x] = 0;
    } else if (Map[pacman->y][pacman->x] == 5) {
        pacman->lives--;
        Map[pacman->y][pacman->x] = 0;
    } else if (Map[pacman->y][pacman->x] == 6) {
        pacman->speed++;
        Map[pacman->y][pacman->x] = 0;
        isPepperEaten = true;
        pepperTimeStart = time(NULL);
    }
}

void updateCherryMode(Pacman *pacman) {
    if (isCherryEaten) {
        time_t currentTime = time(NULL);
        if (difftime(currentTime, cherryTimeStart) >= 10) {
            isCherryEaten = false; //
            pacman->isMouthOpen = false; //
        } else {
            pacman->isMouthOpen = true; //
        }
    }
}

void updatePepperMode(Pacman *pacman) {
    if (isPepperEaten) {
        time_t currentTime = time(NULL);
        if (difftime(currentTime, pepperTimeStart) >= 10) {
            isPepperEaten = false;
            pacman->speed--;
        }
    }
}

//================================================================================================
void logicOfTheGame(Pacman *pacman, Ghost *ghost1, Ghost *ghost2, Ghost *ghost3, Ghost *ghost4, Ghost *ghost5) {
    time_t currentTime = time(NULL);
    if (isCherryEaten) {
        if (ghost1->isVisible && ghost1->x == pacman->x && ghost1->y == pacman->y) {
            ghost1->isVisible = false;
            pacman->score += 50;
        }
        if (ghost2->isVisible && ghost2->x == pacman->x && ghost2->y == pacman->y) {
            ghost2->isVisible = false;
            pacman->score += 50;
        }
        if (ghost3->isVisible && ghost3->x == pacman->x && ghost3->y == pacman->y) {
            ghost3->isVisible = false;
            pacman->score += 50;
        }
        if (ghost4->isVisible && ghost4->x == pacman->x && ghost4->y == pacman->y) {
            ghost4->isVisible = false;
            pacman->score += 50;
        }
        if (ghost5->isVisible && ghost5->x == pacman->x && ghost5->y == pacman->y) {
            ghost5->isVisible = false;
            pacman->score += 50;
        }
    } else {
        if (difftime(currentTime, lastCollisionTime) >= 1) {
            if ((pacman->x == ghost1->x && pacman->y == ghost1->y && ghost1->isVisible) ||
                (pacman->x == ghost2->x && pacman->y == ghost2->y && ghost2->isVisible) ||
                (pacman->x == ghost3->x && pacman->y == ghost3->y && ghost3->isVisible) ||
                (pacman->x == ghost4->x && pacman->y == ghost4->y && ghost4->isVisible) ||
                (pacman->x == ghost5->x && pacman->y == ghost5->y && ghost5->isVisible)) {
                pacman->lives--;
                lastCollisionTime = currentTime;
            }

            ghost1->isVisible = true;
            ghost2->isVisible = true;
            ghost3->isVisible = true;
            ghost4->isVisible = true;
            ghost5->isVisible = true;
        }
    }
}


void checkGameOver(Pacman *pacman) {
    if (pacman->lives <= 0) {
        AddRecord(pacman->score);

        isGameOver = true;
    }
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

    pacmanRandomlocation(Map, &pacman);
    pacman.dx = 0;
    pacman.dy = 0;
    pacman.lives = 3;
    pacman.isMouthOpen = true;
    pacman.frameCounter = 0;
    pacman.score = 0;
    pacman.speed = 0;
    // initializing ghosts

    ghostRandomlocation(Map, &ghost1);
    ghost1.dx = 0;
    ghost1.dy = 0;


    ghostRandomlocation(Map, &ghost2);
    ghost2.dx = 0;
    ghost2.dy = 0;

    ghostRandomlocation(Map, &ghost3);
    ghost3.dx = 0;
    ghost3.dy = 0;

    ghostRandomlocation(Map, &ghost4);
    ghost4.dx = 0;
    ghost4.dy = 0;

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
                DrawCircle(posX + 15, posY + 15, 8, yellow);
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

    char scoreText[50];
    char livesText[30];
    sprintf(scoreText, "Your Score: %d", pacman.score);
    DrawText(scoreText, 100, 690, 20, LIGHTGRAY);
    sprintf(livesText, "Your Score: %d", pacman.score);
    DrawText(scoreText, 100, 690, 20, LIGHTGRAY);

    //---------------------------------------------------------------------------------
    //---------------------------------------------------------------------------------
    // drawing characters
    if (!pacman.isMouthOpen) {
        DrawTexture(pacmanOpen, pacman.x * TILE_SIZE, pacman.y * TILE_SIZE,WHITE);
    } else {
        DrawTexture(pacmanClose, pacman.x * TILE_SIZE, pacman.y * TILE_SIZE,WHITE);
    }
    if (ghost1.isVisible) {
        DrawTexture(ghost11, ghost1.x * TILE_SIZE, ghost1.y * TILE_SIZE, WHITE);
    }
    if (ghost2.isVisible) {
        DrawTexture(ghost12, ghost2.x * TILE_SIZE, ghost2.y * TILE_SIZE, WHITE);
    }
    if (ghost3.isVisible) {
        DrawTexture(ghost13, ghost3.x * TILE_SIZE, ghost3.y * TILE_SIZE, WHITE);
    }
    if (ghost4.isVisible) {
        DrawTexture(ghost14, ghost4.x * TILE_SIZE, ghost4.y * TILE_SIZE, WHITE);
    }
    if (ghost5.isVisible) {
        DrawTexture(ghost15, ghost5.x * TILE_SIZE, ghost5.y * TILE_SIZE, WHITE);
    }
}

static void UpdatePlayer(void) {
    if (!isCherryEaten) {
        pacman.frameCounter++;
        if (pacman.frameCounter >= 10) {
            pacman.isMouthOpen = !pacman.isMouthOpen;
            pacman.frameCounter = 0;
        }
    }

    if (IsKeyPressed(KEY_UP)) {
        pacman.dy = -1 - pacman.speed;
        pacman.dx = 0;
    } else if (IsKeyPressed(KEY_DOWN)) {
        pacman.dy = 1 + pacman.speed;
        pacman.dx = 0;
    } else if (IsKeyPressed(KEY_LEFT)) {
        pacman.dx = -1 - pacman.speed;
        pacman.dy = 0;
    } else if (IsKeyPressed(KEY_RIGHT)) {
        pacman.dx = 1 + pacman.speed;
        pacman.dy = 0;
    }
    MovePacman(&pacman);
}

void UpdateGameplayScreen(void) {
    if (!isGameOver) {
        UpdatePlayer();
        MoveGhost(&ghost1, Map);
        MoveGhost(&ghost2, Map);
        MoveGhost(&ghost3, Map);
        MoveGhost(&ghost4, Map);
        MoveGhost(&ghost5, Map);
        checkFoods(&pacman);
        updateCherryMode(&pacman);
        updatePepperMode(&pacman);
        logicOfTheGame(&pacman, &ghost1, &ghost2, &ghost3, &ghost4, &ghost5);
        checkGameOver(&pacman);
    }
}


void UnloadGameplayScreen(void) {
    UnloadTexture(pacmanOpen);
    UnloadTexture(pacmanClose);
    UnloadTexture(ghost11);
    UnloadTexture(ghost12);
    UnloadTexture(ghost13);
    UnloadTexture(ghost14);
    UnloadTexture(ghost15);
    // UnloadSound(eatSound);
    // UnloadSound(ghostEatenSound);
}

bool FinishGameplayScreen(void) {
    if (IsKeyPressed(KEY_ESCAPE)) {
        AddRecord(pacman.score);
        return true;
    }
    return isGameOver;
}
