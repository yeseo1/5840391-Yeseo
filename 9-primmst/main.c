#include <stdio.h>
#include <stdlib.h>
#include "prim.h"

int main(void) {
    GraphType* g;
    g = (GraphType*)malloc(sizeof(GraphType));
    graph_init(g);
    // �׷����� �����ϴ� �Լ�
    GenerateGraph(g);
    FindPrimMST(g); // Prim�� �̿��� MST�� ã��
    free(g);
    return 0;
}
