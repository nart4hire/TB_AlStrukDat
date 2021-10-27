#include <stdio.h>
#include <string.h>
#include "main.h"

int main(int argc, char const *argv[])
{
    char configs[512][CAPACITY_WORDMACHINE];
    int i = 0;
    parseConfig(configs);
    readConfig(configs);

    // Index Pemetaan Config Sbb:
    // Map           : N -> configs[0], M -> configs[1]
    // Coord HQ      : Row -> configs[2], Col -> configs[3]
    // No. of City   : L -> configs[4]
    // City Coords   : configs[5] s.d. configs[L * 3 + 4]
    // Matrix Hub.   : configs[L * 3 + 5] s.d. configs[(L + 1)^2 + (L * 3 + 4)]
    // No. of Orders : O -> configs[(L + 1)^2 + (L * 3 + 5)]
    // Orders        : configs[O] s.d. End
}
