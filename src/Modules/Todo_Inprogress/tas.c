// File : stack.c 
// Definisi ADT Stack dengan representasi array secara eksplisit dan alokasi statik 
// TOP adalah alamat elemen puncak 

#include <stdio.h>
#include "tas.h"

// CONSTANTS:
// #define IDX_UNDEF -1
// #define CAPACITY_STACK 100

// DEFINITION:
// typedef int ElType_Stack;
// typedef struct {
//   ElType_Stack buffer[CAPACITY_STACK]; // tabel penyimpan elemen 
//   int idxTop;              // alamat TOP: elemen puncak 
// } Stack;

// ********* AKSES (Selektor) ********* 
// Jika s adalah Stack, maka akses elemen : 

// #define IDX_TOP(s) (s).idxTop
// #define     TOP(s) (s).buffer[(s).idxTop]

// *** Konstruktor/Kreator *** 

int stack_capacity;

void initTas(int cap)
{
    stack_capacity = cap;
}

void CreateStack(Stack *s)
{
    IDX_TOP(*s) = IDX_UNDEF;
}
// I.S. sembarang; 
// F.S. Membuat sebuah stack S kosong dengan kondisi sbb: 
// - Index top bernilai IDX_UNDEF 
// Proses : Melakukan alokasi, membuat sebuah s kosong 

// ************ Prototype ************ 

boolean isEmpty_Stack(Stack s)
{
    return (IDX_TOP(s) == IDX_UNDEF);
}
// Mengirim true jika s kosong: lihat definisi di atas

boolean isFull_Stack(Stack s)
{
    return (IDX_TOP(s) == CAPACITY_STACK - 1);
}
// Mengirim true jika tabel penampung nilai s stack penuh 

boolean isFull_Tas(Stack s)
{
    return (IDX_TOP(s) == stack_capacity - 1);
}

// ************ Menambahkan sebuah elemen ke Stack ************ 

void push(Stack *s, item val)
{
    ++IDX_TOP(*s);
    TOP(*s) = copyItem(val);
}
// Menambahkan val sebagai elemen Stack s 
// I.S. s mungkin kosong, tabel penampung elemen stack TIDAK penuh 
// F.S. val menjadi TOP yang baru,IDX_TOP bertambah 1 

// ************ Menghapus sebuah elemen Stack ************ 

void pop(Stack *s, item *val)
{
    if (!isEmpty_Stack(*s))
    {
        *val = copyItem(TOP(*s));
        --IDX_TOP(*s);
    }
}

void increaseCapacity(int amount)
{
    if (stack_capacity != CAPACITY_STACK) {
        if (stack_capacity + amount >= CAPACITY_STACK) {
            stack_capacity = CAPACITY_STACK;
        } else {
            stack_capacity += amount;
        }
    }
}

void displayStack(Stack s){
    for (int i = 0; i <= IDX_TOP(s);i++)
    {
        printf("%d. ", i+1);
        switch (TYPE(ELMT(s, IDX_TOP(s) - i)))
        {
        case 'N':
            printf("Normal Item");
            break;
        case 'H':
            printf("Heavy Item");
            break;
        case 'P':
            printf("Perishable Item");
            break;
        case 'V':
            printf("VIP Item");
            break;
        default:
            break;
        }
        printf(" (Tujuan: %c)", TYPE(ELMT(s, IDX_TOP(s) - i)));
        if (isPerishable(ELMT(s, IDX_TOP(s) - i)))
            printf(" (Time remaining %d)", PTIME(ELMT(s, IDX_TOP(s) - i)));
        printf("\n");
    }
}
// Menghapus val dari Stack s 
// I.S. s tidak mungkin kosong 
// F.S. val adalah nilai elemen TOP yang lama, IDX_TOP berkurang 1 

void advPerishable(Stack *s)
{
    Stack temp;
    item it;
    for (int i = 0; i < IDX_TOP(*s); i++)
    {
        pop(s, &it);
        if (!SPEED(abilities))
            PTIME(it) -= numHeavy() + 1;
        if (PTIME(it) > 0)
            push(&temp, it);
    }
    while (!isEmpty_Stack(temp))
    {
        pop(&temp, &it);
        push(s, it);
    }
}
