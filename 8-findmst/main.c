#include <stdio.h>
#include <stdlib.h>
#include "mst.h"

int main(void) {
    GraphType* g;
    g = (GraphType*)malloc(sizeof(GraphType));

    graph_init(g);
    GenerateGraph(g);
    QuickKruskal(g); // Quick ��� Kruskal
    MinHeapKruskal(g); // MinHeap ��� Kruskal

    free(g);

    printf("Press Enter to exit...");
    getchar();

    return 0;
}
