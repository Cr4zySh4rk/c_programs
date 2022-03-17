#include<stdio.h>
#include<math.h>
#include<stdlib.h>

typedef struct node
{
    int ex, ey, ez, coef;
    struct node *next;
}node;

node *insert(node*head,int ex1, int ey1, int ez1, int coef1)
{
    node *p,*q;
    p=(node *)malloc(sizeof(node));
    p->ex=ex1;
    p->ey=ey1;
    p->ez=ez1;
    p->coef=coef1;
    p->next=NULL;
    if(head==NULL)
    {
        head=p;
        head->next=head;
        return(head);
    }

    if((ex1+ey1+ez1)>head->ex+head->ey+head->ez)
    {
        p->next=head->next;
        head->next=p;
        head=p;
        return(head);
    }
    if(ex1==head->ex && ey1==head->ey && ez1==head->ez)
    {
        head->coef=head->coef+coef1; 
        return(head);
    }
    
    q=head;
    while(q->next!=head&&(ex1+ey1+ez1)>=((q->next->ex)+(q->next->ey)+(q->next->ez)))
        q=q->next;
        
    if(p->ex==q->ex && p->ey==q->ey && p->ez==q->ez)
        q->coef=q->coef+coef1;
    else
    {
        p->next=q->next;
        q->next=p;
    }
    return(head);
}


node *create()
{
    int n,i,ex1, ey1, ez1, coef1;
    node *head=NULL;
    printf("\nEnter no of terms of polynomial : ");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        printf("Enter coef & expos: ");
        scanf("%d%d%d%d",&coef1,&ex1, &ey1, &ez1);
        head=insert(head, ex1, ey1, ez1, coef1);
    }
    return(head);
}

node *add(node *p1,node *p2)
{
    node *p;
    node *head=NULL;
    printf("\nAddition of polynomials : \n");
    p=p1->next;
    do
    {
        head=insert(head,p->ex, p->ey, p->ez, p->coef);
        p=p->next;
    }while(p!=p1->next);
    p=p2->next;
    do
    { 
        head=insert(head,p->ex, p->ey, p->ez ,p->coef);
        p=p->next;
    }while(p!=p2->next);
    return(head);
}


int eval(node *head)
{
    node *p;
    int x, y, z, ans=0;
    printf("\nEnter the values of x, y, z : ");
    scanf("%d%d%d",&x, &y, &z);
    p=head->next;
    do
    {
        ans=ans+p->coef*pow(x,p->ex)*pow(y,p->ey)*pow(z,p->ez);
        p=p->next;
    }while(p!=head->next);
    return(ans);
}


void display(node *head)
{
    node *p;
    printf("The polynomial is :");
    p=head->next;

    do
    {
            printf(" +%d(x^%d)(y^%d)(z^%d)",p->coef,p->ex, p->ey, p->ez);
            p=p->next;
    } while(p!=head->next);
}


void main()
{
    int a,x,ch;
    node *p1,*p2,*p3;
    p1=p2=p3=NULL;
    while(1)
    {
        printf("\n----------Menu----------");
        printf("\n[1]Add Polynomials");
        printf("\n[2]Evaluate Polynomial");
        printf("\n[3]Exit");
        printf("\n------------------------");
        printf("\nEnter your choice: ");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1: p1=create();
                    display(p1);
                    p2=create();
                    display(p2);
                    p3=add(p1,p2);
                    display(p3);
                    break;
            case 2: p1=create();
                    display(p1);
                    a=eval(p1);
                    printf("Value of polynomial = %d",a);
                    break;
            case 3: exit(0);
                    break;
            default: printf("Invalid choice!\n");
                     break;
        }
    }
}