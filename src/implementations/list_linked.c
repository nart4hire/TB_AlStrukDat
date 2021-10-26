// File : list_linked.h
// contoh ADT list berkait dengan representasi fisik pointer
// Representasi Address dengan pointer
// ElType_ListLinked adalah integer

#include <stdio.h>
#include <stdlib.h>
#include "list_linked.h"

// typedef Address ListLinked;

// #define IDX_UNDEF (-1)
// #define FIRST(l) (l)

// Definisi ListLinked :
// ListLinked kosong : FIRST(l) = NULL
// Setiap elemen dengan Address p dapat diacu INFO(p), NEXT(p)
// Elemen terakhir list: jika addressnya Last, maka NEXT(Last)=NULL

// PROTOTYPE
//***************** PEMBUATAN LIST KOSONG *****************


void CreateListLinked(ListLinked *l)
{
    FIRST(*l) = NULL;
}
// I.S. sembarang
// F.S. Terbentuk list kosong


//***************** TEST LIST KOSONG *****************


boolean isEmpty_ListLinked(ListLinked l)
{
    return (FIRST(l) == NULL);
}
// Mengirim true jika list kosong


//***************** GETTER SETTER *****************


ElType_ListLinked getElmt_ListLinked(ListLinked l, int idx)
{
    Address current_node = FIRST(l);
    for (int i = 0; i < idx; i++)
        current_node = NEXT(current_node);
    return INFO(current_node);
}
// I.S. l terdefinisi, idx indeks yang valid dalam l, yaitu 0..length_ListLinked(l)
// F.S. Mengembalikan nilai elemen l pada indeks idx


void setElmt_ListLinked(ListLinked *l, int idx, ElType_ListLinked val)
{
    Address current_node = FIRST(*l);
    for (int i = 0; i < idx; i++)
        current_node = NEXT(current_node);
    INFO(current_node) = val;
}
// I.S. l terdefinisi, idx indeks yang valid dalam l, yaitu 0..length_ListLinked(l)
// F.S. Mengubah elemen l pada indeks ke-idx menjadi val


int indexOf_ListLinked(ListLinked l, ElType_ListLinked val)
{
    Address current_node = FIRST(l);
    int idx = 0;
    while (INFO(current_node) != val && NEXT(current_node) != NULL)
    {
        current_node = NEXT(current_node);
        ++idx;
    }
    if (INFO(current_node) == val)
        return idx;
    else
        return IDX_UNDEF;
}
// I.S. l, val terdefinisi
// F.S. Mencari apakah ada elemen list l yang bernilai val
// Jika ada, mengembalikan indeks elemen pertama l yang bernilai val
// Mengembalikan IDX_UNDEF jika tidak ditemukan


//***************** PRIMITIF BERDASARKAN NILAI *****************
//** PENAMBAHAN ELEMEN **


void insertFirst_ListLinked(ListLinked *l, ElType_ListLinked val)
{
    Address temp_node = FIRST(*l);
    FIRST(*l) = newNode(val);
    if (temp_node != NULL)
        NEXT(FIRST(*l)) = temp_node;        
}
// I.S. l mungkin kosong
// F.S. Melakukan alokasi sebuah elemen dan
// menambahkan elemen pertama dengan nilai val jika alokasi berhasil.
// Jika alokasi gagal: I.S.= F.S.


void insertLast_ListLinked(ListLinked *l, ElType_ListLinked val)
{
    Address current_node = FIRST(*l);
    if (isEmpty_ListLinked(*l))
        FIRST(*l) = newNode(val);
    else
    {
        while (NEXT(current_node) != NULL)
            current_node = NEXT(current_node);
        NEXT(current_node) = newNode(val);
    }
}
// I.S. l mungkin kosong
// F.S. Melakukan alokasi sebuah elemen dan
// menambahkan elemen list di akhir: elemen terakhir yang baru
// bernilai val jika alokasi berhasil. Jika alokasi gagal: I.S.= F.S.


void insertAt_ListLinked(ListLinked *l, ElType_ListLinked val, int idx)
{
    Address current_node = FIRST(*l), prev_node = NULL;
    for (int i = 0; i < idx; i++)
    {
        prev_node = current_node;
        current_node = NEXT(current_node);
    }
    if (prev_node == NULL)
    {
        FIRST(*l) = newNode(val);
        NEXT(FIRST(*l)) = current_node;
    }
    else
    {
        NEXT(prev_node) = newNode(val);
        NEXT(NEXT(prev_node)) = current_node;
    }
}
// I.S. l tidak mungkin kosong, idx indeks yang valid dalam l, yaitu 0..length_ListLinked(l)
// F.S. Melakukan alokasi sebuah elemen dan
// menyisipkan elemen dalam list pada indeks ke-idx (bukan menimpa elemen di i)
// yang bernilai val jika alokasi berhasil. Jika alokasi gagal: I.S.= F.S.


