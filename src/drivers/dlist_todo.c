#include <stdio.h>
#include "list_todo.h"

int main(){
    ListLinked l;
    Time tServ;
    char pick;
    char drop;
    char item;
    Time perTime;
    int n;
    CreateListOrder(&l);
    scanf("%d", &n);
    while (n > 0){
        scanf("%d %c %c %c", &tServ, &pick, &drop, &item);
        if (item == 'P'){
            scanf("%d", &perTime);
        }
        else{
            perTime = -1;
        }
        insertLast_ListOrder(&l, tServ, pick, drop, item, perTime);
        n--;
    }
    while (!(isEmpty_ListOrder(l))){
        deleteFirst_ListOrder(&l, &tServ, &pick, &drop, &item, &perTime);
        printf("%d %c %c %c %d\n", tServ, pick, drop, item, perTime);
    }
}