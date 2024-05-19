#include <limits.h>
#include <malloc.h>
#include <string.h>
#include <windows.h>
#include <stdbool.h>
#define true 1
#define false 0
#include <stdio.h>
#include "../include/StackDinamis.h"

/********** BODY SUB PROGRAM ***********/

/****** Modul Pemanggil Program ******/
bool checkBracket(char input[]){
	List MyBracket;
	
	CreateStack(&MyBracket);
	for(int count = 0; count < strlen(input); count++){
		if(input[count] == '('){
			PushV(&MyBracket, '(');
		} else if(input[count] == ')'){
			if(!StackEmpty(MyBracket)){
				PopV(&MyBracket);
			} else {
				return false;
			}
		}
	}
	if(StackEmpty(MyBracket)){
		return true;
	} else {
		return false;
	}
}



/**** Predikat untuk test keadaan LIST  ****/
boolean StackEmpty (List L)
/* Mengirim true jika List Kosong */
{
	return ((L).Top == Nil);
}

/**** Konstruktor/Kreator List Kosong ****/
void CreateStack (List * L)
/* IS : L sembarang */
/* FS : Terbentuk List Kosong */
{
	(*L).Top = Nil;
}


/**** Manajemen Memory ****/
address Alokasi (infotype X)
/* Mengirimkan address hasil alokasi sebuah elemen */
/* Jika alokasi berhasil, maka address != Nil, 	   */
/*	dan misalnya menghasilkan P, maka Info(P) = X, Next(P) = Nil */
/* Jika alokasi gagal, mengirimkan Nil */
{
	 /* Kamus Lokal */
	 address P;
	 /* Algoritma */
	 P = (address) malloc (sizeof (ElmtList));
	 if (P != Nil)		/* Alokasi berhasil */
	 {
	(P)->info = X;
	(P)->next = Nil;
	(P)->prev = Nil;
	 }
	 return (P);
}

void DeAlokasi (address P)
/* IS : P terdefinisi */
/* FS : P dikembalikan ke sistem */
/* Melakukan dealokasi / pengembalian address P ke system */
{
	 if (P != Nil)
	 {
	free (P);
	 }
}

void PushV (List * L, infotype X)
/* IS : L mungkin Kosong */
/* FS : melakukan alokasi sebuah elemen dan */
/* menambahkan elemen list di akhir (elemen terakhir adalah yang baru) */
/* bernilai X jika alokasi berhasil. Jika alokasi gagal IS = FS */
{
	 /* Kamus Lokal */
	address P;
	 /* Algoritma */
	P = Alokasi (X);
	if (P != Nil)
	{
	Push (&(*L), P);		}
}

void Push (List * L, address P)
/* IS : L sembarang, P sudah dialokasi */
/* FS : P ditambahkan sebagai elemen terakhir yang baru */
{
	/* Algoritma */
	if ((*L).Top != Nil)
	{
		((*L).Top)->next = P;
		(P)->prev = (*L).Top;
		(*L).Top = P;
	}
		else
	{	(*L).Top = P;		}
}

void PopV (List * L)
/* IS : L TIDAK Kosong */
/* FS : Elemen terakhir list dihapus : nilai info disimpan pada X */
/* 	dan alamat elemen terakhir di dealokasi */
{
	 /* Kamus Lokal */
	address PDel;
	 /* Algoritma */
	PDel = (*L).Top;
	Pop (&(*L), &PDel);
	DeAlokasi (PDel);
}

void Pop (List * L, address *P)
/* IS : L TIDAK kosong */
/* FS : P adalah alamat elemen terakhir list sebelum penghapusan */
/*	Elemen list berkurang satu (mungkin menjadi kosong) */
/* Last elemen baru adalah predesessor elemen terakhir yang lama, jika ada */
{
	/* Algoritma */
	*P = (*L).Top;
		
	if (((*L).Top)->prev == Nil){	/* Hanya 1 elemen */
		(*L).Top = Nil;
	}
	else{	/* List Lebih dari 1 elemen */
		(*L).Top = ((*L).Top)->prev;
	}
}