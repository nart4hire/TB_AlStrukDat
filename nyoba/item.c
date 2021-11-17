#include "item.h"

int cash; //variable global

item createItem(Time tServe, char pickUp, char dropOff, char type_item, Time pTime)
{
    item i;
    TSERVE(i) = tServe;
    PICKUP(i) = pickUp;
    DROPOFF(i) = dropOff;
    switch (type_item)
    {
    case 'N':
        TYPE(i) = "Normal";
        break;
    case 'H':
        TYPE(i) = "Heavy";
        break;
    case 'V':
        TYPE(i) = "VIP";
        break;
    case 'P':
        TYPE(i) = "Perishable";
        break;
    
    default:
        break;
    }
    PTIME(i) = pTime;
    return i;
}

void displayItem(item i){
    printf("Item: %s", TYPE(i));
    if (TYPE(i) == "Perishable") printf("Expire: %d", PTIME(i));
    printf("Pickup: %c", PICKUP(i));
    printf("Drop Off: %c", DROPOFF(i));
}

boolean isNormal(item i){
    return (i.type_item == "Normal");
}
boolean isHeavy(item i){
    return (i.type_item == "Heavy");
}
boolean isPerishable(item i){
    return (i.type_item == "Perishable");
}
boolean isVIP(item i){
    return (i.type_item == "VIP");
}

void HeavyEffect(int jumlah_heavy){
    for (int i =0; i<jumlah_heavy; i++){
        advTime(); //menambah waktu lagi masing2 1 unit waktu per item, prosedur HeavyEffect digunakan selama membawa Heavy Item
    }
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