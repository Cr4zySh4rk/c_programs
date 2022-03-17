#include <stdio.h>
#include <stdlib.h>
int main()
{
    int i, j, k, n, temp;
    printf("\nEnter the number of elements: ");
    scanf("%d", &n);
    int array[n];
    printf("\nEnter the elements: ");
    for (i = 0; i < n; i++)
        scanf("%d", &array[i]);
    for (j = 0; j < n - 1; j++)
    {
        for (k = 0; k < n - j - 1; k++)
        {
            if (array[k] > array[k + 1])
            {
                temp = array[k];
                array[k] = array[k + 1];
                array[k + 1] = temp;
            }
        }
    }
    for (i = 0; i < n; i++)
        printf(" %d", array[i]);
    printf("\n");
    return 0;
}