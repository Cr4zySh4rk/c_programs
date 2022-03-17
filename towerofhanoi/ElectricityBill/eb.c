#include <stdio.h>
int main ()
{
    char user[20];
    float unit,amount=100.00;
    printf("\nEnter your name please:");
    scanf("%s",user);
    printf("\nEnter number of units consumed:");
    scanf("%f",&unit);

    if(unit<=200)
        amount+=unit*0.80;
    else if(unit<=300)
        amount+=(200*0.80)+(unit-200)*0.90;
    else if (unit>300)
        amount+=(200*0.80)+(unit-200)*0.90+(unit-300);
    if (amount>400)
        amount+=amount*0.15;
    printf("\nUser:%s\nTotal amount due for payment: Rs %.2f\n",user,amount);
    
    return 0;          
}