#include "item.h"
#include "ability.h"
#include "time.h"
#include "tas.h"
#include <stdio.h>
#include <stdlib.h>

int main(){

    int masukanuang;
    int cash;


    scanf("%d", &masukanuang);
    printf("masukanuang saat ini ialah %d\n", masukanuang);

    initCash(masukanuang);
    printf("Cash saat ini berjumlah %d \n",cash);


    item it = createItem(1,'G','N','N',0);
    displayItem(it);

    printf("item it akan dikopi ke item it2\n");
    item it2 = copyItem(it);

    displayItem(it2);

    if (isEqItem(it,it2)){
        printf("Item sama\n");
    }
    else{
        printf("Item tidak sama\n");
    }

    if (isNormal(it)){
        printf("Item normal\n");
    }
    else{
        printf("Item tidak normal\n");
    }

    if (isHeavy(it)){
        printf("Item Heavy\n");
    }
    else{
        printf("Item tidak Heavy\n");
    }
    if (isPerishable(it)){
        printf("Item Perishable\n");
    }
    else{
        printf("Item tidak Perishable\n");
    }
    if (isVIP(it)){
        printf("Item VIP\n");
    }
    else{
        printf("Item tidak VIP\n");
    }

    SuccessNormal();
    printf("Cash saat ini berjumlah %d\n", cash);
    SuccessHeavy();
    printf("Cash saat ini berjumlah %d\n", cash);
    SuccessPerishable();
    printf("Cash saat ini berjumlah %d\n", cash);
    SuccessVIP();
    printf("Cash saat ini berjumlah %d\n", cash);

    return 0;
}
