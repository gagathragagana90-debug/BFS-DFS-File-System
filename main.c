
#include <stdio.h>
#include <string.h>

#define MAX 20

char names[MAX][50];
int graph[MAX][MAX];
int visited[MAX];
int n;

/* Breadth First Search */
int BFS(int start, int target)
{
    int queue[MAX];
    int front = 0, rear = 0;
    int found = 0;

    memset(visited, 0, sizeof(visited));

    queue[rear++] = start;
    visited[start] = 1;

    printf("\nBFS Traversal: ");

    while (front < rear)
    {
        int current = queue[front++];
        printf("%s ", names[current]);

        if (current == target)
            found = 1;

        for (int i = 0; i < n; i++)
        {
            if (graph[current][i] == 1 &&
                visited[i] == 0)
            {
                visited[i] = 1;
                queue[rear++] = i;
            }
        }
    }

    return found;
}

/* Depth First Search */
void DFS(int current, int target, int *found)
{
    visited[current] = 1;
    printf("%s ", names[current]);

    if (current == target)
        *found = 1;

    for (int i = 0; i < n; i++)
    {
        if (graph[current][i] == 1 &&
            visited[i] == 0)
        {
            DFS(i, target, found);
        }
    }
}

int main()
{
    int edges, u, v;
    int start = -1, target = -1;
    int bfsFound, dfsFound;
    char startName[50], targetName[50];

    printf("FILE SYSTEM SEARCH USING BFS AND DFS\n");

    printf("Enter number of files/directories: ");
    scanf("%d", &n);

    if (n < 1 || n > MAX)
    {
        printf("Invalid number of nodes!\n");
        return 1;
    }

    printf("Enter names of files/directories:\n");

    for (int i = 0; i < n; i++)
    {
        printf("Node %d: ", i);
        scanf("%49s", names[i]);
    }

    memset(graph, 0, sizeof(graph));

    printf("Enter number of connections: ");
    scanf("%d", &edges);

    if (edges < 0 || edges > n * (n - 1) / 2)
    {
        printf("Invalid number of connections!\n");
        return 1;
    }

    printf("Enter connections (node numbers 0 to %d):\n",
           n - 1);

    for (int i = 0; i < edges; i++)
    {
        scanf("%d %d", &u, &v);

        if (u < 0 || u >= n || v < 0 ||
            v >= n || u == v)
        {
            printf("Invalid connection!\n");
            return 1;
        }

        graph[u][v] = 1;
        graph[v][u] = 1;
    }

    printf("Enter starting directory name: ");
    scanf("%49s", startName);

    printf("Enter target file name: ");
    scanf("%49s", targetName);

    for (int i = 0; i < n; i++)
    {
        if (strcmp(names[i], startName) == 0)
            start = i;

        if (strcmp(names[i], targetName) == 0)
            target = i;
    }

    if (start == -1 || target == -1)
    {
        printf("Starting directory or target file not found!\n");
        return 1;
    }

    bfsFound = BFS(start, target);

    printf("\nBFS Result: %s\n",
           bfsFound ? "Target file found" :
                      "Target file not found");

    memset(visited, 0, sizeof(visited));
    dfsFound = 0;

    printf("\nDFS Traversal: ");
    DFS(start, target, &dfsFound);

    printf("\nDFS Result: %s\n",
           dfsFound ? "Target file found" :
                      "Target file not found");

    return 0;
}
