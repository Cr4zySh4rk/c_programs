#include<stdio.h>
#include<string.h>

void main()
{
    char arr[20]; int i;
    printf("\nEnter a string : ");
    gets(arr);
    for(i=0;i<strlen(arr);i++)
        if(arr[i]>=97&&arr[i]<=123)
            arr[i]-=32;
    printf("\nModified string : ");
    puts(arr);        
}
