#include <stdio.h>
#include "wordmachine.h"

void parseConfig()
{
    startFile();
    displayCurrentWord(currentWord);
    printf("%c", BLANK);
    while (!endWord)
    {
        advWord();
        displayCurrentWord(currentWord);
        if (endLine)
            printf("%c", NEWLINE);
        else
            printf("%c", BLANK);
    }
}