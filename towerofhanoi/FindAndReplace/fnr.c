#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char str[100],pat[100],rep[100],result[100],temp[100];
int sl,pl,rl,count=0,pos=-1;
void find();
void replace();
void main()
{
    printf("\nEnter a string : ");
    gets(str);
    sl=strlen(str);
    for(int i=strlen(str);i<100;i++)
        str[i]=' ';
    printf("Enter pattern to find : ");
    gets(pat);
    pl=strlen(pat);
    printf("Replace with : ");
    gets(rep);
    rl=strlen(rep);
    find();
    printf("Replaced string is : %s",result);
}

void find()
{
    for (int i=0;i<sl;i++)
    {
        if (pat[0]==str[i])
            for(int j=0;j<pl;j++)
                if (str[i+j]==pat[j])
                {
                    count+=1;
                    if (count==pl)
                    {
                        pos=i;
                        replace();
                    }
                }
        count=0;
    }
    if (pos==-1)
    {
        printf("\n Couldn't find pattern in string!\n");
        exit(0);
    }                
}

void replace()
{
     for (int i=0;i<sl-pos;i++)
        temp[i]=str[pos+pl+i];
     int tl=strlen(temp);   
     for (int i=0;i<pos;i++)
        result[i]=str[i];
     for (int i=0;i<rl;i++)
        result[pos+i]=rep[i];
     for (int i=0;i<tl;i++)
        result[pos+rl+i]=temp[i];   
     for(int i=0;i<strlen(result);i++)
        str[i]=result[i];
     for(int i=strlen(result);i<100;i++)
        str[i]='\0';
     for(int i=0;i<100;i++)
        temp[i]='\0';   
     sl=strlen(result);

}