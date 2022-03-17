#include <stdio.h>
int main()
{
    int n,swap;
    printf("\nEnter size of array : ");
    scanf("%d",&n);
    int arr[n];
    printf("Enter elements of the array : ");
    for(int i=0;i<n;i++)
        scanf("%d",&arr[i]);
    for(int i=0;i<n-1;i++)
        for(int j=0;j<n-i-1;j++)
            if(arr[j]>arr[j+1])
            {
                swap=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=swap;
            }
    printf("\n");        
    for(int i=0;i<n;i++)
        printf("%d ",arr[i]);    
    printf("\n");     
    return 0;   
}