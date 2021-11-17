#include <stdio.h>
#include "color.h"

void wipeScreen()
{
    printf("%s", wipe);
}

void loreStart()
{
    printf("%s", lore_color);
}

void loreEnd()
{
    printf("%s", clear);
}