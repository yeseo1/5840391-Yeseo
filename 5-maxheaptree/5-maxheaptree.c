#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include "5-maxheaptree.h"

// 노드 생성 함수
TreeNode* createNode(int data) {
    TreeNode* newNode = (TreeNode*)malloc(sizeof(TreeNode));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// 트리의 마지막 노드를 찾아 반환하는 함수
TreeNode* getLastNode(TreeNode* root) {
    TreeNode* queue[100];
    int front = 0, rear = 0;
    queue[rear++] = root;
    TreeNode* lastNode = NULL;
    while (front < rear) {
        lastNode = queue[front++];
        if (lastNode->left) queue[rear++] = lastNode->left;
        if (lastNode->right) queue[rear++] = lastNode->right;
    }
    return lastNode;
}

// 부모 노드를 찾아주는 함수
TreeNode* findParent(TreeNode* root, TreeNode* node) {
    if (root == NULL || root == node) return NULL;
    if (root->left == node || root->right == node) return root;

    TreeNode* leftSearch = findParent(root->left, node);
    if (leftSearch) return leftSearch;
    return findParent(root->right, node);
}

// 트리를 중위 순서로 출력하는 함수 (노드 이동 과정 출력용)
void printInOrder(TreeNode* root) {
    if (root == NULL) return;
    printInOrder(root->left);
    printf("%d ", root->data);
    printInOrder(root->right);
}

// 최대 히프 트리에 노드 추가
void insertMaxHeapTree(TreeNode** root, int data, int* moveCount, int silent) {
    if (*root == NULL) {
        *root = createNode(data);
        return;
    }

    // 레벨 순서대로 트리에서 빈 자리를 찾아 새로운 노드를 삽입
    TreeNode* queue[100];
    int front = 0, rear = 0;
    queue[rear++] = *root;

    TreeNode* parent = NULL;
    while (front < rear) {
        parent = queue[front++];
        if (parent->left == NULL || parent->right == NULL) {
            break;
        }
        if (parent->left) queue[rear++] = parent->left;
        if (parent->right) queue[rear++] = parent->right;
    }

    TreeNode* newNode = createNode(data);
    if (parent->left == NULL) {
        parent->left = newNode;
    }
    else {
        parent->right = newNode;
    }

    // 노드 이동 과정을 출력 (silent가 0일 때만 출력)
    if (!silent) {
        printInOrder(*root);
        printf("\n");
    }

    // 최대 히프 성질을 유지하기 위해 상향식으로 노드 교환
    TreeNode* current = newNode;
    while (parent != NULL && current->data > parent->data) {
        (*moveCount)++;
        int temp = parent->data;
        parent->data = current->data;
        current->data = temp;

        // 노드가 이동된 후 상태 출력 (silent가 0일 때만 출력)
        if (!silent) {
            printInOrder(*root);
            printf("\n");
        }

        current = parent;
        parent = findParent(*root, current);
    }
}

// 최대 히프 트리에서 루트 노드 삭제
void deleteMaxHeapTree(TreeNode** root, int* moveCount) {
    if (*root == NULL) return;

    TreeNode* lastNode = getLastNode(*root);
    if (lastNode == *root) {
        free(*root);
        *root = NULL;
        return;
    }

    (*root)->data = lastNode->data;

    TreeNode* parent = findParent(*root, lastNode);
    if (parent->left == lastNode) {
        parent->left = NULL;
    }
    else {
        parent->right = NULL;
    }
    free(lastNode);

    // 노드 이동 과정을 출력
    printInOrder(*root);
    printf("\n");

    // 최대 히프 성질을 유지하기 위해 하향식으로 노드 교환
    TreeNode* current = *root;
    while (current->left || current->right) {
        if (current->right == NULL || (current->left && current->left->data > current->right->data)) {
            if (current->data < current->left->data) {
                (*moveCount)++;
                int temp = current->data;
                current->data = current->left->data;
                current->left->data = temp;

                // 노드가 이동된 후 상태 출력
                printInOrder(*root);
                printf("\n");

                current = current->left;
            }
            else {
                break;
            }
        }
        else {
            if (current->data < current->right->data) {
                (*moveCount)++;
                int temp = current->data;
                current->data = current->right->data;
                current->right->data = temp;

                // 노드가 이동된 후 상태 출력
                printInOrder(*root);
                printf("\n");

                current = current->right;
            }
            else {
                break;
            }
        }
    }
}

// 트리 레벨별 출력
void printLevelOrder(TreeNode* root) {
    if (root == NULL) return;

    TreeNode* queue[100];
    int front = 0, rear = 0;
    queue[rear++] = root;

    int level = 1;
    while (front < rear) {
        int levelSize = rear - front;
        printf("[%d] ", level++);
        for (int i = 0; i < levelSize; i++) {
            TreeNode* current = queue[front++];
            printf("%d ", current->data);
            if (current->left) queue[rear++] = current->left;
            if (current->right) queue[rear++] = current->right;
        }
        printf("\n");
    }
}

// 트리 메모리 해제
void freeTree(TreeNode* root) {
    if (root == NULL) return;
    freeTree(root->left);
    freeTree(root->right);
    free(root);
}

// 사용자 인터페이스 실행
void runUserInterface(TreeNode* root) {
    char choice;
    int value;
    int moveCount;
    printf("\ni : 노드 추가\n");
    printf("d : 노드 삭제\n");
    printf("p : 레벨별 출력\n");
    printf("c : 종료\n");
    while (1) {

        printf("메뉴 입력: ");
        scanf(" %c", &choice);

        switch (choice) {
        case 'i':
            printf("추가할 값 입력: ");
            scanf("%d", &value);
            moveCount = 0;
            insertMaxHeapTree(&root, value, &moveCount, 0); // 사용자 삽입 시 출력
            printf("노드가 이동된 횟수: %d\n", moveCount);
            break;

        case 'd':
            moveCount = 0;
            deleteMaxHeapTree(&root, &moveCount);
            printf("노드가 이동된 횟수: %d\n", moveCount);
            break;

        case 'p':
            printf("트리 레벨별 출력\n");
            printLevelOrder(root);
            break;

        case 'c':
            freeTree(root);
            return;

        default:
            printf("유효하지 않은 입력입니다.\n");
            break;
        }
    }
}

// 주어진 데이터 배열을 이용하여 최대 히프 트리 생성
TreeNode* generateMaxHeapTree(int inputData[], int size) {
    TreeNode* root = NULL;
    int moveCount = 0;
    for (int i = 0; i < size; i++) {
        insertMaxHeapTree(&root, inputData[i], &moveCount, 1); // 트리 생성 시 silent 모드로 출력 방지
    }
    return root;
}