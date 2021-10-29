/* File : list_order.h */
/* contoh ADT list berkait dengan representasi fisik pointer  */
/* Representasi Address dengan pointer */
/* ElType_ListLinked adalah integer */

#ifndef LIST_H
#define LIST_H

#include "boolean.h"
#include "node_order.h"

typedef Address ListLinked;

#define IDX_UNDEF (-1)
#define FIRST(l) (l)

/* Definisi ListLinked : */
/* ListLinked kosong : FIRST(l) = NULL */
/* Setiap elemen dengan Address p dapat diacu INFO(p), NEXT(p) */
/* Elemen terakhir list: jika addressnya Last, maka NEXT(Last)=NULL */

/* PROTOTYPE */
/****************** PEMBUATAN LIST KOSONG ******************/
void CreateListOrder(ListLinked *l);
/* I.S. sembarang             */
/* F.S. Terbentuk list kosong */

/****************** TEST LIST KOSONG ******************/
boolean isEmpty_ListOrder(ListLinked l);
/* Mengirim true jika list kosong */

/****************** GETTER SETTER ******************/
Time getTServe_ListOrder(ListLinked l, int idx);
/* I.S. l terdefinisi, idx indeks yang valid dalam l, yaitu 0..length_ListLinked(l) */
/* F.S. Mengembalikan waktu pesanan list l pada indeks idx */

char getPickUp_ListOrder(ListLinked l, int idx);
/* I.S. l terdefinisi, idx indeks yang valid dalam l, yaitu 0..length_ListLinked(l) */
/* F.S. Mengembalikan posisi pick up pesanan list l pada indeks idx */

char getDrop_ListOrder(ListLinked l, int idx);
/* I.S. l terdefinisi, idx indeks yang valid dalam l, yaitu 0..length_ListLinked(l) */
/* F.S. Mengembalikan posisi drop pesanan list l pada indeks idx */

char getItem_ListOrder(ListLinked l, int idx);
/* I.S. l terdefinisi, idx indeks yang valid dalam l, yaitu 0..length_ListLinked(l) */
/* F.S. Mengembalikan item pesanan list l pada indeks idx */

Time getPerTime_ListOrder(ListLinked l, int idx);
/* I.S. l terdefinisi, idx indeks yang valid dalam l, yaitu 0..length_ListLinked(l) */
/* F.S. Mengembalikan perishable time pesanan list l pada indeks idx dengan tipe item P*/

int indexOf_ListOrder(ListLinked l, Time t_serve);
/* I.S. l, t_serve terdefinisi */
/* F.S. Mencari apakah ada elemen list l yang bernilai t_serve */
/* Jika ada, mengembalikan indeks elemen pertama l yang bernilai t_serve */
/* Mengembalikan IDX_UNDEF jika tidak ditemukan */

/****************** PRIMITIF BERDASARKAN NILAI ******************/
/*** PENAMBAHAN ELEMEN ***/
void insertFirst_ListOrder(ListLinked *l, Time t_serve, char pickUp, char dropOff, char item, Time perTime);
/* I.S. l mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen pertama dengan nilai t_serve, pickUp, dropOff, item, dan perTime jika alokasi berhasil. */
/* Jika alokasi gagal: I.S.= F.S. */

void insertLast_ListOrder(ListLinked *l, Time t_serve, char pickUp, char dropOff, char item, Time perTime);
/* I.S. l mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen list di akhir dengan nilai t_serve, pickUp, dropOff, item, dan perTime jika alokasi berhasil */
/* Jika alokasi gagal: I.S.= F.S. */

void insertAt_ListOrder(ListLinked *l, Time t_serve, char pickUp, char dropOff, char item, Time perTime, int idx);
/* I.S. l tidak mungkin kosong, idx indeks yang valid dalam l, yaitu 0..length_ListLinked(l) */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menyisipkan elemen dalam list pada indeks ke-idx (bukan menimpa elemen di i) */
/* dengan nilai t_serve, pickUp, dropOff, item, dan perTime jika alokasi berhasil jika alokasi berhasil. Jika alokasi gagal: I.S.= F.S. */

/*** PENGHAPUSAN ELEMEN ***/
void deleteFirst_ListOrder(ListLinked *l, Time *t_serve, char *pickUp, char *dropOff, char *item, Time *perTime);
/* I.S. ListLinked l tidak kosong  */
/* F.S. Elemen pertama list dihapus: nilai info disimpan pada pada masing masing variabel */
/*      dan alamat elemen pertama di-dealokasi */

void deleteLast_ListOrder(ListLinked *l, Time *t_serve, char *pickUp, char *dropOff, char *item, Time *perTime);
/* I.S. list tidak kosong */
/* F.S. Elemen terakhir list dihapus: nilai info disimpan pada masing masing variabel */
/*      dan alamat elemen terakhir di-dealokasi */

void deleteAt_ListOrder(ListLinked *l, Time *t_serve, char *pickUp, char *dropOff, char *item, Time *perTime, int idx);
/* I.S. list tidak kosong, idx indeks yang valid dalam l, yaitu 0..length_ListLinked(l) */
/* F.S. nilai info disimpan pada masing masing variabel sesuai indeks ke-idx. */
/*      Elemen l pada indeks ke-idx dihapus dari l */


/****************** PROSES SEMUA ELEMEN LIST ******************/
int length_ListOrder(ListLinked l);
/* Mengirimkan banyaknya elemen list; mengirimkan 0 jika list kosong */

#endif