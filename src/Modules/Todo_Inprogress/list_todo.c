// File : list_order.c
// contoh ADT list berkait dengan representasi fisik pointer
// Representasi Address dengan pointer
// ElType_ListLinked adalah integer

#include <stdio.h>
#include <stdlib.h>
#include "list_todo.h"

/****************** PEMBUATAN LIST KOSONG ******************/
void CreateListOrder(ListLinked *l){
/* I.S. sembarang             */
/* F.S. Terbentuk list kosong */
    FIRST(*l) = NULL;
}

/****************** TEST LIST KOSONG ******************/
boolean isEmpty_ListOrder(ListLinked l){
/* Mengirim true jika list kosong */
    return (FIRST(l) == NULL);
}


/****************** GETTER SETTER ******************/
Time getTServe_ListOrder(ListLinked l, int idx){
/* I.S. l terdefinisi, idx indeks yang valid dalam l, yaitu 0..length_ListLinked(l) */
/* F.S. Mengembalikan waktu pesanan list l pada indeks idx */
    Address current_node = FIRST(l);
    for (int i = 0; i < idx; i++)
        current_node = NEXT(current_node);
    return T_SERVE(current_node);
}

char getPickUp_ListOrder(ListLinked l, int idx){
/* I.S. l terdefinisi, idx indeks yang valid dalam l, yaitu 0..length_ListLinked(l) */
/* F.S. Mengembalikan posisi pick up pesanan list l pada indeks idx */
    Address current_node = FIRST(l);
    for (int i = 0; i < idx; i++)
        current_node = NEXT(current_node);
    return PICK(current_node);
}

char getDrop_ListOrder(ListLinked l, int idx){
/* I.S. l terdefinisi, idx indeks yang valid dalam l, yaitu 0..length_ListLinked(l) */
/* F.S. Mengembalikan posisi drop pesanan list l pada indeks idx */
    Address current_node = FIRST(l);
    for (int i = 0; i < idx; i++)
        current_node = NEXT(current_node);
    return DROP(current_node);
}

char getItem_ListOrder(ListLinked l, int idx){
/* I.S. l terdefinisi, idx indeks yang valid dalam l, yaitu 0..length_ListLinked(l) */
/* F.S. Mengembalikan item pesanan list l pada indeks idx */
    Address current_node = FIRST(l);
    for (int i = 0; i < idx; i++)
        current_node = NEXT(current_node);
    return ITEM(current_node);
}

Time getPerTime_ListOrder(ListLinked l, int idx){
/* I.S. l terdefinisi, idx indeks yang valid dalam l, yaitu 0..length_ListLinked(l) */
/* F.S. Mengembalikan perishable time pesanan list l pada indeks idx dengan tipe item P*/
    Address current_node = FIRST(l);
    for (int i = 0; i < idx; i++)
        current_node = NEXT(current_node);
    return PER_TIME(current_node);
}

int indexOfPick_ListOrder(ListLinked l, char pick){
/* I.S. l, t_serve terdefinisi */
/* F.S. Mencari apakah ada elemen list l yang bernilai t_serve */
/* Jika ada, mengembalikan indeks elemen pertama l yang bernilai t_serve */
/* Mengembalikan IDX_UNDEF jika tidak ditemukan */
    Address current_node = FIRST(l);
    int idx = 0;
    if (!isEmpty_ListOrder(l))
    {
        while ((PICK(current_node) != pick) && (NEXT(current_node) != NULL))
        {
            current_node = NEXT(current_node);
            ++idx;
        }
        if (PICK(current_node) == pick)
            return idx;
    }
    return IDX_UNDEF;
}

int indexOfDrop_ListOrder(ListLinked l, char drop){
/* I.S. l, t_serve terdefinisi */
/* F.S. Mencari apakah ada elemen list l yang bernilai t_serve */
/* Jika ada, mengembalikan indeks elemen pertama l yang bernilai t_serve */
/* Mengembalikan IDX_UNDEF jika tidak ditemukan */
    Address current_node = FIRST(l);
    int idx = 0;
    if (!isEmpty_ListOrder(l))
    {
        while ((DROP(current_node) != drop) && (NEXT(current_node) != NULL))
        {
            current_node = NEXT(current_node);
            ++idx;
        }
        if (DROP(current_node) == drop)
            return idx;
    }
    return IDX_UNDEF;
}
/****************** PRIMITIF BERDASARKAN NILAI ******************/
/*** PENAMBAHAN ELEMEN ***/
void insertFirst_ListOrder(ListLinked *l, item it){
/* I.S. l mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen pertama dengan nilai t_serve, pickUp, dropOff, item, dan perTime jika alokasi berhasil. */
/* Jika alokasi gagal: I.S.= F.S. */
    /*Kamus*/
    Address p;
    /*Algoritma*/
    p = newNode(it);
    if (p != NULL){
        NEXT(p) = *l;
        *l = p;
    }
}


