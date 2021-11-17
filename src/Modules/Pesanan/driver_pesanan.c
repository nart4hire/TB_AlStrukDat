#include <stdio.h>
#include "q_pesanan.h"

int main(){
    /*Kamus*/
    Queue pesanan;
    ElType_Queue order;

    /*Algoritma*/
    CreateQueue(&pesanan);
    if (isEmpty_Queue(pesanan)){
        printf("Daftar pesanan kosong\n");
    }
    else{
        printf("Daftar pesanan tidak kosong\n");
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
        enqueue(&pesanan, order);
        n--;
    }
    printf("Panjang daftar pesanan: %d\n", length_Queue(pesanan));
    n = 5;
    displayQueue(pesanan);
    while (n>0){
        dequeue(&pesanan, &order);
        n--;
    }
    printf("Setelah dihapus: \n");
    displayQueue(pesanan);
    if (isFull_Queue(pesanan)){
        printf("Daftar pesanan penuh\n");
    }
    else{
        printf("Daftar pesanan tidak penuh\n");
    }
}