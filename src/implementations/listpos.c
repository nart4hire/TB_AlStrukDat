/* MODUL LIST INTEGER DENGAN ELEMEN POSITIF */
/* Berisi definisi dan semua primitif pemrosesan list integer dengan elemen 
   positif */
/* Penempatan elemen selalu rapat kiri */
/* Banyaknya elemen didefinisikan secara implisit, memori array statik */

#include <stdio.h>
#include "listpos.h"

/* ********** KONSTRUKTOR ********** */
/* Konstruktor : create List kosong  */

void CreateListPos(ListPos *l)
{
    for (int i = 0; i < CAPACITY_LISTPOS; i++)
    {
        ELMT_LISTPOS(*l, i) = VAL_UNDEF;
    }
}
/* I.S. l sembarang */
/* F.S. Terbentuk List l kosong dengan kapasitas CAPACITY_LISTPOS */
/* Proses: Inisialisasi semua elemen List l dengan VAL_UNDEF */

/* ********** SELEKTOR (TAMBAHAN) ********** */
/* *** Banyaknya elemen *** */

int length_ListPos(ListPos l)
{
    int i = 0;
    while (i < CAPACITY_LISTPOS && ELMT_LISTPOS(l, i) != VAL_UNDEF)
    {
        i++;
    }
    return i;
}
/* Mengirimkan banyaknya elemen efektif List */
/* Mengirimkan nol jika List kosong */

/* ********** Test Indeks yang valid ********** */

boolean isIdxValid_ListPos(ListPos l, int i)
{
    return (i > IDX_UNDEF && i < CAPACITY_LISTPOS);
}
/* Mengirimkan true jika i adalah indeks yang valid utk kapasitas List l */
/* yaitu antara indeks yang terdefinisi utk container*/

boolean isIdxEff_ListPos(ListPos l, int i)
{
    return (i > IDX_UNDEF && i < length_ListPos(l));
}
/* Mengirimkan true jika i adalah indeks yang terdefinisi utk List l */
/* yaitu antara 0..length_ListPos(l)-1 */

/* ********** TEST KOSONG/PENUH ********** */
/* *** Test List kosong *** */

boolean isEmpty_ListPos(ListPos l)
{
    return (length_ListPos(l) == 0);
}
/* Mengirimkan true jika List l kosong, mengirimkan false jika tidak */
/* *** Test List penuh *** */

boolean isFull_ListPos(ListPos l)
{
    return (length_ListPos(l) == CAPACITY_LISTPOS);
}
/* Mengirimkan true jika List l penuh, mengirimkan false jika tidak */

/* ********** BACA dan TULIS dengan INPUT/OUTPUT device ********** */
/* *** Mendefinisikan isi List dari pembacaan *** */

void readList_ListPos(ListPos *l)
{
    int n;
    ElType x;
    CreateListPos(l);
    do
    {
        scanf("%d", &n);
    } while (n < 0 || n > CAPACITY_LISTPOS);
    if (n > 0)
    {
        for (int i = 0; i < n; i++)
        {
            scanf("%d", &x);
            ELMT_LISTPOS(*l, i) = x;
        }
    }
}
/* I.S. l sembarang */
/* F.S. List l terdefinisi */
/* Proses: membaca banyaknya elemen l dan mengisi nilainya */
/* 1. Baca banyaknya elemen diakhiri enter, misalnya n */
/*    Pembacaan diulangi sampai didapat n yang benar yaitu 0 <= n <= CAPACITY_LISTPOS */
/*    Jika n tidak valid, tidak diberikan pesan kesalahan */
/* 2. Jika 0 < n <= CAPACITY_LISTPOS; Lakukan n kali: 
          Baca elemen mulai dari indeks 0 satu per satu diakhiri enter */
/*    Jika n = 0; hanya terbentuk List kosong */

void displayList_ListPos(ListPos l)
{
    int i;
    printf("[");
    if (!isEmpty_ListPos(l))
    {
        for (i = 0; i < length_ListPos(l) - 1; i++)
        {
            printf("%d,", ELMT_LISTPOS(l, i));
        }
        printf("%d", ELMT_LISTPOS(l, (i)));
    }
    printf("]");
}
/* Proses : Menuliskan isi List dengan traversal, List ditulis di antara kurung 
   siku; antara dua elemen dipisahkan dengan separator "koma", tanpa tambahan 
   karakter di depan, di tengah, atau di belakang, termasuk spasi dan enter */
/* I.S. l boleh kosong */
/* F.S. Jika l tidak kosong: [e1,e2,...,en] */
/* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [1,20,30] */
/* Jika List kosong : menulis [] */

/* ********** OPERATOR ARITMATIKA ********** */
/* *** Aritmatika List : Penjumlahan, pengurangan, perkalian, ... *** */

ListPos plusMinusTab(ListPos l1, ListPos l2, boolean plus)
{
    int len = length_ListPos(l1);
    ListPos l;
    CreateListPos(&l);
    if (plus)
    {
        for (int i = 0; i < len; i++)
        {
            ELMT_LISTPOS(l, i) = ELMT_LISTPOS(l1, i) + ELMT_LISTPOS(l2, i);
        }
    }
    else if (!plus)
    {
        for (int i = 0; i < len; i++)
        {
            ELMT_LISTPOS(l, i) = ELMT_LISTPOS(l1, i) - ELMT_LISTPOS(l2, i);
        }
    }
    return l;
}
/* Prekondisi : l1 dan l2 berukuran sama dan tidak kosong */
/* Jika plus = true, mengirimkan  l1+l2, yaitu setiap elemen l1 dan l2 pada 
       indeks yang sama dijumlahkan */
