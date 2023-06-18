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
        printf("2.语法分析\n");
        printf("3.中间代码生成\n");
        printf("*************************************************\n");
        c = getchar();
        switch (c)
        {
            case '1':
            {
                int index = 0,i;
                int *p1 = &index;
                memset(CharStream,0,sizeof (CharStream));
                word_sum = ReadAndDeal_C_File(CharStream);
                CFFX(p1,CharStream);
            }
            break;
            case '2':
            {
                int index =0;
                int *p2 = &index;
                int len = InputToken(token);
                lrparser(token,p2);
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