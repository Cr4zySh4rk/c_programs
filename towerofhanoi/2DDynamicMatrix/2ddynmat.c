#include <stdio.h>
#include <stdlib.h> 
int main()
{
   int m, n;
   printf("Enter the number of rows and columns : ");
   scanf("%d%d",&m,&n);
   int *arr = (int *)malloc(m * n * sizeof(int)); 
   int i, j;
   printf("Enter the array elements");
   for (i = 0; i < m; i++){
      for (j = 0; j < n; j++){
          scanf("%d",(arr+i*n+j));
      }
   }       
   printf("The matrix elements are:\n");
   for (i = 0; i < m; i++) {
      for (j = 0; j < n; j++) {
         printf("%d ", *(arr + i*n + j)); 
      }
      printf("\n");
   }
   return 0;
}