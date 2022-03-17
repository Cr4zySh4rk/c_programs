#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int count=0;
struct node
{
    char name[25],usn[10],branch[5];
    int sem;
    long int phno;
    struct node *next;
}*start=NULL,*current;
void insert_beg()
{
        count++;
        struct node *newnode=(struct node*)malloc(sizeof(struct node));
        printf("\nEnter the details of the student : ");
        printf("\nName : ");
        scanf("%s",&newnode->name);
        printf("\nUSN : ");
        scanf("%s",&newnode->usn);
        printf("\nBranch : ");
        scanf("%s",&newnode->branch);
        printf("\nSem : ");
        scanf("%d",&newnode->sem);
        printf("\nPhone No : ");
        scanf("%ld",&newnode->phno);
        if(start==NULL)
        {
            start=newnode;
            start->next=NULL;
            current=start;
        }
        else
        {
            newnode->next=start;
            start=newnode;
        }
}

void delete_beg()
{
    if(count==0)
        printf("\nUnderflow!");
    else
    {
        count--;
        struct node *temp=(struct node*)malloc(sizeof(struct node));
        temp=start;
        start=start->next;
        free(temp);
    }    
}

void insert_end()
{
    struct node *newnode=(struct node*)malloc(sizeof(struct node));
        count++;
    printf("\nEnter the details of the student : ");
        printf("\nName : ");
        scanf("%s",&newnode->name);
        printf("\nUSN : ");
        scanf("%s",&newnode->usn);
        printf("\nBranch : ");
        scanf("%s",&newnode->branch);
        printf("\nSem : ");
        scanf("%d",&newnode->sem);
        printf("\nPhone No : ");
        scanf("%ld",&newnode->phno);
        if (start==NULL)
        {
            start=newnode;
            current=newnode;
        }
        else
        {
            current->next=newnode;
            current=newnode;
            current->next=NULL;
        }
}

void delete_end()
{
    if(count==0)
        printf("\nUnderflow!");
    else
    {    
        count--;
        struct node *temp=(struct node*)malloc(sizeof(struct node));
        struct node *temp1=(struct node*)malloc(sizeof(struct node));
        temp1=start;
        while(temp1->next!=NULL)
            temp1=temp1->next;
        temp=temp1;
        temp1=temp1->next;
        temp->next=NULL;
        free(temp1);
        current=temp;
    }
}

void create()
{
    int ch=1;
    do
    {
        insert_beg();
        printf("\nEnter 0 to stop inserting : ");
        scanf(" %d",&ch);
    }while(ch!=0);
}

void display()
{
    if(count==0)
        printf("\nList is empty!");
    else
    {
        struct node *temp=(struct node*)malloc(sizeof(struct node));
        temp=start;
        for(int i=1;i<=count;i++)
        {
        printf("\nDetails of the student %d : ",i);
        printf("\nName : ");
        puts(temp->name);
        printf("\nUSN : ");
        puts(temp->usn);
        printf("\nBranch : ");
        puts(temp->branch);
        printf("\nSem : %d ",temp->sem);
        printf("\nPhone No : %ld",temp->phno);
        temp=temp->next;
        }
        printf("\nNumber of nodes : %d",count);
    }
}

void main()
{
    int choice;
    while(1)
    {
        printf("\n---------------MENU---------------");
        printf("\n[1]Create");
        printf("\n[2]Display");
        printf("\n[3]Insert at beginning");
        printf("\n[4]Delete at beginning");
        printf("\n[5]Insert at end");
        printf("\n[6]Delete at end");
        printf("\n[7]Exit");
        printf("\n----------------------------------");
        printf("\nEnter choice : ");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
                create();
                break;
            case 2:
                display();
                break;
            case 3:
                insert_beg();
                break;
            case 4:
                delete_beg();
                break;
            case 5:
                insert_end();
                break;
            case 6:
                delete_end();
                break;
            case 7:
                printf("\nExiting program...\n");
                exit(0);
            default:
                printf("\nInvalid choice!");                         
        }
    }
}