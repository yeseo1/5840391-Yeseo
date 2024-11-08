// dijkstra.c
#include <stdio.h>
#include "dijkstra.h"

// 최소 거리 노드를 찾는 함수
int minDistance(int dist[], int processed[], int numNodes) {
    int min = INFINITY, minIndex = -1;
    for (int v = 0; v < numNodes; v++) {
        if (!processed[v] && dist[v] <= min) {
            min = dist[v];
            minIndex = v;
        }
    }
    return minIndex;
}

// Dijkstra 알고리즘 구현
void dijkstra(int graph[MAX_NODES][MAX_NODES], int startNode) {
    int dist[MAX_NODES];           // 출발 노드로부터 각 노드까지의 최단 거리를 저장하는 배열
    int processed[MAX_NODES] = { 0 }; // 각 노드가 처리되었는지를 표시하는 배열
    int order[MAX_NODES];          // 방문 순서를 저장하는 배열
    int orderIndex = 0;            // 방문 순서 인덱스

    // 모든 거리를 무한대로 초기화하고, 처리 여부를 false로 설정
    for (int i = 0; i < MAX_NODES; i++) {
        dist[i] = INFINITY;
    }
    dist[startNode] = 0; // 시작 노드의 거리는 0으로 설정

    // 그래프의 모든 노드를 순회하면서 최단 경로를 계산
    for (int count = 0; count < MAX_NODES - 1; count++) {
        // 최소 거리를 가진 노드를 선택
        int u = minDistance(dist, processed, MAX_NODES);
        if (u == -1) break; // 도달할 수 없는 노드가 남아 있으면 종료
        processed[u] = 1;   // 선택한 노드를 처리된 것으로 표시
        order[orderIndex++] = u; // 방문 순서 기록

        // 디버깅 정보를 출력
        printf("Distance: ");
        for (int i = 0; i < MAX_NODES; i++) {
            if (dist[i] == INFINITY) {
                printf("* ");
            }
            else {
                printf("%d ", dist[i]);
            }
        }
        printf("\nFound: ");
        for (int i = 0; i < MAX_NODES; i++) {
            printf("%d ", processed[i]);
        }
        printf("\n");

        // 선택된 노드의 인접한 노드들의 거리를 업데이트
        for (int v = 0; v < MAX_NODES; v++) {
            if (!processed[v] && graph[u][v] && dist[u] != INFINITY
                && dist[u] + graph[u][v] < dist[v]) {
                dist[v] = dist[u] + graph[u][v];
            }
        }
    }

    // 마지막 노드를 방문 순서에 추가
    for (int i = 0; i < MAX_NODES; i++) {
        if (!processed[i]) {
            order[orderIndex++] = i;
        }
    }

    // 최종 방문 순서 출력
    printf("Found Order: ");
    for (int i = 0; i < orderIndex; i++) {
        printf("%d ", order[i] + 1); // 1부터 시작하는 순서로 출력
    }
    printf("\n");
}
