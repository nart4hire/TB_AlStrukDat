// MODUL LIST INTEGER
// Berisi definisi dan semua primitif pemrosesan list integer
// Penempatan elemen selalu rapat kiri
// Versi III : dengan banyaknya elemen didefinisikan secara implisit,
//    memori list dinamik

// #ifndef LISTDINPOS_H
// #define LISTDINPOS_H

#include <stdio.h>
#include <stdlib.h>
#include "listdinpos.h"

// Kamus Umum
// #define IDX_UNDEF -1
// Indeks tak terdefinisi
// #define VAL_UNDEF -999
// Nilai elemen tak terdefinisi

// Definisi elemen dan koleksi objek
// typedef int IdxType; // type indeks
// typedef int ElType;  // type elemen list
// typedef struct
// {
//   ElType *buffer; // memori tempat penyimpan elemen (container)
//   int capacity;  // ukuran elemen
// } ListDin;
// Indeks yang digunakan [0..capacity-1]
// Jika l adalah ListDin, cara deklarasi dan akses:
// Deklarasi : l : ListDin
// Maka cara akses:
//    l.buffer    untuk mengakses seluruh nilai elemen list
//    l.buffer[i] untuk mengakses elemen ke-i
// Definisi :
//   List kosong: semua elemen bernilai VAL_UNDEF
//   Definisi elemen pertama : l.buffer[i] dengan i=0
//   Definisi elemen terakhir yang terdefinisi: l.buffer[i] dengan i terbesar
//                                              sehingga l.buffer[i] != VAL_UNDEF
//   Definisi nEff: jumlah elemen efektif, di mana l.buffer[nEff] == VAL_UNDEF
//                                              dan l.buffer[nEff-1] != VAL_UNDEF

// ********** SELEKTOR **********
// #define BUFFER(l) (l).buffer
// #define ELMT_LISTDIN(l, i) (l).buffer[i]
// #define CAPACITY_LISTDIN(l) (l).capacity

// ********** KONSTRUKTOR **********
// Konstruktor : create list kosong

void CreateListDin(ListDin *l, int capacity)
{
    CAPACITY_LISTDIN(*l) = capacity;
    BUFFER(*l) = (ElType *)malloc(capacity * sizeof(ElType));
    for (int i = 0; i < capacity; i++)
    {
        ELMT_LISTDIN(*l, i) = VAL_UNDEF;
    }
}
// I.S. l sembarang, capacity > 0
// F.S. Terbentuk list l kosong dengan kapasitas capacity
// Proses: Inisialisasi semua elemen list l dengan VAL_UNDEF

void dealocate(ListDin *l)
{
    CAPACITY_LISTDIN(*l) = 0;
    free(BUFFER(*l));
}
// I.S. l terdefinisi;
// F.S. TI(l) dikembalikan ke system, CAPACITY_LISTDIN(l)=0; nEff(l)=0

// ********** SELEKTOR (TAMBAHAN) **********
// *** Banyaknya elemen ***

int length_ListDin(ListDin l)
{
    int i = 0;
    while (i < CAPACITY_LISTDIN(l) && ELMT_LISTDIN(l, i) != VAL_UNDEF)
    {
        i++;
    }
    return i;
}
// Mengirimkan banyaknya elemen efektif list
// Mengirimkan nol jika list kosong

// *** Selektor INDEKS ***

IdxType getLastIdx(ListDin l)
{
    IdxType idx = length_ListDin(l) - 1;
    return idx;
}
// Prekondisi : List l tidak kosong
// Mengirimkan indeks elemen l terakhir

// ********** Test Indeks yang valid **********

boolean isIdxValid_ListDin(ListDin l, IdxType i)
{
    return (i > IDX_UNDEF && i < CAPACITY_LISTDIN(l));
}
// Mengirimkan true jika i adalah indeks yang valid utk ukuran list
// yaitu antara indeks yang terdefinisi utk container

