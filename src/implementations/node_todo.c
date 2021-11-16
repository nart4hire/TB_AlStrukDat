/* File: nodeOrder.c */
/* Implementasi Node */

#include "node_todo.h"
#include <stdlib.h>

Address newNode(Time time, char pickUp, char dropOff, char item, Time perTime)
{
    Address p = (Address)malloc(sizeof(Node));
    if (p != NULL)
    {
        T_SERVE(p) = time;
        PICK(p) = pickUp;
        DROP(p) = dropOff;
        ITEM(p) = item;
        PER_TIME(p) = perTime;
        NEXT(p) = NULL;
    }
    return p;
}
