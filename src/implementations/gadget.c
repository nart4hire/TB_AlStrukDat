// Tanggal : 27 Oktober 2021
// Deskripsi : Realisasi Gadget

// Dengan uang yang didapat Mobita, maka Mobita dapat membeli beberapa gadget
// dari doraemonangis. Setiap gadget yang terbeli hanya dapat digunakan tepat sekali
// dan kemudian akan hangus. Gadget yang tersedia adalah sebagai berikut:
// a. Kain Pembungkus Waktu
// Harga: 800 Yen
// Setiap kain pembungkus waktu dapat dipakai sekali untuk perishable item
// teratas pada tas agar kembali ke durasi semula.
// b. Senter Pembesar
// Harga: 1200 Yen
// Senter pembesar dapat digunakan untuk meningkatkan kapasitas tas
// sebesar dua kali lipat, namun tidak melebihi batas maksimum kapasitas tas.
// c. Pintu Kemana Saja
// Harga: 1500 Yen
// Pintu Kemana Saja dapat digunakan sekali untuk berpindah ke lokasi yang
// diinginkan tanpa menambahkan unit waktu.
// d. Mesin Waktu
// Harga: 3000 Yen
// Mesin waktu dapat digunakan untuk mengurangi waktu sebanyak 50 unit.
// (jika waktu kurang dari 50 unit, maka waktu menjadi 0 unit).
// e. (Bonus) Senter Pengecil
// Harga: 800 Yen
// Senter pengecil dapat digunakan untuk menghilangkan efek dari satu heavy
// item jika terdapat pada tumpukan teratas tas. Efek dari senter pengecil ini
// akan berlangsung sampai melakukan drop off / return pertama kali setelah
// penggunaan gadget ini.

#include <stdio.h>
#include "inventoryGadget.h"
#include "gadget.h"


void displayGadget() {
// Menampilkan daftar gadget yang tersedia
// KAMUS LOKAL
// ALGORITMA
    printf("Gadget yang tersedia: \n\n");
    printf("1. Kain pembungkus waktu (800 Yen)\n");
    printf("2. Senter Pembesar (1200 Yen)\n");
    printf("3. Pintu Kemana Saja (1500 Yen)\n");
    printf("4. Mesin Waktu (3000 Yen)\n");
    printf("5. Senter Pengecil (800 yen)\n\n");
    printf("Gadget mana yang ingin Mobita beli? (ketik 0 jika ingin kembali)\n\n");
}

boolean buy(int command, int* uang, ListPos* l) {
// I.S. \nUang dan l terdefinisi sebelumnya
// F.S. Jika gadget yang dibeli harganya <= uang dan gadget tersebut belum ada di list l
// maka uang = uang - hargaBarang dan gadget ditambahkan ke list l 
// Jika gadget yang dibeli harganya > uang maka I.S. = F.S.
// KAMUS LOKAL
// -
// ALGORITMA
    if (isFull_ListPos(*l) && command != 0) {
        printf("\n\"Mobita, dalam shopping spree yang ia lakukan lupa bahwa ransel yang ia bawa memiliki kapasitas terbatas.\n");
        printf("Dengan berat hati ia pun meninggalkan toko milik Doraemonangis itu.\"\n\n");
        printf("Inventori gadget penuh!\n\n");
    } else {
        switch (command) {
        case 0:
            printf("\n\"Mobita teringat bahwa ia melakukan pekerjaan ini untuk membantu orang tuanya. Dengan berat hati, ia\n");
            printf("meninggalkan toko milik Doraemonangis itu.\"\n\n");
            return true;
            break;
        case 1:
            if (*uang >= 800) {
                insertLast_ListPos(l, 1);
                printf("Kain pembungkus waktu berhasil dibeli!\n");
                *uang -= 800;
                printf("\nUang Anda sekarang: %d yen\n\n", *uang);
                return true;
            } else {
                printf("\n\"Doraemonangis menggelengkan kepala dengan sedih, ia juga terkena dampak PPKM secara moneter dan terpaksa\n");
                printf("menjual gadgetnya untuk mendapatkan uang. Sudah tidak bisa gratis lagi seperti dahulu kala.\"\n");
                printf("\nUang Mobita tidak cukup untuk membeli gadget ini.\n\n");
                return false;
            }
            break;
        case 2:
            if (*uang >= 1200) {
                insertLast_ListPos(l, 2);
                printf("Senter Pembesar berhasil dibeli!\n");
                *uang -= 1200;
                printf("\nUang Anda sekarang: %d yen\n\n", *uang);
                return true;
            } else {
                printf("\n\"Doraemonangis menggelengkan kepala dengan sedih, ia juga terkena dampak PPKM secara moneter dan terpaksa\n");
                printf("menjual gadgetnya untuk mendapatkan uang. Sudah tidak bisa gratis lagi seperti dahulu kala.\"\n");
                printf("\nUang Mobita tidak cukup untuk membeli gadget ini.\n\n");
                return false;
            }
            break;
        case 3:
            if (*uang >= 1500) {
                insertLast_ListPos(l,3);
                printf("Pintu Kemana Saja berhasil dibeli!\n");
                *uang -= 1500;
                printf("\nUang Anda sekarang: %d yen\n\n", *uang);
                return true;
            } else {
                printf("\n\"Doraemonangis menggelengkan kepala dengan sedih, ia juga terkena dampak PPKM secara moneter dan terpaksa\n");
                printf("menjual gadgetnya untuk mendapatkan uang. Sudah tidak bisa gratis lagi seperti dahulu kala.\"\n");
                printf("\nUang Mobita tidak cukup untuk membeli gadget ini.\n\n");
                return false;
            }
            break;
        case 4:
            if (*uang >= 3000) {
                insertLast_ListPos(l,4);
                printf("Mesin Waktu berhasil dibeli!\n");
                *uang -= 3000;
                printf("\nUang Anda sekarang: %d yen\n\n", *uang);
                return true;
            } else {
                printf("\n\"Doraemonangis menggelengkan kepala dengan sedih, ia juga terkena dampak PPKM secara moneter dan terpaksa\n");
                printf("menjual gadgetnya untuk mendapatkan uang. Sudah tidak bisa gratis lagi seperti dahulu kala.\"\n");
                printf("\nUang Mobita tidak cukup untuk membeli gadget ini.\n\n");
                return false;
            }
            break;
        case 5:
            if (*uang >= 800) {
                insertLast_ListPos(l,5);
                printf("Senter Pengecil berhasil dibeli!\n");
                *uang -= 800;
                printf("\nUang Anda sekarang: %d yen\n\n", *uang);
                return true;
            } else {
                printf("\n\"Doraemonangis menggelengkan kepala dengan sedih, ia juga terkena dampak PPKM secara moneter dan terpaksa\n");
                printf("menjual gadgetnya untuk mendapatkan uang. Sudah tidak bisa gratis lagi seperti dahulu kala.\"\n");
                printf("\nUang Mobita tidak cukup untuk membeli gadget ini.\n\n");
                return false;
            }
            break;
        default:
            printf("Command salah!\n");
            break;
        }
    }
}

