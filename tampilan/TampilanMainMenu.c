/*============================================================


============================================================*/
#include <stdio.h>
#include "gotoxy.c"

void TampilanMainMenu();
void TampilanCalculator();
void TampilanBatasanProgam();
void TampilanKonversiSuhu();


void TampilanMainMenu(){
	gotoxy(24,2);printf("010101   010   01     010101 01  01 01       010   01010101 010101 01010\n");//122 - 74 =
	gotoxy(24,3);printf("01      01 01  01     01     01  01 01      01 01     01    01  01 01  01\n");
	gotoxy(24,4);printf("01     0101010 01     01     01  01 01     0101010    01    01  01 01010\n");
	gotoxy(24,5);printf("01     01   01 01     01     01  01 01     01   01    01    01  01 01 01\n");
	gotoxy(24,6);printf("010101 01   01 010101 010101 010101 010101 01   01    01    010101 01  01\n");
	gotoxy(30,8);printf("010101 010101 01 010101 010  01 01010101 01 010101 01 010101\n");
	gotoxy(30,9);printf("01     01     01 01     0101 01    01    01 01     01 01\n");
	gotoxy(30,10);printf("010101 01     01 010101 01 0 01    01    01 010101 01 01\n");
	gotoxy(30,11);printf("    01 01     01 01     01 0101    01    01 01     01 01\n");
	gotoxy(30,12);printf("010101 010101 01 010101 01  010    01    01 01     01 010101\n");
	gotoxy(41,14);printf("1. Calculator                 Choose\n");
	gotoxy(41,15);printf("2. Batasan Prohram         +----------+    \n");
	gotoxy(41,16);printf("3. More                    |          |\n");
	gotoxy(41,17);printf("99. Exit                   +----------+    \n");
	/*Begin
		gotoxy(24,2)
		cetak(layar)"010101   010   01     010101 01  01 01       010   01010101 010101 01010"
		gotoxy(24,3)
		cetak(layar)"01      01 01  01     01     01  01 01      01 01     01    01  01 01  01"
		gotoxy(24,4)
		cetak(layar)"01     0101010 01     01     01  01 01     0101010    01    01  01 01010"
		gotoxy(24,5)
		cetak(layar)"01     01   01 01     01     01  01 01     01   01    01    01  01 01 01"
		gotoxy(24,6)
		cetak(layar)"010101 01   01 010101 010101 010101 010101 01   01    01    010101 01  01"
		gotoxy(30,8)
		cetak(layar)"010101 010101 01 010101 010  01 01010101 01 010101 01 010101"
		gotoxy(30,9)
		cetak(layar)"01     01     01 01     0101 01    01    01 01     01 01"
		gotoxy(30,10)
		cetak(layar)"010101 01     01 010101 01 0 01    01    01 010101 01 01"
		gotoxy(30,11)
		cetak(layar)"    01 01     01 01     01 0101    01    01 01     01 01"
		gotoxy(30,12)
		cetak(layar)"010101 010101 01 010101 01  010    01    01 01     01 010101\"
		gotoxy(41,14)
		cetak(layar)"1. Calculator                 Choose"
		gotoxy(41,15)
		cetak(layar)"2. Batasan Prohram         +----------+"
		gotoxy(41,17)
		cetak(layar)"99. Exit                   +----------+"
	End*/
}


