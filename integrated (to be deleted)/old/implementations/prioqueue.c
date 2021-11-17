#include "prioqueue.h"
#include <stdlib.h>
#include <stdio.h>


/* *** Kreator *** */
void CreatePrioQueue(PrioQueue *pq){
    /* I.S. sembarang */
    /* F.S. Sebuah pq kosong terbentuk dengan kondisi sbb: */
    /* - Index head bernilai IDX_UNDEF */
    /* - Index tail bernilai IDX_UNDEF */
    /* Proses : Melakukan alokasi, membuat sebuah pq kosong */
    IDX_HEAD_PQ(*pq) = IDX_UNDEF;
    IDX_TAIL_PQ(*pq) = IDX_UNDEF;
}

boolean isEmpty(PrioQueue pq){
    /* Mengirim true jika pq kosong: lihat definisi di atas */
    return (IDX_HEAD_PQ(pq) == IDX_UNDEF && IDX_TAIL_PQ(pq) == IDX_UNDEF);
}

boolean isFull(PrioQueue pq){
    /* Mengirim true jika tabel penampung elemen pq sudah penuh */
    /* yaitu jika index head bernilai 0 dan index tail bernilai CAPACITY-1 */
    return (IDX_HEAD_PQ(pq) == 0 && IDX_TAIL_PQ(pq) == CAPACITY-1);
}

int lengthPrioQueue(PrioQueue pq){
    /* Mengirimkan banyaknya elemen queue. Mengirimkan 0 jika q kosong. */
    if (isEmpty(pq)) {
        return 0;
    } 
    else {
        return (IDX_TAIL_PQ(pq) - IDX_HEAD_PQ(pq) + 1);
    }
}

/*** Primitif Add/Delete ***/
void enqueue_PrioQueue(PrioQueue *pq, Pesanan val)
{
  if(isEmpty(*pq)){
    IDX_HEAD_PQ(*pq) = 0;
    IDX_TAIL_PQ(*pq) = 0;
    TAIL(*pq) = val;
  }else{
    if(IDX_HEAD_PQ(*pq) != 0 && IDX_TAIL_PQ(*pq) == CAPACITY - 1){
      // geserKiri(pq);
    }
    boolean found = false;
    for(int i = IDX_HEAD_PQ(*pq); i <= IDX_TAIL_PQ(*pq); i++){
      if(val.t < (*pq).buffer[i].t){
        found = true;
        for(int j = IDX_TAIL_PQ(*pq); j >= i; j--){
          (*pq).buffer[j+1] = (*pq).buffer[j];
        }
        (*pq).buffer[i] = val;
        break;
      }
    }
    IDX_TAIL_PQ(*pq)++;
    if(!found){
      TAIL(*pq) = val;
    }
  }
}


void dequeue_PrioQueue(PrioQueue * pq, Pesanan *val){
    /* Proses: Menghapus val pada q dengan aturan FIFO */
    /* I.S. pq tidak mungkin kosong */
    /* F.S. val = nilai elemen HEAD pd
    I.S., HEAD dan IDX_HEAD_PQ "mundur"; 
            pq mungkin kosong */
    *val = HEAD(*pq);
    if (IDX_HEAD_PQ(*pq) == IDX_TAIL_PQ(*pq)) {
        IDX_HEAD_PQ(*pq) = IDX_UNDEF;
        IDX_TAIL_PQ(*pq) = IDX_UNDEF;
    } 
    else {
        IDX_HEAD_PQ(*pq)++;
    }
}
