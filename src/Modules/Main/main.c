#include <stdio.h>
#include "main.h"
#include "command.c"

int main(int argc, char const *argv[])
{
    char configs[512][CAPACITY_WORDMACHINE];
    Menu(configs);
    Game(configs);
}
