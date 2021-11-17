#ifndef ITEM_H
#define ITEM_H

#include "boolean.h"
#include "time.h"
 
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

item createItem(Time tServe, char pickUp, char dropOff, char type_item, Time pTime);

boolean isNormal(item i);
/* Mengembalikan True apabila type item == normal*/

boolean isHeavy(item i);
/* Mengembalikan True apabila type item == heavy*/

boolean isPerishable(item i);
/* Mengembalikan true apabila type  item == perishable */

boolean isVIP(item i);
/* Mengembalikan True apabila type item == VIP*/

void HeavyEffect(int jumlah_heavy);
/*I.S : Diketahui berapa jumlah heavy pada tas*/
/*F.S : Untuk setiap heavy item yang ada dalam progress, maka waktu untuk melewati 1 unit lokasi bertambah sebanyak 1 unit waktu*/

int StartPerishable(item *perish_item);
/*I.S : Tidak ada (mem-pick up item perishable)*/
/*F.S : Telah menerima input waktu dan mengubah waktu hangus dari sebuah item, lalu memulai perhitungan waktu hangus item*/

void InProgressPerish(item *perish_item);
/*I.S : tidak ada (terdapat perishable item pada inprogresslist*/
/*F.S : menghitung mundur waktu dan perishable akan hangus jika waktu perjalanan melebihi batas waktu item*/

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

#endif
