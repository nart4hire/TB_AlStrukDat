#ifndef NODE_ORDER_H
#define NODE_ORDER_H

#include <stdlib.h>
#include "time.h"

typedef int ElType_ListLinked_order;
typedef struct node_order* Address_order;
typedef struct node_order {
    Time tServe;
    // char pick;
    char drop;
    char item;
    Time pTime;
    Address_order next;
} Node_order;

#define T_SERVE(p) (p)->tServe
#define PICK(p) (p)->pick
#define DROP(p) (p)->drop
#define ITEM(p) (p)->item
#define PER_TIME(p) (p)->pTime
#define NEXT(p) (p)->next

Address_order newNode_order(Time tServe, char drop, char item, Time pTime);


#endif
