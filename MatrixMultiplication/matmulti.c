#include <stdio.h>
#include <stdlib.h>
int main()
{
    int i,j,k,l,p,q,r;
    printf("Enter the order of matrix A : ");
    scanf("%d %d",&i,&j);
    int A[i][j];
    printf("Enter the order of matrix B : ");
    scanf("%d %d",&k,&l);
    int B[k][l];
    if (j!=k)
    {
        printf("The matrices can't be multiplied!\n");
        exit (0);
    }
    else
    {
        int C[i][l];
        printf("Enter the elements of matrix A : ");
        for (p=0;p<i;p++)
        {
            for (q=0;q<j;q++)
                scanf("%d",&A[p][q]);
        }
        printf("Enter the elements of matrix B : ");
        for (p=0;p<k;p++)
        {
            for (q=0;q<l;q++)
                scanf("%d",&B[p][q]);
        }
        
        for (p=0;p<i;p++)
        {
            for (q=0;q<l;q++)
            {
                C[p][q]=0;
                for (r=0;r<j;r++)
                    C[p][q]+=(A[p][r]*B[r][q]);
            }
        }
        
        printf("\nThe elements of matrix A : ");
        for (p=0;p<i;p++)
        {
            printf("\n");
            for (q=0;q<j;q++)
                printf("%d ",A[p][q]);   
        }
        printf("\nThe elements of matrix B : ");
        for (p=0;p<k;p++)
        {
            printf("\n");
            for (q=0;q<l;q++)
                printf("%d ",B[p][q]);   
        }
        printf("\nThe elements of matrix C : ");
        for (p=0;p<i;p++)
        {
            printf("\n");
            for (q=0;q<l;q++)
                printf("%d ",C[p][q]);   
        }
    }
}