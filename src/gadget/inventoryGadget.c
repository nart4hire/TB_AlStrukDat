// Tanggal : 27 Oktober 2021
// Deskripsi : Realisasi Inventory Gadget

// Setiap gadget yang terbeli dapat dimasukkan ke dalam inventory dan setiap gadget
// yang hangus otomatis terbuang dari inventory. Inventory memiliki kapasitas sebesar
// 5. Jika inventory penuh, maka Mobita tidak dapat membeli gadget.

#include <stdio.h>
#include "inventoryGadget.h"
#include <string.h>

// void createInventoryGadget(ListPos* l) {
// // I.S. list l sembarang
// // F.S. semua elemen list l diisi 0
// // KAMUS LOKAL
//     int i;
// // ALGORITMA
//     for (i = 0; i < CAPACITY_LISTPOS; i++) {
//         ELMT_LISTPOS(*l,i) = 0;
//     }
// }

void displayInventoryGadget(ListPos l) {
// I.S. l merupakan list inventory gadget dan sudah terdefinisi sebelumnya
// F.S. I.S = F.S
// proses : Menampilkan isi inventory gadget
// KAMUS LOKAL
    int i;
// ALGORITMA
    for (i = 0; i < CAPACITY_LISTPOS; i++) {
        if (ELMT_LISTPOS(l,i) == 1) {
            printf("%d. Kain Pembungkus Waktu\n",i + 1);
        } else if (ELMT_LISTPOS(l,i) == 2) {
            printf("%d. Senter Pembesar\n",i + 1);
        } else if (ELMT_LISTPOS(l,i) == 3) {
            printf("%d. Pintu Kemana Saja\n",i + 1);
        } else if (ELMT_LISTPOS(l,i) == 4) {
            printf("%d. Mesin Waktu\n",i + 1);
        } else if (ELMT_LISTPOS(l,i) == 5) {
            printf("%d. Senter Pengecil\n",i + 1);
        } else {
            printf("%d. -\n", i + 1);
        }  
    }
    printf("\n");
}

void kainPembungkusWaktu(int timePerishableItem,int* sisaWaktu) {
// I.S. timePerishableItem adalah sisa waktu perishable item teratas pada tas
// timePerishableItemAwal adalah waktu awal perishable item 
// F.S. timePerishableItem kembali ke durasi semula (timePerishableItem = timePerishableItemAwal)
// KAMUS LOKAL
// ALGORITMA
    *sisaWaktu = timePerishableItem;
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

void senterPengecil(char jenisItem[], int* increaseTime) {
// I.S. jenisItem adalah jenis Item teratas di Tas. 
// dan increaseTime adalah waktu yang ditambahkan ke waktu yang sedang berjalan
// F.S. Jika jenis item teratas Tas adalah heavy maka effeknya akan dihilangkan
// yaitu increaseTime dikurangi 1
    if (strcmp(jenisItem,"heavy") == 0) {
        *increaseTime = *increaseTime - 1;
    }
}

void inventory(int command, ListPos* l, int* gadget) {
// I.S. l adalah list inventory gadget dan sebelumnya sudah terdefinisi
// F.S. jika item ada di inventory gadget maka gadget akan di remove dari l
// dan gadget berisi nomer jenis gadget (misal 1 adalah nomor untuk gadget jenis kain pembungkus waktu)
// jika tidak ditampilkan pesan "Tidak ada Gadget yang dapat digunakan!" dan gadget berisi VAL_UNDEF
// KAMUS LOKAL
// ALGORITMA
    int val;
    if (command >= 1 && command <= 5) {
        if (isEmpty_ListPos(*l)) {
            printf("Tidak ada Gadget yang dapat digunakan\n\n");
            *gadget = VAL_UNDEF;
        } else if (ELMT_LISTPOS(*l, command - 1) == VAL_UNDEF) {
            printf("Gadget kosong!\n\n");
            *gadget = VAL_UNDEF;
        } else {
            if (ELMT_LISTPOS(*l,command - 1) == 1) {
                printf("Kain Pembungkus Waktu berhasil digunakan!\n\n");
                deleteAt_ListPos(l,command-1,&val);
                *gadget = 1;
            } else if (ELMT_LISTPOS(*l,command - 1) == 2) {
                printf("Senter Pembesar berhasil digunakan!\n\n");
                deleteAt_ListPos(l,command-1,&val);
                *gadget = 2;
            } else if (ELMT_LISTPOS(*l,command - 1) == 3) {
                printf("Pintu Kemana Saja berhasil digunakan!\n\n");
                deleteAt_ListPos(l,command-1,&val);
                *gadget = 3;
            } else if (ELMT_LISTPOS(*l,command - 1) == 4) {
                printf("Mesin Waktu berhasil digunakan!\n\n");
                deleteAt_ListPos(l,command-1,&val);
                *gadget = 4;
            } else if (ELMT_LISTPOS(*l,command - 1) == 5) {
                printf("Senter Pengecil berhasil digunakan!\n\n");
                deleteAt_ListPos(l,command-1,&val);
                *gadget = 5;
            }
        } 
    } else {
        printf("Command salah!\n\n");
        *gadget = VAL_UNDEF;
    }
}
