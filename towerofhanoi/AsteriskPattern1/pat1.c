#include <stdio.h>
int main()
{
    int h, temp1, temp2;
    printf("\nEnter pyramid height: ");
    scanf("%d", &h);
    temp1 = temp2 = h;
    printf("\nDesired pyramid [height=%d]\n\n", h);
    for (int i = 1; i < (h * 2); i += 2)
    {
        for (int j = 1; j <= i; j++)
        {
            while (temp1 != 0)
            {
                printf("  ");
                --temp1;
            }
            printf("* ");
        }
        temp1 = --temp2;
        printf("\n");
    }
    return 0;
}