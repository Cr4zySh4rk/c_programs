#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void main()
{
    int pos=-1,count;
    char str[25],pat[5];
    printf("\nEnter a string : ");
    gets(str);
    printf("\nEnter pattern to find : ");
    gets(pat);
    int sl=strlen(str),pl=strlen(pat);//stores length of string and pat respectively
    for (int i=sl-1;i>=0;i--)
    {
        if(pat[0]==str[i])
            for (int j=0;j<pl;j++)
            {
                if(pat[j]==str[i+j])
                    ++count; 
                if (count==pl)
                    pos=i;
            }
    }        
    if (pos!=-1)
        printf("\nPatter found in position %d\n",pos);
    else
        printf("\nPatter not found!\n");
}