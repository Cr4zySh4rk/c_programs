#include <stdio.h>
void main()
{
    int n;
    printf("\nEnter the size of array : ");
    scanf("%d",&n);
    int arr[n];
    printf("Enter the elements of the array : ");
    for(int i=0;i<n;i++)
        scanf("%d",&arr[i]);
    for(int i=0;i<n-1;i++)
        for (int j=0;j<n-i-1;j++)
            if(arr[j+1]<arr[j])
                {
                    arr[j]+=arr[j+1];
                    arr[j+1]=arr[j]-arr[j+1];
                    arr[j]=arr[j]-arr[j+1];
                }
    printf("\nThe sorted array is : \n");         
    for(int i=0;i<n;i++)
        printf("%d ",arr[i]);  
    printf("\n");              
}