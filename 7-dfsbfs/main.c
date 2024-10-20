// main.c

#include <stdio.h>
#include "7-dfsbfs.h"

int main() {
    int choice, startNode, targetNode;

    while (1) {
        printf("\n�޴�:\n");
        printf("1. ���� �켱 Ž��(DFS)\n");
        printf("2. �ʺ� �켱 Ž��(BFS)\n");
        printf("3. ���α׷� ����\n");
        printf("����: ");
        scanf_s("%d", &choice);

        if (choice == 3) {
            printf("���α׷��� �����մϴ�.\n");
            break;
        }

        printf("���� ��ȣ�� Ž���� �� �Է�: ", MAX - 1);
        scanf_s("%d %d", &startNode, &targetNode);

        if (startNode < 0 || startNode >= MAX || targetNode < 0 || targetNode >= MAX) {
            printf("�������� �ʴ� ����Դϴ�. �ٽ� �Է��ϼ���.\n");
            continue;
        }

        switch (choice) {
        case 1:
            dfs(startNode, targetNode);
            break;
        case 2:
            bfs(startNode, targetNode);
            break;
        default:
            printf("�߸��� �����Դϴ�. �ٽ� �Է��ϼ���.\n");
        }
    }

    return 0;
}
