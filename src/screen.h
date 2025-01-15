

#ifndef SCREEN_H
#define SCREEN_H
#include<time.h>

typedef enum GameScreen { MENU, SCORE, GAMEPLAY, ENDING } GameScreen;
void AddRecord(int score);
#define MAX_NAME_LENGTH 50
#define MAX_RECORDS 10

typedef struct {
    char playerName[MAX_NAME_LENGTH];
    int score;
    time_t time;
} ScoreRecord;

//--------------------------------------------------------------------------------
// Logo Screen Functions Declaration
//----------------------------------------------------------------------------------
// void InitLogoScreen(void);
// void UpdateLogoScreen(void);
// void DrawLogoScreen(void);
// void UnloadLogoScreen(void);
// int FinishLogoScreen(void);

//----------------------------------------------------------------------------------
// Menu Screen Functions Declaration
//----------------------------------------------------------------------------------
void InitMenuScreen(void);
void UpdateMenuScreen(void);
void DrawMenuScreen(void);
void UnloadMenuScreen(void);
int  FinishMenuScreen(void);

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
bool  FinishGameplayScreen(void);

//----------------------------------------------------------------------------------
// Ending Screen Functions Declaration
//----------------------------------------------------------------------------------
void InitEndingScreen(void);
void UpdateEndingScreen(void);
void DrawEndingScreen(void);
void UnloadEndingScreen(void);
int  FinishEndingScreen(void);
//----------------------------------------------------------------------------------
// Functions for inputs
//----------------------------------------------------------------------------------


#endif // SCREEN_H
