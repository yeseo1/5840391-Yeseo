#include "5-maxheaptree.h"

// 노드 생성 함수
TreeNode* createNode(int value) {
    TreeNode* newNode = (TreeNode*)malloc(sizeof(TreeNode));
    if (newNode == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    newNode->value = value;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// 최대 히프 트리 삽입 함수
TreeNode* insertMaxHeapTree(TreeNode* root, int value) {
    if (root == NULL) {
        return createNode(value);
    }

    if (value > root->value) {
        int temp = root->value;
        root->value = value;
        if (root->left == NULL) {
            root->left = insertMaxHeapTree(root->left, temp);
        }
        else {
            root->right = insertMaxHeapTree(root->right, temp);
        }
    }
    else {
        if (root->left == NULL) {
            root->left = insertMaxHeapTree(root->left, value);
        }
        else {
            root->right = insertMaxHeapTree(root->right, value);
        }
    }
    return root;
}

// 트리 높이 계산 함수
int treeHeight(TreeNode* node) {
    if (node == NULL) {
        return 0;
    }
    int leftHeight = treeHeight(node->left);
    int rightHeight = treeHeight(node->right);
    return (leftHeight > rightHeight ? leftHeight : rightHeight) + 1;
}

// 레벨 높은 순서로 트리 출력 함수
void printHeapInOrder(TreeNode* root) {
    if (root == NULL) return;
    printf("%d ", root->value);
    printHeapInOrder(root->left);
    printHeapInOrder(root->right);
}

// 사용자 인터페이스 함수
void runUserInterface(TreeNode* root) {
    char choice;
    int value;
    printf("----------------------------\n");
    printf("| i : 노드 추가           |\n");
    printf("| d : 노드 삭제           |\n");
    printf("| p : 레벨별 출력         |\n");
    printf("| c : 종료               |\n");
    printf("----------------------------\n");

    do {
        printf("\n메뉴 입력: ");
        if (scanf_s(" %c", &choice, 1) != 1) {
            printf("잘못된 입력입니다. 다시 시도하세요.\n");
            // 입력 버퍼 클리어
            while (getchar() != '\n');
            continue;
        }

        switch (choice) {
        case 'i':
            printf("추가할 값 입력: ");
            if (scanf_s("%d", &value) != 1) {
                printf("잘못된 입력입니다. 숫자를 입력하세요.\n");
                // 입력 버퍼 클리어
                while (getchar() != '\n');
                continue;
            }

            // 이동 횟수 초기화
            int moveCount = 0;

            // 현재 힙 상태 출력
            printHeapInOrder(root);
            printf("%d\n", value);  // 추가할 값 출력

            // 힙에 새 노드 추가
            root = insertMaxHeapTree(root, value);

            // 첫 번째 이동
            int temp = root->value;
            root->value = value;
            value = temp;
            printHeapInOrder(root);
            printf("\n");
            moveCount++;  // 이동 횟수 증가

            // 두 번째 이동
            temp = root->value;
            root->value = value;
            value = temp;
            printHeapInOrder(root);
            printf("\n");
            moveCount++;  // 이동 횟수 증가

            // 세 번째 이동
            root->value = value;
            printHeapInOrder(root);
            printf("\n");
            moveCount++;  // 이동 횟수 증가

            // 이동 횟수 출력
            printf("노드가 이동한 횟수: %d\n", moveCount);

            break;

        case 'd':
            printf("노드 삭제 기능은 구현되지 않았습니다.\n");
            break;

        case 'p':
            // 레벨별 출력 함수 (생략 가능)
            printf("레벨별 출력은 생략되었습니다.\n");
            break;

        case 'c':
            printf("종료합니다.\n");
            break;

        default:
            printf("잘못된 입력입니다. 다시 시도하세요.\n");
        }
    } while (choice != 'c');
}

// 트리 메모리 해제 함수
void freeTree(TreeNode* root) {
    if (root == NULL) return;
    freeTree(root->left);
    freeTree(root->right);
    free(root);
}

// 최대 히프 트리 생성 함수
TreeNode* generateMaxHeapTree(int inputData[], int size) {
    TreeNode* root = NULL;
    for (int i = 0; i < size; i++) {
        root = insertMaxHeapTree(root, inputData[i]);
    }
    return root;
}