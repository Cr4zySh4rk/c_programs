#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void failure(char p[]);
int pat_match(char p[],char t[]);
int f[5];
void main()
{
    char str[20],pat[20];
    int pos;
    printf("Enter a string : ");
    gets(str);
    printf("Enter a pattern to find : ");
    gets(pat);
    failure(pat);
    pos=pat_match(pat,str);
    if (pos!=-1)
        printf("Pattern found in position %d\n",pos);
    else
        printf("Pattern not found!\n");    
}
void failure(char p[])
{
    int i=0,j=1;
    f[i]=0;
    while(j<strlen(p))
    {
        if(p[i]==p[j])
        {
            f[j]=i+1;
            i++;
            j++;
        }
        else if (i==0)
            f[j++]=i;
        else
            i=f[i-1];    
    }
}
int pat_match(char p[],char t[])
{
    int i=0,j=0;
    while(i<strlen(t)&&j<strlen(p))
    {
        if (t[i]==p[j])
        {
            i++;
            j++;
        }
        else if (j==0)
            i++;
        else
        j=f[j-1];    
    }
    if(j==strlen(p))
        return i-strlen(p);
    else
        return -1;    
}