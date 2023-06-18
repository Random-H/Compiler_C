#include "../Inc/LexicalAnalysis.h"
#include <stdio.h>
#include <string.h>

#define KNUM    15
#define OPNUM 	17
#define DENUM 	8

typedef struct token
{
    char *p;
    int id;
}token;

char key[][10]={"main","int","double","char","struct","return","float",
                "while","if","else","void","typedef","unsigned","long",
                "for"};
int keyNum[KNUM];


char Operator_base[10]={'=','+','<','>','-','*','/','!','.',':'};
char Operator[][3] = {"=",">","<","+","-","*","/",">=","<=","+=",
                       "-=",".",":","!=","++","--","=="};
int OperatorNum[OPNUM];

char Delimiter[8]={'(',')','{','}','[',']',';',','};
int DelimiterNum[DENUM];

void Init()
{
    int j=2;
    for (int i = 0; i < KNUM; ++i) {
        keyNum[i]=j++;
    }
    for (int i = 0; i < OPNUM; ++i) {
        OperatorNum[i]=j++;
    }
    for (int i = 0; i < DENUM; ++i) {
        DelimiterNum[i]=j++;
    }
}

int isKey(char *s)
{
    int i;
    for(i=0;i<KNUM;i++)
    {
        if(!strcmp(s,key[i]))
        {
            return keyNum[i];
        }
    }
    return 0;
}


int isNum(char ch){
    if(ch>='0' && ch<='9')
        return 1;
    return 0;
}

int isLetter(char ch)                //鍒ゆ柇鏄惁涓哄瓧姣?
{
    if(ch>='a' && ch<='z')
        return 1;
    if(ch>='A' && ch<='Z')
        return 1;
    if(ch=='_')
        return 1;
    return 0;
}

int isOperator1(char *s)
{
    int i;
    for(i=0;i<OPNUM;i++)
    {
        if(!strcmp(s,Operator[i]))
        {

            return OperatorNum[i];

        }

    }
    return 0;
}
int isOperator2(char ch)
{
    int i;
    for(i=0;i<10;i++)
    {
        if(ch== Operator_base[i])
            return 1;
    }
    return 0;
}

int isDelimiter(char ch)
{
    int i;
    for(i=0 ; i<DENUM ; i++)
    {
        if(ch==Delimiter[i])
            return DelimiterNum[i];
    }
    return 0;
}

char GetChar(int *p,char *cs)
{
    return cs[*p];
}

void pNext(int *p)
{
    (*p)++;
}

void pPrior(int *p)
{
    (*p)--;
}



int ReadAndDeal_C_File(char *s)
{
    char ch;
    int count = 0;
    FILE *f=fopen("c.c","r");
    if(f==NULL)
        return 0;
    while ((ch = fgetc(f)) != EOF){
        if(ch!= ' '&& ch!='\n'&& ch!='\t'){
            *(s++) = ch;
        }
    }
    *(s++)='\0';
    fclose(f);
    return count+1;
}

void CFFX(int *p,char *cs)
{
    Init();
    int i=0;
    char buf[16];
    char bufout[256];
    char ch;
    FILE  *f = fopen("LexicalAnalysis.txt","w");
    memset(buf,0,sizeof(buf));
    while(cs[*p] != '\0')
    {
        if(isLetter(GetChar(p,cs)))		//如果第一个是字母，则可能是标识符或关键字
        {
            while(isLetter(GetChar(p,cs))||isNum(GetChar(p,cs)))
            {
                ch = GetChar(p,cs);
                if(ch<='Z'&&ch>='A')
                {
                    ch = ch+32;//忽略大小写;
                }
                buf[i++] = ch;
                if(isKey(buf))
                {
                    sprintf(bufout,"(\"%s\",%d)\n",buf,isKey(buf));
                    fputs(bufout,f);
                    memset(buf,0,sizeof(buf));
                    memset(bufout,0,sizeof(bufout));
                    i=0;
                }
                else {
                    pNext(p);
                    if (!isLetter(GetChar(p, cs)) && !isNum(GetChar(p, cs))) {
                        sprintf(bufout, "(\"%s\",%d)\n", buf, 0);
                        fputs(bufout, f);
                        memset(buf, 0, sizeof(buf));
                        memset(bufout, 0, sizeof(bufout));
                        i=0;
                        break;
                    } else {
                        pPrior(p);
                    }
                }pNext(p);
            }
            pPrior(p);
        }
        else if(isDelimiter(GetChar(p,cs)))
        {
            ch = GetChar(p,cs);
            sprintf(bufout,"(\"%c\",%d)\n",ch,isDelimiter(ch));
            fputs(bufout,f);
        }
        else if(isOperator2(GetChar(p,cs)))
        {
            buf[0] = GetChar(p,cs);
            pNext(p);
            if(isOperator2(GetChar(p,cs)))
            {
                buf[1] = GetChar(p,cs);
            } else{
                pPrior(p);
            }
            sprintf(bufout,"(\"%s\",%d)\n",buf,isOperator1(buf));
            fputs(bufout,f);
            memset(buf, 0, sizeof(buf));
            memset(bufout, 0, sizeof(bufout));
        }
        else if(isNum(GetChar(p,cs)))
        {
            while(isNum(GetChar(p,cs))) {
                buf[i++] = GetChar(p, cs);
                pNext(p);
            }
            pPrior(p);
            sprintf(bufout,"(\"%s\",%d)\n",buf,1);
            fputs(bufout,f);
            memset(buf, 0, sizeof(buf));
            memset(bufout, 0, sizeof(bufout));
            i=0;
        }
        pNext(p);
    }
    fclose(f);
}