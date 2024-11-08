#include <stdio.h>
#include <stdlib.h>
#include "dijkstrabonus.h"

// ���ο� ���� ����Ʈ ��� ����
AdjListNode* newAdjListNode(int dest, int weight) {
    AdjListNode* newNode = (AdjListNode*)malloc(sizeof(AdjListNode));
    newNode->dest = dest;
    newNode->weight = weight;
    newNode->next = NULL;
    return newNode;
}

// �׷��� ����
Graph* createGraph(int V) {
    Graph* graph = (Graph*)malloc(sizeof(Graph));
    graph->V = V;
    graph->array = (AdjList*)malloc(V * sizeof(AdjList));
    for (int i = 0; i < V; ++i)
        graph->array[i].head = NULL;
    return graph;
}

// �׷����� ���� �߰�
void addEdge(Graph* graph, int src, int dest, int weight) {
    AdjListNode* newNode = newAdjListNode(dest, weight);
    newNode->next = graph->array[src].head;
    graph->array[src].head = newNode;

    newNode = newAdjListNode(src, weight);
    newNode->next = graph->array[dest].head;
    graph->array[dest].head = newNode;
}

// Min Heap ����
MinHeap* createMinHeap(int capacity) {
    MinHeap* minHeap = (MinHeap*)malloc(sizeof(MinHeap));
    minHeap->pos = (int*)malloc(capacity * sizeof(int));
    minHeap->size = 0;
    minHeap->capacity = capacity;
    minHeap->array = (MinHeapNode**)malloc(capacity * sizeof(MinHeapNode*));
    return minHeap;
}

// Min Heapify
void minHeapify(MinHeap* minHeap, int idx) {
    int smallest = idx;
    int left = 2 * idx + 1;
    int right = 2 * idx + 2;

    if (left < minHeap->size && minHeap->array[left]->dist < minHeap->array[smallest]->dist)
        smallest = left;

    if (right < minHeap->size && minHeap->array[right]->dist < minHeap->array[smallest]->dist)
        smallest = right;

    if (smallest != idx) {
        MinHeapNode* smallestNode = minHeap->array[smallest];
        MinHeapNode* idxNode = minHeap->array[idx];

        minHeap->pos[smallestNode->v] = idx;
        minHeap->pos[idxNode->v] = smallest;

        MinHeapNode* temp = minHeap->array[smallest];
        minHeap->array[smallest] = minHeap->array[idx];
        minHeap->array[idx] = temp;

        minHeapify(minHeap, smallest);
    }
}

// Min Heap���� �ּڰ� ����
MinHeapNode* extractMin(MinHeap* minHeap) {
    if (minHeap->size == 0)
        return NULL;

    MinHeapNode* root = minHeap->array[0];
    MinHeapNode* lastNode = minHeap->array[minHeap->size - 1];
    minHeap->array[0] = lastNode;

    minHeap->pos[root->v] = minHeap->size - 1;
    minHeap->pos[lastNode->v] = 0;

    --minHeap->size;
    minHeapify(minHeap, 0);

    return root;
}

// Key �� ����
void decreaseKey(MinHeap* minHeap, int v, int dist) {
    int i = minHeap->pos[v];
    minHeap->array[i]->dist = dist;

    while (i && minHeap->array[i]->dist < minHeap->array[(i - 1) / 2]->dist) {
        minHeap->pos[minHeap->array[i]->v] = (i - 1) / 2;
        minHeap->pos[minHeap->array[(i - 1) / 2]->v] = i;

        MinHeapNode* temp = minHeap->array[i];
        minHeap->array[i] = minHeap->array[(i - 1) / 2];
        minHeap->array[(i - 1) / 2] = temp;

        i = (i - 1) / 2;
    }
}

// Min Heap�� ��尡 �����ϴ��� Ȯ��
int isInMinHeap(MinHeap* minHeap, int v) {
    return minHeap->pos[v] < minHeap->size;
}

// Distance �� Found �迭 ��� �Լ�
void printStatus(int dist[], int found[], int V) {
    printf("Distance: ");
    for (int i = 0; i < V; i++) {
        if (dist[i] == INF) {
            printf("* ");
        }
        else {
            printf("%d ", dist[i]);
        }
    }
    printf("\nFound: ");
    for (int i = 0; i < V; i++) {
        printf("%d ", found[i]);
    }
    printf("\n\n");
}

// Dijkstra �˰��� ����
void dijkstra(Graph* graph, int src) {
    int V = graph->V;
    int* dist = (int*)malloc(V * sizeof(int)); // ���� �Ҵ�
    int* found = (int*)malloc(V * sizeof(int)); // ���� �Ҵ�

    if (dist == NULL || found == NULL) {
        fprintf(stderr, "�޸� �Ҵ� ����\n");
        return;
    }

    MinHeap* minHeap = createMinHeap(V);

    for (int v = 0; v < V; ++v) {
        dist[v] = INF;
        found[v] = 0;
        minHeap->array[v] = (MinHeapNode*)malloc(sizeof(MinHeapNode));
        minHeap->array[v]->v = v;
        minHeap->array[v]->dist = dist[v];
        minHeap->pos[v] = v;
    }

    dist[src] = 0;
    minHeap->array[src]->dist = dist[src];
    decreaseKey(minHeap, src, dist[src]);
    minHeap->size = V;

    while (minHeap->size > 0) {
        MinHeapNode* minHeapNode = extractMin(minHeap);
        int u = minHeapNode->v;
        found[u] = 1;

        printStatus(dist, found, V);

        AdjListNode* pCrawl = graph->array[u].head;
        while (pCrawl != NULL) {
            int v = pCrawl->dest;

            if (isInMinHeap(minHeap, v) && dist[u] != INF && pCrawl->weight + dist[u] < dist[v]) {
                dist[v] = dist[u] + pCrawl->weight;
                decreaseKey(minHeap, v, dist[v]);
            }
            pCrawl = pCrawl->next;
        }
    }

    printf("Found Order: ");
    for (int i = 0; i < V; i++) {
        printf("%d ", found[i]);
    }
    printf("\n");

    free(dist);
    free(found);
}
