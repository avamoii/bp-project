#include <stdio.h>
#include <stdlib.h>
#include <raylib.h>
#include "screen.h"
#include <string.h>

#define MAX_RECORDS 10

bool IsScoreScreenFinished = false;

typedef struct {
    char name[50];
    int score;
    char timeString[64];
} ScoreRecord;

int recordIndex = 0;
ScoreRecord records[MAX_RECORDS];

void readInfo(void) {
    // باز کردن فایل باینری برای خواندن اطلاعات
    FILE *file = fopen("output.bin", "rb");

    if (file == NULL) {
        perror("Error opening file");
        return;
    }


    while (!feof(file) && recordIndex < MAX_RECORDS) {
        size_t nameLength, timeLength;
        char name[50], timeString[64];
        int score;

        // خواندن نام
        if (fread(&nameLength, sizeof(size_t), 1, file) != 1) break;
        if (fread(name, sizeof(char), nameLength, file) != nameLength) break;

        // خواندن امتیاز
        if (fread(&score, sizeof(int), 1, file) != 1) break;

        // خواندن زمان
        if (fread(&timeLength, 20, 1, file) != 1) break;
        if (fread(timeString, sizeof(char), timeLength, file) != timeLength) break;

        strcpy(records[recordIndex].name, name);
        strcpy(records[recordIndex].timeString, timeString);
        records[recordIndex].score = score;

        recordIndex++;
    }

    fclose(file);
}


void InitScoreScreen(void) {
    recordIndex = 0;
    readInfo();
}

void UpdateScoreScreen(void) {
    if (IsKeyPressed(KEY_ENTER)) {
        IsScoreScreenFinished = true;
    }
}

void DrawScoreScreen(void) {
    ClearBackground(RAYWHITE);

    for (int i = 0; i < recordIndex; i++) {
        char recordText[128];
        snprintf(recordText, sizeof(recordText), "Score : %d, Date and Time: %s", records[i].score, records[i].timeString);
        DrawText(recordText, 50, 120, 20, YELLOW);
        DrawText(records[i].name, 50, 400, 20, YELLOW);
    }
}

void UnloadScoreScreen(void) {
}

bool FinishScoreScreen(void) {
    return IsScoreScreenFinished;
}
