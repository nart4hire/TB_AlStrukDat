#include <stdio.h>
#include "time.h"

Time time_game;

void startTime(){
/* I.S. : Waktu sembarang.
   F.S. : Waktu diset menjadi 0*/
    time_game = 0;
}

void advTime(){
/* Menambah waktu sebesar 1 satuan. 
   I.S. : Waktu telah dimulai, dan bukan merupakan akhir dari permainan
   F.S. : Waktu bertambah 1*/
    time_game += 1;    
}

void timeMachine(){
/* Mengurangi waktu sebesar 50 satuan sesuai fungsi item. 
   I.S. : Waktu telah dimulai, dan mungkin <50
   F.S. : Waktu berkurang 50, atau menjadi 0 jika <50*/
    if (time_game < 50){
        time_game = 0;
    }
    else{
        time_game -= 50;
    }
}
