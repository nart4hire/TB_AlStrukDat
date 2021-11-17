#include <stdio.h>
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
    ListDin locs = parsePoints(configs);
    Matrix map = parseMap(configs, locs), adj = parsePath(configs);
    displayList_ListDin(locs);
    displayMatrix(map);
    displayMatrix(adj);
    return 0;
}
