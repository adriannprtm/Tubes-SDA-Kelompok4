#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include "temperature.h"

void mainMenu(){
	int cursorY;
	int Choose;
	TampilanKonversiSuhu();
	
	cursorY = 6;
	do{
		gotoxy(3,6); printf(" ");
		gotoxy(3,6); scanf("%d", &Choose);
		gotoxy(31,cursorY);printf("|             |            |                |            |\n");
		gotoxy(31,cursorY+1);printf("+-------------+------------+----------------+------------+\n");
		switch(Choose){
			case 1 : countCelcius(cursorY); break;
			case 2 : countReamur(cursorY);break;
			case 3 : countFahrenheit(cursorY); break;
			case 4 : countKelvin(cursorY);break;
			case 99 : Choose = 99; break;
			default : printf("Pilihan Salah\n"); cursorY -=2;
		}
		cursorY += 2;
	}while(Choose != 99);
}

void countCelcius(int CursorY){
	float c, r, f, k;
	gotoxy(38,CursorY); scanf("%f", &c);
    fflush(stdin);
    r = c*4/5;
    f = (c*9/5)+32;
    k = c+273.16;
    gotoxy(49, CursorY);printf("%.2f", r);
    gotoxy(64, CursorY);printf("%.2f", f);
    gotoxy(79, CursorY);printf("%.2f",k);
}

void countReamur(int CursorY){
	float c, r, f, k;
	gotoxy(51, CursorY);
	scanf("%f",&r);
    fflush(stdin);
    c = r*5/4;
    f = (r*9/4)+32;
    k = (r*5/4)+273.16;
    gotoxy(36,CursorY);printf("%.2f", c);
    gotoxy(64, CursorY);printf("%.2f", f);
    gotoxy(79, CursorY);printf("%.2f", k);
}

void countFahrenheit(int CursorY){
	float c, r, f, k;
	gotoxy(65, CursorY);
    scanf("%f", &f);
    fflush(stdin);
    c = (f*5/9)-32;
    r = (f*4/9)-32;
    k = (f-32)*5/9+273.16;
    gotoxy(36,CursorY);printf("%.2f",c);
    gotoxy(49, CursorY);printf("%.2f",r);
    gotoxy(79,CursorY);printf("%.2f",k);
}

void countKelvin(int CursorY){
	float c, r, f, k;
    gotoxy(79,CursorY);
	scanf("%f", &k);
    fflush(stdin);
    c = k-273.16;
    r = (k-273.16)*4/5;
    f = (k-273.16)*9/5+32;
    gotoxy(36,CursorY);printf("%.2f",c);
    gotoxy(49, CursorY);printf("%.2f",r);
    gotoxy(63, CursorY);printf("%.2f",f);
}