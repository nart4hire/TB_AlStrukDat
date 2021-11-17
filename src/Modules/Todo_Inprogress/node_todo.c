/* File: nodeOrder.c */
/* Implementasi Node */

#include "node_todo.h"

Address newNode(item i)
{
    Address p = (Address)malloc(sizeof(Node));
    if (p != NULL)
    {
        INFO(p) = copyItem(i);
        NEXT(p) = NULL;
    }
    return p;
}
