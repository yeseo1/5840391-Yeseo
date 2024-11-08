// dijkstra.c
#include <stdio.h>
#include "dijkstra.h"

// �ּ� �Ÿ� ��带 ã�� �Լ�
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

// Dijkstra �˰��� ����
void dijkstra(int graph[MAX_NODES][MAX_NODES], int startNode) {
    int dist[MAX_NODES];           // ��� ���κ��� �� �������� �ִ� �Ÿ��� �����ϴ� �迭
    int processed[MAX_NODES] = { 0 }; // �� ��尡 ó���Ǿ������� ǥ���ϴ� �迭
    int order[MAX_NODES];          // �湮 ������ �����ϴ� �迭
    int orderIndex = 0;            // �湮 ���� �ε���

    // ��� �Ÿ��� ���Ѵ�� �ʱ�ȭ�ϰ�, ó�� ���θ� false�� ����
    for (int i = 0; i < MAX_NODES; i++) {
        dist[i] = INFINITY;
    }
    dist[startNode] = 0; // ���� ����� �Ÿ��� 0���� ����

    // �׷����� ��� ��带 ��ȸ�ϸ鼭 �ִ� ��θ� ���
    for (int count = 0; count < MAX_NODES - 1; count++) {
        // �ּ� �Ÿ��� ���� ��带 ����
        int u = minDistance(dist, processed, MAX_NODES);
        if (u == -1) break; // ������ �� ���� ��尡 ���� ������ ����
        processed[u] = 1;   // ������ ��带 ó���� ������ ǥ��
        order[orderIndex++] = u; // �湮 ���� ���

        // ����� ������ ���
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

        // ���õ� ����� ������ ������ �Ÿ��� ������Ʈ
        for (int v = 0; v < MAX_NODES; v++) {
            if (!processed[v] && graph[u][v] && dist[u] != INFINITY
                && dist[u] + graph[u][v] < dist[v]) {
                dist[v] = dist[u] + graph[u][v];
            }
        }
    }

    // ������ ��带 �湮 ������ �߰�
    for (int i = 0; i < MAX_NODES; i++) {
        if (!processed[i]) {
            order[orderIndex++] = i;
        }
    }

    // ���� �湮 ���� ���
    printf("Found Order: ");
    for (int i = 0; i < orderIndex; i++) {
        printf("%d ", order[i] + 1); // 1���� �����ϴ� ������ ���
    }
    printf("\n");
}
