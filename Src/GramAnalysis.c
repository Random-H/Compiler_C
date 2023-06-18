#include "../Inc/GramAnalysis.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int syn;

int InputToken(Token t[])
{
    int count = 0;
    char ch[32];
    memset(ch, 0, sizeof(ch));
    int i=2,j=0,k=0,l=0;
    int flag =0 ;
    char temp[2];
    FILE *f=fopen("LexicalAnalysis.txt","r");
    if(f==NULL)
        return 0;
    while (!feof(f)){
        fgets(ch,32,f);
        while(ch[i]!='\n')
        {
            if(ch[i]!='"'&&flag==0)
            {
                t[k].value[j++] = ch[i++];
            }
            else
            {
                flag=1;
                if(ch[i]!=','&&ch[i]!='"'&&ch[i]!=')')
                {
                    temp[l] = ch[i];
                    i++;
                    l++;
                }
                else 
                {
                    i++;
                }
            }
                
        }count++;
        t[k].id = atoi(temp);
        temp[1]='\0';
        k++;
        j=0;
        i=2;
        flag =0;
        l=0;
    }
    fclose(f);
    return count;
}

void scaner(Token t[],int *p)
{
    (*p)++;
    syn = t[*p].id;
}

void lrparser(Token t[],int *p)
{
    syn = t[0].id;
    if(syn == 3)//int
    {
        scaner(t,p);
        if(syn == 2)//main
        {
            scaner(t,p);
            if (syn == 34)//(
            {
                scaner(t,p);
                if(syn == 35)//)
                {
                    scaner(t,p);
                    yucu(t,p);
                }
                ERROR(xkuohao_y);
            }
            else
                 ERROR(xkuohao_z);
        }
        else
             ERROR(main_);
    }
    else
        ERROR(main_);
}

void yucu(Token t[],int *p)
{
    if(syn == 36)   //{
    {
        scaner(t,p);
        statements(t,p);
        if(syn == 37)   //}
        {

        }
        else
            ERROR(dkuohao_y);
    }
    else
        ERROR(dkuohao_z);
}

void statements(Token t[],int *p)
{
    statement(t,p);
    while (syn == 40)//;
    {
        scaner(t,p);
        statement(t,p);
    }
}

void statement(Token t[],int *p)
{
    if(syn == 0) //标识符
        fuzhi(t,p);
    else if (syn == 16) //for
        foryuju(t,p);
    else if (syn == 10) //if 
        ifyuju(t,p);
}

void fuzhi(Token t[],int *p)
{
    printf("赋值");
}

void foryuju(Token t[],int *p)
{
    printf("for");
}

void ifyuju(Token t[],int *p)
{
    printf("if");
}

void ERROR(int type)
{
    FILE *f=fopen("relust.txt","w");
    if(f==NULL)
    {
        return 0;
    }
    switch (type)
    {
    case main_:    
        printf("缺少主函数\n");
        fputs("缺少主函数\n",f);
        break;
    case dkuohao_z:    
        printf("缺少{\n");
        fputs("缺少{\n",f);
        break;
    case dkuohao_y:        
        printf("缺少}\n");
        fputs("缺少}\n",f);
        break;
    case xkuohao_z:       
        printf("缺少(\n");
        fputs("缺少(\n",f);
        break;    
    case xkuohao_y:      
        printf("缺少)\n");
        fputs("缺少)\n",f);
        break;
    case fenhao:      
        printf("缺少;\n");
        fputs("缺少主函数\n",f);
        break;
    case biaoshifu:      
        printf("标识符\n");
        fputs("标识符\n",f);
        break;
    case unknow:      
        printf("未知\n");
        fputs("未知\n",f);
        break;
    default:
        break;
    }
    fclose(f);
    exit(type);
}