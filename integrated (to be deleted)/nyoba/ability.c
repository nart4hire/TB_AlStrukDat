#include "ability.h"

ability abilities;

void initAbilities(){
    SPEED(abilities) = false;
    DONE(abilities) = false;
    RETURN(abilities) = 0;
    TIMER(abilities) = 0;
    HEAVY(abilities) = 0;
    REDUCT(abilities) = false;
}

void ActSpeedBoost(){
    --HEAVY(abilities);
    SPEED(abilities) = true;
    DONE(abilities) = false;
    TIMER(abilities) = 5;
    // belum ada mekanisme untuk memberi tahu jika speedboost true, 1 unit waktu = 2 unit lokasi
    // belum ada mekanisme untuk mengurangi waktu speedboost ( waktunya 5 detik)
}

void removeSpeedBoost(){
    SPEED(abilities) = false;
    DONE(abilities) = false;
}

int ActIncCapacity(){
    return 1;
}

void ActIncHeavy(){
    ++HEAVY(abilities);
}

void ActIncReturn(){
    ++RETURN(abilities);
}

boolean UseReturn(){
    if (RETURN(abilities) > 0)
    {
        --RETURN(abilities);
        return true;
    }
    return false;
}

boolean UseSpeed() {
    if (HEAVY(abilities) - REDUCT(abilities) > 0 || TIMER(abilities) <= 0){
        removeSpeedBoost(abilities);
    }

    if (!DONE(abilities) && (SPEED(abilities) == true) && (TIMER(abilities) > 0)){
        TIMER(abilities) -= 1;
        return true;
    } else if (DONE(abilities)){
        DONE(abilities) = false;
    }

    return false;
    // increaseCapacity(INCCAP(*a));
}

int numHeavy(){
    return (HEAVY(abilities) - REDUCT(abilities));
}

void ActReduct(){
    REDUCT(abilities) = true;
}
