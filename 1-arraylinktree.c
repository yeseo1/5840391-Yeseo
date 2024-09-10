#include <stdio.h>
#include <stdlib.h>

// Ʈ�� ��带 ���� ����ü ���� (��ũ ��� Ʈ��)
typedef struct TreeNode {
    int data;
    struct TreeNode* left;
    struct TreeNode* right;
} TreeNode;

// �迭 ��� Ʈ�� ����
void GenerateArrayTree(int* tree) {
    int list[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15 };  // Ʈ�� ��� ��

    for (int i = 0; i < 15; i++) {
        tree[i] = list[i];
    }

    // �迭 ��� Ʈ�� ���
    printf("Array-based Tree: ");
    for (int i = 0; i < 15; i++) {
        printf("%d ", tree[i]);
    }
    printf("\n\n");  // ��� �� �� �� ����
}

// ���� ��ȸ (Pre-order) - �迭 ���
void arraypreorder(int* tree, int index) {
    if (index >= 15) return;
    printf("%d ", tree[index]);
    arraypreorder(tree, 2 * index + 1);
    arraypreorder(tree, 2 * index + 2);
}

// ���� ��ȸ (In-order) - �迭 ���
void arrayinorder(int* tree, int index) {
    if (index >= 15) return;
    arrayinorder(tree, 2 * index + 1);
    printf("%d ", tree[index]);
    arrayinorder(tree, 2 * index + 2);
}

// ���� ��ȸ (Post-order) - �迭 ���
void arraypostorder(int* tree, int index) {
    if (index >= 15) return;
    arraypostorder(tree, 2 * index + 1);
    arraypostorder(tree, 2 * index + 2);
    printf("%d ", tree[index]);
}

// �迭 ��� Ʈ�� ��ȸ ȣ��
void arrayorders(int* tree) {
    printf("Array Pre-order: ");
    arraypreorder(tree, 0);
    printf("\n");

    printf("Array In-order: ");
    arrayinorder(tree, 0);
    printf("\n");

    printf("Array Post-order: ");
    arraypostorder(tree, 0);
    printf("\n\n");  // ��ȸ ��� ��� �� �� �� ����
}

// ��� ���� �Լ� (��ũ ��� Ʈ��)
TreeNode* createNode(int data) {
    TreeNode* newNode = (TreeNode*)malloc(sizeof(TreeNode));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// ��带 �ش� ��ġ�� ��ġ�ϴ� �Լ�
void placenode(TreeNode* node, int direction, TreeNode* newNode) {
    if (direction == 0) {
        node->left = newNode;
    }
    else {
        node->right = newNode;
    }
}

// ��ũ ��� Ʈ�� ����
TreeNode* GenerateLinkTree() {
    TreeNode* root = createNode(1);
    placenode(root, 0, createNode(2));  // ���� �ڽ�
    placenode(root, 1, createNode(3));  // ������ �ڽ�

    // 2�� �ڽ�
    placenode(root->left, 0, createNode(4));
    placenode(root->left, 1, createNode(5));

    // 3�� �ڽ�
    placenode(root->right, 0, createNode(6));
    placenode(root->right, 1, createNode(7));

    // 4�� �ڽ�
    placenode(root->left->left, 0, createNode(8));
    placenode(root->left->left, 1, createNode(9));

    // 5�� �ڽ�
    placenode(root->left->right, 0, createNode(10));
    placenode(root->left->right, 1, createNode(11));

    // 6�� �ڽ�
    placenode(root->right->left, 0, createNode(12));
    placenode(root->right->left, 1, createNode(13));

    // 7�� �ڽ�
    placenode(root->right->right, 0, createNode(14));
    placenode(root->right->right, 1, createNode(15));

    return root;
}

// ���� ��ȸ (Pre-order) - ��ũ ���
void linkpreorder(TreeNode* node) {
    if (node == NULL) return;
    printf("%d ", node->data);
    linkpreorder(node->left);
    linkpreorder(node->right);
}

// ���� ��ȸ (In-order) - ��ũ ���
void linkinorder(TreeNode* node) {
    if (node == NULL) return;
    linkinorder(node->left);
    printf("%d ", node->data);
    linkinorder(node->right);
}

// ���� ��ȸ (Post-order) - ��ũ ���
void linkpostorder(TreeNode* node) {
    if (node == NULL) return;
    linkpostorder(node->left);
    linkpostorder(node->right);
    printf("%d ", node->data);
}

// ��ũ ��� Ʈ�� ��ȸ ȣ��
void linkorders(TreeNode* root) {
    printf("Link Pre-order: ");
    linkpreorder(root);
    printf("\n");

    printf("Link In-order: ");
    linkinorder(root);
    printf("\n");

    printf("Link Post-order: ");
    linkpostorder(root);
    printf("\n\n");  // ��ȸ ��� ��� �� �� �� ����
}

int main() {
    int arr[15];

    // �迭 ��� Ʈ�� ���� �� ��ȸ
    GenerateArrayTree(arr);
    arrayorders(arr);

    // ��ũ ��� Ʈ�� ���� �� ��ȸ
    TreeNode* root = GenerateLinkTree();
    linkorders(root);

    return 0;
}