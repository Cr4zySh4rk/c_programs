//prints numbers 1-n & n-1 using recursion
#include<stdio.h>

void numbers (int n)
{
    if(n>1)
    numbers(n-1);
    printf("%d ",n);
}

void reverse_numbers (int n)
{
    printf("%d ",n);
    if(n>1)
    reverse_numbers(n-1);
}

void main()
{
    int n;
    printf("\nEnter a number : ");
    scanf("%d",&n);
    printf("\n1 to %d : ",n);
    numbers (n);
    printf("\n");
    printf("\n%d to 1 : ",n);
    reverse_numbers(n);
    printf("\n");
}