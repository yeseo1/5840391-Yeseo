#ifndef PRIM_H
#define PRIM_H

typedef struct {
    int start; // ���� ���� ����
    int end;   // ���� �� ����
    int select; // ������ ���ð� (����ġ)
} Edge;

typedef struct {
    int num_vertices; // ���� ��
    int num_edges;    // ���� ��
    Edge edges[20];   // ���� �迭 (�ִ� 20��)
} GraphType;

// �Լ� ����
void graph_init(GraphType* g);
void GenerateGraph(GraphType* g);
void FindPrimMST(GraphType* g);

#endif // PRIM_H
