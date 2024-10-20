// 7-dfsbfs.c

#include <stdio.h>
#include "7-dfsbfs.h"

// 그래프 인접 행렬 정의
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

// 방문 노드 배열
int visited[MAX];

// 스택을 사용한 반복적 깊이 우선 탐색(DFS)
void dfs(int start, int target) {
    int stack[MAX], top = -1;
    int i, visitedCount = 0;

    for (i = 0; i < MAX; i++) visited[i] = 0;
    stack[++top] = start;
    visited[start] = 1;

    printf("DFS 탐색 순서: ");
    while (top >= 0) {
        int node = stack[top--];
        printf("%d ", node);
        visitedCount++;

        if (node == target) {
            printf("\n탐색 성공한 노드: %d\n", target);
            printf("방문한 노드의 수: %d\n", visitedCount);
            return;
        }

        for (i = MAX - 1; i >= 0; i--) {
            if (graph[node][i] && !visited[i]) {
                stack[++top] = i;
                visited[i] = 1;
            }
        }
    }
    printf("\n탐색 실패: 목표 노드를 찾을 수 없습니다.\n");
    printf("방문한 노드의 수: %d\n", visitedCount);
}

// 큐를 사용한 반복적 너비 우선 탐색(BFS)
void bfs(int start, int target) {
    int queue[QUEUE_SIZE], front = 0, rear = 0;
    int i, visitedCount = 0;

    for (i = 0; i < MAX; i++) visited[i] = 0;
    queue[rear++] = start;
    visited[start] = 1;

    printf("BFS 탐색 순서: ");
    while (front < rear) {
        int node = queue[front++];
        printf("%d ", node);
        visitedCount++;

        if (node == target) {
            printf("\n탐색 성공: %d\n", target);
            printf("방문한 노드의 수: %d\n", visitedCount);
            return;
        }

        for (i = 0; i < MAX; i++) {
            if (graph[node][i] && !visited[i]) {
                queue[rear++] = i;
                visited[i] = 1;
            }
        }
    }
    printf("\n탐색 실패: 목표 노드를 찾을 수 없습니다.\n");
    printf("방문한 노드의 수: %d\n", visitedCount);
}
