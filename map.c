
#include "raylib.h"
#include "map.h"


void displayMap() {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {

            int x = j * TILE_SIZE;
            int y = i * TILE_SIZE;


            Color color = (gameMap[i][j] == 1) ? DARKGRAY : WHITE;


            DrawRectangle(x, y, TILE_SIZE, TILE_SIZE, color);


            DrawRectangleLines(x, y, TILE_SIZE, TILE_SIZE, LIGHTGRAY);
        }
    }
}