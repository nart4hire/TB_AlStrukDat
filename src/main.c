#include <stdio.h>
#include "wordmachine.h"

int main(int argc, char const *argv[])
{
    startWord();
    displayCurrentWord(currentWord);
    printf("%c", BLANK);
    while (!endWord)
    {
        advWord();
        displayCurrentWord(currentWord);
        if (currentChar == NEWLINE)
            printf("%c", NEWLINE);
        else
            printf("%c", BLANK);
    }
    return 0;
}
