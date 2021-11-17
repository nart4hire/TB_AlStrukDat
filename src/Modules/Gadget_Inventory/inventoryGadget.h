#ifndef INVENTORYGADGET_H
#define INVENTORYGADGET_H

#include "listpos.h"

void displayInventoryGadget(ListPos l);
// I.S. l merupakan list inventory gadget dan sudah terdefinisi sebelumnya

void kainPembungkusWaktu(int timePerishableItem,int* sisaWaktu);
// I.S. timePerishableItem adalah sisa waktu perishable item teratas pada tas
// timePerishableItemAwal adalah waktu awal perishable item 
// F.S. timePerishableItem kembali ke durasi semula (timePerishableItem = timePerishableItemAwal)

void senterPembesar(int* kapasitasTas);
// I.S. KapasitasTas merupakan kapasitas awal tas sebelumnya
// F.S. KapasitasTas ditambah menjadi dua kali lipat, tetapi tidak melebihi kapasitas maksimum tas

void pintuKemanasaja(char* lokasi, char tujuan);
// I.S. lokasi merupakan lokasi di mana Mobita berada
// F.S. lokasi = tujuan

void mesinWaktu(int* time);
// I.S. time merupakan waktu yang sedang berjalan
// F.S. time dikurangi 50. Jika time < 0 maka time = 0.

void senterPengecil(char jenisItem[], int* increaseTime);
// I.S. jenisItem adalah jenis Item teratas di Tas. 
// dan increaseTime adalah waktu yang ditambahkan ke waktu yang sedang berjalan
// F.S. Jika jenis item teratas Tas adalah heavy maka effeknya akan dihilangkan

void inventory(int command, ListPos* l, int* gadget);
// I.S. l adalah list inventory gadget dan sebelumnya sudah terdefinisi
// F.S. jika item ada di inventory gadget maka gadget akan di remove dari l
// dan gadget berisi nomer jenis gadget (misal 1 adalah nomor untuk gadget jenis kain pembungkus waktu)
// jika tidak ditampilkan pesan "Tidak ada Gadget yang dapat digunakan!" dan gadget berisi VAL_UNDEF

#endif