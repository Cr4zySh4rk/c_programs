#include <stdio.h>
int main()
{
    int h, space;
    printf("Enter the height of inverted pyramid: ");
    scanf("%d", &h);
    for (int i = h; i >= 1; --i)
    {
        for (space = 0; space < h - i; ++space)
            printf("  ");
        for (int j = i; j <= 2 * i - 1; ++j)
            printf("* ");
        for (int j = 0; j < i - 1; ++j)
            printf("* ");
        printf("\n");
    }
    return 0;
}