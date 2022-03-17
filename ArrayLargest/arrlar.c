
#include <stdio.h>

int main()
{
    int size,max1,max2;
    printf("\nEnter the size of array: ");
    scanf("%d",&size);
    int values[size];
    printf("Enter values: ");
    
    for(int i = 0; i < size; ++i)
    {
        scanf("%d", &values[i]);
    }
    for(int i = 0; i < size; ++i)
    {
        if (values[i] < values[i+1])
        {
            max1=values[i+1];
        }
    }
    for(int i = 0; i < size; ++i)
    {
        if (max1-values[i]<max1-values[i+1]&&max1-values[i]!=0&&max1-values[i+1]!=0)
        {
            max2=values[i];
        }
    }
    printf("\nMax value:%d\n",max2);
}