/* File: nodeOrder.c */
/* Implementasi Node */

#include "node_order.h"
#include <stdlib.h>

Address_order newNode_order(Time time, char dropOff, char item, Time perTime)
{
    Address_order p = (Address_order)malloc(sizeof(Node_order));
    if (p != NULL)
    {
        T_SERVE(p) = time;
        // PICK(p) = pickUp;
        DROP(p) = dropOff;
        ITEM(p) = item;
        PER_TIME(p) = perTime;
        NEXT(p) = NULL;
    }
    return p;
}
