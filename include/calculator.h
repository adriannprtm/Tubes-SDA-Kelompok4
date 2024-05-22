#ifndef CALCULATOR_H
#define CALCULATOR_H
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>


void gotoxy(int x, int y);
//Menu utama dari kalculator 
void TampilanMainMenu();
//Menu utama dari fitur kalkulator ilmiah
void TampilanKalkulator();
//Menampilkan tampilan untuk menginputkan ekspresi matematika
void TampilanBatasanProgram(); 
//Menampilkan batasan program kalkulator
void runCalc();
//Untuk memilih menu kalkulator yang diinginkan
void aboutCalculator();
//Menampilkan cara penggunaan calculator
#endif