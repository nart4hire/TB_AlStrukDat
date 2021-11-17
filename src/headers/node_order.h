#ifndef NODE_H
#define NODE_H

#include <stdlib.h>
#include "time.h"

typedef int ElType_ListLinked;
typedef struct node* Address;
typedef struct node {
    Time tServe;
    // char pick;
    char drop;
    char item;
    Time pTime;
    Address next;
} Node;

#define T_SERVE(p) (p)->tServe
// #define PICK(p) (p)->pick
#define DROP(p) (p)->drop
#define ITEM(p) (p)->item
#define PER_TIME(p) (p)->pTime
#define NEXT(p) (p)->next

Address newNode(Time tServe, char drop, char item, Time pTime);


#endif
