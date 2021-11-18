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
            for (int k = 0; k < 6; k++)
            {
                advFile();
                j = 0;
                while (currentWord.contents[j] != '\0')
                {
                    cfg[i][j] = currentWord.contents[j];
                    ++j;
                }
                cfg[i][j] = '\0';
                ++i;
            }
            count = atoi(cfg[i-1]);
            for (int k = 0; k < count + 1; k++)
            {
                advFile();
                j = 0;
                while (currentWord.contents[j] != '\0')
                {
                    cfg[i][j] = currentWord.contents[j];
                    ++j;
                }
                cfg[i][j] = '\0';
                ++i;
            }
            count = atoi(cfg[i-1]);
            for (int k = 0; k < count + 1; k++)
            {
                advFile();
                j = 0;
                while (currentWord.contents[j] != '\0')
                {
                    cfg[i][j] = currentWord.contents[j];
                    ++j;
                }
                cfg[i][j] = '\0';
                ++i;
            }
            count = atoi(cfg[i-1]);
            for (int k = 0; k < count + 1; k++)
            {
                advFile();
                j = 0;
                while (currentWord.contents[j] != '\0')
                {
                    cfg[i][j] = currentWord.contents[j];
                    ++j;
                }
                cfg[i][j] = '\0';
                ++i;
            }
            count = atoi(cfg[i-1]);
            for (int k = 0; k < count + 1; k++)
            {
                advFile();
                j = 0;
                while (currentWord.contents[j] != '\0')
                {
                    cfg[i][j] = currentWord.contents[j];
                    ++j;
                }
                cfg[i][j] = '\0';
                ++i;
            }
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
        sscanf(cfg[i + x], "%d %c %c %c", &tserve, &pick, &drop, &item);
        if (item == 'P')
            sscanf(cfg[i + x], "%d %c %c %c %d", &tserve, &pick, &drop, &item, &perish);
        else
            perish = 0;
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

int saveGame(char cfg[][CAPACITY_WORDMACHINE], Queue *ords, ListLinked *todo, ListLinked *inpro, Stack *bag, ListPos *inv)
{
    item it;
    int idx = getSaveArea(cfg), i, g;
    char string[100];
    boolean avail = startWrite(currentPath.contents, currentPath.length);

    if (avail)
    {
        cfg[idx][0] = mobita;
        cfg[idx][1] = '\0';
        ++idx;

        sprintf(string, "%d", time_game);
        i = 0;
        while (string[i] != '\0')
        {
            cfg[idx][i] = string[i];
            ++i;
        }
        cfg[idx][i] = '\0';
        ++idx;

        sprintf(string, "%d", cash);
        i = 0;
        while (string[i] != '\0')
        {
            cfg[idx][i] = string[i];
            ++i;
        }
        cfg[idx][i] = '\0';
        ++idx;
            
        sprintf(string, "%d", stack_capacity);
        i = 0;
        while (string[i] != '\0')
        {
            cfg[idx][i] = string[i];
            ++i;
        }
        cfg[idx][i] = '\0';
        ++idx;
            
        sprintf(string, "%u %u %d %d %d %u", SPEED(abilities), DONE(abilities), RETURN(abilities), TIMER(abilities), HEAVY(abilities), REDUCT(abilities));
        i = 0;
        while (string[i] != '\0')
        {
            cfg[idx][i] = string[i];
            ++i;
        }
        cfg[idx][i] = '\0';
        ++idx;

        sprintf(string, "%d", length_Queue(*ords));
        i = 0;
        while (string[i] != '\0')
        {
            cfg[idx][i] = string[i];
            ++i;
        }
        cfg[idx][i] = '\0';
        ++idx;

        while (!isEmpty_Queue(*ords))
        {
            dequeue(ords, &it);
            if (isPerishable(it))
                sprintf(string, "%d %c %c %c %d", TSERVE(it), PICKUP(it), DROPOFF(it), TYPE(it), PTIME(it));
            else
                sprintf(string, "%d %c %c %c", TSERVE(it), PICKUP(it), DROPOFF(it), TYPE(it));
            i = 0;
            while (string[i] != '\0')
            {
                cfg[idx][i] = string[i];
                ++i;
            }
            cfg[idx][i] = '\0';
            ++idx;
        }
        
        sprintf(string, "%d", length_ListOrder(*todo));
        i = 0;
        while (string[i] != '\0')
        {
            cfg[idx][i] = string[i];
            ++i;
        }
        cfg[idx][i] = '\0';
        ++idx;

        while (!isEmpty_ListOrder(*todo))
        {
            deleteFirst_ListOrder(todo, &it);
            if (isPerishable(it))
                sprintf(string, "%d %c %c %c %d", TSERVE(it), PICKUP(it), DROPOFF(it), TYPE(it), PTIME(it));
            else
                sprintf(string, "%d %c %c %c", TSERVE(it), PICKUP(it), DROPOFF(it), TYPE(it));
            i = 0;
            while (string[i] != '\0')
            {
                cfg[idx][i] = string[i];
                ++i;
            }
            cfg[idx][i] = '\0';
            ++idx;
        }
        
        sprintf(string, "%d", length_ListOrder(*inpro));
        printf("%s", string);
        i = 0;
        while (string[i] != '\0')
        {
            cfg[idx][i] = string[i];
            ++i;
        }
        cfg[idx][i] = '\0';
        ++idx;

        while (!isEmpty_ListOrder(*inpro))
        {
            deleteFirst_ListOrder(inpro, &it);
            if (isPerishable(it))
                sprintf(string, "%d %c %c %c %d", TSERVE(it), PICKUP(it), DROPOFF(it), TYPE(it), PTIME(it));
            else
                sprintf(string, "%d %c %c %c", TSERVE(it), PICKUP(it), DROPOFF(it), TYPE(it));
            i = 0;
            while (string[i] != '\0')
            {
                cfg[idx][i] = string[i];
                ++i;
            }
            cfg[idx][i] = '\0';
            ++idx;
        }
        
        sprintf(string, "%d", IDX_TOP(*bag) + 1);
        i = 0;
        while (string[i] != '\0')
        {
            cfg[idx][i] = string[i];
            ++i;
        }
        cfg[idx][i] = '\0';
        ++idx;
        
        while (!isEmpty_Stack(*bag))
        {
            pop(bag, &it);
            if (isPerishable(it))
                sprintf(string, "%d %c %c %c %d", TSERVE(it), PICKUP(it), DROPOFF(it), TYPE(it), PTIME(it));
            else
                sprintf(string, "%d %c %c %c", TSERVE(it), PICKUP(it), DROPOFF(it), TYPE(it));
            i = 0;
            while (string[i] != '\0')
            {
                cfg[idx][i] = string[i];
                ++i;
            }
            cfg[idx][i] = '\0';
            ++idx;
        }

        sprintf(string, "%d %d %d %d %d", ELMT_LISTPOS(*inv, 0), ELMT_LISTPOS(*inv, 1), ELMT_LISTPOS(*inv, 2), ELMT_LISTPOS(*inv, 3), ELMT_LISTPOS(*inv, 4));
        i = 0;
        while (string[i] != '\0')
        {
            cfg[idx][i] = string[i];
            ++i;
        }
        cfg[idx][i] = '\0';
        ++idx;

        int i = 0;
        while (cfg[i][0] != '\0')
        {
            saveLine(cfg[i++]);
        }
    }
    closeSave();
    return avail;
}

