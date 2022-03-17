#include <stdio.h>
int main()
{
    float num, i;
    printf("\nEnter a number to find it's square root: ");
    scanf("%f", &num);

    if (num > 0)
    {
        for (i = 0.00; (i * i) < num; i += 0.01)
            ;
        printf("\nThe Square root of the number is: %.2f\n", i);
    }
    else
    printf("\nCan't compute square root for -ve numbers.\n");

    return 0;
}