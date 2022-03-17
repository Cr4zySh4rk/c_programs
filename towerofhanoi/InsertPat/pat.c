#include<stdio.h>
#include<string.h>

void main()
{
char str[20],pat[5],result[25];
int sl,pl,pos;

printf("\nEnter a string : ");
gets(str);
sl=strlen(str);
printf("Enter a pattern to insert : ");
gets(pat);
pl=strlen(pat);
printf("Enter a position in the array to insert the pattern : ");
scanf("%d",&pos);
for (int i=0;i<pos;i++)
    result[i]=str[i];
for (int i=0;i<pl;i++)
    result[i+pos]=pat[i];
for (int i=0;i<sl;i++)
    result[i+pos+pl]=str[pos+i];
puts(result);
}      
