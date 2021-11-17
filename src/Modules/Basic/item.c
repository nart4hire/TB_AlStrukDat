#include "item.h"

int cash; //variable global

void initCash(int money){
    cash = money;
}

item createItem(Time tServe, char pickUp, char dropOff, char type_item, Time pTime)
{
    item i;
    TSERVE(i) = tServe;
    PICKUP(i) = pickUp;
    DROPOFF(i) = dropOff;
    TYPE(i) = type_item;
    PTIME(i) = pTime;
    return i;
}

item copyItem(item src)
{
    item i;
    TSERVE(i) = TSERVE(src);
    PICKUP(i) = PICKUP(src);
    DROPOFF(i) = DROPOFF(src);
    TYPE(i) = TYPE(src);
    PTIME(i) = PTIME(src);
    return i;
}

boolean isNormal(item i){
    return (TYPE(i) == 'N');
}

boolean isHeavy(item i){
    return (TYPE(i) == 'H');
}

boolean isPerishable(item i){
    return (TYPE(i) == 'P');
}

boolean isVIP(item i){
    return (TYPE(i) == 'V');
}

int StartPerishable(item *perish_item){
    int waktu;
    scanf("%d", &waktu);
    PTIME(*perish_item) = waktu;
    InProgressPerish(perish_item);
}

void InProgressPerish(item *perish_item){
    PTIME(*perish_item) -= 1;
    // item belum diberikan fungsi pop jika perish time <= 0
}

void SuccessNormal(){
    cash += 200;
}

void SuccessHeavy(){
    cash += 400;
    ActSpeedBoost();
}

void SuccessPerishable(){
    cash += 400;
    ActIncCapacity();
}

void SuccessVIP(){
    cash += 600;
    ActIncReturn();
}