// File : stack.c 
// Definisi ADT Stack dengan representasi array secara eksplisit dan alokasi statik 
// TOP adalah alamat elemen puncak 

#include <stdio.h>
#include "stack.h"

// CONSTANTS:
// #define IDX_UNDEF -1
// #define CAPACITY 100

// DEFINITION:
// typedef int ElType;
// typedef struct {
//   ElType buffer[CAPACITY]; // tabel penyimpan elemen 
//   int idxTop;              // alamat TOP: elemen puncak 
// } Stack;

// ********* AKSES (Selektor) ********* 
// Jika s adalah Stack, maka akses elemen : 

// #define IDX_TOP(s) (s).idxTop
// #define     TOP(s) (s).buffer[(s).idxTop]

// *** Konstruktor/Kreator *** 

void CreateStack(Stack *s)
{
    IDX_TOP(*s) = IDX_UNDEF;
}
// I.S. sembarang; 
// F.S. Membuat sebuah stack S kosong dengan kondisi sbb: 
// - Index top bernilai IDX_UNDEF 
// Proses : Melakukan alokasi, membuat sebuah s kosong 

// ************ Prototype ************ 

boolean isEmpty_Stack(Stack s)
{
    return (IDX_TOP(s) == IDX_UNDEF);
}
// Mengirim true jika s kosong: lihat definisi di atas

boolean isFull_Stack(Stack s)
{
    return (IDX_TOP(s) == CAPACITY - 1);
}
// Mengirim true jika tabel penampung nilai s stack penuh 

// ************ Menambahkan sebuah elemen ke Stack ************ 

void push(Stack *s, ElType val)
{
    ++IDX_TOP(*s);
    TOP(*s) = val;
}
// Menambahkan val sebagai elemen Stack s 
// I.S. s mungkin kosong, tabel penampung elemen stack TIDAK penuh 
// F.S. val menjadi TOP yang baru,IDX_TOP bertambah 1 

// ************ Menghapus sebuah elemen Stack ************ 

void pop(Stack *s, ElType *val)
{
    *val = TOP(*s);
    --IDX_TOP(*s);
}
// Menghapus val dari Stack s 
// I.S. s tidak mungkin kosong 
// F.S. val adalah nilai elemen TOP yang lama, IDX_TOP berkurang 1 
