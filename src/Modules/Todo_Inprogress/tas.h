/* File : stack.h */
/* Definisi ADT Stack dengan representasi array secara eksplisit dan alokasi statik */
/* TOP adalah alamat elemen puncak */

#ifndef STACK_H
#define STACK_H

#include "item.h"

#define CAPACITY_STACK 100
#define IDX_UNDEF -1

typedef item StackElType;
typedef struct {
  StackElType buffer[CAPACITY_STACK]; /* tabel penyimpan elemen */
  int idxTop; /* alamat TOP: elemen puncak */
} Stack;

extern int stack_capacity;

/* ********* AKSES (Selektor) ********* */
/* Jika s adalah Stack, maka akses elemen : */
#define IDX_TOP(s) (s).idxTop
#define     TOP(s) (s).buffer[(s).idxTop]
#define ELMT(s, i) (s).buffer[i]

/* *** Konstruktor/Kreator *** */
void initTas(int cap);

void CreateStack(Stack *s);
/* I.S. sembarang; */
/* F.S. Membuat sebuah stack S kosong dengan kondisi sbb: */
/* - Index top bernilai IDX_UNDEF */
/* Proses : Melakukan alokasi, membuat sebuah s kosong */

/* ************ Prototype ************ */
boolean isEmpty_Stack(Stack s);
/* Mengirim true jika s kosong: lihat definisi di atas */
boolean isFull_Stack(Stack s);
/* Mengirim true jika tabel penampung nilai s stack penuh */
boolean isFull_Tas(Stack s);

/* ************ Menambahkan sebuah elemen ke Stack ************ */
void push(Stack *s, StackElType val);
/* Menambahkan val sebagai elemen Stack s */
/* I.S. s mungkin kosong, tabel penampung elemen stack TIDAK penuh */
/* F.S. val menjadi TOP yang baru,IDX_TOP bertambah 1 */

/* ************ Menghapus sebuah elemen Stack ************ */
void pop(Stack *s, StackElType *val);
/* Menghapus val dari Stack s */
/* I.S. s tidak mungkin kosong */
/* F.S. val adalah nilai elemen TOP yang lama, IDX_TOP berkurang 1 */

/* ************ Menambah kapasitas Stack ************ */
//NOTE ini gw ganti dari boolean jadi void
void increaseCapacity(int amount);
/* Menambah kapasitas maksimal Stack sebanyak amount */
/* Mengembalikan true bila stack_capacity belum bernilai maksimal (penambahan berhasil) */
/* Mengembalikan false di kasus sebaliknya */
/* stack_capacity bernilai maksimal 100 */

void displayStack(Stack s);
// void setCapacity(int amount);

Stack advPerishable(Stack *s);

#endif