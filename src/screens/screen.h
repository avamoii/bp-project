#ifndef SCREEN_H
#define SCREEN_H

typedef enum GameScreen { MENU, SCORE, GAMEPLAY, ENDING, NAME } GameScreen;

void AddRecord(int score);

void AddName(char *name);

#define MAX_RECORDS 10

//----------------------------------------------------------------------------------
// Menu Screen Functions Declaration
//----------------------------------------------------------------------------------
void InitMenuScreen(void);

void UpdateMenuScreen(void);

void DrawMenuScreen(void);

void UnloadMenuScreen(void);

int FinishMenuScreen(void);

//----------------------------------------------------------------------------------
// Name Screen Functions Declaration
//----------------------------------------------------------------------------------
void InitnamePageScreen(void);

void UpdatenamePageScreen(void);

void DrawnamePageScreen(void);

void UnloadnamePageScreen(void);

bool FinishnamePageScreen(void);

//----------------------------------------------------------------------------------
// Score Screen Functions Declaration
//----------------------------------------------------------------------------------
void InitScoreScreen(void);

void UpdateScoreScreen(void);

void DrawScoreScreen(void);

void UnloadScoreScreen(void);

bool FinishScoreScreen(void);

//----------------------------------------------------------------------------------
// Gameplay Screen Functions Declaration
//----------------------------------------------------------------------------------
void InitGameplayScreen(void);

void UpdateGameplayScreen(void);

void DrawGameplayScreen(void);

void UnloadGameplayScreen(void);

bool FinishGameplayScreen(void);

//----------------------------------------------------------------------------------
// Ending Screen Functions Declaration
//----------------------------------------------------------------------------------
void InitEndingScreen(void);

void UpdateEndingScreen(void);

void DrawEndingScreen(void);

void UnloadEndingScreen(void);

bool FinishEndingScreen(void);

#endif // SCREEN_H
