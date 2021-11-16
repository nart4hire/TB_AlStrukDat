#ifndef MAIN_H
#define MAIN_H

#define HEADQUARTERS '8'
#define ADJACENT '1'

#define none_color          "\x1B[30m"
#define pickup_color        "\x1B[31m"
#define dest_color          "\x1B[32m"
#define mob_color           "\x1B[33m"
#define dropoff_color       "\x1B[34m"
#define bg_color            "\x1B[48;2;117;85;2m"

#define normal              "\x1B[0m"
#define clear               "\x1B[39m"
#define wipe                "\x1b[2J\x1b[H"

#include "point.h"
#include "listdinpos.h"
#include "matrix.h"
#include "wordmachine.h"

#include "list_order.h"

#include "config.c"
#include "map.c"
#include "command.c"

#endif