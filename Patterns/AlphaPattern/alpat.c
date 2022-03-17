#include <stdio.h>
int main()
{
    int n;
    char alpha=65;
    printf("Enter number of rows: ");
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            printf("%c ", alpha);
        }
        alpha++;
        printf("\n");
    }
    return 0;
}