void TampilanKalkulator(){
	gotoxy(40,3);printf(" _________________________________________\n");
	gotoxy(40,4);printf("|  _____________________________________  |\n");
	gotoxy(40,5);printf("| | Choose Operator                     | |\n");
	gotoxy(40,6);printf("| |                                     | |\n");
	gotoxy(40,7);printf("| |_____________________________________| |\n");
	gotoxy(40,8);printf("|  _______   _______   _______   _______  |\n");
	gotoxy(40,9);printf("| |   (   | |   )   | |   %%   | |   /   | |\n");
	gotoxy(40,10);printf("| |_______| |_______| |_______| |_______| |\n");
	gotoxy(40,11);printf("|  _______   _______   _______   _______  |\n");
	gotoxy(40,12);printf("| |   7   | |   8   | |   9   | |   *   | |\n");
	gotoxy(40,13);printf("| |_______| |_______| |_______| |_______| |\n");
	gotoxy(40,14);printf("|  _______   _______   _______   _______  |\n");
	gotoxy(40,15);printf("| |   4   | |   5   | |   6   | |   -   | |\n");
	gotoxy(40,16);printf("| |_______| |_______| |_______| |_______| |\n");
	gotoxy(40,17);printf("|  _______   _______   _______   _______  |\n");
	gotoxy(40,18);printf("| |   1   | |   2   | |   3   | |       | |\n");
	gotoxy(40,19);printf("| |_______| |_______| |_______| |       | |\n");
	gotoxy(40,20);printf("|  _______   _______   _______  |   +   | |\n");
	gotoxy(40,21);printf("| |   .   | |   0   | |   =   | |       | |\n");
	gotoxy(40,22);printf("| |_______| |_______| |_______| |_______| |\n");
	gotoxy(40,23);printf("|_________________________________________|\n");
	gotoxy(40,25);printf("Infix to Postfix : ");
	gotoxy(40,56); printf("Infix to Prefix  : ");
	/*gotoxy(44,6); Untuk Inputan*/
	/*Begin
		gotoxy(40,3);
		cetak(layar)" _________________________________________"
		gotoxy(40,4);
		cetak(layar)"|  _____________________________________  |"
		gotoxy(40,5)
		cetak(layar)"| | Choose Operator                     | |"
		gotoxy(40,6)
		cetak(layar)"| |                                     | |"
		gotoxy(40,7)
		cetak(layar)"| |_____________________________________| |"
		gotoxy(40,8)
		cetak(layar)"|  _______   _______   _______   _______  |"
		gotoxy(40,9)
		cetak(layar)"| |   (   | |   )   | |   %%   | |   /   | |"
		gotoxy(40,10)
		cetak(layar)"| |_______| |_______| |_______| |_______| |"
		gotoxy(40,11)
		cetak(layar)"|  _______   _______   _______   _______  |"
		gotoxy(40,12)
		cetak(layar)"| |   7   | |   8   | |   9   | |   *   | |"
		gotoxy(40,13)
		cetak(layar)"| |_______| |_______| |_______| |_______| |"
		gotoxy(40,14)
		cetak(layar)"|  _______   _______   _______   _______  |"
		gotoxy(40,15)
		cetak(layar)"| |   4   | |   5   | |   6   | |   -   | |"
		gotoxy(40,16)
		cetak(layar)"| |_______| |_______| |_______| |_______| |"
		gotoxy(40,17)
		cetak(layar)"|  _______   _______   _______   _______  |"
		gotoxy(40,18)'
		cetak(layar)"| |   1   | |   2   | |   3   | |       | |"
		gotoxy(40,19)
		cetak(layar)"| |_______| |_______| |_______| |       | |"
		gotoxy(40,20)
		cetak(layar)"|  _______   _______   _______  |   +   | |"
		gotoxy(40,21)
		cetak(layar)"| |   .   | |   0   | |   =   | |       | |"
		gotoxy(40,22)
		cetak(layar)"| |_______| |_______| |_______| |_______| |"
		gotoxy(40,23)
		cetak(layar)"|_________________________________________|"
		gotoxy(40,25)
		cetak(layar)"Infix to Postfix : "
		gotoxy(40,56)
		cetak(layar)"Infix to Prefix  : "
	End*/
}

