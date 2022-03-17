#include<stdio.h>
#include <math.h>
#include<stdlib.h>
#include<ctype.h>
int stack[20];
int top = -1;

void push(int x)
{
    stack[++top] = x;
}

int pop()
{
    return stack[top--];
}

int main()
{
    char exp[20];
    char* e;
    int n1, n2, n3, num;
    printf("Enter the postfix/suffix expression  :");
    gets(exp);
    e = exp;
    while (*e != '\0')
    {
        if (isdigit(*e))
        {
            num = *e - 48;
            push(num);
        }
        else
        {
            n2 = pop();
            n1 = pop();
            switch (*e)
            {
            case '+':
                n3 = n1 + n2;
                break;
            case '-':
                n3 = n1 - n2;
                break;
            case '*':
                n3 = n1 * n2;
                break;
            case '/':
                n3 = n1 / n2;
                break;
            case '^':
                n3 = pow(n1,n2);
                break;
            case '%':
                n3 = n1 % n2;
                break;
            default:
                printf("\nInvalid Operand!");
            }
            push(n3);
        }
        e++;
    }
    printf("\nEvaluation of the postfix/suffix expression gives : %d\n",pop());
    return 0;
}