// File : list_order.c
// contoh ADT list berkait dengan representasi fisik pointer
// Representasi Address_order dengan pointer
// ElType_ListLinked adalah integer

#include <stdio.h>
#include <stdlib.h>
#include "inprogress.h"

/****************** PEMBUATAN LIST KOSONG ******************/
void CreateListInPro(ListLinked_order *l){
/* I.S. sembarang             */
/* F.S. Terbentuk list kosong */
    FIRST(*l) = NULL;
}

/****************** TEST LIST KOSONG ******************/
boolean isEmpty_ListInPro(ListLinked_order l){
/* Mengirim true jika list kosong */
    return (FIRST(l) == NULL);
}


/****************** GETTER SETTER ******************/
Time getTServe_ListInPro(ListLinked_order l, int idx){
/* I.S. l terdefinisi, idx indeks yang valid dalam l, yaitu 0..length_ListLinked(l) */
/* F.S. Mengembalikan waktu pesanan list l pada indeks idx */
    Address_order current_node = FIRST(l);
    for (int i = 0; i < idx; i++)
        current_node = NEXT(current_node);
    return T_SERVE(current_node);
}

char getPickUp_ListInPro(ListLinked_order l, int idx){
/* I.S. l terdefinisi, idx indeks yang valid dalam l, yaitu 0..length_ListLinked(l) */
/* F.S. Mengembalikan posisi pick up pesanan list l pada indeks idx */
    Address_order current_node = FIRST(l);
    for (int i = 0; i < idx; i++)
        current_node = NEXT(current_node);
    return ' ';
}

char getDrop_ListInPro(ListLinked_order l, int idx){
/* I.S. l terdefinisi, idx indeks yang valid dalam l, yaitu 0..length_ListLinked(l) */
/* F.S. Mengembalikan posisi drop pesanan list l pada indeks idx */
    Address_order current_node = FIRST(l);
    for (int i = 0; i < idx; i++)
        current_node = NEXT(current_node);
    return DROP(current_node);
}

char getItem_ListInPro(ListLinked_order l, int idx){
/* I.S. l terdefinisi, idx indeks yang valid dalam l, yaitu 0..length_ListLinked(l) */
/* F.S. Mengembalikan item pesanan list l pada indeks idx */
    Address_order current_node = FIRST(l);
    for (int i = 0; i < idx; i++)
        current_node = NEXT(current_node);
    return ITEM(current_node);
}

Time getPerTime_ListInPro(ListLinked_order l, int idx){
/* I.S. l terdefinisi, idx indeks yang valid dalam l, yaitu 0..length_ListLinked(l) */
/* F.S. Mengembalikan perishable time pesanan list l pada indeks idx dengan tipe item P*/
    Address_order current_node = FIRST(l);
    for (int i = 0; i < idx; i++)
        current_node = NEXT(current_node);
    return PER_TIME(current_node);
}

int indexOf_ListInPro(ListLinked_order l, Time t_serve){
/* I.S. l, t_serve terdefinisi */
/* F.S. Mencari apakah ada elemen list l yang bernilai t_serve */
/* Jika ada, mengembalikan indeks elemen pertama l yang bernilai t_serve */
/* Mengembalikan IDX_UNDEF jika tidak ditemukan */
    Address_order current_node = FIRST(l);
    int idx = 0;
    while ((T_SERVE(current_node) != t_serve) && (NEXT(current_node) != NULL))
    {
        current_node = NEXT(current_node);
        ++idx;
    }
    if (T_SERVE(current_node) == t_serve)
        return idx;
    else
        return IDX_UNDEF;
}

/****************** PRIMITIF BERDASARKAN NILAI ******************/
/*** PENAMBAHAN ELEMEN ***/
void insertFirst_ListInPro(ListLinked_order *l, Time t_serve, char pickUp, char dropOff, char item, Time perTime){
/* I.S. l mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen pertama dengan nilai t_serve, pickUp, dropOff, item, dan perTime jika alokasi berhasil. */
/* Jika alokasi gagal: I.S.= F.S. */
    /*Kamus*/
    Address_order p;
    /*Algoritma*/
    p = newNode_order(t_serve, dropOff, item, perTime);
    if (p != NULL){
        NEXT(p) = *l;
        *l = p;
    }
}


void insertLast_ListInPro(ListLinked_order *l, Time t_serve, char pickUp, char dropOff, char item, Time perTime){
/* I.S. l mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen list di akhir dengan nilai t_serve, pickUp, dropOff, item, dan perTime jika alokasi berhasil */
/* Jika alokasi gagal: I.S.= F.S. */
    /*Kamus*/
    Address_order p, last;
    /*Algoritma*/
    p = newNode_order(t_serve, dropOff, item, perTime);
    if (isEmpty_ListInPro(*l)){
        if (p != NULL){
            NEXT(p) = *l;
            *l = p;
        }
    }
    else{
        if (p != NULL){
            last = *l;
            while (NEXT(last) != NULL){
                last = NEXT(last);
            }
            NEXT(last) = p;
        }
    }
}


