#include<stdio.h>
#include<stdlib.h>
void transfer(int n,char s,char t, char d)
{
    if(n==0)
    return;
    transfer(n-1,s,d,t);
    printf("\nMove disk %d from %c to %c",n,s,d);
    transfer(n-1,t,s,d);
}

void main()
{
    int n;
    printf("\nEnter number of disks : ");
    scanf("%d",&n);
    transfer(n,'A','B','C');
}