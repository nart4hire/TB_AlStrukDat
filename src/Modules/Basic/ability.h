#ifndef ABILITY_H
#define ABILITY_H

#include "time.h"

typedef struct {
    boolean speedboost;
    boolean donelast;
    Time timerspeedboost;
    int rettosender;
    int heavy;
    boolean reductheavy;
} ability;

#define SPEED(a) (a).speedboost
#define DONE(a) (a).donelast
#define RETURN(a) (a).rettosender
#define TIMER(a) (a).timerspeedboost
#define HEAVY(a) (a).heavy
#define REDUCT(a) (a).reductheavy

extern ability abilities;

void initAbilities();

void ActSpeedBoost();
/*I.S : Tidak ada (setelah berhasil mendropoff heavy item)*/
/*F.S : Mengubah speedbost menjadi true*/

void removeSpeedBoost();
/*I.S : Tidak ada (setelah pick-up heavy item atau waktu speedboost habis*/
/*F.S : Mengubah speedboost menjadi false*/

int ActIncCapacity();
/*I.S : Tidak ada (setelah berhasil mendropoff perishable item*/
/*F.S : Menambah inccapacity sebanyak 1 buah*/

void ActIncHeavy();

void ActIncReturn();

boolean UseReturn();

boolean UseSpeed();
/*I.S : Tidak ada (digunakan sepanjang permainan)*/
/*F.S : Melakukan pengecekan ability yang ada */

int numHeavy();

#endif

