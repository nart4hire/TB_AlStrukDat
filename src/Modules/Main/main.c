#include <stdio.h>
#include "command.c"

int main(int argc, char const *argv[])
{
    boolean load;
    char configs[512][CAPACITY_WORDMACHINE];
    while (1)
    {
        load = Menu(configs);
        Game(configs, load);
    }
}
