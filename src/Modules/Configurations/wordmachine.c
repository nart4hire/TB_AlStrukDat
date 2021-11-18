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
Word currentWord;
Word currentPath;

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
    while (currentChar != NEWLINE)
    {
        if (currentWord.length < CAPACITY_WORDMACHINE)
        {
            currentWord.contents[currentWord.length] = currentChar;
            currentWord.length++;
        }
        adv();
    }
    currentWord.contents[currentWord.length] = '\0';
}
// Mengakuisisi kata, menyimpan dalam currentWord
//    I.S. : currentChar adalah karakter pertama dari kata
//    F.S. : currentWord berisi kata yang sudah diakuisisi;
//           currentChar = BLANK atau currentChar = MARK;
//           currentChar adalah karakter sesudah karakter terakhir yang diakuisisi.
//           Jika panjang kata melebihi CAPACITY_WORDMACHINE, maka sisa kata terpotong



boolean startFile(char *file, int length)
{
    boolean exist;
    exist = config(file, length);
    if (exist == 0)
        return 0;
    advFile();
    return 1;
}


void advFile()
{
    ignoreBlank();
    ignoreNewline();
    copyWordFile();
    endWord = eot;
}


void endFile()
{
    close();
}


void copyWordFile()
{
    currentWord.length = 0;
    while (currentChar != NEWLINE && currentChar != MARK)
    {
        if (currentWord.length < CAPACITY_WORDMACHINE)
        {
            currentWord.contents[currentWord.length] = currentChar;
            currentWord.length++;
        }
        adv();
    }
    currentWord.contents[currentWord.length] = '\0';
}

boolean startWrite(char *file, int length)
{
    boolean exist;
    exist = save(file, length);
    if (exist == 0)
        return 0;
    return 1;
}

void saveLine(char *saved)
{
    int i = 0;
    while (saved[i] != '\0')
    {
        write(saved[i++]);
    }
    write(NEWLINE);
}

void closeSave()
{
    savedat();
}

void copyPath()
{
    int i = 0;
    while (currentWord.contents[i] != '\0')
    {
        currentPath.contents[i] = currentWord.contents[i];
        ++i;
    }
    currentPath.contents[i] = '\0';
    currentPath.length = currentWord.length;
}

void displayCurrentWord(Word currentWord)
{
    printf("%s\n", currentWord.contents);
}
/* Menampilkan currrentWord pada terminal
   I.S. : currentWord berisi kata yang sudah diakuisisi;
   F.S. : currentWord tertampil pada layar. */