void TampilanBatasanProgam(){
	gotoxy(21,2);printf("+------------------------------------------------------------------------------+\n");
	gotoxy(21,3);printf("|a. Dalam program ini kami menggunakan tipe data float.                        |\n");
	gotoxy(21,4);printf("|b. User harus menginputkan dengan Angka agar bisa dikalkulasikan.             |\n");
	gotoxy(21,5);printf("|c. Sesuai dengan konsep matematika, program yang kita buat tidak bisa         |\n");
	gotoxy(21,6);printf("|   menampilkan hasil saat membagi suatu bilangan dengan angka 0.              |\n");
	gotoxy(21,7);printf("|d. Dalam penginputan ekspresi matematika, operator tidak boleh berhimpitan,   |\n");
	gotoxy(21,8);printf("|   hanya boleh ada tanda negatif untuk menunjukkan angka negatif.             |\n");
	gotoxy(21,9);printf("|e. Apabila memasukkan ekspresi matematika user tidak boleh menginputkan huruf.|\n");
	gotoxy(21,10);printf("|f. Akan menunjukkan error apabila user menginputkan ekspresi matematika dengan|\n");
	gotoxy(21,11);printf("|   tanda kurung yang tidak sesuai (kurungnya tidak ditutup atau kelebihan)    |\n");
	gotoxy(21,12);printf("|g. Tidak bisa menghitung ekspresi matematika seperti 4(5+20)                  |\n");
	gotoxy(21,13);printf("|h. Inputan harus berhimpitan / tidak boleh dipisahkan dengan spasi            |\n");
	gotoxy(21,14);printf("|i. Untuk operator perpangkatan belum ditambahkan di modul isValid dan         |\n"); 
	gotoxy(21,15);printf("|   perhtiungan di stacknya                                                    |\n");
	gotoxy(21,16);printf("|j. Apabila Ingin Menginputkan - (negatif) diawal maka harus diawali dengan () |\n");
	gotoxy(21,17);printf("|   seperti (-20)+10                                                           |\n");
	gotoxy(21,18);printf("+------------------------------------------------------------------------------+\n");
	gotoxy(21,20);system("pause");
	/*Begin
		gotoxy(21,2)
		cetak(layar)"+------------------------------------------------------------------------------+"
		gotoxy(21,3)
		cetak(layar)"|a. Dalam program ini kami menggunakan tipe data float.                        |"
		gotoxy(21,4)
		cetak(layar)"|b. User harus menginputkan dengan Angka agar bisa dikalkulasikan.             |"
		gotoxy(21,5)
		cetak(layar)"|c. Sesuai dengan konsep matematika, program yang kita buat tidak bisa         |"
		gotoxy(21,6)
		cetak(layar)"|   menampilkan hasil saat membagi suatu bilangan dengan angka 0.              |"
		gotoxy(21,7)
		cetak(layar)"|d. Dalam penginputan ekspresi matematika, operator tidak boleh berhimpitan,   |"
		gotoxy(21,8)
		cetak(layar)"|   hanya boleh ada tanda negatif untuk menunjukkan angka negatif.             |"
		gotoxy(21,9)
		cetak(layar)"|e. Apabila memasukkan ekspresi matematika user tidak boleh menginputkan huruf.|"
		gotoxy(21,10)
		cetak(layar)"|f. Akan menunjukkan error apabila user menginputkan ekspresi matematika dengan|"
		gotoxy(21,11)
		cetak(layar)"|   tanda kurung yang tidak sesuai (kurungnya tidak ditutup atau kelebihan)    |"
		gotoxy(21,12)
		cetak(layar)"|g. Tidak bisa menghitung ekspresi matematika seperti 4(5+20)                  |"
		gotoxy(21,13)
		cetak(layar)"|h. Inputan harus berhimpitan / tidak boleh dipisahkan dengan spasi            |"
		gotoxy(21,14)
		cetak(layar)"|i. Untuk operator perpangkatan belum ditambahkan di modul isValid dan         |" 
		gotoxy(21,15)
		cetak(layar)"|   perhtiungan di stacknya                                                    |"
		gotoxy(21,16)
		cetak(layar)"|j. Apabila Ingin Menginputkan - (negatif) diawal maka harus diawali dengan () |"
		gotoxy(21,17)
		cetak(layar)"|   seperti (-20)+10                                                           |"
		gotoxy(21,18)
		cetak(layar)"+------------------------------------------------------------------------------+"
		gotoxy(21,20)
		system("pause");
	End*/
}

void TampilanKonversiSuhu(){
	printf("Konversi Suhu\n");
	printf("1. Celcius (C)\n");
	printf("2. Reamur (R)\n");
	printf("3. Farennheit (F)\n");
	printf("4. Kelvin (K)\n");
	printf("99. Keluar\n");
	printf(" : ");
	gotoxy(31,3);printf("+-------------+------------+----------------+------------+\n");
	gotoxy(31,4);printf("| Celcius (C) | Reamur (R) | Fahrenheit (F) | Kelvin (K) |\n");
	gotoxy(31,5);printf("+-------------+------------+----------------+------------+\n");
	/*Begin
		cetak(layar)"Konversi Suhu"
		cetak(layar)"1. Celcius (C)"
		cetak(layar)"2. Reamur (R)"
		cetak(layar)"3. Farennheit (F)"
		cetak(layar)"4. Kelvin (K)"
		cetak(layar)("99. Keluar"
		cetak(layar)" : "
		gotoxy(31,3)
		cetak(layar)"+-------------+------------+----------------+------------+"
		gotoxy(31,4)
		cetak(layar)"| Celcius (C) | Reamur (R) | Fahrenheit (F) | Kelvin (K) |"
		gotoxy(31,5)
		cetak(layar)"+-------------+------------+----------------+------------+"
		gotoxy(31,6)
		cetak(layar)"|             |            |                |            |"
		gotoxy(31,7)
		cetak(layar)"+-------------+------------+----------------+------------+"
	End*/
}