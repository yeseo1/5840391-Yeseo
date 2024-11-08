// dijkstra.h
#ifndef DIJKSTRA_H
#define DIJKSTRA_H

#define MAX_NODES 10    // 그래프의 노드 수
#define INFINITY 100000 // 도달할 수 없는 거리를 나타내기 위한 큰 값

// 함수 프로토타입 선언
void dijkstra(int graph[MAX_NODES][MAX_NODES], int startNode);
void printSolution(int dist[], int numNodes);

#endif
