// File: wordmachine.h
// Definisi Word Engine

#include <stdio.h>
#include <string.h>
#include "wordmachine.h"

// typedef struct {
//    char contents[CAPACITY_WORDMACHINE]; // container penyimpan kata, indeks yang dipakai [0..CAPACITY_WORDMACHINE-1]
//    int length;
// } Word;

// Word Engine State
boolean endLine;
boolean endWord;
boolean inGame = 0;
Word currentWord;

void ignoreBlank()
{
    while (currentChar == BLANK)
        adv();
}
// Mengabaikan satu atau beberapa BLANK
//    I.S. : currentChar sembarang
//    F.S. : currentChar ≠ BLANK atau currentChar = MARK

void ignoreNewline()
{
    while (currentChar == NEWLINE)
        adv();
}

void startWord()
{
    start();
    advWord();
}
// I.S. : currentChar sembarang
//    F.S. : endWord = true, dan currentChar = MARK;
//           atau endWord = false, currentWord adalah kata yang sudah diakuisisi,
//           currentChar karakter pertama sesudah karakter terakhir kata

void advWord()
{
    ignoreBlank();
    ignoreNewline();
    copyWord();
    endWord = (currentChar == MARK);
}
// I.S. : currentChar adalah karakter pertama kata yang akan diakuisisi
//    F.S. : currentWord adalah kata terakhir yang sudah diakuisisi,
//           currentChar adalah karakter pertama dari kata berikutnya, mungkin MARK
//           Jika currentChar = MARK, endWord = true.
//    Proses : Akuisisi kata menggunakan procedure copyWord

void copyWord()
{
    currentWord.length = 0;
    while (currentChar != NEWLINE && currentChar != MARK)
    {
        if (currentWord.length < CAPACITY_WORDMACHINE)
        {
            currentWord.contents[currentWord.length] = currentChar;
            currentWord.length++;
        }
        currentWord.contents[currentWord.length] = '\0';
        adv();
    }
}
// Mengakuisisi kata, menyimpan dalam currentWord
//    I.S. : currentChar adalah karakter pertama dari kata
//    F.S. : currentWord berisi kata yang sudah diakuisisi;
//           currentChar = BLANK atau currentChar = MARK;
//           currentChar adalah karakter sesudah karakter terakhir yang diakuisisi.
//           Jika panjang kata melebihi CAPACITY_WORDMACHINE, maka sisa kata terpotong

void startFile()
{
    config();
    advFile();
}

void advFile()
{
    ignoreBlank();
    copyLine();
    endLine = eol;
    ignoreBlank();
    ignoreNewline();

    // Reading Engine
    displayCurrentWord();
}

void copyLine()
{
    currentWord.length = 0;
    while (currentChar != NEWLINE && currentChar != BLANK && currentChar != MARK)
    {
        printf("%c", currentChar);
        if (currentChar != BLANK)
        {
            currentWord.contents[currentWord.length] = currentChar;
            currentWord.length++;
        }
        currentWord.contents[currentWord.length] = '\0';
        advf();
    }
}

void displayCurrentWord()
{
    for (int i = 0; i < currentWord.length; i++)
        printf("%c", currentWord.contents[i]);
    printf("\n");
}
/* Menampilkan currrentWord pada terminal
   I.S. : currentWord berisi kata yang sudah diakuisisi;
   F.S. : currentWord tertampil pada layar. */

