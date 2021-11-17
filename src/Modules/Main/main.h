#ifndef MAIN_H
#define MAIN_H

#define none_color          "\x1B[30m"
#define pickup_color        "\x1B[31m"
#define dest_color          "\x1B[32m"
#define mob_color           "\x1B[33m"
#define dropoff_color       "\x1B[34m"
#define bg_color            "\x1B[48;2;117;85;2m"

#define normal              "\x1B[0m"
#define clear               "\x1B[39m"
#define wipe                "\x1b[H\x1b[2J\x1b[H"

#include "config.h"

#include "list_todo.h"
#include "q_pesanan.h"

#include "tas.h"

#include "gadget.h"

#include "ability.h"

#include "command.c"

#endif