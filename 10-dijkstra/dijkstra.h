// dijkstra.h
#ifndef DIJKSTRA_H
#define DIJKSTRA_H

#define MAX_NODES 10    // �׷����� ��� ��
#define INFINITY 100000 // ������ �� ���� �Ÿ��� ��Ÿ���� ���� ū ��

// �Լ� ������Ÿ�� ����
void dijkstra(int graph[MAX_NODES][MAX_NODES], int startNode);
void printSolution(int dist[], int numNodes);

#endif
