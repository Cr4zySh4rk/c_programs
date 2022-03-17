#include <stdio.h>
#include<stdlib.h>
#define MAX 5
char data;
char q[MAX];
int f=0,r=-1,count=0,i;

void insert()
{
    if(count==MAX)
        printf("\nQueue is Overflowing!");
    else
    {
        printf("\nEnter value to insert : ");
        scanf(" %c",&data);
        r=(r+1)%MAX;
        q[r]=data;
        count++;
    }
}

void delete()
{
    if (count==0)
        printf("\nQueue is Underflowing!");
    else
    {
        data=q[f];
        printf("\nData to be delete : %c ",data);
        f=(f+1)%MAX;
        count--;
    }    
}

void display()
{
    if(count==0)
        printf("\nStack is empty!");
    else
    {
        if(f<=r)
            for(i=f;i<=r;i++)
                printf("%c ",q[i]);
        else
        {
            for(i=f;i<MAX;i++)
                printf("%c ",q[i]);
            for(i=0;i<=r;i++)
                printf("%c ",q[i]);    
        }
    }
}

void main()
{
    while(1)
    {
        int choice;
        printf("\n--------------MENU---------------");
        printf("\n[1]Insert");
        printf("\n[2]Delete");
        printf("\n[3]Display");
        printf("\n[4]Exit");
        printf("\nEnter corresponding choice : ");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
                insert();
                break;
            case 2:
                delete();
                break;
            case 3:
                display();
                break;
            case 4:
                printf("\nExiting program...\n");
                exit(0);
            default :
                printf("\nInvalid choice!");
        }
    }
}