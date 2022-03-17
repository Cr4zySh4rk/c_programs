#include <stdio.h>

int main()
{
    int num, count = 0, temp, reversed = 0, sum = 0;

    printf("\n************************************************\n");
    printf("Enter an number: ");
    scanf("%d", &num);
    temp = num;

    while (temp != 0)
    {
        reversed = (reversed * 10) + (temp % 10);
        sum += (temp % 10);
        temp /= 10;
        ++count;
    }

    printf("The number has %d significant digit(s).\n", count);
    printf("The sum of its digits is: %d \n", sum);
    printf("The reversal of its digits is: %d", reversed);

    if (num == reversed)
        printf("\nThe entered number is a palindrome!");
    else
        printf("\nThe entered number is not a palindrome.");
    printf("\n************************************************\n");

    return 0;
}