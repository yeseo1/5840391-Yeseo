// main.c
#include <stdio.h>
#include "dijkstra.h"

int main() {
    // PDF에 기반한 고정된 인접 행렬
    int graph[MAX_NODES][MAX_NODES] = {
        {0, 3, INFINITY, 7, INFINITY, INFINITY, INFINITY, INFINITY, INFINITY, INFINITY},
        {3, 0, 4, INFINITY, 11, INFINITY, INFINITY, INFINITY, INFINITY, INFINITY},
        {INFINITY, 4, 0, 8, 2, INFINITY, INFINITY, INFINITY, INFINITY, INFINITY},
        {7, INFINITY, 8, 0, INFINITY, 5, INFINITY, INFINITY, INFINITY, INFINITY},
        {INFINITY, 11, 2, INFINITY, 0, 13, 5, INFINITY, INFINITY, INFINITY},
        {INFINITY, INFINITY, INFINITY, 5, 13, 0, 6, INFINITY, INFINITY, INFINITY},
        {INFINITY, INFINITY, INFINITY, INFINITY, 5, 6, 0, 9, 8, INFINITY},
        {INFINITY, INFINITY, INFINITY, INFINITY, INFINITY, INFINITY, 9, 0, INFINITY, 7},
        {INFINITY, INFINITY, INFINITY, INFINITY, INFINITY, INFINITY, 8, INFINITY, 0, 9},
        {INFINITY, INFINITY, INFINITY, INFINITY, INFINITY, INFINITY, INFINITY, 7, 9, 0}
    };

    int startNode = 0; // 시작 노드 (0부터 시작)

    // Dijkstra 알고리즘 호출
    dijkstra(graph, startNode);

    getchar();

    return 0;
}
