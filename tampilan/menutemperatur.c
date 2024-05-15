#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
//#include <gotoxy.c>
#include "TampilanMainMenu.c"
#include "temperature.c"

int main(){
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
	return 0;
}