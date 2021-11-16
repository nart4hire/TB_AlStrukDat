#include <stdio.h>
#include <stdlib.h>
#include "listdinpos.h"

void CreateListDin(ListDin *l, int capacity)
{
    CAPACITY_LISTDIN(*l) = capacity;
    BUFFER(*l) = (ElType_ListDin *)malloc(capacity * sizeof(ElType_ListDin));
    NAMES(*l) = (char *)malloc(capacity * sizeof(char));
    for (int i = 0; i < capacity; i++)
    {
        ELMT_LISTDIN(*l, i) = EMPTY_POINT;
        NAME(*l, i) = EMPTY_NAME;
    }
}

void dealocate(ListDin *l)
{
    CAPACITY_LISTDIN(*l) = 0;
    free(BUFFER(*l));
    free(NAMES(*l));
}

int length_ListDin(ListDin l)
{
    int i = 0;
    while (i < CAPACITY_LISTDIN(l) && NAME(l, i) != EMPTY_NAME)
    {
        i++;
    }
    return i;
}

IdxType getLastIdx(ListDin l)
{
    IdxType idx = length_ListDin(l) - 1;
    return idx;
}

boolean isIdxValid_ListDin(ListDin l, IdxType i)
{
    return (i > IDX_UNDEF && i < CAPACITY_LISTDIN(l));
}

boolean isIdxEff_ListDin(ListDin l, IdxType i)
{
    return (i > IDX_UNDEF && i < length_ListDin(l));
}

boolean isEmpty_ListDin(ListDin l)
{
    return (length_ListDin(l) == 0);
}

boolean isFull_ListDin(ListDin l)
{
    return (length_ListDin(l) == CAPACITY_LISTDIN(l));
}

void displayList_ListDin(ListDin l)
{
    if (!isEmpty_ListDin(l))
    {
        for (int i = 0; i < length_ListDin(l); i++)
        {
            printf("%d. %c ", i + 1, NAME(l, i));
            TulisPOINT(ELMT_LISTDIN(l, i));
            printf("\n");
        }
    }
    else
        printf("There are no adjacent cities, Nobita is stranded!\n");
}

IdxType indexOf_ListDin(ListDin l, char name)
{
    for (int i = 0; i < length_ListDin(l); i++)
    {
        if (NAME(l, i) == name)
        {
            return i;
        }
    }
    return IDX_UNDEF;
}

void copyList(ListDin lIn, ListDin *lOut)
{
    CreateListDin(lOut, CAPACITY_LISTDIN(lIn));
    for (int i = 0; i < length_ListDin(lIn); i++)
    {
        ELMT_LISTDIN(*lOut, i) = ELMT_LISTDIN(lIn, i);
        NAME(*lOut, i) = NAME(lIn, i);
    }
}

void insertLast_ListDin(ListDin *l, ElType_ListDin val, char name)
{
    ELMT_LISTDIN(*l, length_ListDin(*l)) = val;
    NAME(*l, length_ListDin(*l)) = name;
}
