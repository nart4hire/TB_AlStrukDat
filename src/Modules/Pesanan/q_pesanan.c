// File : queue.c */
// Definisi ADT Queue dengan representasi array secara eksplisit dan alokasi statik */

#include <stdio.h>
#include <stdlib.h>
#include "q_pesanan.h"

// #define IDX_UNDEF -1
// #define CAPACITY_QUEUE 100

// Definisi elemen dan address */
// typedef int ElType_Queue;
// typedef struct
// {
//     ElType_Queue buffer[CAPACITY_QUEUE];
//     int idxHead;
//     int idxTail;
// } Queue;

// ********* AKSES (Selektor) ********* */
// Jika q adalah Queue, maka akses elemen : */
// #define IDX_HEAD(q) (q).idxHead
// #define IDX_TAIL(q) (q).idxTail
// #define     HEAD(q) (q).buffer[(q).idxHead]
// #define     TAIL(q) (q).buffer[(q).idxTail]

// *** Kreator *** */

void CreateQueue(Queue *q)
{
    IDX_HEAD(*q) = IDX_UNDEF;
    IDX_TAIL(*q) = IDX_UNDEF;
}
// I.S. sembarang */
// F.S. Sebuah q kosong terbentuk dengan kondisi sbb: */
// - Index head bernilai IDX_UNDEF */
// - Index tail bernilai IDX_UNDEF */
// Proses : Melakukan alokasi, membuat sebuah q kosong */

// ********* Prototype ********* */

boolean isEmpty_Queue(Queue q)
{
    return (IDX_HEAD(q) == IDX_UNDEF && IDX_TAIL(q) == IDX_UNDEF);
}
// Mengirim true jika q kosong: lihat definisi di atas */

boolean isFull_Queue(Queue q)
{
    return (IDX_HEAD(q) == 0 && IDX_TAIL(q) == CAPACITY_QUEUE - 1);
}
// Mengirim true jika tabel penampung elemen q sudah penuh */
// yaitu jika index head bernilai 0 dan index tail bernilai CAPACITY_QUEUE-1 */

int length_Queue(Queue q)
{
    if (isEmpty_Queue(q))
    {
        return 0;
    }
    return (IDX_TAIL(q) - IDX_HEAD(q) + 1);
}
// Mengirimkan banyaknya elemen queue. Mengirimkan 0 jika q kosong. */

// *** Primitif Add/Delete *** */

void enqueue(Queue *q, ElType_Queue val)
{
    int prev_idx, current_idx;
    ElType_Queue temp;
    if (isEmpty_Queue(*q))
    {
        IDX_HEAD(*q) = 0;
        IDX_TAIL(*q) = 0;
        TAIL(*q) = copyItem(val);
    }
    else
    {
        if (IDX_TAIL(*q) == CAPACITY_QUEUE - 1)
        {
            //Kondisi penuh semu
            for (int i = IDX_HEAD(*q); i <= IDX_TAIL(*q); i++)
            {
                (*q).buffer[i - IDX_HEAD(*q)] = (*q).buffer[i];
            }
            IDX_TAIL(*q) -= IDX_HEAD(*q);
            IDX_HEAD(*q) = 0;
        }
        IDX_TAIL(*q)++;
        TAIL(*q) = copyItem(val);
        //masukkan val sesuai priority
        prev_idx = IDX_TAIL(*q) - 1;
        current_idx = IDX_TAIL(*q);

        while (((*q).buffer[prev_idx].tServe > (*q).buffer[current_idx].tServe) && current_idx > IDX_HEAD(*q)){
            temp = (*q).buffer[prev_idx];
            (*q).buffer[prev_idx] = (*q).buffer[current_idx];
            (*q).buffer[current_idx] = temp;
            prev_idx--;
            current_idx--;
        }
    }
}

// Proses: Menambahkan val pada q dengan aturan FIFO */
// I.S. q mungkin kosong, tabel penampung elemen q TIDAK penuh */
// F.S. val menjadi TAIL yang baru, IDX_TAIL "mundur".
// Jika q penuh semu, maka perlu dilakukan aksi penggeseran "maju" elemen-elemen q
// menjadi rata kiri untuk membuat ruang kosong bagi TAIL baru  */

void dequeue(Queue *q, ElType_Queue *val)
{
/* Proses: Menghapus val pada q dengan aturan FIFO */
/* I.S. q tidak mungkin kosong */
/* F.S. val = nilai elemen HEAD pd I.S., HEAD dan IDX_HEAD "mundur"; 
        q mungkin kosong */
    *val = copyItem(HEAD(*q));
    if (IDX_HEAD(*q) == IDX_TAIL(*q))
    {
        IDX_HEAD(*q) = IDX_UNDEF;
        IDX_TAIL(*q) = IDX_UNDEF;
    }
    else
    {
        IDX_HEAD(*q)++;
    }
}
// Proses: Menghapus val pada q dengan aturan FIFO */
// I.S. q tidak mungkin kosong */
// F.S. val = nilai elemen HEAD pd I.S., HEAD dan IDX_HEAD "mundur";
// q mungkin kosong */

// *** Display Queue *** */

void displayQueue(Queue q)
{
    int cnt = 1;
    if (isEmpty_Queue(q))
    {
        printf("Belum ada pesanan masuk saat ini.\n");
    }
    else
    {
        for (int i = IDX_HEAD(q); i <= IDX_TAIL(q); i++)
        {
            printf("%d. %c -> %c ", cnt, q.buffer[i].pickUp, q.buffer[i].dropOff);
            if (TYPE(q.buffer[i]) == 'N'){
                printf("(Normal Item)");
            }
            else if (TYPE(q.buffer[i]) == 'H'){
                printf("(Heavy Item)");
            }
            else if (TYPE(q.buffer[i]) == 'V'){
                printf("(VIP Item)");
            }
            else{
                printf("(Perishable Item, sisa waktu %d)", PTIME(q.buffer[i]));
            }
            printf("\n");
            cnt++;
        }
    }
}
// Proses : Menuliskan isi Queue dengan traversal, Queue ditulis di antara kurung
//    siku; antara dua elemen dipisahkan dengan separator "koma", tanpa tambahan
//    karakter di depan, di tengah, atau di belakang, termasuk spasi dan enter */
// I.S. q boleh kosong */
// F.S. Jika q tidak kosong: [e1,e2,...,en] */
// Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [1,20,30] */
// Jika Queue kosong : menulis [] */
