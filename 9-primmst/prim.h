#ifndef PRIM_H
#define PRIM_H

typedef struct {
    int start; // 간선 시작 정점
    int end;   // 간선 끝 정점
    int select; // 간선의 선택값 (가중치)
} Edge;

typedef struct {
    int num_vertices; // 정점 수
    int num_edges;    // 간선 수
    Edge edges[20];   // 간선 배열 (최대 20개)
} GraphType;

// 함수 선언
void graph_init(GraphType* g);
void GenerateGraph(GraphType* g);
void FindPrimMST(GraphType* g);

#endif // PRIM_H
