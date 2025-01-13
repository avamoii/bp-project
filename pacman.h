
#ifndef PACMAN_H
#define PACMAN_H

#include <raylib.h>


typedef struct Pacman {
    Vector2 position;
    float speed;
    int frameCounter;
    Texture2D openTexture;
    Texture2D closedTexture;
} Pacman;


void InitPacman(Pacman *pacman, float startX, float startY, float speed, const char *openPath, const char *closedPath);
void UpdatePacman(Pacman *pacman);
void DrawPacman(Pacman *pacman);
void UnloadPacmanTextures(Pacman *pacman);

#endif // PACMAN_H