 #include <stdio.h>
//#include <stdlib.h>
#include <string.h>
#include "Inc/LexicalAnalysis.h"

char CharStream[1024];

int main()
{
    int index = 0,i;
    int *p = &index;
    int word_sum;
    memset(CharStream,0,sizeof (CharStream));
    word_sum = ReadAndDeal_C_File(CharStream);
    printf("%s\n",CharStream);
    CFFX(p,CharStream);
}