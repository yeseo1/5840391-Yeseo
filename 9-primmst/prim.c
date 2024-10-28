#include <stdio.h>
#include <stdlib.h>
#include "prim.h"

void graph_init(GraphType* g) {
    g->num_vertices = 0;
    g->num_edges = 0;
}

void GenerateGraph(GraphType* g) {
    g->num_vertices = 10; // ���� ���� 10���� ����
    g->num_edges = 9;     // ���� ���� 9�� ����

    g->edges[0] = (Edge){ 1, 2, 3 };
    g->edges[1] = (Edge){ 1, 3, 4 };
    g->edges[2] = (Edge){ 2, 3, 5 };
    g->edges[3] = (Edge){ 2, 4, 6 };
    g->edges[4] = (Edge){ 3, 5, 7 };
    g->edges[5] = (Edge){ 4, 5, 8 };
    g->edges[6] = (Edge){ 4, 6, 9 };
    g->edges[7] = (Edge){ 5, 6, 10 };
    g->edges[8] = (Edge){ 5, 7, 11 }; // �߰��� ����
}

void FindPrimMST(GraphType* g) {
    int selected[10] = { 0 }; // ���� ���� ���θ� ��Ÿ���� �迭
    int edges_in_mst = 0; // MST�� ���Ե� ���� ��
    selected[0] = 1; // ���� ���� ���� (���� 1)

    printf("Prim MST Algorithm\n");
    printf("���� 1 �߰�\n"); // �ʱ� ���� �߰�

    while (edges_in_mst < g->num_vertices - 1) {
        int min_edge = 9999; // �ּ� ���� ����
        int u = -1, v = -1;

        for (int i = 0; i < g->num_edges; i++) {
            if (selected[g->edges[i].start - 1] && !selected[g->edges[i].end - 1] && g->edges[i].select < min_edge) {
                min_edge = g->edges[i].select;
                u = g->edges[i].start;
                v = g->edges[i].end;
            }
        }

        if (u != -1 && v != -1) {
            printf("���� %d �߰�\n", v);
            selected[v - 1] = 1; // ���õ� ���� ǥ��
            edges_in_mst++;
        }
    }
}
