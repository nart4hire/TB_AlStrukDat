#include <stdlib.h>
#include <stdio.h>
#include "time.h"
#include "ability.h"
#include "item.h"
#include "tas.h"

int main(){
    initAbilities();


    if (SPEED(abilities)){
        printf("Speedboost aktif\n");
        
    }
    else printf("Speedboost tidak aktif\n");


    ActSpeedBoost();
    if (SPEED(abilities)){
        printf("Speedboost aktif\n");
        
    }
    else printf("Speedboost tidak aktif\n");
    printf("Timer speed boost ialah %d\n", TIMER(abilities));

    removeSpeedBoost();
    if (SPEED(abilities)){
        printf("Speedboost aktif\n");
        
    }
    else printf("Speedboost tidak aktif\n");

    printf("Menaikkan kapasitas tas sejumlah %d\n", ActIncCapacity());

    ActIncReturn();
    printf("Menambah 'Return to Sender' sejumlah 1.\n");
    printf("Saat ini, Kamu punya 'Return to Sender' berjumlah %d\n", RETURN(abilities));


    UseReturn();
    printf("Menggunakan Return to Sender\n");
    printf("Saat ini, return to sender berjumlah %d\n", RETURN(abilities));


    printf("Saat ini, heavy berjumlah %d\n", numHeavy());
    printf("Heavy item dikurangi satu karena speedboost seharusnya diaktifkan setelah drop-off Heavy item\n");


    ActIncHeavy();
    printf("Menambah heavy sejumlah 1.\n");
    printf("Saat ini, heavy berjumlah %d\n", numHeavy());

    if (UseSpeed()){
        printf("Menggunakan Speedboost\n");

    }
    else printf("Tidak menggunakan speedboost\n");

    //printf("Jumlah Heavy item saat ini ialah %d\n", numHeavy());

    if (REDUCT(abilities)) printf("saat ini menggunakan senter pengecil\n");
    else printf("Saat ini tidak menggunakan senter pengecil\n");

    ActReduct();
    printf("Melakukan prosedur ActReduct\n");

    if (REDUCT(abilities)) printf("saat ini menggunakan senter pengecil\n");
    else printf("Saat ini tidak menggunakan senter pengecil\n");
    

    


    return 0;
}