#ifndef TREE_H
#define TREE_H
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>
#define Nil NULL

typedef struct data{
	double angka;
	char mathOperator;
}data ;

typedef struct calcTree{
	struct data isi_data;
    struct calcTree * lChild;//Left child 
    struct calcTree * rChild;//Right child 
}calcTree;

double count(struct calcTree *root); 
//Function untuk menghitung total dari proses proses dalam tree
double inspectExpression(char mathExpression[], int firstIndex, int lastIndex); 
//Function untuk memeriksa apakah inputan mengandung operator atau hanya angka.
struct calcTree * createTree(char mathExpression[], int firstIndex, int lastIndex); 
//Function untuk membuat tree
char isOperator(struct calcTree *root);
//Function untuk mengecek operator atau bukan
double round_double(double number, int decimal_places);
//Function untuk membulatkan hasil perhitungan
bool isOperasi(char oper); 
//Mengecek kesesuaian suatu operator
bool isValid(char input[]); 
//Function ini untuk mengecek apakah operasi yang di inputkan valid atau tidak.
void infixToPostfix(struct calcTree *root);
//Mengubah ekspresi matematika infix menjadi postfix
void infixToPrefix(struct calcTree *root);
//Mengubah ekspresi matematika infix menjadi pretfix
#endif