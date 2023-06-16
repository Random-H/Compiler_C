//
// Created by HMD on 2023/6/14.
//

#ifndef C_COMPILER_LEXICALANALYSIS_H
#define C_COMPILER_LEXICALANALYSIS_H


int isKey(char *s);
int isNum(char ch);
int isLetter(char ch);
int isOperator2(char ch);
int isOperator1(char *s);
int isDelimiter(char ch);
char GetChar(int *p,char *cs);
void pNext(int *p);
void pPrior(int *p);
int ReadAndDeal_C_File(char *s);     //Read and process string "s"
void CFFX(int *p,char *cs);



#endif //C_COMPILER_LEXICALANALYSIS_H
