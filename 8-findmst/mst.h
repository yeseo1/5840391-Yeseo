#ifndef MST_H
#define MST_H

typedef struct {
    int start, end, select; // weight를 select로 변경
} Edge;

typedef struct {
    int parent;
    int rank;
} SetType;

typedef struct {
    int num_vertices;
    int num_edges;
    Edge edges[100]; // 최대 간선 수를 100으로 가정
} GraphType;

typedef struct {
    Edge* heap;
    int size;
    int capacity;
} MinHeap;

void graph_init(GraphType* g);
void GenerateGraph(GraphType* g);
void set_init(SetType sets[], int n);
int find(SetType sets[], int x);
void union_sets(SetType sets[], int x, int y);
void QuickKruskal(GraphType* g);
void MinHeapKruskal(GraphType* g);

MinHeap* create_min_heap(int capacity);
void min_heap_insert(MinHeap* heap, Edge edge);
Edge min_heap_extract(MinHeap* heap);
void min_heapify(MinHeap* heap, int idx);
int compare_edges(const void* a, const void* b);

#endif // MST_H
