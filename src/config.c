#include <stdio.h>
#include <stdlib.h>
#include "wordmachine.h"

int parseConfig(char cfg[][CAPACITY_WORDMACHINE], char *file, int length, boolean load)
{
    boolean able = 0;
    able = startFile(file, length);
    if (able)
    {
        int i = 0, j, count;
        for (int k = 0; k < 3; k++)
        {
            j = 0;
            while (currentWord.contents[j] != '\0')
            {
                cfg[i][j] = currentWord.contents[j];
                ++j;
            }
            cfg[i][j] = '\0';
            ++i;
            advFile();
        }
        count = atoi(cfg[i-1]);
        for (int k = 0; k < count; k++)
        {
            j = 0;
            while (currentWord.contents[j] != '\0')
            {
                cfg[i][j] = currentWord.contents[j];
                ++j;
            }
            cfg[i][j] = '\0';
            ++i;
            advFile();
        }
        for (int k = 0; k < count + 2; k++)
        {
            j = 0;
            while (currentWord.contents[j] != '\0')
            {
                cfg[i][j] = currentWord.contents[j];
                ++j;
            }
            cfg[i][j] = '\0';
            ++i;
            advFile();
        }
        count = atoi(cfg[i-1]);
        for (int k = 0; k < count; k++)
        {
            j = 0;
            while (currentWord.contents[j] != '\0')
            {
                cfg[i][j] = currentWord.contents[j];
                ++j;
            }
            cfg[i][j] = '\0';
            ++i;
            advFile();
        }
        if (load)
        {
            // smth
        }
    }
    return able;
}
