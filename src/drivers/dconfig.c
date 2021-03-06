#include <stdio.h>
#include <stdlib.h>
#include "config.h"

int main(int argc, char const *argv[])
{
    boolean found;
    char configs[512][CAPACITY_WORDMACHINE];
    char *string = "Configs";
    printf("ENTER CONFIG FILE: ");
    startWord();
    found = parseConfig(configs, 0);
    while (!found)
    {
        printf("\nYou entered the wrong config file!\n\n");
        printf("ENTER CONFIG FILE: ");
        startWord();
        found = parseConfig(configs, 0);
    }
    
    
    // printf("ENTER CONFIG FILE: ");
    // startWord();
    // found = saveGame(configs);
    // while (!found)
    // {
    //     printf("\nYou entered the wrong config file!\n\n");
    //     printf("ENTER CONFIG FILE: ");
    //     startWord();
    //     found = saveGame(configs);
    // }

    ListDin locs = parsePoints(configs);
    Matrix map = parseMap(configs, locs), adj = parsePath(configs);
    Queue ords = parseOrders(configs);
    ListLinked todo, inpro;
    Stack bag;
    ListPos inv;
    CreateListPos(&inv);
    CreateStack(&bag);
    CreateListOrder(&todo);
    CreateListOrder(&inpro);
    displayList_ListDin(locs);
    displayMatrix(map);
    displayMatrix(adj);
    displayQueue(ords);
    printf("%d\n", length_Queue(ords));

    saveGame(configs, &ords, &todo, &inpro, &bag, &inv);
    return 0;
}
