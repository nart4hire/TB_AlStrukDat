// Tanggal : 27 Oktober 2021
// Deskripsi : Realisasi Inventory Gadget

// Setiap gadget yang terbeli dapat dimasukkan ke dalam inventory dan setiap gadget
// yang hangus otomatis terbuang dari inventory. Inventory memiliki kapasitas sebesar
// 5. Jika inventory penuh, maka Mobita tidak dapat membeli gadget.

#include <stdio.h>
#include "listpos.h"

void createInventoryGadget(ListPos* l) {
// I.S. list l sembarang
// F.S. semua elemen list l diisi 0
// KAMUS LOKAL
    int i;
// ALGORITMA
    for (i = 0; i < CAPACITY_LISTPOS; i++) {
        ELMT_LISTPOS(*l,i) = 0;
    }
}

void displayInventoryGadget(ListPos l) {
// I.S. l merupakan list inventory gadget dan sudah terdefinisi sebelumnya
// F.S. I.S = F.S
// proses : Menampilkan isi inventory gadget
// KAMUS LOKAL
    int i;
// ALGORITMA
    for (i = 0; i < CAPACITY_LISTPOS; i++) {
        if (ELMT_LISTPOS(l,i) == 0) {
            printf("%d. -", i++);
        } else {
            if (i++ == 1) {
                printf("%d. Kain Pembungkus Waktu\n",i++);
            } else if (i++ == 2) {
                printf("%d. Senter Pembesar\n",i++);
            } else if (i++ == 3) {
                printf("%d. Pintu Kemana Saja\n",i++);
            } else if (i++ == 4) {
                printf("%d. Mesin Waktu\n",i++);
            } else if (i++ == 5) {
                printf("%d. Senter Pengecil\n",i++);
            } 
        }
    }
    printf("\n");
}

void kainPembungkusWaktu(int time,int* timePerishableItem) {
// I.S. timePerishableItem adalah waktu kapan perishable item teratas pada tas akan hangus
// time adalah waktu yang sedang berjalan
// F.S. timePerishableItem kembali ke durasi semula (timePerishableItem = timePerishableItem + time)
// KAMUS LOKAL
// ALGORITMA
    *timePerishableItem += time;
}

void senterPembesar(int* kapasitasTas) {
// I.S. KapasitasTas merupakan kapasitas awal tas sebelumnya
// F.S. KapasitasTas ditambah menjadi dua kali lipat, tetapi tidak melebihi kapasitas maksimum tas
// KAMUS LOKAL
// ALGORITMA
    *kapasitasTas *= 2;
    if (*kapasitasTas > 100) {
        *kapasitasTas = 100;
    }
}

void pintuKemanasaja(char* lokasi, char tujuan) {
// I.S. lokasi merupakan lokasi di mana Mobita berada
// F.S. lokasi = tujuan
// KAMUS LOKAL
// ALGORITMA
    *lokasi = tujuan;
}

void mesinWaktu(int* time) {
// I.S. time merupakan waktu yang sedang berjalan
// F.S. time dikurangi 50. Jika time < 0 maka time = 0.
// KAMUS LOKAL
// ALGORITMA
    *time -= 50;
    if (*time < 0) {
        *time = 0;
    }
}

void senterPengecil(char* jenisItem) {
// I.S. jenisItem adalah jenis Item teratas di Tas. 
// F.S. Jika jenis item teratas Tas adalah heavy maka jenis item diubah ke normal;
    if (*jenisItem == "heavy") {
        *jenisItem = "normal";
    }
}

// void inventory(int command, ListPos* l) {
// // I.S. l adalah list inventory gadget dan sebelumnya sudah terdefinisi
// // F.S. jika item ada di inventory gadget maka gadget akan di remove dari l
// // jika tidak ditampilkan pesan "Tidak ada Gadget yang dapat digunakan!"
// // KAMUS LOKAL
// // ALGORITMA
//     if (ELMT_LISTPOS(*l, command) == 0) {
//         printf("Tidak ada Gadget yang dapat digunakan!\n\n");
//     } else {
//         ELMT_LISTPOS(*l, command) = 0;
//         if (command == 1) {
//             kainPembungkusWaktu();
//         }
//     } 
// } 