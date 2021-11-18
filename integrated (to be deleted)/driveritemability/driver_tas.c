#include <stdio.h>
#include "tas.h"

int main(){
    Stack s;
    item i, j;
    CreateStack(&s);
    i = createItem(1,'G','N','N',0);
    push(&s,i);
    j = createItem(1,'G','N','N',0);
    push(&s,j);
    displayStack(s);
}