#include <stdio.h>
#include <stdlib.h>
#include "prim.h"

void graph_init(GraphType* g) {
    g->num_vertices = 0;
    g->num_edges = 0;
}

void GenerateGraph(GraphType* g) {
    g->num_vertices = 10; // 정점 수를 10으로 증가
    g->num_edges = 9;     // 간선 수를 9로 설정

    g->edges[0] = (Edge){ 1, 2, 3 };
    g->edges[1] = (Edge){ 1, 3, 4 };
    g->edges[2] = (Edge){ 2, 3, 5 };
    g->edges[3] = (Edge){ 2, 4, 6 };
    g->edges[4] = (Edge){ 3, 5, 7 };
    g->edges[5] = (Edge){ 4, 5, 8 };
    g->edges[6] = (Edge){ 4, 6, 9 };
    g->edges[7] = (Edge){ 5, 6, 10 };
    g->edges[8] = (Edge){ 5, 7, 11 }; // 추가된 간선
}

void FindPrimMST(GraphType* g) {
    int selected[10] = { 0 }; // 정점 선택 여부를 나타내는 배열
    int edges_in_mst = 0; // MST에 포함된 간선 수
    selected[0] = 1; // 시작 정점 선택 (정점 1)

    printf("Prim MST Algorithm\n");
    printf("정점 1 추가\n"); // 초기 정점 추가

    while (edges_in_mst < g->num_vertices - 1) {
        int min_edge = 9999; // 최소 간선 선택
        int u = -1, v = -1;

        for (int i = 0; i < g->num_edges; i++) {
            if (selected[g->edges[i].start - 1] && !selected[g->edges[i].end - 1] && g->edges[i].select < min_edge) {
                min_edge = g->edges[i].select;
                u = g->edges[i].start;
                v = g->edges[i].end;
            }
        }

        if (u != -1 && v != -1) {
            printf("정점 %d 추가\n", v);
            selected[v - 1] = 1; // 선택된 정점 표시
            edges_in_mst++;
        }
    }
}
