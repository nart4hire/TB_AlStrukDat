/* File: wordmachine.h */
/* Definisi Word Engine */

#ifndef WORD_ENGINE_H
#define WORD_ENGINE_H

#include "boolean.h"
#include "charmachine.h"
// #include "commands.h"

#define CAPACITY_WORDMACHINE 50
#define BLANK ' '
#define NEWLINE '\n'

typedef struct {
   char contents[CAPACITY_WORDMACHINE]; /* container penyimpan kata, indeks yang dipakai [0..CAPACITY_WORDMACHINE-1] */
   int length;
} Word;

/* Word Engine State */
extern boolean endLine;
extern boolean endWord;
extern boolean inGame;
extern Word currentWord;

void ignoreBlank();
/* Mengabaikan satu atau beberapa BLANK
   I.S. : currentChar sembarang 
   F.S. : currentChar ≠ BLANK atau currentChar = MARK */

void ignoreNewline();

void startWord();
/* I.S. : currentChar sembarang 
   F.S. : endWord = true, dan currentChar = MARK; 
          atau endWord = false, currentWord adalah kata yang sudah diakuisisi,
          currentChar karakter pertama sesudah karakter terakhir kata */

void advWord();
/* I.S. : currentChar adalah karakter pertama kata yang akan diakuisisi 
   F.S. : currentWord adalah kata terakhir yang sudah diakuisisi, 
          currentChar adalah karakter pertama dari kata berikutnya, mungkin MARK
          Jika currentChar = MARK, endWord = true.		  
   Proses : Akuisisi kata menggunakan procedure copyWord */

void copyWord();
/* Mengakuisisi kata, menyimpan dalam currentWord
   I.S. : currentChar adalah karakter pertama dari kata
   F.S. : currentWord berisi kata yang sudah diakuisisi; 
          currentChar = BLANK atau currentChar = MARK; 
          currentChar adalah karakter sesudah karakter terakhir yang diakuisisi.
          Jika panjang kata melebihi CAPACITY_WORDMACHINE, maka sisa kata terpotong */

// Tambahan
void parseCommand();

void startFile();

void advFile();

void copyLine();

void displayCurrentWord();

#endif
