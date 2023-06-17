#include "../Inc/GramAnalysis.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

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
        }
        t[k].id = atoi(temp);
        printf("%s %d\n",t[k].value,t[k].id);;
        temp[1]='\0';
        k++;
        j=0;
        i=2;
        flag =0;
        l=0;
    }
    fclose(f);
    return count+1;
}