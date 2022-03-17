#include<stdio.h>
#include<stdlib.h>
#define MAX 5
int top=-1,i;
int stack[MAX];
void push()
{
    int term;
    if(top<MAX)
    {
        printf("\nEnter an element to push : ");
        scanf("%d",&term);
        ++top;
        stack[top]=term;
    }
    else
        printf("\nStack is overflowing!");
}

void pop()
{
    int term;
    if (top>-1)
    {
        term=stack[top];
        --top;
        printf("\nElement popped out is %d",term);
    }
    else
        printf("\nThe stack is underflowing!");
}

void palin()
{
    if(top!=-1)
    {
        int rev[MAX],count=0;
        for(i=0;i<=top;i++);
            rev[i]=stack[top-i];
        for(i=0;i<=top;i++)
            if(rev[i]==stack[i])
                count++;
        if(count==top)
            printf("\nIt's a palidrome");
        else
            printf("\nIt's not a plaindrome!");         
    }
    else
        printf("\nStack empty!");
}

void display()
{
    if(top!=-1)
    {
        printf("\nThe elements of the stack are : \n");
        for(i=0;i<=top;i++)
            printf(" %d",stack[i]);
    }
    else
        printf("\nThe stack is empty!");
}

void main()
{
    int choice;
    while(1)
    {
        int choice;
        printf("\n--------------MENU---------------");
        printf("\n[1]Push");
        printf("\n[2]Pop");
        printf("\n[3]Plaindrome?");
        printf("\n[4]Display");
        printf("\n[5]Exit");
        printf("\nEnter corresponding choice : ");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
                push();
                break;
            case 2:
                pop();
                break;
            case 3:
                palin();
                break;
            case 4:
                display();
                break;    
            case 5:
                printf("\nExiting program...\n");
                exit(0);
            default :
                printf("\nInvalid choice!");
        }
    }
}