void parseLoad(char cfg[][CAPACITY_WORDMACHINE], Queue *ords, ListLinked *todo, ListLinked *inpro, Stack *bag, ListPos *inv)
{
    Stack temp;
    CreateStack(&temp);
    CreateQueue(ords);
    item it;
    Time tserve, ptime;
    char pick, drop, type;
    int idx = getSaveArea(cfg), num, count, a, b, c, d, e;
    mobita = cfg[idx][0];
    ++idx;
    sscanf(cfg[idx], "%d", &num);
    time_game = num;
    ++idx;
    sscanf(cfg[idx], "%d", &num);
    initCash(num);
    ++idx;
    sscanf(cfg[idx], "%d", &num);
    initTas(num);
    ++idx;
    sscanf(cfg[idx], "%u %u %d %d %d %u", & SPEED(abilities), &DONE(abilities), &RETURN(abilities), &TIMER(abilities), &HEAVY(abilities), &REDUCT(abilities));
    ++idx;
    sscanf(cfg[idx], "%d", &count);
    ++idx;
    for (int i = 0; i < count; i++)
    {
        sscanf(cfg[idx], "%d %c %c %c", &tserve, &pick, &drop, &type);
        ptime = 0;
        if (type = 'P')
            sscanf(cfg[idx], "%d %c %c %c %d", &tserve, &pick, &drop, &type, &ptime);
        enqueue(ords, createItem(tserve, pick, drop, type, ptime));
        ++idx;
    }
    sscanf(cfg[idx], "%d", &count);
    ++idx;
    for (int i = 0; i < count; i++)
    {
        sscanf(cfg[idx], "%d %c %c %c", &tserve, &pick, &drop, &type);
        ptime = 0;
        if (type = 'P')
            sscanf(cfg[idx], "%d %c %c %c %d", &tserve, &pick, &drop, &type, &ptime);
        insertLast_ListOrder(todo, createItem(tserve, pick, drop, type, ptime));
        ++idx;
    }
    sscanf(cfg[idx], "%d", &count);
    ++idx;
    for (int i = 0; i < count; i++)
    {
        sscanf(cfg[idx], "%d %c %c %c", &tserve, &pick, &drop, &type);
        ptime = 0;
        if (type = 'P')
            sscanf(cfg[idx], "%d %c %c %c %d", &tserve, &pick, &drop, &type, &ptime);
        insertLast_ListOrder(inpro, createItem(tserve, pick, drop, type, ptime));
        ++idx;
    }
    sscanf(cfg[idx], "%d", &count);
    ++idx;
    for (int i = 0; i < count; i++)
    {
        sscanf(cfg[idx], "%d %c %c %c", &tserve, &pick, &drop, &type);
        ptime = 0;
        if (type = 'P')
            sscanf(cfg[idx], "%d %c %c %c %d", &tserve, &pick, &drop, &type, &ptime);
        push(&temp, createItem(tserve, pick, drop, type, ptime));
        ++idx;
    }
    while (!isEmpty_Stack(temp))
    {
        pop(&temp, &it);
        push(bag, it);
    }
    sscanf(cfg[idx], "%d %d %d %d %d", &a, &b, &c, &d, &e);
    ELMT_LISTPOS(*inv, 0) = a;
    ELMT_LISTPOS(*inv, 1) = b;
    ELMT_LISTPOS(*inv, 2) = c;
    ELMT_LISTPOS(*inv, 3) = d;
    ELMT_LISTPOS(*inv, 4) = e;
}