boolean isIdxEff_ListDin(ListDin l, IdxType i)
{
    return (i > IDX_UNDEF && i < length_ListDin(l));
}
// Mengirimkan true jika i adalah indeks yang terdefinisi utk list
// yaitu antara 0..getLastIdx(l)

// ********** TEST KOSONG/PENUH **********
// *** Test list kosong ***

boolean isEmpty_ListDin(ListDin l)
{
    return (length_ListDin(l) == 0);
}
// Mengirimkan true jika list l kosong, mengirimkan false jika tidak
// *** Test list penuh ***

boolean isFull_ListDin(ListDin l)
{
    return (length_ListDin(l) == CAPACITY_LISTDIN(l));
}
// Mengirimkan true jika list l penuh, mengirimkan false jika tidak

// ********** BACA dan TULIS dengan INPUT/OUTPUT device **********
// *** Mendefinisikan isi list dari pembacaan ***

void readList_ListDin(ListDin *l)
{
    int n;
    ElType x;
    do
    {
        scanf("%d", &n);
    } while (n < 0 || n > CAPACITY_LISTDIN(*l));
    if (n > 0)
    {
        for (int i = 0; i < n; i++)
        {
            scanf("%d", &x);
            ELMT_LISTDIN(*l, i) = x;
        }
    }
}
// I.S. l sembarang dan sudah dialokasikan sebelumnya
// F.S. List l terdefinisi
// Proses : membaca banyaknya elemen l dan mengisi nilainya
// 1. Baca banyaknya elemen diakhiri enter, misalnya N
//    Pembacaan diulangi sampai didapat N yang benar yaitu 0 <= N <= CAPACITY_LISTDIN(l)
//    Jika N tidak valid, tidak diberikan pesan kesalahan
// 2. Jika 0 < N <= CAPACITY_LISTDIN(l); Lakukan N kali: Baca elemen mulai dari indeks
//   IdxMin satu per satu diakhiri enter
//    Jika N = 0; hanya terbentuk l kosong

void displayList_ListDin(ListDin l)
{
    int i;
    printf("[");
    if (!isEmpty_ListDin(l))
    {
        for (i = 0; i < length_ListDin(l) - 1; i++)
        {
            printf("%d,", ELMT_LISTDIN(l, i));
        }
        printf("%d", ELMT_LISTDIN(l, (i)));
    }
    printf("]");
}
// Proses : Menuliskan isi list dengan traversal, list ditulis di antara kurung siku;
//    antara dua elemen dipisahkan dengan separator "koma", tanpa tambahan karakter di depan,
//    di tengah, atau di belakang, termasuk spasi dan enter
// I.S. l boleh kosong
// F.S. Jika l tidak kosong: [e1,e2,...,en]
// Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [1,20,30]
// Jika list kosong : menulis []

// ********** OPERATOR ARITMATIKA **********
// *** Aritmatika list : Penjumlahan, pengurangan, perkalian, ... ***

ListDin plusMinusList(ListDin l1, ListDin l2, boolean plus)
{
    int len = length_ListDin(l1);
    ListDin l;
    CreateListDin(&l, length_ListDin(l1));
    if (plus)
    {
        for (int i = 0; i < len; i++)
        {
            ELMT_LISTDIN(l, i) = ELMT_LISTDIN(l1, i) + ELMT_LISTDIN(l2, i);
        }
    }
    else if (!plus)
    {
        for (int i = 0; i < len; i++)
        {
            ELMT_LISTDIN(l, i) = ELMT_LISTDIN(l1, i) - ELMT_LISTDIN(l2, i);
        }
    }
    return l;
}
// Prekondisi : l1 dan l2 memiliki nEff sama dan tidak kosong
//              Jika plus=false, tidak ada elemen l1-l2 yang menghasilkan nilai <= 0
// Jika plus = true, mengirimkan  l1+l2, yaitu setiap elemen l1 dan l2 pada indeks yang sama dijumlahkan
// Jika plus = false, mengirimkan l1-l2, yaitu setiap elemen l1 dikurangi elemen l2 pada indeks yang sama

