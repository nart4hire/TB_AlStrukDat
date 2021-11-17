#ifndef CONFIG_H
#define CONFIG_H

#include "boolean.h"
#include "wordmachine.h"
#include "matrix.h"
#include "listdinpos.h"

#define HEADQUARTERS '8'
#define ADJACENT '1'

int parseConfig(char cfg[][CAPACITY_WORDMACHINE], boolean load);

ListDin parsePoints(char cfg[][CAPACITY_WORDMACHINE]);

Matrix parseMap(char cfg[][CAPACITY_WORDMACHINE], ListDin locs);

Matrix parsePath(char cfg[][CAPACITY_WORDMACHINE]);

#endif