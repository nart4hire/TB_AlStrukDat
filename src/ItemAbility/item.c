#include "item.h"

int uang;//variable global
boolean isNormal(item i){
    return (i.type_item == 'Normal');
}
boolean isHeavy(item i){
    return (i.type_item == 'Heavy');
}
boolean isPerishable(item i){
    return (i.type_item == 'Perishable');
}
boolean isVIP(item i){
    return (i.type_item == 'VIP');
}

void HeavyEffect(int jumlah_heavy){
    for (int i =0; i<jumlah_heavy; i++){
        advTime(); //menambah waktu lagi masing2 1 unit waktu per item, prosedur HeavyEffect digunakan selama membawa Heavy Item
    }
}
int StartPerishable(item *perish_item){
    int waktu;
    scanf("%d",&waktu);
    PTIME(*perish_item) = waktu;
    InProgressPerish(perish_item);
}

void InProgressPerish(item *perish_item){
    PTIME(*perish_item) -= 1;
    // item belum diberikan fungsi pop jika perish time <= 0
}

void SuccessNormal(){
    uang+= 200;
}

void SuccessHeavy(){
    uang+= 400;
    ActSpeedBoost();
}

void SuccessPerishable(){
    uang+= 400;
    ActIncCapacity();
}