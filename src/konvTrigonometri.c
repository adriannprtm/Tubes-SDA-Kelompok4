#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "../include/calculator.h"
#include "../include/konvTrigonometri.h"

void TampilanKonversiTrigonometri() {
    printf("Konversi Trigonometri\n");
    printf("Masukkan derajat (ketik 99 untuk kembali ke Main Menu): ");
    gotoxy(31, 3); printf("+-------------+-------------+-------------+\n");
    gotoxy(31, 4); printf("|     Sin     |     Cos     |     Tan     |\n");
    gotoxy(31, 5); printf("+-------------+-------------+-------------+\n");
}

void mainMenuTrigonometri() {
    int cursorY;
    double degree;

    system("cls");
    TampilanKonversiTrigonometri();

    cursorY = 6;
    do {
        gotoxy(3, 2); printf(" ");
        gotoxy(3, 2); scanf("%lf", &degree); fflush(stdin);

        gotoxy(31, cursorY); printf("|             |             |             |\n");
        gotoxy(31, cursorY + 1); printf("+-------------+-------------+-------------+\n");

        countTrigonometri(degree, cursorY);

        cursorY += 2;
    } while (degree != 99);
    system("cls");
}

void countTrigonometri(double degree, int cursorY) {
    double rad = degree * M_PI / 180.0;
    double sinValue = sin(rad);
    double cosValue = cos(rad);
    double tanValue = tan(rad);

    gotoxy(38, cursorY); printf("%.2f", sinValue);
    gotoxy(51, cursorY); printf("%.2f", cosValue);
    gotoxy(64, cursorY); printf("%.2f", tanValue);
}
