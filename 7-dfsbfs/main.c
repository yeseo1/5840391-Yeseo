// main.c

#include <stdio.h>
#include "7-dfsbfs.h"

int main() {
    int choice, startNode, targetNode;

    while (1) {
        printf("\n메뉴:\n");
        printf("1. 깊이 우선 탐색(DFS)\n");
        printf("2. 너비 우선 탐색(BFS)\n");
        printf("3. 프로그램 종료\n");
        printf("선택: ");
        scanf_s("%d", &choice);

        if (choice == 3) {
            printf("프로그램을 종료합니다.\n");
            break;
        }

        printf("시작 번호와 탐색할 값 입력: ", MAX - 1);
        scanf_s("%d %d", &startNode, &targetNode);

        if (startNode < 0 || startNode >= MAX || targetNode < 0 || targetNode >= MAX) {
            printf("존재하지 않는 노드입니다. 다시 입력하세요.\n");
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
            printf("잘못된 선택입니다. 다시 입력하세요.\n");
        }
    }

    return 0;
}
