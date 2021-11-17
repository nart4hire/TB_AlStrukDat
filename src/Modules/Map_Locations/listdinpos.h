#ifndef LISTDINPOS_H
#define LISTDINPOS_H

#include "boolean.h"
#include "point.h"

#define IDX_UNDEF -1
#define VAL_UNDEF -999
#define EMPTY_NAME ' '
#define EMPTY_POINT MakePOINT(VAL_UNDEF, VAL_UNDEF)

typedef int IdxType;
typedef POINT ElType_ListDin;
typedef struct
{
   ElType_ListDin *buffer;
   char *name;
   int capacity;
} ListDin;

#define BUFFER(l) (l).buffer
#define ELMT_LISTDIN(l, i) (l).buffer[i]
#define CAPACITY_LISTDIN(l) (l).capacity
#define NAMES(l) (l).name
#define NAME(l, i) (l).name[i]

void CreateListDin(ListDin *l, int capacity);

void dealocate(ListDin *l);

int length_ListDin(ListDin l);

IdxType getLastIdx(ListDin l);

boolean isIdxValid_ListDin(ListDin l, IdxType i);

boolean isIdxEff_ListDin(ListDin l, IdxType i);

boolean isEmpty_ListDin(ListDin l);

boolean isFull_ListDin(ListDin l);

void displayList_ListDin(ListDin l);

IdxType indexOf_ListDin(ListDin l, char val);

void copyList(ListDin lIn, ListDin *lOut);

void insertLast_ListDin(ListDin *l, ElType_ListDin val, char name);

#endif