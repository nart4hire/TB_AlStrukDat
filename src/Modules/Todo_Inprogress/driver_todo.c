#include <stdio.h>
#include "list_todo.h"

int main(){
    /*Kamus*/
    ListLinked list;
    item order;
    /*Algoritma*/
    CreateListOrder(&list);
    if (isEmpty_ListOrder(list)){
        printf("Daftar list to do kosong\n");
    }
    else{
        printf("Daftar list to do tidak kosong\n");
    }
    int n = 10;
    while (n>0){
        scanf("%d %c %c %c", &order.tServe, &order.pickUp, &order.dropOff, &order.type_item);
        if (order.type_item == 'P'){
            scanf("%d", &order.pTime);
        }
        else{
            order.pTime = -1;
        }
        insertLast_ListOrder(&list, order);
        n--;
    }
    printf("Panjang daftar pesanan: %d\n", length_ListOrder(list));
    n = 5;
    displayList_ListOrder(list);
    while (n>0){
        deleteLast_ListOrder(&list, &order);
        n--;
    }
    printf("Setelah dihapus: \n");
    displayList_ListOrder(list);
}