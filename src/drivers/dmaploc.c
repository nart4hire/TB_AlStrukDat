#include <stdio.h>
#include "listdinpos.h"
#include "matrix.h"

int main(int argc, char const *argv[])
{
    Matrix m;
    CreateMatrix(10, 10, &m);
    ListDin l, lcopy;
    CreateListDin(&l, 10);
    POINT p;
    char x;


    if (isEmpty_ListDin(l))
        printf("I am empty!\n");

    for (int i = 0; i < 10; i++)
    {
        char x = i % 26 + 65;
        insertLast_ListDin(&l, MakePOINT(length_ListDin(l), getLastIdx(l)), x);
    }
    if (isFull_ListDin(l))
        printf("I am Full!\n");

    displayList_ListDin(l);
    printf("C is at index %d\n", indexOf_ListDin(l, 'C'));
    copyList(l, &lcopy);

    dealocate(&l);
    if (isEmpty_ListDin(l))
        printf("Now I am empty again!\n");

    displayList_ListDin(lcopy);
    printf("I am a copy!\n");

    if (isIdxValid_ListDin(lcopy, indexOf_ListDin(lcopy, 'G')) && isIdxEff_ListDin(lcopy, indexOf_ListDin(lcopy, 'E')))
        printf("G and E are valid and effective.\n");

    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
            ELMT_MATRIX(m, i, j) = i + j % 26 + 65;
    }
    
    displayMatrix(m);

    return 0;
}
