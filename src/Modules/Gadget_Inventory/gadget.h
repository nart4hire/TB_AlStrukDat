#ifndef GADGET_H
#define GADGET_H

#include "listpos.h"
#include "inventoryGadget.h"

void displayGadget();
// Menampilkan daftar gadget yang tersedia

boolean buy(int command, int* uang, ListPos* l);
// I.S. Uang dan l terdefinisi sebelumnya
// F.S. Jika gadget yang dibeli harganya <= uang dan gadget tersebut belum ada di list l
// maka uang = uang - hargaBarang dan gadget ditambahkan ke list l 
// Jika gadget yang dibeli harganya > uang maka I.S. = F.S.

#endif