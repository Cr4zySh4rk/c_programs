#include <stdio.h>
#include <stdlib.h>
int main()
{
    int n, key, high, low, mid;
    printf("\nEnter the number of elements: ");
    scanf("%d", &n);
    int array[n];
    printf("\nEnter array elements: ");
    for (int i = 0; i < n; i++)
        scanf("%d", &array[i]);
    printf("\nEnter the number to be searched: ");
    scanf("%d", &key);

    low = 0;
    high = n - 1;
    while (low <= high)
    {
        mid = (low + high) / 2;
        if (array[mid] == key)
        {
            printf("\nThe number is in position %d\n", mid + 1);
            exit(0);
        }
        else if (array[mid] < key)
            low = mid + 1;
        else
            high = mid - 1;
    }
    printf("\nThe number could not be found!\n");
    return 0;
}