#include <stdio.h>
int main()
{
    int marks;
    char grade;
    printf("\nEnter marks obtained: ");
    scanf("%d",&marks);
    switch (marks)
    {
        case 0 ... 39:
        grade='F';
        break;
        case 40 ... 49:
        grade='E';
        break;
        case 50 ... 59:
        grade='D';
        break;
        case 60 ... 69:
        grade='C';
        break;
        case 70 ... 79:
        grade='B';
        break;
        case 80 ... 89:
        grade='A';
        break;
        case 90 ... 100:
        grade='O';
        break;
    }
    printf("\nYour grade is %c\n",grade);
    return 0;
}