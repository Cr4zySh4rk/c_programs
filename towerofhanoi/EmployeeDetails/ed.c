#include<stdio.h>
#include<stdlib.h> 
int count = 0;
struct node
{
	long int phno;
	float sal;
	char name[20], dept[10], desg[20],id[10];
	struct node *next,*prev;
}*start, *nn, *current, *temp;

void scan()
{
	nn = (struct node *)malloc(sizeof(struct node));
	nn->prev = NULL;
	nn->next = NULL;
    printf("\nEnter the employee details : \n");
    printf("ID : ");
	scanf("%s",&nn->id);
    printf("Name : ");
    scanf("%s",nn->name);
    printf("Department : ");
    scanf("%s",nn->dept);
    printf("Designation : ");
    scanf("%s",nn->desg);
    printf("Salary : ");
    scanf("%f",&nn->sal);
    printf("Phone Number : ");
    scanf("%ld",&nn->phno);
	count++;
}
void create()
{   char flag;
    do{
    
	if (start == NULL)
	{
		scan();
		start = nn;
		current = start;
	}
	else
	{
		scan();
		current->next = nn;
		nn->prev = current;
		current = nn;
	}
	printf("Continue? (y/n) : ");
	scanf(" %c",&flag);
}while(flag!='n');
}
void insert_beg()
{
	if (start == NULL)
	{
		scan();
		start = nn;
		current = start;
	}
	else
	{
		scan();
		nn->next = start;
		start->prev = nn;
		start = nn;
	}
}
void insert_end()
{
	if (start == NULL)
	{
		scan();
		start = nn;
		current = start;
	}
	else
	{
		scan();
		current->next = nn;
		nn->prev = current;
		current = nn;
	}
}
void display()
{
	temp = start;
	if (temp == NULL)
		printf("List empty to display \n");
    else
    {
        printf("No of nodes: %d\n ", count);
		printf("Employee Details are:\n");
        printf("\n-------------------------------------------------------------------------\n");
		printf("ID \tName \tDepartment \tDesignation \tSalary \tPh No\n");
		printf("\n-------------------------------------------------------------------------\n");
        while(temp!= NULL)
        {
            printf("%s \t%s \t%s \t\t%s \t%f \t%ld\n", temp->id, temp->name, temp->dept, temp->desg, temp->sal,temp->phno);
            temp = temp->next;                     
        }
    }
}
void delete_end()
{
	temp = start;
	if (temp == NULL)
	{
		printf("Underflow\n");
		return;
	}
	else
	{
		temp=current;
        current=current->prev;
        current->next=NULL;
        free(temp);
	}
	count--;
}
void delete_beg()
{
	temp = start;
	if (start == NULL)
	{
		printf("Underflow\n");
		return;
	}
	else
	{
        temp=start;
        start=start->next;
        start->prev=NULL;
        free(temp);
	}
	count--;
}
int main()
{
	int choice, n, i;
    while(1)
    {
        printf("\n---------------MENU---------------");
        printf("\n[1] Create");
        printf("\n[2] Display");
        printf("\n[3] Insert at end");
        printf("\n[4] Delete at end");
        printf("\n[5] Insert at beg");
        printf("\n[6] Delete at beg");
        printf("\n[7] exit");
        printf("\n----------------------------------");
        printf("\nEnter corresponding choice : ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1 :    create();
                    break;
        case 2 :    display();
                    break;
        case 3 :    insert_end();
                    break;
        case 4 :    delete_end();
                    break;
        case 5 :    insert_beg();
                    break;
        case 6 :    delete_beg();
                    break;
        case 7 : 	exit(0);
        default: printf("invaild choice\n");
        }
    }
}