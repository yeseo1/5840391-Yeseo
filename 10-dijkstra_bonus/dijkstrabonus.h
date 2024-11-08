#ifndef DIJKSTRA_H
#define DIJKSTRA_H

#define INF 1000000

typedef struct AdjListNode {
    int dest;
    int weight;
    struct AdjListNode* next;
} AdjListNode;

typedef struct AdjList {
    AdjListNode* head;
} AdjList;

typedef struct Graph {
    int V;
    AdjList* array;
} Graph;

typedef struct MinHeapNode {
    int v;
    int dist;
} MinHeapNode;

typedef struct MinHeap {
    int size;
    int capacity;
    int* pos;
    MinHeapNode** array;
} MinHeap;

Graph* createGraph(int V);
void addEdge(Graph* graph, int src, int dest, int weight);
void dijkstra(Graph* graph, int src);

#endif
