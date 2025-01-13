//
// Created by Aras Computer on 1/13/2025.
//
#define NOMINMAX
#define WIN32_LEAN_AND_MEAN
#include<raylib.h>
#include "menu.h"


#define TILE_SIZE 25
#define  GRID_WIDTH 40
#define  GRID_HEIGHT 28


int main()
{
    InitWindow(GRID_WIDTH, GRID_HEIGHT, " menu");
    Texture2D background = LoadTexture("background.png");
    GameState currentState = MENU;
    int selectedItem = 0;

    const int SCREEN_WIDTH = 1000;
    const int SCREEN_HEIGHT = 700;

    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "GameMap");
    int pacmanX = TILE_SIZE, pacmanY = TILE_SIZE;
    int pacmanSpeed = 5;


    Texture2D pacmanTexture = LoadTexture("C:/Users/Aras Computer/Desktop/bp/tools/pacman4.png");


    int map[28][40]={
        {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
        {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
        {1,0,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,0,1,1,1,1,1},
        {1,0,1,0,0,0,0,0,0,0,0,1,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,0,0,1,0,1,1,0,1,1,0,1,1},
        {1,0,1,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,1,0,0,1,1,1,1,0,1,1,1,1,1},
        {1,0,1,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,1,0,0,1,0,1,1,1,1,1,0,1,1},
        {1,0,1,0,0,1,1,1,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,1},
        {1,0,0,0,0,1,0,0,0,0,0,0,0,0,0,1,0,0,1,0,0,0,1,1,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,1},
        {1,0,0,0,0,1,0,0,0,1,0,0,0,0,0,1,0,0,0,0,0,0,0,1,0,0,0,1,0,0,0,0,0,0,0,0,1,0,0,1},
        {1,0,0,0,1,1,0,0,0,1,0,0,0,0,0,1,0,0,0,0,0,0,0,1,0,0,0,1,0,1,1,1,1,1,0,0,1,0,0,1},
        {1,0,0,0,0,1,0,0,0,1,0,0,0,1,1,1,1,1,1,1,1,1,1,1,0,0,0,1,0,1,0,0,0,1,0,0,1,1,0,1},
        {1,0,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,1,0,0,0,1,0,0,0,1,0,1},
        {1,0,1,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,0,0,0,1,0,1,0,0,0,1,0,0,0,1,0,1},
        {1,0,1,0,0,0,0,0,0,0,0,0,1,0,0,1,0,0,0,0,0,0,0,1,0,0,0,1,0,1,0,0,0,1,1,1,1,1,0,1},
        {1,0,1,0,0,0,0,0,0,0,0,0,1,0,0,1,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,1},
        {1,0,1,0,0,1,1,1,1,1,1,1,1,0,0,1,1,1,0,0,0,1,0,1,0,0,0,0,0,0,0,1,0,0,0,1,0,0,0,1},
        {1,0,1,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,1,0,0,0,0,1,0,0,0,1,0,0,0,1},
        {1,0,1,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,1,1,1,1,1,1,0,0,0,1,0,0,0,1},
        {1,0,1,1,1,1,0,0,1,0,0,1,1,1,1,1,1,1,1,0,0,1,0,0,0,0,0,0,0,0,0,1,0,0,0,1,0,0,0,1},
        {1,0,1,0,0,0,0,0,1,0,0,1,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,1,0,0,0,1,0,0,0,1},
        {1,0,1,0,0,0,0,0,1,0,0,1,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,0,0,0,1,0,0,0,1},
        {1,0,1,0,0,1,1,1,1,0,0,1,0,0,0,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,1},
        {1,0,1,0,0,1,0,0,0,0,0,1,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,1},
        {1,0,1,0,0,1,0,0,0,0,0,1,0,0,0,1,0,0,0,0,0,1,1,1,1,1,1,1,1,0,0,0,1,1,1,1,0,0,0,1},
        {1,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,1,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,1},
        {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,1,1,1,0,0,0,0,1},
        {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
        {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}
    };
    SetTargetFPS(60);

    Color myColor1 = (Color){0,0,90,255};
    Color myColor2 = (Color){173,216,230,255};
    Color yellow = (Color){204,204,0,255};
// Main loop of the game
    while (!WindowShouldClose())
    {while (!WindowShouldClose()) {
        // مدیریت حالت‌ها
        if (currentState == MENU) {
            HandleMenuInput(&selectedItem, &currentState); // مدیریت ورودی
        } else if (currentState == GAME || currentState == SCORE) {
            if (IsKeyPressed(KEY_ESCAPE)) currentState = MENU; // بازگشت به منو
        } else if (currentState == EXIT) {
            break; // خروج
        }

        // رسم حالت‌ها
        if (currentState == MENU) {
            DrawMenu(selectedItem, background);
        } else if (currentState == GAME) {
            BeginDrawing();
            ClearBackground(DARKGRAY);
            DrawText("Game Started! Press ESC to return to menu.", 100, 200, 20, RAYWHITE);
            EndDrawing();
        } else if (currentState == SCORE) {
            BeginDrawing();
            ClearBackground(DARKGRAY);
            DrawText("Score Screen! Press ESC to return to menu.", 100, 200, 20, RAYWHITE);
            EndDrawing();
        }
    }

        UnloadTexture(background);
        CloseWindow();
        return 0;
    }
        //pacman location
        int gridX = (pacmanX / TILE_SIZE);
        int gridY = (pacmanY / TILE_SIZE);

        // input limitation and movement
        if(IsKeyDown(KEY_UP) && gridY > 0 && map[gridY-1][gridX] == 0)
        {
            pacmanY-= pacmanSpeed;
        }
        if(IsKeyDown(KEY_DOWN) && gridY < GRID_HEIGHT - 1 && map[gridY + 1][gridX] == 0)
        {
            pacmanY+= pacmanSpeed;
        }
        if(IsKeyDown(KEY_LEFT) && gridX > 0 && map[gridY][gridX -1] == 0)
        {
            pacmanX-= pacmanSpeed;
        }
        if(IsKeyDown(KEY_RIGHT) && gridX < GRID_WIDTH - 1 && map[gridY][gridX +1] == 0)
        {
            pacmanX+= pacmanSpeed;
        }

        BeginDrawing();
        ClearBackground(BLACK);

        for( int y = 0; y < GRID_HEIGHT; y++)
        {
            for( int x = 0; x < GRID_WIDTH; x++)
            {
                if(map[y][x] == 1)
                {
                    DrawRectangle(x*TILE_SIZE,y*TILE_SIZE,TILE_SIZE,TILE_SIZE,myColor2);
                }
                else
                {
                    DrawRectangle(x*TILE_SIZE,y*TILE_SIZE,TILE_SIZE,TILE_SIZE,myColor1);
                }
                if(map[y][x] == 0)
                {
                    DrawCircle(x*TILE_SIZE+12.5,y*TILE_SIZE + 12.5,2,yellow);
                }
            }
        }
        // Draw pacman
        DrawTextureEx(pacmanTexture,(Vector2){pacmanX +12/5,pacmanY +12/5},0.0f,0.08f,WHITE);

        EndDrawing();
    }
    UnloadTexture(pacmanTexture);
    CloseWindow();
}





