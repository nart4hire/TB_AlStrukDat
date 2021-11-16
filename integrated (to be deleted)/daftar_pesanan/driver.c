#include "q_pesanan.h"
#include <stdio.h>

int main(){
    Queue pesanan;
    ElType_Queue val;
    Time tServe, perTime;
    char pickUp, dropOff, item;

    CreateQueue(&pesanan);
    int n = 10;
    while (n>0){
        scanf("%d %c %c %c", &tServe, &pickUp, &dropOff, &item);
        if (item == 'P'){
            scanf("%d", &perTime);
        }
        else{
            perTime = -1;
        }
        val.tServe = tServe;
        val.pickUp = pickUp;
        val.dropOff = dropOff;
        val.item = item;
        val.pTime = perTime;
        enqueue(&pesanan, val);
        n--;
    }
/*    while (!isEmpty_Queue(pesanan)){
        dequeue(&pesanan, &val);
        printf("%d %c %c %c %d\n", val.tServe, val.pickUp, val.dropOff, val.item, val.pTime);
    }
*/    displayQueue(pesanan);
}