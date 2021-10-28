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
// ALGORITMA
    CreateListPos(&l);
    uang = 100000;
    printf("Apakah Anda ingin membeli gadget? y/n ");
    scanf(" %c",&c);
    while (c == 'y') {
        buy(&uang,&l);
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
        inventory(command,&l);
        displayInventoryGadget(l);
        printf("Apakah Anda ingin menggunakan gadget lagi? y/n ");
        scanf(" %c",&c);
    }
    return 0;
}