/* Jika plus = false, mengirimkan l1-l2, yaitu setiap elemen l1 dikurangi 
       elemen l2 pada indeks yang sama */

/* ********** OPERATOR RELASIONAL ********** */
/* *** Operasi pembandingan List: *** */

boolean isListEqual_ListPos(ListPos l1, ListPos l2)
{
    int len = length_ListPos(l1);
    if (len == length_ListPos(l2))
    {
        for (int i = 0; i < len; i++)
        {
            if (ELMT_LISTPOS(l1, i) != ELMT_LISTPOS(l2, i))
            {
                return false;
            }
        }
        return true;
    }
    return false;
}
/* Mengirimkan true jika l1 sama dengan l2 yaitu jika ukuran l1 = l2 dan semua 
   elemennya sama */

/* ********** SEARCHING ********** */
/* ***  Perhatian : List boleh kosong!! *** */

int indexOf_ListPos(ListPos l, ElType val)
{
    for (int i = 0; i < length_ListPos(l); i++)
    {
        if (ELMT_LISTPOS(l, i) == val)
        {
            return i;
        }
    }
    return IDX_UNDEF;
}
/* Search apakah ada elemen List l yang bernilai val */
/* Jika ada, menghasilkan indeks i terkecil, dengan ELMT_LISTPOS(l,i) = val */
/* Jika tidak ada atau jika l kosong, mengirimkan IDX_UNDEF */
/* Skema Searching yang digunakan bebas */

/* ********** NILAI EKSTREM ********** */

void extremes_ListPos(ListPos l, ElType *max, ElType *min)
{
    *max = ELMT_LISTPOS(l, 0);
    *min = ELMT_LISTPOS(l, 0);
    for (int i = 1; i < length_ListPos(l); i++)
    {
        if (ELMT_LISTPOS(l, i) > *max)
        {
            *max = ELMT_LISTPOS(l, i);
        }
        if (ELMT_LISTPOS(l, i) < *min)
        {
            *min = ELMT_LISTPOS(l, i);
        }
    }
}
/* I.S. List l tidak kosong */
/* F.S. Max berisi nilai terbesar dalam l;
        Min berisi nilai terkecil dalam l */

/* ********** OPERASI LAIN ********** */

boolean isAllEven_ListPos(ListPos l)
{
    for (int i = 0; i < length_ListPos(l); i++)
    {
        if (ELMT_LISTPOS(l, i) % 2 == 1)
        {
            return false;
        }
    }
    return true;
}
/* Menghailkan true jika semua elemen l genap */

/* ********** SORTING ********** */

void sort_ListPos(ListPos *l, boolean asc)
{
    int key, i, j;
    if (asc)
    {
        for (i = 1; i < length_ListPos(*l); i++)
        {
            key = ELMT_LISTPOS(*l, i);
            j = i - 1;
            while (j >= 0 && ELMT_LISTPOS(*l, j) > key)
            {
                ELMT_LISTPOS(*l, (j + 1)) = ELMT_LISTPOS(*l, j);
                j = j - 1;
            }
            ELMT_LISTPOS(*l, (j + 1)) = key;
        }
    }
    else
    {
        for (i = 1; i < length_ListPos(*l); i++)
        {
            key = ELMT_LISTPOS(*l, i);
            j = i - 1;
            while (j >= 0 && ELMT_LISTPOS(*l, j) < key)
            {
                ELMT_LISTPOS(*l, (j + 1)) = ELMT_LISTPOS(*l, j);
                j = j - 1;
            }
            ELMT_LISTPOS(*l, (j + 1)) = key;
        }
    }
}
/* I.S. l boleh kosong */
/* F.S. Jika asc = true, l terurut membesar */
/*      Jika asc = false, l terurut mengecil */
/* Proses : Mengurutkan l dengan salah satu algoritma sorting,
   algoritma bebas */

/* ********** MENAMBAH DAN MENGHAPUS ELEMEN DI AKHIR ********** */
/* *** Menambahkan elemen terakhir *** */

void insertLast_ListPos(ListPos *l, ElType val)
{
    ELMT_LISTPOS(*l, length_ListPos(*l)) = val;
}
/* Proses: Menambahkan val sebagai elemen terakhir List */
/* I.S. List l boleh kosong, tetapi tidak penuh */
/* F.S. val adalah elemen terakhir l yang baru */
/* ********** MENGHAPUS ELEMEN ********** */

void deleteLast_ListPos(ListPos *l, ElType *val)
{
    *val = ELMT_LISTPOS(*l, (length_ListPos(*l) - 1));
    ELMT_LISTPOS(*l, (length_ListPos(*l) - 1)) = VAL_UNDEF;
}
/* Proses : Menghapus elemen terakhir List */
/* I.S. List tidak kosong */
/* F.S. val adalah nilai elemen terakhir l sebelum penghapusan, */
/*      Banyaknya elemen List berkurang satu */
/*      List l mungkin menjadi kosong */
