 #include <stdio.h>
//#include <stdlib.h>
#include <string.h>
#include "Inc/LexicalAnalysis.h"
#include "Inc/GramAnalysis.h"

char CharStream[1024];
Token token[1024];


void menu()
{
    
}


int main()
{
    int word_sum;
    while (1)
    {
        char c;
        printf("*************************************************\n");
        printf("1.词法分析\n");
        printf("1.语法分析\n");
        printf("1.词法分析\n");
        printf("*************************************************\n");
        c = getchar();
        switch (c)
        {
            case '1':
            {
                int index = 0,i;
                int *p = &index;
                memset(CharStream,0,sizeof (CharStream));
                word_sum = ReadAndDeal_C_File(CharStream);
                CFFX(p,CharStream);
            }
            break;
            case '2':
            {
                InputToken(token);
            }
            
            break;
        case '3':
            exit(1);
        default:
            getchar();
            break;
        }
        getchar();
    }
}