#ifndef GRAMANALYSIS_H
#define GRAMANALYSIS_H

typedef struct Token
{
    char value[10];
    int id;
}Token;

enum{
    main_=1,     //缺少main
    xkuohao_z,  //缺少小括�?(
    xkuohao_y,  //缺少小括号）
    dkuohao_z,
    dkuohao_y,
    zkuohao_z,
    zkuohao_y,
    fenhao,
    biaoshifu,
    unknow,
    keyerror,
}typeError;

int InputToken(Token t[]);
void lrparser(Token t[],int *p);
void yucu(Token t[],int *p);
void statements(Token t[],int *p);
void statement(Token t[],int *p);
void fuzhi(Token t[],int *p);
void foryuju(Token t[],int *p);
void ifyuju(Token t[],int *p);
void ERROR(int type);


#endif