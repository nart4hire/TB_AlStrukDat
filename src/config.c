#include <stdio.h>
#include <stdlib.h>
#include "wordmachine.h"

#define CAPACITY_CFG 2048

void parseConfig(char cfg[][CAPACITY_WORDMACHINE])
{
    char string[51];
    int i = 0;
    startFile();
    while (!endWord)
    {
        memcpy(string, currentWord.contents, currentWord.length);
        string[currentWord.length] = '\0';
        strcpy(cfg[i++], string);
        advWord();
    }
}

void readConfig(char cfg[][CAPACITY_WORDMACHINE])
{
    int ct, o, os;
    printf("###     CONFIGURATIONS     ###\n");
    printf("Map Size         : %s x %s\n", cfg[0], cfg[1]);
    printf("HQ Coordinates   : (%s,%s)\n", cfg[2], cfg[3]);
    printf("Number of Cities : %s\n", cfg[4]);
    ct = atoi(cfg[4]);
    for (int i = 0; i < ct * 3; i += 3)
        printf("%s Coordinates    : (%s,%s)\n", cfg[i + 5], cfg[i + 6], cfg[i + 7]);
    printf("Matrix Hubungan  :\n");
    ++ct;
    o = ct * ct + 56;
    for (int i = 56; i < o; i += 18)
    {
        for (int j = i; j < i + ct; j++)
        {
            printf("%s ", cfg[j]);
        }
        printf("\n");
    }
    printf("Number of Orders : %s\n", cfg[o]);
    os = atoi(cfg[o]);
    for (int i = 0; i < os; i++)
    {
        printf("Order %-2d :\n", i + 1);
        printf("    Time    : %s\n", cfg[++o]);
        printf("    Pickup  : %s\n", cfg[++o]);
        printf("    Dropoff : %s\n", cfg[++o]);
        printf("    Type    : %s ", cfg[++o]);
        if (cfg[o][0] == 'P')
            printf("(Time limit : %d)", atoi(cfg[++o]));
        printf("\n");
    }
    printf("###     CONFIGURATIONS     ###");
}