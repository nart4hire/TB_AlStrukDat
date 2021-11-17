/* File : list_order.h */
/* contoh ADT list berkait dengan representasi fisik pointer  */
/* Representasi Address_order dengan pointer */
/* ElType_ListLinked adalah integer */

#ifndef LISTINPRO_H
#define LISTINPRO_H

#include "boolean.h"
#include "node_order.h"

typedef Address_order ListLinked_order;

#define IDX_UNDEF -1
#define FIRST(l) (l)

/* Definisi ListLinked_order : */
/* ListLinked_order kosong : FIRST(l) = NULL */
/* Setiap elemen dengan Address_order p dapat diacu INFO(p), NEXT(p) */
/* Elemen terakhir list: jika addressnya Last, maka NEXT(Last)=NULL */

/* PROTOTYPE */
/****************** PEMBUATAN LIST KOSONG ******************/
void CreateListInPro(ListLinked_order *l);
/* I.S. sembarang             */
/* F.S. Terbentuk list kosong */

/****************** TEST LIST KOSONG ******************/
boolean isEmpty_ListInPro(ListLinked_order l);
/* Mengirim true jika list kosong */

/****************** GETTER SETTER ******************/
Time getTServe_ListInPro(ListLinked_order l, int idx);
/* I.S. l terdefinisi, idx indeks yang valid dalam l, yaitu 0..length_ListLinked(l) */
/* F.S. Mengembalikan waktu pesanan list l pada indeks idx */

char getPickUp_ListInPro(ListLinked_order l, int idx);
/* I.S. l terdefinisi, idx indeks yang valid dalam l, yaitu 0..length_ListLinked(l) */
/* F.S. Mengembalikan posisi pick up pesanan list l pada indeks idx */

char getDrop_ListInPro(ListLinked_order l, int idx);
/* I.S. l terdefinisi, idx indeks yang valid dalam l, yaitu 0..length_ListLinked(l) */
/* F.S. Mengembalikan posisi drop pesanan list l pada indeks idx */

char getItem_ListInPro(ListLinked_order l, int idx);
/* I.S. l terdefinisi, idx indeks yang valid dalam l, yaitu 0..length_ListLinked(l) */
/* F.S. Mengembalikan item pesanan list l pada indeks idx */

Time getPerTime_ListInPro(ListLinked_order l, int idx);
/* I.S. l terdefinisi, idx indeks yang valid dalam l, yaitu 0..length_ListLinked(l) */
/* F.S. Mengembalikan perishable time pesanan list l pada indeks idx dengan tipe item P*/

int indexOf_ListInPro(ListLinked_order l, Time t_serve);
/* I.S. l, t_serve terdefinisi */
/* F.S. Mencari apakah ada elemen list l yang bernilai t_serve */
/* Jika ada, mengembalikan indeks elemen pertama l yang bernilai t_serve */
/* Mengembalikan IDX_UNDEF jika tidak ditemukan */

/****************** PRIMITIF BERDASARKAN NILAI ******************/
/*** PENAMBAHAN ELEMEN ***/
void insertFirst_ListInPro(ListLinked_order *l, Time t_serve, char pickUp, char dropOff, char item, Time perTime);
/* I.S. l mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen pertama dengan nilai t_serve, pickUp, dropOff, item, dan perTime jika alokasi berhasil. */
/* Jika alokasi gagal: I.S.= F.S. */

void insertLast_ListInPro(ListLinked_order *l, Time t_serve, char pickUp, char dropOff, char item, Time perTime);
/* I.S. l mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen list di akhir dengan nilai t_serve, pickUp, dropOff, item, dan perTime jika alokasi berhasil */
/* Jika alokasi gagal: I.S.= F.S. */

void insertAt_ListInPro(ListLinked_order *l, Time t_serve, char pickUp, char dropOff, char item, Time perTime, int idx);
/* I.S. l tidak mungkin kosong, idx indeks yang valid dalam l, yaitu 0..length_ListLinked(l) */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menyisipkan elemen dalam list pada indeks ke-idx (bukan menimpa elemen di i) */
/* dengan nilai t_serve, pickUp, dropOff, item, dan perTime jika alokasi berhasil jika alokasi berhasil. Jika alokasi gagal: I.S.= F.S. */

/*** PENGHAPUSAN ELEMEN ***/
void deleteFirst_ListInPro(ListLinked_order *l, Time *t_serve, char *pickUp, char *dropOff, char *item, Time *perTime);
/* I.S. ListLinked_order l tidak kosong  */
/* F.S. Elemen pertama list dihapus: nilai info disimpan pada pada masing masing variabel */
/*      dan alamat elemen pertama di-dealokasi */

void deleteLast_ListInPro(ListLinked_order *l, Time *t_serve, char *pickUp, char *dropOff, char *item, Time *perTime);
/* I.S. list tidak kosong */
/* F.S. Elemen terakhir list dihapus: nilai info disimpan pada masing masing variabel */
/*      dan alamat elemen terakhir di-dealokasi */

void deleteAt_ListInPro(ListLinked_order *l, Time *t_serve, char *pickUp, char *dropOff, char *item, Time *perTime, int idx);
/* I.S. list tidak kosong, idx indeks yang valid dalam l, yaitu 0..length_ListLinked(l) */
/* F.S. nilai info disimpan pada masing masing variabel sesuai indeks ke-idx. */
/*      Elemen l pada indeks ke-idx dihapus dari l */


/****************** PROSES SEMUA ELEMEN LIST ******************/
int length_ListInPro(ListLinked_order l);
/* Mengirimkan banyaknya elemen list; mengirimkan 0 jika list kosong */

#endif