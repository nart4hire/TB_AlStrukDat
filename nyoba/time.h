#ifndef TIME_H
#define TIME_H

#include "boolean.h"

/* Char Engine State */
typedef int Time;
extern Time time_game;

void startTime();
/* I.S. : Waktu sembarang.
   F.S. : Waktu diset menjadi 0*/

void advTime();
/* Menambah waktu sebesar 1 satuan. 
   I.S. : Waktu telah dimulai, dan bukan merupakan akhir dari permainan
   F.S. : Waktu bertambah 1*/

void timeMachine();
/* Mengurangi waktu sebesar 50 satuan sesuai fungsi item. 
   I.S. : Waktu telah dimulai, dan mungkin <50
   F.S. : Waktu berkurang 50, atau menjadi 0 jika <50*/


#endif