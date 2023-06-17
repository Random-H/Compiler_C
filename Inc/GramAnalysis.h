#ifndef GRAMANALYSIS_H
#define GRAMANALYSIS_H

typedef struct Token
{
    char value[10];
    int id;
}Token;


int InputToken(Token t[]);

#endif