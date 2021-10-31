/* File : queue.h */
/* Definisi ADT Queue dengan representasi array secara eksplisit dan alokasi statik */

#ifndef QUEUE_H
#define QUEUE_H

#include "boolean.h"
#include "time.h"

#define IDX_UNDEF -1
#define CAPACITY_QUEUE 100

/* Definisi elemen dan address */
typedef struct {
        char pickUp;
        char dropOff;
        char item;
        Time pTime;
} ElType_Queue;
typedef struct {
	ElType_Queue buffer[CAPACITY_QUEUE]; 
	int idxHead;
	int idxTail;
} Queue;


/* ********* AKSES (Selektor) ********* */
/* Jika q adalah Queue, maka akses elemen : */
#define IDX_HEAD(q) (q).idxHead
#define IDX_TAIL(q) (q).idxTail
#define HEAD_PICK(q) (q).buffer[(q).idxHead].pickUp
#define HEAD_DROP(q) (q).buffer[(q).idxHead].dropOff
#define HEAD_ITEM(q) (q).buffer[(q).idxHead].item
#define HEAD_PTIME(q) (q).buffer[(q).idxHead].pTime
#define TAIL_PICK(q) (q).buffer[(q).idxTail].pickUp
#define TAIL_DROP(q) (q).buffer[(q).idxTail].dropOff
#define TAIL_ITEM(q) (q).buffer[(q).idxTail].item
#define TAIL_PTIME(q) (q).buffer[(q).idxTail].pTime

/* *** Kreator *** */
void CreateQueue(Queue *q);
/* I.S. sembarang */
/* F.S. Sebuah q kosong terbentuk dengan kondisi sbb: */
/* - Index head bernilai IDX_UNDEF */
/* - Index tail bernilai IDX_UNDEF */
/* Proses : Melakukan alokasi, membuat sebuah q kosong */

/* ********* Prototype ********* */
boolean isEmpty_Queue(Queue q);
/* Mengirim true jika q kosong: lihat definisi di atas */

boolean isFull_Queue(Queue q);
/* Mengirim true jika tabel penampung elemen q sudah penuh */
/* yaitu jika index head bernilai 0 dan index tail bernilai CAPACITY_QUEUE-1 */

int length_Queue(Queue q);
/* Mengirimkan banyaknya elemen queue. Mengirimkan 0 jika q kosong. */

/* *** Primitif Add/Delete *** */
void enqueue(Queue *q, char pick, char drop, char item, Time per_time);
/* Proses: Menambahkan info pada q dengan aturan FIFO */
/* I.S. q mungkin kosong, tabel penampung elemen q TIDAK penuh */
/* F.S. info baru menjadi TAIL yang baru, IDX_TAIL "mundur".
        Jika q penuh semu, maka perlu dilakukan aksi penggeseran "maju" elemen-elemen q
        menjadi rata kiri untuk membuat ruang kosong bagi TAIL baru  */

void dequeue(Queue *q, char *pick, char *drop, char *item, Time *per_time);
/* Proses: Menghapus val pada q dengan aturan FIFO */
/* I.S. q tidak mungkin kosong */
/* F.S. val = nilai elemen HEAD pd I.S., HEAD dan IDX_HEAD "mundur"; 
        q mungkin kosong */

/* *** Display Queue *** */
void displayQueue(Queue q);
/* Proses : Menuliskan isi Queue dengan traversal, Queue ditulis menurun sesuai urutan
   tiap baris berisi informasi tempat_pick -> tempat_drop (jenis_item, sisa waktu t(jika perishable))*/
/* I.S. q boleh kosong */
/* F.S. Jika q tidak kosong: [e1,e2,...,en] */
/* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [1,20,30] */
/* Jika Queue kosong : menulis [] */


#endif