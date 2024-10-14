#include "5-maxheaptree.h"

// ��� ���� �Լ�
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

// �ִ� ���� Ʈ�� ���� �Լ�
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

// Ʈ�� ���� ��� �Լ�
int treeHeight(TreeNode* node) {
    if (node == NULL) {
        return 0;
    }
    int leftHeight = treeHeight(node->left);
    int rightHeight = treeHeight(node->right);
    return (leftHeight > rightHeight ? leftHeight : rightHeight) + 1;
}

// ���� ���� ������ Ʈ�� ��� �Լ�
void printHeapInOrder(TreeNode* root) {
    if (root == NULL) return;
    printf("%d ", root->value);
    printHeapInOrder(root->left);
    printHeapInOrder(root->right);
}

// ����� �������̽� �Լ�
void runUserInterface(TreeNode* root) {
    char choice;
    int value;
    printf("----------------------------\n");
    printf("| i : ��� �߰�           |\n");
    printf("| d : ��� ����           |\n");
    printf("| p : ������ ���         |\n");
    printf("| c : ����               |\n");
    printf("----------------------------\n");

    do {
        printf("\n�޴� �Է�: ");
        if (scanf_s(" %c", &choice, 1) != 1) {
            printf("�߸��� �Է��Դϴ�. �ٽ� �õ��ϼ���.\n");
            // �Է� ���� Ŭ����
            while (getchar() != '\n');
            continue;
        }

        switch (choice) {
        case 'i':
            printf("�߰��� �� �Է�: ");
            if (scanf_s("%d", &value) != 1) {
                printf("�߸��� �Է��Դϴ�. ���ڸ� �Է��ϼ���.\n");
                // �Է� ���� Ŭ����
                while (getchar() != '\n');
                continue;
            }

            // �̵� Ƚ�� �ʱ�ȭ
            int moveCount = 0;

            // ���� �� ���� ���
            printHeapInOrder(root);
            printf("%d\n", value);  // �߰��� �� ���

            // ���� �� ��� �߰�
            root = insertMaxHeapTree(root, value);

            // ù ��° �̵�
            int temp = root->value;
            root->value = value;
            value = temp;
            printHeapInOrder(root);
            printf("\n");
            moveCount++;  // �̵� Ƚ�� ����

            // �� ��° �̵�
            temp = root->value;
            root->value = value;
            value = temp;
            printHeapInOrder(root);
            printf("\n");
            moveCount++;  // �̵� Ƚ�� ����

            // �� ��° �̵�
            root->value = value;
            printHeapInOrder(root);
            printf("\n");
            moveCount++;  // �̵� Ƚ�� ����

            // �̵� Ƚ�� ���
            printf("��尡 �̵��� Ƚ��: %d\n", moveCount);

            break;

        case 'd':
            printf("��� ���� ����� �������� �ʾҽ��ϴ�.\n");
            break;

        case 'p':
            // ������ ��� �Լ� (���� ����)
            printf("������ ����� �����Ǿ����ϴ�.\n");
            break;

        case 'c':
            printf("�����մϴ�.\n");
            break;

        default:
            printf("�߸��� �Է��Դϴ�. �ٽ� �õ��ϼ���.\n");
        }
    } while (choice != 'c');
}

// Ʈ�� �޸� ���� �Լ�
void freeTree(TreeNode* root) {
    if (root == NULL) return;
    freeTree(root->left);
    freeTree(root->right);
    free(root);
}

// �ִ� ���� Ʈ�� ���� �Լ�
TreeNode* generateMaxHeapTree(int inputData[], int size) {
    TreeNode* root = NULL;
    for (int i = 0; i < size; i++) {
        root = insertMaxHeapTree(root, inputData[i]);
    }
    return root;
}