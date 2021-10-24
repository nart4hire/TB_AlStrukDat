// File: wordmachine.h
// Definisi Word Engine

#include <stdio.h>
#include "wordmachine.h"

// typedef struct {
//    char contents[CAPACITY_WORDMACHINE]; // container penyimpan kata, indeks yang dipakai [0..CAPACITY_WORDMACHINE-1]
//    int length;
// } Word;

// Word Engine State
boolean endWord;
Word currentWord;

void ignoreBlank()
{
    while (currentChar == BLANK || currentChar == NEWLINE)
    {
        adv();
    }
}
// Mengabaikan satu atau beberapa BLANK
//    I.S. : currentChar sembarang
//    F.S. : currentChar ≠ BLANK atau currentChar = MARK

void startWord()
{
    start();
    ignoreBlank();
    advWord();
}
// I.S. : currentChar sembarang
//    F.S. : endWord = true, dan currentChar = MARK;
//           atau endWord = false, currentWord adalah kata yang sudah diakuisisi,
//           currentChar karakter pertama sesudah karakter terakhir kata

void advWord()
{
    copyWord();
    ignoreBlank();
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
    while (currentChar != BLANK && currentChar != NEWLINE && currentChar != MARK)
    {
        if (currentWord.length < CAPACITY_WORDMACHINE)
        {
            currentWord.contents[currentWord.length] = currentChar;
            currentWord.length++;
        }
        adv();
    }
}
// Mengakuisisi kata, menyimpan dalam currentWord
//    I.S. : currentChar adalah karakter pertama dari kata
//    F.S. : currentWord berisi kata yang sudah diakuisisi;
//           currentChar = BLANK atau currentChar = MARK;
//           currentChar adalah karakter sesudah karakter terakhir yang diakuisisi.
//           Jika panjang kata melebihi CAPACITY_WORDMACHINE, maka sisa kata terpotong

void displayCurrentWord(Word currentWord)
{
    for (int i = 0; i < currentWord.length; i++)
        printf("%c", currentWord.contents[i]);
}
/* Menampilkan currrentWord pada terminal
   I.S. : currentWord berisi kata yang sudah diakuisisi;
   F.S. : currentWord tertampil pada layar. */

