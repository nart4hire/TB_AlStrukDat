/* File: wordmachine.h */
/* Definisi Word Engine */

#ifndef WORD_ENGINE_H
#define WORD_ENGINE_H

#include "charmachine.h"

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
extern Word currentWord;
extern Word currentPath;

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

boolean startFile(char *file, int length);

void advWord();
/* I.S. : currentChar adalah karakter pertama kata yang akan diakuisisi 
   F.S. : currentWord adalah kata terakhir yang sudah diakuisisi, 
          currentChar adalah karakter pertama dari kata berikutnya, mungkin MARK
          Jika currentChar = MARK, endWord = true.		  
   Proses : Akuisisi kata menggunakan procedure copyWord */

void advFile();

void copyWord();
/* Mengakuisisi kata, menyimpan dalam currentWord
   I.S. : currentChar adalah karakter pertama dari kata
   F.S. : currentWord berisi kata yang sudah diakuisisi; 
          currentChar = BLANK atau currentChar = MARK; 
          currentChar adalah karakter sesudah karakter terakhir yang diakuisisi.
          Jika panjang kata melebihi CAPACITY_WORDMACHINE, maka sisa kata terpotong */

void copyWordFile();

void endFile();

boolean startWrite(char *file, int length);

void saveLine(char *saved);

void closeSave();

void copyPath();

void displayCurrentWord(Word currentWord);
/* Menampilkan currrentWord pada terminal
   I.S. : currentWord berisi kata yang sudah diakuisisi;
   F.S. : currentWord tertampil pada layar. */

#endif
