#ifndef CONFIG_H
#define CONFIG_H

#include "boolean.h"
#include "wordmachine.h"
#include "matrix.h"
#include "listdinpos.h"
#include "q_pesanan.h"
#include "list_todo.h"
#include "listpos.h"
#include "tas.h"

#define HEADQUARTERS '8'
#define ADJACENT '1'

int parseConfig(char cfg[][CAPACITY_WORDMACHINE], boolean load);

ListDin parsePoints(char cfg[][CAPACITY_WORDMACHINE]);

Matrix parseMap(char cfg[][CAPACITY_WORDMACHINE], ListDin locs);

Matrix parsePath(char cfg[][CAPACITY_WORDMACHINE]);

Queue parseOrders(char cfg[][CAPACITY_WORDMACHINE]);

int getSaveArea(char cfg[][CAPACITY_WORDMACHINE]);

int saveGame(char cfg[][CAPACITY_WORDMACHINE], Queue *ords, ListLinked *todo, ListLinked *inpro, Stack *bag, ListPos *inv);

void parseLoad(char cfg[][CAPACITY_WORDMACHINE], Queue *ords, ListLinked *todo, ListLinked *inpro, Stack *bag, ListPos *inv);

#endif