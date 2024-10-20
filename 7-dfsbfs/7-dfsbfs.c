// 7-dfsbfs.c

#include <stdio.h>
#include "7-dfsbfs.h"

// �׷��� ���� ��� ����
int graph[MAX][MAX] = {
    {0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0},
    {1, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0},
    {0, 1, 0, 1, 0, 0, 1, 0, 0, 0, 0},
    {0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0},
    {1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0},
    {0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0},
    {0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1},
    {0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0}
};

// �湮 ��� �迭
int visited[MAX];

// ������ ����� �ݺ��� ���� �켱 Ž��(DFS)
void dfs(int start, int target) {
    int stack[MAX], top = -1;
    int i, visitedCount = 0;

    for (i = 0; i < MAX; i++) visited[i] = 0;
    stack[++top] = start;
    visited[start] = 1;

    printf("DFS Ž�� ����: ");
    while (top >= 0) {
        int node = stack[top--];
        printf("%d ", node);
        visitedCount++;

        if (node == target) {
            printf("\nŽ�� ������ ���: %d\n", target);
            printf("�湮�� ����� ��: %d\n", visitedCount);
            return;
        }

        for (i = MAX - 1; i >= 0; i--) {
            if (graph[node][i] && !visited[i]) {
                stack[++top] = i;
                visited[i] = 1;
            }
        }
    }
    printf("\nŽ�� ����: ��ǥ ��带 ã�� �� �����ϴ�.\n");
    printf("�湮�� ����� ��: %d\n", visitedCount);
}

// ť�� ����� �ݺ��� �ʺ� �켱 Ž��(BFS)
void bfs(int start, int target) {
    int queue[QUEUE_SIZE], front = 0, rear = 0;
    int i, visitedCount = 0;

    for (i = 0; i < MAX; i++) visited[i] = 0;
    queue[rear++] = start;
    visited[start] = 1;

    printf("BFS Ž�� ����: ");
    while (front < rear) {
        int node = queue[front++];
        printf("%d ", node);
        visitedCount++;

        if (node == target) {
            printf("\nŽ�� ����: %d\n", target);
            printf("�湮�� ����� ��: %d\n", visitedCount);
            return;
        }

        for (i = 0; i < MAX; i++) {
            if (graph[node][i] && !visited[i]) {
                queue[rear++] = i;
                visited[i] = 1;
            }
        }
    }
    printf("\nŽ�� ����: ��ǥ ��带 ã�� �� �����ϴ�.\n");
    printf("�湮�� ����� ��: %d\n", visitedCount);
}
