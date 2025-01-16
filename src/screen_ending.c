#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <raylib.h>
#include <string.h>

#include "screen.h"
#define MAX_RECORDS 10

//Texture2D background;
void saveInformation() {
    // Open the file in append mode to add information without overwriting
    FILE *file = fopen("output.txt", "a");

    // Check if the file opened successfully
    if (file == NULL) {
        perror("Error opening file");
        return;
    }

    // Write the information to the file
    fprintf(file, "Name: %s\n", name);
    fprintf(file, "Score: %d\n", score);
    fprintf(file, "Time: %.2f seconds\n", time);
    fprintf(file, "Data: %s\n", data);
    fprintf(file, "----------------------\n"); // Separator for readability

    // Close the file
    fclose(file);
}

char name1 [15];
void AddName(char *name)
{
    strcpy(name1, name);
}
int recordCount =0;
ScoreRecord records[MAX_RECORDS];

void AddRecord(int score)
{
    if (recordCount < MAX_RECORDS) {
        records[recordCount].score = score;
        records[recordCount].time = time(NULL);
        recordCount++;
    } else {

        int minIndex = 0;
        for (int i = 1; i < MAX_RECORDS; i++) {
            if (records[i].score < records[minIndex].score) {
                minIndex = i;
            }
        }
        if (score > records[minIndex].score) {
            records[minIndex].score = score;
            records[minIndex].time = time(NULL);
        }
    }
}
void ClearRecords(void) {
    for (int i = 0; i < MAX_RECORDS; i++) {
        records[i].score = 0;
        records[i].time = 0;
    }
    recordCount = 0;
}

void InitEndingScreen(void) {
  //background = LoadTexture("../assets/background2.png");
    struct tm *timeInfo = localtime(&records[i].time);
}

void UpdateEndingScreen(void) {
    if (IsKeyPressed(KEY_C)) {
        ClearRecords();
    }
}

void DrawEndingScreen(void) {
    Color myColor1 = (Color){0, 0, 90, 255};
    ClearBackground(myColor1);
    //DrawTexture(background, 0, 0, WHITE);


    DrawText("Ending Board", 200, 20, 70,LIGHTGRAY);

    for (int i = 0; i < recordCount; i++) {
        char buffer[64];

        strftime(buffer, sizeof(buffer), " %Y-%m-%d  %H:%M:%S ", timeInfo);

        char recordText[128];
        snprintf(recordText, sizeof(recordText), "%d. Score : %d, Date and Time: %s", i + 1, records[i].score, buffer);
        DrawText(recordText, 50, 120, 20, YELLOW);
        DrawText(name1, 50, 400, 20, YELLOW);

    }

    DrawText("Press ENTER to return", 70, 520, 25,DARKPURPLE);
    DrawText("Press C to clear all records", 70, 550,25 ,DARKPURPLE);
}

void UnloadEndingScreen(void) {
    // آزادسازی منابع استفاده‌شده در صفحه امتیاز
}
bool FinishEndingScreen(void) {
    if (IsKeyPressed(KEY_ENTER))
    {
        return true;
    }
    return false;
}