#include <stdio.h>
#include <stdlib.h>
#include "mst.h"

void graph_init(GraphType* g) {
    g->num_vertices = 0;
    g->num_edges = 0;
}

void GenerateGraph(GraphType* g) {
    g->num_vertices = 10; // 정점 수를 10으로 증가
    g->num_edges = 8;     // 간선 수를 8로 설정

    g->edges[0] = (Edge){ 2, 5, 1 };
    g->edges[1] = (Edge){ 3, 4, 2 };
    g->edges[2] = (Edge){ 1, 2, 3 };
    g->edges[3] = (Edge){ 2, 4, 4 };
    g->edges[4] = (Edge){ 3, 8, 5 };
    g->edges[5] = (Edge){ 3, 7, 6 };
    g->edges[6] = (Edge){ 2, 6, 7 };
    g->edges[7] = (Edge){ 9, 10, 10 };
    // 추가 간선 (선택 값: 15)
    g->edges[8] = (Edge){ 8, 10, 15 };
}

void set_init(SetType sets[], int n) {
    for (int i = 0; i < n; i++) {
        sets[i].parent = i;
        sets[i].rank = 0;
    }
}

int find(SetType sets[], int x) {
    if (x < 0 || x >= 10) // 정점 번호가 유효한지 체크
        return -1; // 유효하지 않은 경우 -1 반환

    if (sets[x].parent != x) {
        sets[x].parent = find(sets, sets[x].parent);
    }
    return sets[x].parent;
}

void union_sets(SetType sets[], int x, int y) {
    int rootX = find(sets, x);
    int rootY = find(sets, y);

    if (rootX == -1 || rootY == -1) return; // 유효하지 않은 경우 무시

    if (sets[rootX].rank < sets[rootY].rank) {
        sets[rootX].parent = rootY;
    }
    else if (sets[rootX].rank > sets[rootY].rank) {
        sets[rootY].parent = rootX;
    }
    else {
        sets[rootY].parent = rootX;
        sets[rootX].rank++;
    }
}

// MinHeap 생성 함수
MinHeap* create_min_heap(int capacity) {
    MinHeap* heap = (MinHeap*)malloc(sizeof(MinHeap));
    heap->heap = (Edge*)malloc(capacity * sizeof(Edge));
    heap->size = 0;
    heap->capacity = capacity;
    return heap;
}

// 최소 힙에 간선 삽입
void min_heap_insert(MinHeap* heap, Edge edge) {
    int i = heap->size++;
    while (i && edge.select < heap->heap[(i - 1) / 2].select) {
        heap->heap[i] = heap->heap[(i - 1) / 2];
        i = (i - 1) / 2;
    }
    heap->heap[i] = edge;
}

// 최소 힙에서 최소 간선 추출
Edge min_heap_extract(MinHeap* heap) {
    Edge root = heap->heap[0];
    heap->heap[0] = heap->heap[--heap->size];
    min_heapify(heap, 0);
    return root;
}

// 힙 속성 유지
void min_heapify(MinHeap* heap, int idx) {
    int smallest = idx;
    int left = 2 * idx + 1;
    int right = 2 * idx + 2;

    if (left < heap->size && heap->heap[left].select < heap->heap[smallest].select) {
        smallest = left;
    }
    if (right < heap->size && heap->heap[right].select < heap->heap[smallest].select) {
        smallest = right;
    }
    if (smallest != idx) {
        Edge temp = heap->heap[idx];
        heap->heap[idx] = heap->heap[smallest];
        heap->heap[smallest] = temp;
        min_heapify(heap, smallest);
    }
}

// qsort를 위한 비교 함수
int compare_edges(const void* a, const void* b) {
    Edge* edge1 = (Edge*)a;
    Edge* edge2 = (Edge*)b;
    return edge1->select - edge2->select; // 오름차순
}

void QuickKruskal(GraphType* g) {
    SetType* sets = (SetType*)malloc(g->num_vertices * sizeof(SetType));
    set_init(sets, g->num_vertices);
    qsort(g->edges, g->num_edges, sizeof(Edge), compare_edges);

    printf("Quick Based Kruskal:\n"); // 변경된 출력
    for (int i = 0, edges_in_mst = 0; edges_in_mst < g->num_vertices - 1 && i < g->num_edges; i++) {
        int u = g->edges[i].start, v = g->edges[i].end;
        if (find(sets, u) != find(sets, v)) {
            printf("Edge (%d, %d) select: %d\n", u, v, g->edges[i].select); // 각 간선의 선택값 출력
            union_sets(sets, u, v);
            edges_in_mst++;
        }
    }
    free(sets);
}

void MinHeapKruskal(GraphType* g) {
    MinHeap* heap = create_min_heap(g->num_edges);
    for (int i = 0; i < g->num_edges; i++) {
        min_heap_insert(heap, g->edges[i]);
    }

    SetType* sets = (SetType*)malloc(g->num_vertices * sizeof(SetType));
    set_init(sets, g->num_vertices);

    printf("Minheap Based Kruskal:\n"); // 변경된 출력
    int edges_in_mst = 0;
    while (edges_in_mst < g->num_vertices - 1 && heap->size) {
        Edge min_edge = min_heap_extract(heap);
        int u = min_edge.start, v = min_edge.end;
        if (find(sets, u) != find(sets, v)) {
            printf("Edge (%d, %d) select: %d\n", u, v, min_edge.select); // 각 간선의 선택값 출력
            union_sets(sets, u, v);
            edges_in_mst++;
        }
    }

    free(sets);
    free(heap->heap);
    free(heap);
}
