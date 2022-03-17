#include <stdio.h>
#include <string.h>
int main()
{
    char swap;
    char arr[10];
    printf("Enter a string : ");
    scanf("%s",arr);
    int n=strlen(arr);
    for(int i=0;i<n-1;i++)
        for(int j=0;j<n-i-1;j++)
            if(arr[j]>arr[j+1])
            {
                swap=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=swap;
            }       
    printf("The string in ascending order is : %s\n",arr);         
    return 0;   
}