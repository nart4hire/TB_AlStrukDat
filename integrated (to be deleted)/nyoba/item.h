#ifndef ITEM_H
#define ITEM_H

#include "ability.h"

typedef struct{
        Time tServe;
        char pickUp;
        char dropOff;
        char type_item;
        Time pTime;
} item;

#define TSERVE(p) (p).tServe
#define PICKUP(p) (p). pickUp
#define DROPOFF(p) (p).dropOff
#define TYPE(p) (p).type_item
#define PTIME(p) (p).pTime

extern int cash;

void initCash(int money);

item createItem(Time tServe, char pickUp, char dropOff, char type_item, Time pTime);

item copyItem(item src);

boolean isEqItem(item src, item dst);

boolean isNormal(item it);
/* Mengembalikan True apabila type item == normal*/

boolean isHeavy(item it);
/* Mengembalikan True apabila type item == heavy*/

boolean isPerishable(item it);
/* Mengembalikan true apabila type  item == perishable */

boolean isVIP(item it);
/* Mengembalikan True apabila type item == VIP*/

void SuccessNormal();
/*I.S : tidak ada ( diaktifkan ketika Berhasil mengantarkan item bertipe normal )*/
/*F.S : Bertambah uang sebesar 200 yen*/

void SuccessHeavy();
/*I.S : Tidak ada (diaktifkan ketika berhasil mengantarkan item bertime heavy*/
/*F.S : Bertambah uang sebesar 400 yen dan Mengaktifkan Ability SpeedBoost */

void SuccessPerishable();
/*I.S : Tidak ada (diaktifkan ketika berhasil mengantaarkan item bertipe perishable*/
/*F.S : Bertambah uang sebesar 400 yen dan mengaktifkan item increase capacity*/

void SuccessVIP();

void displayItem(item it);
// for testing driver

#endif