// ********** OPERATOR RELASIONAL **********
// *** Operasi pembandingan list : < =, > ***

boolean isListEqual_ListDin(ListDin l1, ListDin l2)
{
    int len = length_ListDin(l1);
    if (len == length_ListDin(l2))
    {
        for (int i = 0; i < len; i++)
        {
            if (ELMT_LISTDIN(l1, i) != ELMT_LISTDIN(l2, i))
            {
                return false;
            }
        }
        return true;
    }
    return false;
}
// Mengirimkan true jika l1 sama dengan l2 yaitu jika nEff l1 = l2 dan semua elemennya sama

// ********** SEARCHING **********
// ***  Perhatian : List boleh kosong!! ***

IdxType indexOf_ListDin(ListDin l, ElType val)
{
    for (int i = 0; i < length_ListDin(l); i++)
    {
        if (ELMT_LISTDIN(l, i) == val)
        {
            return i;
        }
    }
    return IDX_UNDEF;
}
// Search apakah ada elemen list l yang bernilai val
// Jika ada, menghasilkan indeks i terkecil, dengan elemen ke-i = val
// Jika tidak ada, mengirimkan VAL_UNDEF
// Menghasilkan nilai tak terdefinisi (VAL_UNDEF) jika list l kosong
// Skema Searching yang digunakan bebas

// ********** NILAI EKSTREM **********

void extremes_ListDin(ListDin l, ElType *max, ElType *min)
{
    *max = ELMT_LISTDIN(l, 0);
    *min = ELMT_LISTDIN(l, 0);
    for (int i = 1; i < length_ListDin(l); i++)
    {
        if (ELMT_LISTDIN(l, i) > *max)
        {
            *max = ELMT_LISTDIN(l, i);
        }
        if (ELMT_LISTDIN(l, i) < *min)
        {
            *min = ELMT_LISTDIN(l, i);
        }
    }
}
// I.S. List l tidak kosong
// F.S. max berisi nilai maksimum l;
// min berisi nilai minimum l

// ********** OPERASI LAIN **********

void copyList(ListDin lIn, ListDin *lOut)
{
    CreateListDin(lOut, CAPACITY_LISTDIN(lIn));
    for (int i = 0; i < length_ListDin(lIn); i++)
    {
        ELMT_LISTDIN(*lOut, i) = ELMT_LISTDIN(lIn, i);
    }
}
// I.S. lIn terdefinisi tidak kosong, lOut sembarang
// F.S. lOut berisi salinan dari lIn (identik, nEff dan Capacity sama)
// Proses : Menyalin isi lIn ke lOut

ElType sumList(ListDin l)
{
    ElType x = 0;
    for (int i = 0; i < length_ListDin(l); i++)
    {
        x = x + ELMT_LISTDIN(l, i);
    }
    return x;
}
// Menghasilkan hasil penjumlahan semua elemen l
// Jika l kosong menghasilkan 0

int countVal(ListDin l, ElType val)
{
    int x = 0;
    for (int i = 0; i < length_ListDin(l); i++)
    {
        if (ELMT_LISTDIN(l, i) == val)
        {
            x++;
        }
    }
    return x;
}
// Menghasilkan berapa banyak kemunculan val di l
// Jika l kosong menghasilkan 0

boolean isAllEven_ListDin(ListDin l)
{
    for (int i = 0; i < length_ListDin(l); i++)
    {
        if (ELMT_LISTDIN(l, i) % 2 == 1)
        {
            return false;
        }
    }
    return true;
}
// Menghailkan true jika semua elemen l genap. l boleh kosong

// ********** SORTING **********