//** PENGHAPUSAN ELEMEN **


void deleteFirst_ListLinked(ListLinked *l, ElType_ListLinked *val)
{
    Address temp_node = FIRST(*l);
    *val = INFO(temp_node);
    if (NEXT(FIRST(*l)) == NULL)
        FIRST(*l) = NULL;
    else
        FIRST(*l) = NEXT(FIRST(*l));
    free(temp_node);
}
// I.S. ListLinked l tidak kosong
// F.S. Elemen pertama list dihapus: nilai info disimpan pada x
//      dan alamat elemen pertama di-dealokasi


void deleteLast_ListLinked(ListLinked *l, ElType_ListLinked *val)
{
    Address current_node = FIRST(*l), prev_node = NULL;
    while (NEXT(current_node) != NULL)
    {
        prev_node = current_node;
        current_node = NEXT(current_node);
    }
    *val = INFO(current_node);
    if (prev_node == NULL)
        FIRST(*l) = NULL;
    else
        NEXT(prev_node) = NULL;
    free(current_node);
}
// I.S. list tidak kosong
// F.S. Elemen terakhir list dihapus: nilai info disimpan pada x
//      dan alamat elemen terakhir di-dealokasi


void deleteAt_ListLinked(ListLinked *l, int idx, ElType_ListLinked *val)
{
    Address current_node = FIRST(*l), prev_node = NULL;
    for (int i = 0; i < idx; i++)
    {
        prev_node = current_node;
        current_node = NEXT(current_node);
    }
    *val = INFO(current_node);
    if (prev_node == NULL)
        FIRST(*l) = NEXT(current_node);
    else
        NEXT(prev_node) = NEXT(current_node);
    free(current_node);
}
// I.S. list tidak kosong, idx indeks yang valid dalam l, yaitu 0..length_ListLinked(l)
// F.S. val diset dengan elemen l pada indeks ke-idx.
//      Elemen l pada indeks ke-idx dihapus dari l


//***************** PROSES SEMUA ELEMEN LIST *****************


void printInfo(ListLinked l)
{
    Address node = FIRST(l);
    if (NEXT(node) != NULL)
        printf("%d,", INFO(node));
    else
        printf("%d", INFO(node));
}

void displayList_ListLinked(ListLinked l)
{
    Address current_node = FIRST(l);
    printf("[");
    while (current_node != NULL)
    {
        printInfo(current_node);
        current_node = NEXT(current_node);
    }
    printf("]");
}
// I.S. ListLinked mungkin kosong
// F.S. Jika list tidak kosong, iai list dicetak ke kanan: [e1,e2,...,en]
// Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [1,20,30]
// Jika list kosong : menulis []
// Tidak ada tambahan karakter apa pun di awal, akhir, atau di tengah


int length_ListLinked(ListLinked l)
{
    Address current_node = FIRST(l);
    int i = 0;
    if (isEmpty_ListLinked(l))
        return 0;
    else
    {
        while (NEXT(current_node) != NULL)
        {
            current_node = NEXT(current_node);
            ++i;
        }
        return ++i;
    }
}
// Mengirimkan banyaknya elemen list; mengirimkan 0 jika list kosong


//***************** PROSES TERHADAP LIST *****************


ListLinked concat(ListLinked l1, ListLinked l2)
{
    ListLinked l3;
    CreateListLinked(&l3);
    Address current_l1 = FIRST(l1), current_l2 = FIRST(l2);
    while (current_l1 != NULL)
    {
        insertLast_ListLinked(&l3, INFO(current_l1));
        current_l1 = NEXT(current_l1);
    }
    while (current_l2 != NULL)
    {
        insertLast_ListLinked(&l3, INFO(current_l2));
        current_l2 = NEXT(current_l2);
    }
    return l3;
}
// I.S. l1 dan l2 sembarang
// F.S. l1 dan l2 kosong, l3 adalah hasil konkatenasi l1 & l2
// Konkatenasi dua buah list : l1 dan l2
// menghasilkan l3 yang baru (dengan elemen list l1 dan l2 secara beurutan).
// Tidak ada alokasi/dealokasi pada prosedur ini

