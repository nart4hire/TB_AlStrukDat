#ifndef ABILITY_H
#define ABILITY_H
#include "tas.h"
#include "boolean.h"
#include "time.h"

typedef struct {
    boolean speedboost;
    Time timerspeedboost;
    int inccapacity;
    boolean rettosender;
} ability;

#define SPEED(p) (p).speedboost
#define INCCAP(p) (p).inccapacity
#define RETSENDER(p) (p).rettosender
#define SPEEDTIMER(p) (p).timerspeedboost




void ActSpeedBoost();
/*I.S : Tidak ada (setelah berhasil mendropoff normal item)*/
/*F.S : Mengubah speedbost menjadi true*/
void removeSpeedBoost();
/*I.S : Tidak ada (setelah pick-up heavy item atau waktu speedboost habis*/
/*F.S : Mengubah speedboost menjadi false*/
void ActIncCapacity();
/*I.S : Tidak ada (setelah berhasil mendropoff heavy item*/
/*F.S : Menambah inccapacity sebanyak 1 buah*/
void UseAbility(ability *a);
/*I.S : Tidak ada (digunakan sepanjang permainan)*/
/*F.S : Melakukan pengecekan ability yang ada */

void advTimeSpeedBoost();
/*I.S : Tidak ada (digunakan jika Speedboost aktif)*/
/*F.S : menggunakan advTime dengan time game bertambah setengah*/

#endif

