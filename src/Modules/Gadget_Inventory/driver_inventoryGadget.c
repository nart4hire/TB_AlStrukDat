#include <stdio.h> 
#include "listpos.h"
#include "gadget.h"
#include "inventoryGadget.h"

int main(int argc, char const *argv[])
{
// KAMUS LOKAL
    ListPos l;
    int uang, command;
    char c;
    int timePerishableItem = 10;
    int sisaWaktu = 5;
    int kapasitasTas = 15;
    char lokasi = 'X';
    char tujuan = 'Y';
    int time = 30;
    char jenisItem[] = "heavy";
    int increaseTime = 3;
    int gadget;
// ALGORITMA
    CreateListPos(&l);
    uang = 100000;
    printf("Apakah Anda ingin membeli gadget? y/n ");
    scanf(" %c",&c);
    while (c == 'y') {
        printf("Uang Anda sekarang: %d\n", uang);
        displayGadget();
        printf("ENTER COMMAND: ");
        scanf("%d",&command);
        buy(command,&uang,&l);
        displayInventoryGadget(l);
        printf("Apakah Anda ingin membeli gadget lagi? y/n ");
        scanf(" %c",&c);
    }

    printf("Apakah Anda ingin menggunakan gadget? y/n ");
    scanf(" %c",&c);
    while(c == 'y') {
        displayInventoryGadget(l);
        printf("Command: ");
        scanf("%d",&command);
        inventory(command,&l, &gadget);

        if (gadget == 1) {
            kainPembungkusWaktu(timePerishableItem,&sisaWaktu);
            printf("Sisa waktu perishable item: %d\n", sisaWaktu);
        } else if (gadget == 2) {
            senterPembesar(&kapasitasTas);
            printf("Kapasitas tas sekarang: %d\n", kapasitasTas);
        } else if (gadget == 3){
            pintuKemanasaja(&lokasi,tujuan);
            printf("lokasi Anda sekarang: %c\n", lokasi);
        } else if (gadget == 4) {
            mesinWaktu(&time);
            printf("waktu sekarang adalah: %d\n",time);
        } else if (gadget == 5) {
            senterPengecil(jenisItem,&increaseTime);
            printf("waktu yang dibutuhkan untuk berpindah tempat sekarang adalah: %d\n", increaseTime);
        }

        displayInventoryGadget(l);
        printf("Apakah Anda ingin menggunakan gadget lagi? y/n ");
        scanf(" %c",&c);
    }
    return 0;
}