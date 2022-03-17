#include <stdio.h> 
#include <stdlib.h>
void create();
void display();
void insert();
void delete();
int n=-1,a[100];
void main()
{
    int choice;
    while(1)
    {
        printf("\n---------------Menu--------------\n");
        printf("[1] Create an array\n");
        printf("[2] Display the array\n");
        printf("[3] Insert element in the array\n");
        printf("[4] Delete element in the array\n");
        printf("[5] Exit\n");
        printf("Enter corresponding number for desired operation : ");
        scanf("%d",&choice);
        printf("\n---------------------------------\n");

        switch(choice)
        {
            case 1:
            create();
            break;
            
            case 2:
            display();
            break;

            case 3:
            insert();
            break;

            case 4:
            delete();
            break;

            case 5:
            printf("\nExiting program...\n");
            exit (0);
            break;

            default:
            printf("\nInvalid choice!");
        }
    }
}

void create ()
{
    int i;
    for(i=0;i<100;i++) //clearing the array
        a[i]=0;
    printf("\nEnter the size of the array : ");
    scanf("%d",&n);
    if (n>0&&n<=100)
    {
        printf("\nEnter the array elements : ");
        for (i=0;i<n;i++)
            scanf("%d",&a[i]);
    }    
    else
        printf("\nInvalid array size!");
}

void display()
{
    int i;
    if (n>0)
    {
        printf("\nThe elements of the array are : \n");
        for (i=0;i<n;i++)
            printf("%d ",a[i]);
    }
    else
        printf("\nArray empty/not created!");
}
void insert()
{
    int i,pos,num;
    if (n>0)
    {
        printf("\nEnter the element for insertion : ");
        scanf("%d",&num);
        printf("\nEnter the position of insertion : ");
        scanf("%d",&pos);
        if (pos<=n && pos>=0 && n!=100)
        {
            for(i=n-1;i>pos;i--) //shifting elements of the array
                a[i+1]=a[i];
            n+=1;
            a[pos]=num;
        }
        else
            printf("\nInvalid position of insertion!\n\t(or)\nArray is full!");
    }
    else
        printf("\nArray empty/not created!");
}
void delete()
{
    int i,pos;
    if (n>0)
    {
        printf("\nEnter the position of deletion : ");
        scanf("%d",&pos);
        if (pos<=n && pos>=0 && n!=100)
        {
            for(i=pos;i<n;i++)
                a[i]=a[i+1];
            n-=1;    
        }
        else
            printf("\nInvalid position of deletion!\n\t(or)\nArray is full!");
    }
    else
        printf("\nArray empty/not created!");
}