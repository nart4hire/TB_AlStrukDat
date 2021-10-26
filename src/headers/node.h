#ifndef NODE_H
#define NODE_H

#include <stdlib.h>

typedef int ElType_ListLinked;
typedef struct node* Address;
typedef struct node {
    ElType_ListLinked info;
    Address next;
} Node;

#define INFO(p) (p)->info
#define NEXT(p) (p)->next

Address newNode(ElType_ListLinked val);


#endif