void insertAt_ListInPro(ListLinked_order *l, Time t_serve, char pickUp, char dropOff, char item, Time perTime, int idx){
/* I.S. l tidak mungkin kosong, idx indeks yang valid dalam l, yaitu 0..length_ListLinked(l) */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menyisipkan elemen dalam list pada indeks ke-idx (bukan menimpa elemen di i) */
/* dengan nilai t_serve, pickUp, dropOff, item, dan perTime jika alokasi berhasil jika alokasi berhasil. Jika alokasi gagal: I.S.= F.S. */
    /*Kamus*/
    Address_order p, loc;
    int pos;
    /*Algoritma*/
    if (idx == 0){
        insertFirst_ListInPro(l, t_serve, pickUp, dropOff, item, perTime);
    }
    else{
        p = newNode_order(t_serve, dropOff, item, perTime);
        pos = 0;
        loc = *l;
        if (p != NULL){
            while (pos < idx-1){
                pos++;
                loc = NEXT(loc);
            }
            NEXT(p) = NEXT(loc);
            NEXT(loc) = p;
        }
    }
}


/*** PENGHAPUSAN ELEMEN ***/
void deleteFirst_ListInPro(ListLinked_order *l, Time *t_serve, char *pickUp, char *dropOff, char *item, Time *perTime){
/* I.S. ListLinked_order l tidak kosong  */
/* F.S. Elemen pertama list dihapus: nilai info disimpan pada pada masing masing variabel */
/*      dan alamat elemen pertama di-dealokasi */
    /*Kamus*/
    Address_order p;
    /*Algoritma*/
    p = *l;
    *t_serve = T_SERVE(p);
    *pickUp = ' ';
    *dropOff = DROP(p);
    *item = ITEM(p);
    *perTime = PER_TIME(p);
    *l = NEXT(p);
    free(p);    
}


void deleteLast_ListInPro(ListLinked_order *l, Time *t_serve, char *pickUp, char *dropOff, char *item, Time *perTime){
/* I.S. list tidak kosong */
/* F.S. Elemen terakhir list dihapus: nilai info disimpan pada masing masing variabel */
/*      dan alamat elemen terakhir di-dealokasi */
    /*Kamus*/
    Address_order p, loc;
    /*Algoritma*/
    p = *l;
    loc = NULL;
    while (NEXT(p) != NULL){
        loc = p;
        p = NEXT(p);
    }
    if (loc == NULL){
        /*List menjadi kosong*/
        *l = NULL;
    }
    else{
        NEXT(loc) = NULL;
    }
    *t_serve = T_SERVE(p);
    *pickUp = ' ';
    *dropOff = DROP(p);
    *item = ITEM(p);
    *perTime = PER_TIME(p);
    *l = NEXT(p);
    free(p);
}


void deleteAt_ListInPro(ListLinked_order *l, Time *t_serve, char *pickUp, char *dropOff, char *item, Time *perTime, int idx){
/* I.S. list tidak kosong, idx indeks yang valid dalam l, yaitu 0..length_ListLinked(l) */
/* F.S. nilai info disimpan pada masing masing variabel sesuai indeks ke-idx. */
/*      Elemen l pada indeks ke-idx dihapus dari l */
    /*Kamus*/
    int pos;
    Address_order p, loc;
    /*Algoritma*/
    if (idx == 0){
        deleteFirst_ListInPro(l, t_serve, pickUp, dropOff, item, perTime);
    }
    else{
        pos = 0;
        p = *l;
        while (pos < idx-1){
            p = NEXT(p);
            pos++;
        }
        loc = NEXT(p);
        NEXT(p) = NEXT(loc);
        *t_serve = T_SERVE(p);
        *pickUp = ' ';
        *dropOff = DROP(p);
        *item = ITEM(p);
        *perTime = PER_TIME(p);
        *l = NEXT(p);
        free(loc);
    }
}

/****************** PROSES SEMUA ELEMEN LIST ******************/
int length_ListInPro(ListLinked_order l){
/* Mengirimkan banyaknya elemen list; mengirimkan 0 jika list kosong */
    /*Kamus*/
    int cnt;
    Address_order p;
    /*Algoritma*/
    cnt = 0;
    p = l;
    while (p != NULL){
        cnt++;
        p = NEXT(p);
    }
    return cnt;
}
