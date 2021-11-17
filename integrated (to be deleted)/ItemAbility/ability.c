#include "ability.h"




void ActSpeedBoost(ability *a){
    SPEED(*a) = true;
    // belum ada mekanisme untuk memberi tahu jika speedboost true, 1 unit waktu = 2 unit lokasi
    SPEEDTIMER(*a) = 5;
    // belum ada mekanisme untuk mengurangi waktu speedboost ( waktunya 5 detik)
}
void removeSpeedBoost(ability *a){
    SPEED(*a) = false;
}
void ActIncCapacity(ability *a){
    INCCAP(*a) +=1;
}
void UseAbility(ability *a){
    if ((SPEEDTIMER(*a) >0) && (SPEED(*a) == true)){
        SPEEDTIMER(*a) -=1;
                        
    }
    increaseCapacity(INCCAP(*a));
    if (SPEEDTIMER(*a) <= 0){
        removeSpeedBoost(a);
    }
}


