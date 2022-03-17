#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>
int count=0;
int min=1000, max=9999;

struct node
{
    char name[25];
    long int phno;
    float billamnt;
    int otp;
    int payment_status;
    int mod;
    struct node *next;
}*start=NULL,*current;

void add_customer()
{
        count++;
        struct node *newnode=(struct node*)malloc(sizeof(struct node));
        printf("\nEnter customer details: ");
        printf("\nName : ");
        scanf("%s",&newnode->name);
        printf("\nPhone No : ");
        scanf("%ld",&newnode->phno);
        printf("\nBill Amount : ");
        scanf("%f",&newnode->billamnt);
        newnode->payment_status=0;
        srand(time(NULL));
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

void undo()
{
    if(count==0)
        printf("\n<<List is empty!>>");
    else
    {
        printf("\n<<Deleted last entry>>");
        count--;
        struct node *temp=(struct node*)malloc(sizeof(struct node));
        temp=start;
        start=start->next;
        free(temp);
    }    
}

void display()
{
    if(count==0)
        printf("\n<<List is empty!>>");
    else
    {
        printf("\nCustomer Details : ");
        printf("\nName : ");
        puts(start->name);
        printf("Phone No : %ld",start->phno);
        printf("\nBill amount : Rs.%.2f",start->billamnt);
        if(start->payment_status==1)
        {
            printf("\nPayment status : Paid");
        if(start->mod==1)
            printf("\nMode of payment : Card");
        else if(start->mod==2)
            printf("\nMode of payment : UPI");   
        else
            printf("\nMode of payment : Cash");
        }
        else
            printf("\nPayment status : Unpaid");
    }
}

void payment()
{
    int ch,pay;
    while(1)
    {
    printf("\nEnter mode of payment : ");
    printf("\n[1]Card");
    printf("\n[2]UPI");
    printf("\n[3]Cash");
    printf("\n[4]Exit");
    printf("\nEnter choice : ");
    scanf("%d",&ch);
    switch(ch)
    {
        case 1:
            printf("\nBill amount : %.2f",start->billamnt);
            printf("\nPay? (1 for yes, 0 for no) : ");
            scanf("%d",&pay);
            if (pay==0)
                printf("\nPayment cancelled!");
            else
            {
                printf("\nPayment Successful!");
                start->mod=1;
                start->payment_status=1;
                start->otp=(rand()%(max-min+1))+min;
                return;
            }
            break;
        case 2:
            printf("\nBill amount : %.2f",start->billamnt);
            printf("\nPay? (1 for yes, 0 for no) : ");
            scanf("%d",&pay);
            if (pay==0)
                printf("\nPayment cancelled!");
            else
            {
                printf("\nPayment Successful!");
                start->mod=2;
                start->payment_status=1;
                start->otp=(rand()%(max-min+1))+min;
                return;
            }
            break;
        case 3:
            printf("\nBill amount : %.2f",start->billamnt);
            printf("\nPay? (1 for yes, 0 for no) : ");
            scanf("%d",&pay);
            if (pay==0)
                printf("\nPayment cancelled!");
            else
            {
                printf("\nPayment Successful!");
                start->mod=3;
                start->payment_status=1;
                start->otp=(rand()%(max-min+1))+min;
                return;
            }
            break;
        case 4:
            return;    
        default:
        printf("\nInvalid option!");      
    }
    }
}

void customer_menu()
{
    int ch;
    while(1)
    {
    printf("\n-----Generic Customer Store-----");
    printf("\n[1]Pay bill");
    printf("\n[2]OTP");
    printf("\n[3]Exit");
    printf("\nEnter choice : ");
    scanf("%d",&ch);
    switch(ch)
    {
        case 1:
             payment();
             break;
        case 2:
            if(start->payment_status==0)
                printf("\nKindly pay to generate OTP");
            else
            {
                printf("\nThanks for shopping!");
                printf("Enter OTP:- %d at exit gate to exit\n",start->otp);
            }
            break;
        case 3:
            return;
        default:
            printf("\nInvalid choice!");                    
    }
}
}

void main()
{
    int choice;
    while(1)
    {
        printf("\n---------------MENU---------------");
        printf("\n[1]Add Customer details");
        printf("\n[2]Undo last entry");
        printf("\n[3]Display details");
        printf("\n[4]Coustomer Menu");
        printf("\n[5]Exit");
        printf("\n----------------------------------");
        printf("\nEnter choice : ");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
                add_customer();
                break;
            case 2:
                undo();
                break;
            case 3:
                display();
                break;
            case 4:
                customer_menu();
                break;
            case 5:
                printf("\nExiting program...\n");
                exit(0);    
            default:
                printf("\nInvalid choice!");                         
        }
    }
}