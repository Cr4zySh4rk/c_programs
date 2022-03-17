#include <stdio.h>
#include <math.h>

int main()
{
    int bin,temp,n=0;
    long deci=0;
    printf("Enter a binary number: ");
    scanf("%d",&bin);
    temp=bin;
    while (temp!=0)
    {
        deci+=(temp%10)*pow(2,n);
        ++n;
        temp/=10;
    }
    printf("%ld\n",deci);
    return 0;
}