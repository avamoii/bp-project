#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <raylib.h>
#include <string.h>
#include "screen.h"

char name1[15];
int score;
struct tm *timeInfo;
bool isScreenFinished = false;
char timeString[64];

void AddName(char *_name) {
    strcpy(name1, _name);
}

void AddRecord(int _score) {
    score = _score;
}

void saveInformation() {
    // Open the file in append mode to add information without overwriting
    FILE *file = fopen("output.txt", "a");

    printf("Name: %s\n", name1);
    printf("Score: %d\n", score);
    printf("%s\n", timeString);
    printf("----------------------\n"); // Separator for readability

    // Check if the file opened successfully
    if (file == NULL) {
        perror("Error opening file");
        return;
    }

    // Write the information to the file
    fprintf(file, "Name: %s\n", name1);
    fprintf(file, "Score: %d\n", score);
    fprintf(file, "%s\n", timeString);
    fprintf(file, "----------------------\n"); // Separator for readability

    // Close the file
    fclose(file);
}

void InitEndingScreen(void) {
    //background = LoadTexture("../assets/background2.png");
    timeInfo = localtime(&(time_t){time(NULL)});
}

void UpdateEndingScreen(void) {
    if (IsKeyPressed(KEY_ENTER)) {
        saveInformation();
        isScreenFinished = true;
    }
}

void DrawEndingScreen(void) {
    Color myColor1 = (Color){0, 0, 90, 255};
    ClearBackground(myColor1);
    //DrawTexture(background, 0, 0, WHITE);

    DrawText("Ending Board", 200, 20, 70,LIGHTGRAY);

    strftime(timeString, sizeof(timeString), " %Y-%m-%d  %H:%M:%S ", timeInfo);

    char recordText[128];
    snprintf(recordText, sizeof(recordText), "Score : %d, Date and Time: %s", score, timeString);
    DrawText(recordText, 50, 120, 20, YELLOW);
    DrawText(name1, 50, 400, 20, YELLOW);

    DrawText("Press ENTER to return", 70, 520, 25,DARKPURPLE);
    DrawText("Press C to clear all records", 70, 550, 25,DARKPURPLE);
}

void UnloadEndingScreen(void) {
    // آزادسازی منابع استفاده‌شده در صفحه امتیاز
}

bool FinishEndingScreen(void) {
    return isScreenFinished;
}
