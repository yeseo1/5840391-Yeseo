#include <stdio.h>
#include "dijkstrabonus.h"

int main() {
    int V = 10;  // 정점의 개수
    Graph* graph = createGraph(V);

    // 간선 추가 (예제에 맞게 수정)
    addEdge(graph, 0, 1, 3);
    addEdge(graph, 1, 2, 8);
    addEdge(graph, 2, 3, 7);
    addEdge(graph, 2, 5, 4);
    addEdge(graph, 3, 4, 9);
    addEdge(graph, 4, 5, 10);
    addEdge(graph, 5, 6, 2);
    addEdge(graph, 6, 7, 1);
    addEdge(graph, 7, 8, 7);
    addEdge(graph, 8, 9, 9);
    addEdge(graph, 6, 8, 6);

    dijkstra(graph, 0);

    getchar();

    return 0;
}