void sort_ListDin(ListDin *l, boolean asc)
{
    int key, i, j;
    if (asc)
    {
        for (i = 1; i < length_ListDin(*l); i++)
        {
            key = ELMT_LISTDIN(*l, i);
            j = i - 1;
            while (j >= 0 && ELMT_LISTDIN(*l, j) > key)
            {
                ELMT_LISTDIN(*l, (j + 1)) = ELMT_LISTDIN(*l, j);
                j = j - 1;
            }
            ELMT_LISTDIN(*l, (j + 1)) = key;
        }
    }
    else
    {
        for (i = 1; i < length_ListDin(*l); i++)
        {
            key = ELMT_LISTDIN(*l, i);
            j = i - 1;
            while (j >= 0 && ELMT_LISTDIN(*l, j) < key)
            {
                ELMT_LISTDIN(*l, (j + 1)) = ELMT_LISTDIN(*l, j);
                j = j - 1;
            }
            ELMT_LISTDIN(*l, (j + 1)) = key;
        }
    }
}
// I.S. l boleh kosong
// F.S. Jika asc = true, l terurut membesar
//      Jika asc = false, l terurut mengecil
// Proses : Mengurutkan l dengan salah satu algoritma sorting,
//    algoritma bebas

// ********** MENAMBAH DAN MENGHAPUS ELEMEN DI AKHIR **********
// *** Menambahkan elemen terakhir ***

void insertLast_ListDin(ListDin *l, ElType val)
{
    ELMT_LISTDIN(*l, length_ListDin(*l)) = val;
}
// Proses: Menambahkan X sebagai elemen terakhir list
// I.S. List l boleh kosong, tetapi tidak penuh
// F.S. val adalah elemen terakhir l yang baru
// ********** MENGHAPUS ELEMEN **********

void deleteLast_ListDin(ListDin *l, ElType *val)
{
    *val = ELMT_LISTDIN(*l, getLastIdx(*l));
    ELMT_LISTDIN(*l, getLastIdx(*l)) = VAL_UNDEF;
}
// Proses : Menghapus elemen terakhir list
// I.S. List tidak kosong
// F.S. val adalah nilai elemen terakhir l sebelum penghapusan,
//      Banyaknya elemen list berkurang satu
//      List l mungkin menjadi kosong

// ********* MENGUBAH UKURAN ARRAY *********

void growList(ListDin *l, int num)
{
    CAPACITY_LISTDIN(*l) = CAPACITY_LISTDIN(*l) + num;
    BUFFER(*l) = (ElType *)realloc(BUFFER(*l), CAPACITY_LISTDIN(*l) * sizeof(ElType));
}
// Proses : Menambahkan kapasitas sebanyak num
// I.S. List sudah terdefinisi
// F.S. Ukuran list bertambah sebanyak num

void shrinkList(ListDin *l, int num)
{
    CAPACITY_LISTDIN(*l) = CAPACITY_LISTDIN(*l) - num;
    if (length_ListDin(*l) > CAPACITY_LISTDIN(*l))
    {
        for (int i = (CAPACITY_LISTDIN(*l) - 1); i < length_ListDin(*l); i++)
        {
            ELMT_LISTDIN(*l, i) = VAL_UNDEF;
        }
    }
    BUFFER(*l) = (ElType *)realloc(BUFFER(*l), CAPACITY_LISTDIN(*l) * sizeof(ElType));
}
// Proses : Mengurangi kapasitas sebanyak num
// I.S. List sudah terdefinisi, ukuran Capacity > num, dan nEff < Capacity - num.
// F.S. Ukuran list berkurang sebanyak num.

void compactList(ListDin *l)
{
    CAPACITY_LISTDIN(*l) = length_ListDin(*l);
    BUFFER(*l) = (ElType *)realloc(BUFFER(*l), CAPACITY_LISTDIN(*l) * sizeof(ElType));
}
// Proses : Mengurangi kapasitas sehingga nEff = Capacity
// I.S. List tidak kosong
// F.S. Ukuran Capacity = nEff
