#include<stdio.h>
#include<curses.h>//substitute for conio.h which is windows specific
#include<string.h>
struct records
{
	int flag, usn;
	char name[20];
}rec[10];
int hash(int m)
{
	int slots = 10;
	int r;
	r = m % slots;
	return r;
}
void main()
{
	int m, k, usn, loc, i, n, j;
	char name[20];
	FILE *in, *outp;
	printf("\nEnter no of records to read from file: ");
	scanf("%d", &n);
	in = fopen("input.txt", "r");
	if (n <= 10)
	{
		for (k = 0; k<10; k++)
			rec[k].flag = 0;
		for (i = 0; i<n; i++)
		{
			fscanf(in, "%s%d", name, &usn);
			loc = hash(usn);
			printf("\naddress: %d", loc);
			if (rec[loc].flag == 0)
			{
				strcpy(rec[loc].name, name);
				rec[loc].usn = usn;
				rec[loc].flag = 1;
			}
			else
			{
				printf("\nCollision Detected!\n");
				for (j = loc + 1; j % 10<10; j++)
				{
					if (rec[j % 10].flag == 0)
					{
						printf("The address of %d record is %d\n",i+1,j%10);
						strcpy(rec[j % 10].name, name);
						rec[j % 10].usn = usn;
						rec[j % 10].flag = 1;
						break;
					}
				}
			}
		}
		fclose(in);
		printf("\n\nThe Hash Table Content is: ");
		for (i = 0; i<10; i++)
		{
			if (rec[i].flag == 1)
				printf("\n%s\t\t%d ", rec[i].name, rec[i].usn);
			else
				printf("\n#\t\t#");
		}
		outp = fopen("output.txt", "w");
		for (i = 0; i<10; i++)
		{
			if (rec[i].flag == 0)
				fprintf(outp, "\n#\t\t#");
			else
				fprintf(outp, "\n%s\t\t%d ", rec[i].name, rec[i].usn);
		}
		fclose(outp);
	}
	else
		printf("\n Please Provide less than 10 Records !! ");
    printf("\n");    
}
