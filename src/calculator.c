#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include "../include/tree.h"
#include "../include/temperature.h"
#include "../include/calculator.h"
#include <stdbool.h>
#include <windows.h>
#include <conio.h>

void gotoxy(int x, int y){
 	COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}
void TampilanMainMenu(){
	wchar_t* copyright = L"© Copyright all rights reserved";
    HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
    gotoxy(45,28); WriteConsoleW(handle, copyright, wcslen(copyright), NULL, NULL);
    gotoxy(27,23); printf("Original Works By");
    gotoxy(23,24); printf("Dafa Nurul Fauziansyah &");
    gotoxy(25,25); printf("Hanri Fajar Ramadhan");
    gotoxy(71,23); printf("Modified By Kelompok Yaudahh 1B");
    gotoxy(72,24); printf("Arnanda Prasatya (221524034)");
    gotoxy(66,25); printf("Jeihan Ilham Kusumawardhana (221524042)");
    gotoxy(65,26); printf("Muhammad Fahri Yuwan Dwi Putra (221524047)");
	gotoxy(24,1);printf("010101   010   01     010101 01  01 01       010   01010101 010101 01010\n");//122 - 74 =
	gotoxy(24,2);printf("01      01 01  01     01     01  01 01      01 01     01    01  01 01  01\n");//61
	gotoxy(24,3);printf("01     0101010 01     01     01  01 01     0101010    01    01  01 01010\n");
	gotoxy(24,4);printf("01     01   01 01     01     01  01 01     01   01    01    01  01 01 01\n");
	gotoxy(24,5);printf("010101 01   01 010101 010101 010101 010101 01   01    01    010101 01  01\n");
	gotoxy(30,7);printf("010101 010101 01 010101 010  01 01010101 01 010101 01 010101\n");
	gotoxy(30,8);printf("01     01     01 01     0101 01    01    01 01     01 01\n");
	gotoxy(30,9);printf("010101 01     01 010101 01 0 01    01    01 010101 01 01\n");
	gotoxy(30,10);printf("    01 01     01 01     01 0101    01    01 01     01 01\n");
	gotoxy(30,11);printf("010101 010101 01 010101 01  010    01    01 01     01 010101\n");
	gotoxy(41,13);printf("1. Calculator                 Choose\n");
	gotoxy(41,14);printf("2. Batasan Program         +----------+    \n");
	gotoxy(41,15);printf("3. Konversi Suhu           |          |\n");
	gotoxy(41,16);printf("4. Cara penggunaan         +----------+\n");
	gotoxy(41,17);printf("5. Exit\n");
}
void TampilanKalkulator(){
	gotoxy(40,3);printf("\033[1;35m _________________________________________\n");
	gotoxy(40,4);printf("|  _____________________________________  |\n");
	gotoxy(40,5);printf("| | \033[0;37mChoose Operator\033[1;35m                     | |\n");
	gotoxy(40,6);printf("| |                                     | |\n");
	gotoxy(40,7);printf("| |_____________________________________| |\n");
	gotoxy(40,8);printf("|  _______   _______   _______   _______  |\n");
	gotoxy(40,9);printf("| |   \033[0;37m(\033[1;35m   | |   \033[0;37m)\033[1;35m   | |   \033[0;37m%%\033[1;35m   | |   \033[0;37m/\033[1;35m   | |\n");
	gotoxy(40,10);printf("| |_______| |_______| |_______| |_______| |\n");
	gotoxy(40,11);printf("|  _______   _______   _______   _______  |\n");
	gotoxy(40,12);printf("| |   \033[0;37m7\033[1;35m   | |   \033[0;37m8\033[1;35m   | |   \033[0;37m9\033[1;35m   | |   \033[0;37m*\033[1;35m   | |\n");
	gotoxy(40,13);printf("| |_______| |_______| |_______| |_______| |\n");
	gotoxy(40,14);printf("|  _______   _______   _______   _______  |\n");
	gotoxy(40,15);printf("| |   \033[0;37m4\033[1;35m   | |   \033[0;37m5\033[1;35m   | |   \033[0;37m6\033[1;35m   | |   \033[0;37m-\033[1;35m   | |\n");
	gotoxy(40,16);printf("| |_______| |_______| |_______| |_______| |\n");
	gotoxy(40,17);printf("|  _______   _______   _______   _______  |\n");
	gotoxy(40,18);printf("| |   \033[0;37m1\033[1;35m   | |   \033[0;37m2\033[1;35m   | |   \033[0;37m3\033[1;35m   | |       | |\n");
	gotoxy(40,19);printf("| |_______| |_______| |_______| |       | |\n");
	gotoxy(40,20);printf("|  _______   _______   _______  |   \033[0;37m+\033[1;35m   | |\n");
	gotoxy(40,21);printf("| |   \033[0;37m.\033[1;35m   | |   \033[0;37m0\033[1;35m   | |   \033[0;37m=\033[1;35m   | |       | |\n");
	gotoxy(40,22);printf("| |_______| |_______| |_______| |_______| |\n");
	gotoxy(40,23);printf("|_________________________________________|\033[0;37m\n");
	gotoxy(40,25);printf("Operasi Yang Dimasukan : ");
	gotoxy(40,26);printf("Infix to Postfix : ");
	gotoxy(40,27); printf("Infix to Prefix  : ");
}
void TampilanBatasanProgram(){
	gotoxy(21,2);printf("\033[1;35m+------------------------------------------------------------------------------+\n");
	gotoxy(21,3);printf("|\033[0;37ma. Dalam program ini kami menggunakan tipe data double.\033[1;35m                       |\n");
	gotoxy(21,4);printf("|\033[0;37mb. User harus menginputkan dengan Angka agar bisa dikalkulasikan.\033[1;35m             |\n");
	gotoxy(21,5);printf("|\033[0;37mc. Sesuai dengan konsep matematika, program yang kita buat tidak bisa\033[1;35m         |\n");
	gotoxy(21,6);printf("|\033[0;37m   menampilkan hasil saat membagi suatu bilangan dengan angka 0.\033[1;35m              |\n");
	gotoxy(21,7);printf("|\033[0;37md. Dalam penginputan ekspresi matematika, operator tidak boleh berhimpitan\033[1;35m    |\n");
	gotoxy(21,8);printf("|\033[0;37m   dengan operator lain,hanya boleh ada tanda negatif untuk menunjukkan \033[1;35m	    |\n");
	gotoxy(21,9);printf("|\033[0;37m   angka negatif.\033[1;35m    							    |\n");
	gotoxy(21,10);printf("|\033[0;37me. Apabila memasukkan ekspresi matematika user tidak boleh menginputkan huruf.\033[1;35m|\n");
	gotoxy(21,11);printf("|\033[0;37mf. Akan menunjukkan error apabila user menginputkan ekspresi matematika dengan\033[1;35m|\n");
	gotoxy(21,12);printf("|\033[0;37m   tanda kurung yang tidak sesuai (kurungnya tidak ditutup atau kelebihan)\033[1;35m    |\n");
	gotoxy(21,13);printf("|\033[0;37mg. Tidak bisa menghitung ekspresi matematika seperti 4(5+20)\033[1;35m                  |\n");
	gotoxy(21,14);printf("|\033[0;37mh. Inputan harus berhimpitan / tidak boleh dipisahkan dengan spasi\033[1;35m            |\n");
	gotoxy(21,15);printf("|\033[0;37mi. Apabila Ingin Menginputkan - (negatif) diawal maka harus diawali dengan ()\033[1;35m |\n");
	gotoxy(21,16);printf("|\033[0;37m   seperti (-20)+10.\033[1;35m                                                          |\n");
	gotoxy(21,17);printf("+------------------------------------------------------------------------------+\033[1;37m\n");
	gotoxy(21,19);system("pause");
}
void aboutCalculator(){
	char rules[255];
	FILE *in=fopen("howto.txt","r");//perintah untuk membuka file dengan mode r / read
	system("cls");
	printf("\n");
    while(!feof(in)){
        fscanf(in,"%[^\n]\n", &rules);fflush(stdin);   
        // %[^\n] artinya kita menyimpan bagian dari string dalam file sampai tanda \n atau newline. 
        // Kita tidak menggunnakan %s karena aturan mengandung spasi
        printf("\033[1;37m%s\n", rules);
    }
	fclose(in);//perintah untuk menutup file yang tadi dibuka
	printf("\nTekan tombol apapun untuk kembali ke menu utama.....");
	getch();
}
void runCalc(){
	short int pil;
	char cobaLagi;
	AppMenu:
	TampilanMainMenu();
	gotoxy(73,15);
	fflush(stdin);
	scanf("%d",&pil);
    fflush(stdin);
    if((pil == 1 || pil == 2 || pil == 3 || pil == 4|| pil ==5)){
		    if(pil==1){
		        char expression[200];
		        displayexpression:
		        system("cls");
		        TampilanKalkulator();
				gotoxy(44,6);scanf("%s",expression);
		        fflush(stdin);
		        if(isValid(expression)){
		        	gotoxy(65,25); printf("%s", expression);
   			        struct calcTree* binaryTree=(struct calcTree *)malloc(sizeof(struct calcTree));
			        binaryTree = createTree(expression,0,strlen(expression)-1);
			        gotoxy(44,5); printf("Result                   ");
			        gotoxy(44,6); printf("                                    \033[0;35m| |\033[0;37m\n");
					gotoxy(44,6); printf("%f",count(binaryTree));
			        gotoxy(59,26); infixToPostfix(binaryTree);
			        gotoxy(59,27);infixToPrefix(binaryTree);
			        gotoxy(40,28);printf("Hasil pembulatan dua angka dibelakang koma : %0.2f",round_double(count(binaryTree),2));
				}else{
					gotoxy(38,2); printf("Ekspresi Matematika Yang Anda Masukkan Salah!!!");
				}
		        tryAgain:
		        gotoxy(44,30);printf("Apakah ingin mencoba lagi ? (Y/N):  ");
		        gotoxy(44+35,30);scanf("%c", &cobaLagi);
		        fflush(stdin);
		        if(cobaLagi =='Y'||cobaLagi=='y'){
		        	system("cls");
		        	pil=0;
		        	goto displayexpression;
				}
				else if(cobaLagi =='N'||cobaLagi=='n'){
					system("cls");
					pil=0;
					goto AppMenu;
				}
				else{
					gotoxy(38,33);
					printf("Maaf, perintah yang Anda masukkan tidak dapat diproses.");
					gotoxy(42,34);
					printf("Mohon untuk memasukkan sesuai dengan instruksi.");
					gotoxy(55,35);
					printf("Terima kasih.");
					pil=0;
					goto tryAgain;
				}
			}
			else if(pil==3){
				mainMenuTemp();
				pil=0;
				goto AppMenu;
			}
			else if(pil==2){
				system("cls");
				TampilanBatasanProgram();
				system("cls");
				pil=0;
				goto AppMenu;
			}
			else if(pil==4){
				aboutCalculator();
				system("cls");
				pil=0;
				goto AppMenu;

			}
			else if(pil==5){
				printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\nTerimakasih Telah Menggunakan ClevCalc");

			}
	}else{
		gotoxy(34,19); printf("Maaf, perintah yang Anda masukkan tidak dapat diproses.");
		gotoxy(24,20); printf("Mohon untuk memilih menu dengan angka yang sesuai dengan opsi yang tersedia.");
		gotoxy(55,21); printf("Terima kasih.");
		pil=0;
		goto AppMenu;
	}
}