void insertLast_ListOrder(ListLinked *l, item it){
/* I.S. l mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen list di akhir dengan nilai t_serve, pickUp, dropOff, item, dan perTime jika alokasi berhasil */
/* Jika alokasi gagal: I.S.= F.S. */
    /*Kamus*/
    Address p, last;
    /*Algoritma*/
    p = newNode(it);
    if (isEmpty_ListOrder(*l)){
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


void insertAt_ListOrder(ListLinked *l, item it, int idx){
/* I.S. l tidak mungkin kosong, idx indeks yang valid dalam l, yaitu 0..length_ListLinked(l) */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menyisipkan elemen dalam list pada indeks ke-idx (bukan menimpa elemen di i) */
/* dengan nilai t_serve, pickUp, dropOff, item, dan perTime jika alokasi berhasil jika alokasi berhasil. Jika alokasi gagal: I.S.= F.S. */
    /*Kamus*/
    Address p, loc;
    int pos;
    /*Algoritma*/
    if (idx == 0){
        insertFirst_ListOrder(l, it);
    }
    else{
        p = newNode(it);
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
void deleteFirst_ListOrder(ListLinked *l, item *it){
/* I.S. ListLinked l tidak kosong  */
/* F.S. Elemen pertama list dihapus: nilai info disimpan pada pada masing masing variabel */
/*      dan alamat elemen pertama di-dealokasi */
    /*Kamus*/
    Address p;
    /*Algoritma*/
    p = *l;
    TSERVE(*it) = TSERVE(INFO(p));
    PICKUP(*it) = PICKUP(INFO(p));
    DROPOFF(*it) = DROPOFF(INFO(p));
    TYPE(*it) = TYPE(INFO(p));
    PTIME(*it) = PTIME(INFO(p));
    *l = NEXT(p);
    free(p);    
}


void deleteLast_ListOrder(ListLinked *l, item *it){
/* I.S. list tidak kosong */
/* F.S. Elemen terakhir list dihapus: nilai info disimpan pada masing masing variabel */
/*      dan alamat elemen terakhir di-dealokasi */
    /*Kamus*/
    Address p, loc;
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
    TSERVE(*it) = TSERVE(INFO(p));
    PICKUP(*it) = PICKUP(INFO(p));
    DROPOFF(*it) = DROPOFF(INFO(p));
    TYPE(*it) = TYPE(INFO(p));
    PTIME(*it) = PTIME(INFO(p));
    free(p);
}


void deleteAt_ListOrder(ListLinked *l, item *it, int idx){
/* I.S. list tidak kosong, idx indeks yang valid dalam l, yaitu 0..length_ListLinked(l) */
/* F.S. nilai info disimpan pada masing masing variabel sesuai indeks ke-idx. */
/*      Elemen l pada indeks ke-idx dihapus dari l */
    /*Kamus*/
    int pos;
    Address p, loc;
    /*Algoritma*/
    if (idx == 0){
        deleteFirst_ListOrder(l, it);
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
        TSERVE(*it) = TSERVE(INFO(p));
        PICKUP(*it) = PICKUP(INFO(p));
        DROPOFF(*it) = DROPOFF(INFO(p));
        TYPE(*it) = TYPE(INFO(p));
        PTIME(*it) = PTIME(INFO(p));
        *l = NEXT(p);
        free(loc);
    }
}



/****************** PROSES SEMUA ELEMEN LIST ******************/
int length_ListOrder(ListLinked l){
/* Mengirimkan banyaknya elemen list; mengirimkan 0 jika list kosong */
    /*Kamus*/
    int cnt;
    Address p;
    /*Algoritma*/
    cnt = 0;
    p = l;
    while (p != NULL){
        cnt++;
        p = NEXT(p);
    }
    return cnt;
}

void displayList_ListOrder(ListLinked l)
{
    int cnt = 1;
    Address p = l;
    if (isEmpty_ListOrder(l))
    {
        printf("\n\"No orders have come in, Mobita looks at his to do list with disappointment. Maybe he\n");
        printf("should try moving around the city to kill some time he thinks to himself.\"\n");
    }
    else
    {
        while (p != NULL)
        {
            printf("%d. %c -> %c ", cnt, PICK(p), DROP(p));
            if (ITEM(p) == 'N'){
                printf("(Normal Item)");
            }
            else if (ITEM(p) == 'H'){
                printf("(Heavy Item)");
            }
            else if (ITEM(p) == 'V'){
                printf("(VIP Item)");
            }
            else{
                printf("(Perishable Item, sisa waktu %d)", PER_TIME(p));
            }
            printf("\n");
            cnt++;
            p = NEXT(p);
        }
    }
}