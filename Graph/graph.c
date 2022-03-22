#include <stdlib.h>
#include <stdio.h>
#include <curses.h>
void bfs(int v);
void dfs(int v);

int a[50][50], n, visited[50];
int q[20], front = -1, rear = -1;
int s[20], top = -1, count = 0;

void creategraph()
{
    int i, j;
    printf("\nEnter the number of vertices in graph : ");
    scanf("%d", &n);
    printf("\nEnter the adjacency matrix : \n");
    for (i = 1; i <= n; i++)
        for (j = 1; j <= n; j++)
            scanf("%d", &a[i][j]);
}

void bfs(int v)
{
    int i, cur;
    visited[v] = 1;
    q[++rear] = v;
    printf("\nNodes reachable from starting vertex %d is: ", v);
    while (front != rear)
    {
        cur = q[++front];
        for (i = 1; i <= n; i++)
        {
            if ((a[cur][i] == 1) && (visited[i] == 0))
            {
                q[++rear] = i;

                visited[i] = 1;
                printf("%d ", i);
            }
        }
    }
}

void dfs(int v)
{
    int i;
    visited[v] = 1;
    s[++top] = v;
    for (i = 1; i <= n; i++)
    {
        if (a[v][i] == 1 && visited[i] == 0)
        {
            dfs(i);
            count++;
        }
    }
}

int main()
{
    while (1)
    {
        int ch, start, i, j;
        printf("\n-----Menu-----");
        printf("\n[0] Create adjacency matrix");
        printf("\n[1] BFS");
        printf("\n[2] DFS");
        printf("\n[3] Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &ch);
        switch (ch)
        {
        case 0:
            creategraph();
            break;    
        case 1:
            for (i = 1; i <= n; i++)
                visited[i] = 0;
            printf("\nEnter the starting vertex : ");
            scanf("%d", &start);
            bfs(start);
            for (i = 1; i <= n; i++)
            {
                if (visited[i] == 0)
                    printf("\nThe vertex that is not reachable is %d\n", i);
            }
            break;
        case 2:
            for (i = 1; i <= n; i++)
                visited[i] = 0;
            printf("\nEnter the starting vertex : ");
            scanf("%d", &start);
            dfs(start);
            printf("\nNodes reachable from starting vertex %d is : ", start);
            for (i = 1; i <= count; i++)
                printf("%d ", s[i]);
            break;
        case 3:
            printf("\nExiting Program...\n");
            exit(0);
        default:
            printf("\nInvalid choice!");
        }
    }
}