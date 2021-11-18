#include <stdio.h>
#include <stdlib.h>

#include "config.h"

int parseConfig(char cfg[][CAPACITY_WORDMACHINE], boolean load)
{
    boolean able = 0;
    able = startFile(currentWord.contents, currentWord.length);
    if (able)
    {
        int i = 0, j, count;
        for (int k = 0; k < 3; k++)
        {
            j = 0;
            while (currentWord.contents[j] != '\0')
            {
                cfg[i][j] = currentWord.contents[j];
                ++j;
            }
            cfg[i][j] = '\0';
            ++i;
            advFile();
        }
        count = atoi(cfg[i-1]);
        for (int k = 0; k < count; k++)
        {
            j = 0;
            while (currentWord.contents[j] != '\0')
            {
                cfg[i][j] = currentWord.contents[j];
                ++j;
            }
            cfg[i][j] = '\0';
            ++i;
            advFile();
        }
        for (int k = 0; k < count + 2; k++)
        {
            j = 0;
            while (currentWord.contents[j] != '\0')
            {
                cfg[i][j] = currentWord.contents[j];
                ++j;
            }
            cfg[i][j] = '\0';
            ++i;
            advFile();
        }
        count = atoi(cfg[i-1]);
        for (int k = 0; k < count - 1; k++)
        {
            j = 0;
            while (currentWord.contents[j] != '\0')
            {
                cfg[i][j] = currentWord.contents[j];
                ++j;
            }
            cfg[i][j] = '\0';
            ++i;
            advFile();
        }
        j = 0;
        while (currentWord.contents[j] != '\0')
        {
            cfg[i][j] = currentWord.contents[j];
            ++j;
        }
        cfg[i][j] = '\0';
        ++i;
        if (load)
        {
            // smth
        }
    }
    return able;
}

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

Queue parseOrders(char cfg[][CAPACITY_WORDMACHINE])
{
    int x, y;
    Time tserve, perish;
    char pick, drop, item;
    Queue orders;
    CreateQueue(&orders);

    sscanf(cfg[2], "%d", &x);
    x = 2 * x + 4;
    sscanf(cfg[x++], "%d", &y);
    for (int i = 0; i < y; i++)
    {
        sscanf(cfg[i + x], "%d %c %c %c %d", &tserve, &pick, &drop, &item, &perish);
        enqueue(&orders, createItem(tserve, pick, drop, item, perish));
    }
    return orders;
}

int getSaveArea(char cfg[][CAPACITY_WORDMACHINE])
{
    int i = atoi(cfg[2]);
    int j = atoi(cfg[2 * i + 4]);
    return (2 * i + 5 + j);
}

int saveGame(char cfg[][CAPACITY_WORDMACHINE])
{
    boolean avail = startWrite(currentWord.contents, currentWord.length);
    int i = 0;
    while (cfg[i][0] != '\0')
    {
        saveLine(cfg[i++]);
    }
    return avail;
}