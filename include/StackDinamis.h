/*file: StackDinamis.h
  Program: Stack Dinamis
  Nama: Arnanda Prasatya
  Tanggal/Versi: 27/02/2023, Ver1
*/
#ifndef StackDinamis_H
#define StackDinamis_H
#include <limits.h>
#include <malloc.h>
#include <string.h>
#include <windows.h>
#include <stdbool.h>
//#define boolean_H
//#define true 1
//#define false 0
//#define boolean unsigned char
//#define spnrsll_H
#include <stdio.h>
#define Nil NULL

typedef char infotype;
typedef struct tElmtList *address;
typedef struct tElmtList {
	infotype info;
	address prev;
	address  next;
} ElmtList;

/* Definisi list : */
/* List kosong ===> First(L) = Nil */
/* Setiap elemen dengan address P dapat diacu info(P) dan Next(P);  */
/* Elemen terakhir list ===> Jika addressnya Last maka Next(Last) = Nil */
typedef struct {
	address Top;
} List;


/*********** PROTOTYPE ****************/
/**** Predikat untuk test keadaan LIST  ****/
boolean StackEmpty (List L);
/* Mengirim true jika List Kosong */

/**** Konstruktor/Kreator List Kosong ****/
void CreateStack (List * L);
/* IS : L sembarang */
/* FS : Terbentuk List Kosong */

/**** Manajemen Memory ****/
address Alokasi (infotype X);
/* Mengirimkan address hasil alokasi sebuah elemen */
/* Jika alokasi berhasil, maka address != Nil, 	   */
/*	dan misalnya menghasilkan P, maka Info(P) = X, Next(P) = Nil */
/* Jika alokasi gagal, mengirimkan Nil */

void DeAlokasi (address P);
/* IS : P terdefinisi */
/* FS : P dikembalikan ke sistem */
/* Melakukan dealokasi / pengembalian address P ke system */

void PushV (List * L, infotype X);
/* IS : L mungkin Kosong */
/* FS : melakukan alokasi sebuah elemen dan */
/* menambahkan elemen list di akhir (elemen terakhir adalah yang baru) */
/* bernilai X jika alokasi berhasil. Jika alokasi gagal IS = FS */

void Push (List * L, address P);
/* IS : L sembarang, P sudah dialokasi */
/* FS : P ditambahkan sebagai elemen terakhir yang baru */

void PopV (List * L);
/* IS : L TIDAK Kosong */
/* FS : Elemen terakhir list dihapus : nilai info disimpan pada X */
/* 	dan alamat elemen terakhir di dealokasi */

void Pop (List * L, address *P);
/* IS : L TIDAK kosong */
/* FS : P adalah alamat elemen terakhir list sebelum penghapusan */
/*	Elemen list berkurang satu (mungkin menjadi kosong) */
/* Last elemen baru adalah predesessor elemen terakhir yang lama, jika ada */

bool checkBracket(char input[]);
/*Function ini berfungsi untuk pengecekan apakah bracket sesauai atau tidak*/
/*Mengirimkan boolean true apabila tanda kurung/bracket sesuai dengan ketentuan matematika*/
/*Mengirimkan boolean false apabila tanda kurung/bracket tidak sesuai dengan ketentuan matematika*/
#endif