#include <stdio.h>
int main()
{
    int num, temp;
    long bin = 0;
    printf("Enter decimal number: ");
    scanf("%d", &num);
    temp = num;
    for (int i=1;temp!=0;i*=10)
    {
        bin += (temp % 2) * i;
        temp /= 2;
    }
    printf("%ld\n", bin);
    return 0;
}