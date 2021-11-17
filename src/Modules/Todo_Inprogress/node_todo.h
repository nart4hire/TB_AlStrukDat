#ifndef NODE_H
#define NODE_H

#include <stdlib.h>
#include "item.h"

typedef int ElType_ListLinked;
typedef struct node* Address;
typedef struct node {
    item contents;
    Address next;
} Node;

#define INFO(p) (p)->contents
#define NEXT(p) (p)->next

Address newNode(item i);


#endif
