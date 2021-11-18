#include <stdio.h>
#include "item.h"

int cash; //variable global

void initCash(int money){
    cash = money;
}

item createItem(Time tServe, char pickUp, char dropOff, char type_item, Time pTime)
{
    item it;
    TSERVE(it) = tServe;
    PICKUP(it) = pickUp;
    DROPOFF(it) = dropOff;
    TYPE(it) = type_item;
    PTIME(it) = pTime;
    return it;
}

item copyItem(item src)
{
    item it;
    TSERVE(it) = TSERVE(src);
    PICKUP(it) = PICKUP(src);
    DROPOFF(it) = DROPOFF(src);
    TYPE(it) = TYPE(src);
    PTIME(it) = PTIME(src);
    return it;
}

boolean isEqItem(item src, item dst)
{
    return (TSERVE(src) == TSERVE(dst) && PICKUP(src) == PICKUP(dst) && DROPOFF(src) == DROPOFF(dst) && TYPE(src) == TYPE(dst));
}

boolean isNormal(item it){
    return (TYPE(it) == 'N');
}

boolean isHeavy(item it){
    return (TYPE(it) == 'H');
}

boolean isPerishable(item it){
    return (TYPE(it) == 'P');
}

boolean isVIP(item it){
    return (TYPE(it) == 'V');
}

void SuccessNormal(){
    REDUCT(abilities) = false;
    cash += 200;
}

void SuccessHeavy(){
    REDUCT(abilities) = false;
    cash += 400;
    ActSpeedBoost();
}

int SuccessPerishable(){
    REDUCT(abilities) = false;
    cash += 400;
    return ActIncCapacity();
}

void SuccessVIP(){
    REDUCT(abilities) = false;
    cash += 600;
    ActIncReturn();
}

void displayItem(item it){
    printf("Time: %d, %c -> %c: %c", TSERVE(it), PICKUP(it), DROPOFF(it), TYPE(it));
    if (TYPE(it) == 'P')
        printf(" Expired in: %d", PTIME(it));
    printf("\n");
}