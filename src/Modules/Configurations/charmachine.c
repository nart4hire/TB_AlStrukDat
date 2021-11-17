/* File: charmachine.c */
/* Implementasi Character Engine */

#include "charmachine.h"
#include <stdio.h>

char currentChar;
boolean eot;

static FILE *tape;
static int retval;

void start()
{
       /* Mesin siap dioperasikan. Pita disiapkan untuk dibaca.
   Karakter pertama yang ada pada pita posisinya adalah pada jendela.
   I.S. : sembarang
   F.S. : currentChar adalah karakter pertama pada pita
          Jika currentChar != MARK maka EOP akan padam (false)
          Jika currentChar = MARK maka EOP akan menyala (true) */

       /* Algoritma */
       // tape = stdin;
       tape = stdin;
       adv();
}

boolean config(char *file, int length)
{
       char folder[60] = "../Config/";
       for (int i = 10; i < length + 10; i++)
       {
              folder[i] = file[i-10];
       }
       folder[length + 10] = '\0';
       tape = fopen(folder, "r");
       if (tape == NULL)
              return 0;
       adv();
       return 1;
}

void adv()
{
       /* Pita dimajukan satu karakter. 
   I.S. : Karakter pada jendela = currentChar, currentChar != MARK
   F.S. : currentChar adalah karakter berikutnya dari currentChar yang lama, 
          currentChar mungkin = MARK
		      Jika  currentChar = MARK maka EOP akan menyala (true) */

       /* Algoritma */
       retval = fscanf(tape, "%c", &currentChar);
       eot = (retval == EOF);
       if (eot)
              fclose(tape);
}

void end()
{
       fclose(tape);
}