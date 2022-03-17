#include <stdio.h>
#include <stdlib.h>
typedef struct
{
    int row;
    int col;
    int val;
}TERM;

void main()
{
    int k=0,temp,l=0;
    TERM a[10], t[10];
    printf("\nEnter number of rows : ");
    scanf("%d",&a[0].row);
    printf("\nEnter number of columns : ");
    scanf("%d",&a[0].col);
    printf("Enter the elements of the matrix : \n");
    for (int i=0;i<a[0].row;i++)
        for (int j=0;j<a[0].col;j++)
            {
                scanf("%d",&temp);
                if (temp!=0)
                    {
                        ++k;
                        a[k].row=i;
                        a[k].col=j;
                        a[k].val=temp;
                    }
            }
    a[0].val=k;
    printf("The entered matrix is : \n");
    printf("Row:\tCol:\tVal:\n");
    for (int i=0;i<=k;i++)
        printf("%d\t%d\t%d\n",a[i].row,a[i].col,a[i].val);

    t[0].row=a[0].col;
    t[0].col=a[0].row;

    for (int i=0;i<a[0].col;i++)
        for(int j=1;j<=a[0].val;j++)
            {
                if (a[j].col==i)
                    {
                        ++l;
                        t[l].row=a[j].col;
                        t[l].col=a[j].row;
                        t[l].val=a[j].val;
                    }
            }    
    t[0].val=l;
    printf("\nThe transposed matrix is : \n");
    printf("Row:\tCol:\tVal:\n");
    for (int i=0;i<=l;i++)
        printf("%d\t%d\t%d\n",t[i].row,t[i].col,t[i].val);
}
