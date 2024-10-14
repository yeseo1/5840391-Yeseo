#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include "5-maxheaptree.h"

// ��� ���� �Լ�
TreeNode* createNode(int data) {
    TreeNode* newNode = (TreeNode*)malloc(sizeof(TreeNode));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Ʈ���� ������ ��带 ã�� ��ȯ�ϴ� �Լ�
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

// �θ� ��带 ã���ִ� �Լ�
TreeNode* findParent(TreeNode* root, TreeNode* node) {
    if (root == NULL || root == node) return NULL;
    if (root->left == node || root->right == node) return root;

    TreeNode* leftSearch = findParent(root->left, node);
    if (leftSearch) return leftSearch;
    return findParent(root->right, node);
}

// Ʈ���� ���� ������ ����ϴ� �Լ� (��� �̵� ���� ��¿�)
void printInOrder(TreeNode* root) {
    if (root == NULL) return;
    printInOrder(root->left);
    printf("%d ", root->data);
    printInOrder(root->right);
}

// �ִ� ���� Ʈ���� ��� �߰�
void insertMaxHeapTree(TreeNode** root, int data, int* moveCount, int silent) {
    if (*root == NULL) {
        *root = createNode(data);
        return;
    }

    // ���� ������� Ʈ������ �� �ڸ��� ã�� ���ο� ��带 ����
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

    // ��� �̵� ������ ��� (silent�� 0�� ���� ���)
    if (!silent) {
        printInOrder(*root);
        printf("\n");
    }

    // �ִ� ���� ������ �����ϱ� ���� ��������� ��� ��ȯ
    TreeNode* current = newNode;
    while (parent != NULL && current->data > parent->data) {
        (*moveCount)++;
        int temp = parent->data;
        parent->data = current->data;
        current->data = temp;

        // ��尡 �̵��� �� ���� ��� (silent�� 0�� ���� ���)
        if (!silent) {
            printInOrder(*root);
            printf("\n");
        }

        current = parent;
        parent = findParent(*root, current);
    }
}

// �ִ� ���� Ʈ������ ��Ʈ ��� ����
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

    // ��� �̵� ������ ���
    printInOrder(*root);
    printf("\n");

    // �ִ� ���� ������ �����ϱ� ���� ��������� ��� ��ȯ
    TreeNode* current = *root;
    while (current->left || current->right) {
        if (current->right == NULL || (current->left && current->left->data > current->right->data)) {
            if (current->data < current->left->data) {
                (*moveCount)++;
                int temp = current->data;
                current->data = current->left->data;
                current->left->data = temp;

                // ��尡 �̵��� �� ���� ���
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

                // ��尡 �̵��� �� ���� ���
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

// Ʈ�� ������ ���
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

// Ʈ�� �޸� ����
void freeTree(TreeNode* root) {
    if (root == NULL) return;
    freeTree(root->left);
    freeTree(root->right);
    free(root);
}

// ����� �������̽� ����
void runUserInterface(TreeNode* root) {
    char choice;
    int value;
    int moveCount;
    printf("\ni : ��� �߰�\n");
    printf("d : ��� ����\n");
    printf("p : ������ ���\n");
    printf("c : ����\n");
    while (1) {

        printf("�޴� �Է�: ");
        scanf(" %c", &choice);

        switch (choice) {
        case 'i':
            printf("�߰��� �� �Է�: ");
            scanf("%d", &value);
            moveCount = 0;
            insertMaxHeapTree(&root, value, &moveCount, 0); // ����� ���� �� ���
            printf("��尡 �̵��� Ƚ��: %d\n", moveCount);
            break;

        case 'd':
            moveCount = 0;
            deleteMaxHeapTree(&root, &moveCount);
            printf("��尡 �̵��� Ƚ��: %d\n", moveCount);
            break;

        case 'p':
            printf("Ʈ�� ������ ���\n");
            printLevelOrder(root);
            break;

        case 'c':
            freeTree(root);
            return;

        default:
            printf("��ȿ���� ���� �Է��Դϴ�.\n");
            break;
        }
    }
}

// �־��� ������ �迭�� �̿��Ͽ� �ִ� ���� Ʈ�� ����
TreeNode* generateMaxHeapTree(int inputData[], int size) {
    TreeNode* root = NULL;
    int moveCount = 0;
    for (int i = 0; i < size; i++) {
        insertMaxHeapTree(&root, inputData[i], &moveCount, 1); // Ʈ�� ���� �� silent ���� ��� ����
    }
    return root;
}