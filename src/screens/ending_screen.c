#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <raylib.h>
#include <string.h>
#include "screen.h"

char name1[30];
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

    FILE *file1 = fopen("output.bin", "ab");

    // بررسی موفقیت در باز کردن فایل
    if (file1 == NULL) {
        perror("Error opening file");
        return;
    }

    // نوشتن اطلاعات به فایل به صورت باینری
    size_t nameLength = strlen(name1) + 1; // به همراه \0
    size_t timeLength = strlen(timeString) + 1; // به همراه \0

    // نوشتن نام
    fwrite(&nameLength, sizeof(size_t), 1, file1); // طول نام
    fwrite(name1, sizeof(char), nameLength, file1); // خود نام

    // نوشتن امتیاز
    fwrite(&score, sizeof(int), 1, file1);

    // نوشتن زمان
    fwrite(&timeLength, sizeof(size_t), 1, file1); // طول رشته زمان
    fwrite(timeString, sizeof(char), timeLength, file1); // خود زمان

    // بستن فایل
    fclose(file1);
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

    DrawText("< Ending Board >", 200, 30, 70,LIGHTGRAY);

    strftime(timeString, sizeof(timeString), "%Y-%m-%d  %H:%M:%S", timeInfo);

    char recordText[128];
    snprintf(recordText, sizeof(recordText), "Score : %d, Date and Time: %s", score, timeString);
    DrawText(recordText, 50, 280, 30, YELLOW);
    DrawText(name1, 50, 200, 40, YELLOW);

    DrawText("Press ENTER to return", 70, 520, 30,GRAY);
}

void UnloadEndingScreen(void) {
    // آزادسازی منابع استفاده‌شده در صفحه امتیاز
}

bool FinishEndingScreen(void) {
    return isScreenFinished;
}
