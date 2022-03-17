#include <stdio.h>
#include <math.h>

int main()
{
    int i = 2, deg;
    float x, sum = 0, term, nume, deno = 1;
    printf("\n Enter value in degree: ");
    scanf("%d", &deg);
    x = deg * ((22.00 / 7) / 180); //converting degree to radian
    nume = x;
    do
    {
        term = nume / deno;
        nume = -nume * pow(x, 2);
        deno *= i * (i + 1);
        sum += term;
        i += 2;
    } while (fabs(term) >= 0.0001);
    printf("\n sin(%d) is : %f", deg, sum);
    printf("\n sin(%d) using inbuilt function is: %f\n", deg, sin(x));

    return 0;
}