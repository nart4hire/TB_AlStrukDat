/* File : prioqueue.h */
/* Representasi priority queue dengan array eksplisit dan alokasi stastik */
/* Queue terurut mengecil berdasarkan elemen score (nilai Daspro) */
/* Jika score sama, diurutkan membesar berdasarkan tKedatangan (waktu kedatangan) */
#ifndef PRIOQUEUE_H
#define PRIOQUEUE_H

#include "boolean.h"
#include <stdio.h>
#include <stdlib.h>

/* Konstanta */
#define IDX_UNDEF -1
#define CAPACITY 100

typedef struct {
    char type;
    char* type_desc;
    int value;
    int expiry;
    int expiry_now;
} Item;

/* Deklarasi ElType */
typedef struct {
  int t;
  char pickUp;
  char dropOff;
  Item tipeItem;
} Pesanan;

/* Definisi PrioQueue */
typedef struct {
	Pesanan buffer[CAPACITY];
	int idxHead;
	int idxTail;
} PrioQueue;

/* ********* AKSES (Selektor) ********* */
/* Jika pq adalah PrioQueue, maka akses elemen : */
#define IDX_HEAD_PQ(pq) (pq).idxHead
#define IDX_TAIL_PQ(pq) (pq).idxTail
#define     HEAD(pq) (pq).buffer[(pq).idxHead]
#define     TAIL(pq) (pq).buffer[(pq).idxTail]
#define WAKTUPESANAN(l) (l).t
#define PICKUP(l) (l).pickUp
#define DROPOFF(l) (l).dropOff
#define tipeItem(l) (l).tipeItem
/* *** Kreator *** */
void CreatePrioQueue(PrioQueue *pq);
/* I.S. sembarang */
/* F.S. Sebuah pq kosong terbentuk dengan kondisi sbb: */
/* - Index head bernilai IDX_UNDEF */
/* - Index tail bernilai IDX_UNDEF */
/* Proses : Melakukan alokasi, membuat sebuah pq kosong */

boolean isEmpty(PrioQueue pq);
/* Mengirim true jika pq kosong: lihat definisi di atas */

boolean isFull(PrioQueue pq);
/* Mengirim true jika tabel penampung elemen pq sudah penuh */
/* yaitu jika index head bernilai 0 dan index tail bernilai CAPACITY-1 */

int lengthPrioQueue(PrioQueue pq);
/* Mengirimkan banyaknya elemen queue. Mengirimkan 0 jika pq kosong. */

/*** Primitif Add/Delete ***/
void enqueue_Prioqueue(PrioQueue *pq, Pesanan val);
/* Proses: Menambahkan val pada pq dengan aturan FIFO */
/* I.S. pq mungkin kosong, tabel penampung elemen pq TIDAK penuh */
/* F.S. val menjadi TAIL yang baru, IDX_TAIL_PQ "mundur".
        Jika q penuh semu, maka perlu dilakukan aksi penggeseran "maju" elemen-elemen pq
        menjadi rata kiri untuk membuat ruang kosong bagi TAIL baru  */

void dequeue_PrioQueue(PrioQueue * pq, Pesanan *val);
/* Proses: Menghapus val pada q dengan aturan FIFO */
/* I.S. pq tidak mungkin kosong */
/* F.S. val = nilai elemen HEAD pd
I.S., HEAD dan IDX_HEAD_PQ "mundur"; 
        pq mungkin kosong */

//NOTE ngechek pesanan ini sama apa engga
boolean isPesananEqual(Pesanan p1, Pesanan p2);

//NOTE ini buat ngedisplay 1 pesanan di to do
void displayPesanan(Pesanan p);

//NOTE ini buat display pesanan tipe nya di inprogress
void displayInProgress(Pesanan p);
#endif