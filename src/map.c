#include "matrix.h"
#include "listdinpos.h"

ListDin parsePoints(char cfg[][50])
{
    // Returns a pointlist
    ListDin locs;
    char c;
    int n, m, x;
    sscanf(cfg[1], "%d %d", &n, &m);
    sscanf(cfg[2], "%d", &x);
    CreateListDin(&locs, x + 1);
    insertLast_ListDin(&locs, MakePOINT(n, m), HEADQUARTERS);
    for (int i = 1; i <= x; i++)
    {
        sscanf(cfg[i + 2], "%c %d %d", &c, &n, &m);
        insertLast_ListDin(&locs, MakePOINT(n, m), c);
    }
    return locs;
}

Matrix parseMap(char cfg[][50], ListDin locs)
{
    // returns map from config coords
    Matrix map;
    char c;
    int n, m, x;
    sscanf(cfg[0], "%d %d", &n, &m);
    CreateMatrix(n, m, &map);
    for (int i = 0; i < ROWS(map); i++)
    {
        for (int j = 0; j < COLS(map); j++)
            ELMT_MATRIX(map, i, j) = EMPTY_NAME;
    }
    sscanf(cfg[2], "%d", &x);
    for (int i = 0; i < x + 1; i++)
    {
        ELMT_MATRIX(map, Absis(ELMT_LISTDIN(locs, i)) - 1, Ordinat(ELMT_LISTDIN(locs, i)) - 1) = NAME(locs, i);
    }
    return map;
}

Matrix parsePath(char cfg[][50])
{
    // returns adjacency matrix
    Matrix map;
    char c;
    int n, m, x;
    sscanf(cfg[2], "%d", &x);
    ++x;
    CreateMatrix(x, x, &map);
    for (int i = 0; i < x; i++)
    {
        for (int j = 0; j < x; j++)
            ELMT_MATRIX(map, i, j) = cfg[i + x + 2][2 * j];
    }
    return map;
}