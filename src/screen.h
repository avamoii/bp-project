

#ifndef SCREEN_H
#define SCREEN_H
typedef enum GameScreen { MENU, SCORE, GAMEPLAY, ENDING } GameScreen;

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
int FinishMenuScreen(void);

//----------------------------------------------------------------------------------
// Score Screen Functions Declaration
//----------------------------------------------------------------------------------
void InitScoreScreen(void);
void UpdateScoreScreen(void);
void DrawScoreScreen(void);
void UnloadScoreScreen(void);
int FinishScoreScreen(void);

//----------------------------------------------------------------------------------
// Gameplay Screen Functions Declaration
//----------------------------------------------------------------------------------
void InitGameplayScreen(void);
void UpdateGameplayScreen(void);
void DrawGameplayScreen(void);
void UnloadGameplayScreen(void);
int FinishGameplayScreen(void);

//----------------------------------------------------------------------------------
// Ending Screen Functions Declaration
//----------------------------------------------------------------------------------
void InitEndingScreen(void);
void UpdateEndingScreen(void);
void DrawEndingScreen(void);
void UnloadEndingScreen(void);
int FinishEndingScreen(void);


#endif // SCREEN_H
