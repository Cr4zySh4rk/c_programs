#include <stdio.h>
int isprime(int n);
int main()
{
    int num;
    printf("Enter a positive number : ");
    scanf("%d",&num);
    if(num==1||num==0)
        printf("%d is neither a prime number nor a composite number\n",num);
    else if (isprime(num))
        printf("It is a prime number.\n");
    else
        printf("It's not a prime number!\n");
    return 0;         
}
int isprime (int num)
{
    int i;
    for(i=2;i<=num/2;i++)
        if (num%i==0)
            return 0;          
    return 1;
}