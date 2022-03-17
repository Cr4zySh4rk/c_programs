#include <stdio.h>
#include <math.h>
int bin2deci(long long int);
int main()
{
    int deci;
    long long int num;
    printf("Enter a binary number : ");
    scanf("%lld",&num);
    deci=bin2deci(num);
    printf("Decimal number is : %d\n",deci);
    return 1;
}
int bin2deci(long long int n)
{
    static int i=0;
    if(n==0)
        return 0;
    else
        return n%10*pow(2,i++)+bin2deci(n/10);
}