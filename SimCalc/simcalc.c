#include <stdio.h>

int main()
{
    int choice;
    float num1, num2, result;

    printf("\n*************************************************************************\n");
    printf("This is a simple calculator.\n\n");
    printf("Please choose from the menu below:\n\n");
    printf("[1] Addition (i.e num1 + num2)\n");
    printf("[2] Subtraction (i.e num1 - num2)\n");
    printf("[3] Multiplication (i.e num1 X num2)\n");
    printf("[4] Division (i.e num1 / num2)\n");
    printf("[5] Exit\n");

    printf("\nEnter the corresponding number to perform the desired operation: ");
    scanf("%d", &choice);
    printf("\nEnter value for num1: ");
    scanf("%f", &num1);
    printf("\nEnter value for num2: ");
    scanf("%f", &num2);

    switch (choice)
    {
    case 1:
        result = num1 + num2;
        break;
    case 2:
        result = num1 - num2;
        break;
    case 3:
        result = num1 * num2;
        break;
    case 4:
        if (num2 == 0)
            printf("\nOperation not possible as divisor is zero");
        else
            result = num1 / num2;
        break;
    case 5:
        printf("\nExiting...");
        printf("\nNo operation performed.");
        break;
    default:
        printf("\nInvalid Choice");
        printf("\nNo operation performed.");
        break;
    }
    printf("\nResult of the operation: %.3f", result);
    printf("\n*************************************************************************\n");
}