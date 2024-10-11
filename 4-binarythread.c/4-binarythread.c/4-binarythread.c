#include <stdio.h>
#include <stdlib.h>
#include "4-binarythread.h"

// ���� Ž�� Ʈ���� ������ ����
TreeNode* InsertToBST(TreeNode* root, int data) {
    if (root == NULL) {
        root = (TreeNode*)malloc(sizeof(TreeNode));
        root->data = data;
        root->left = NULL;
        root->right = NULL;
    }
    else if (data < root->data) {
        root->left = InsertToBST(root->left, data);
    }
    else {
        root->right = InsertToBST(root->right, data);
    }
    return root;
}

// ���� Ʈ�� ����
TreeNode* GenerateBinaryTree(int inputData[], int size) {
    TreeNode* root = NULL;
    for (int i = 0; i < size; i++) {
        root = InsertToBST(root, inputData[i]);
    }
    return root;
}

// ���� Ʈ�� ���� ��ȸ
void BinaryTreeInOrder(TreeNode* root) {
    if (root != NULL) {
        BinaryTreeInOrder(root->left);
        printf("%d ", root->data);
        BinaryTreeInOrder(root->right);
    }
}

// ������ ���� Ʈ���� ��ȯ
void ConvertToThreaded(TreeNode* root, ThreadNode** prev) {
    if (root == NULL) return;

    ConvertToThreaded(root->left, prev);

    ThreadNode* current = (ThreadNode*)malloc(sizeof(ThreadNode));
    current->data = root->data;
    current->left = *prev;
    current->right = NULL;
    current->is_thread = 1;

    if (*prev != NULL && (*prev)->right == NULL) {
        (*prev)->right = current;
        (*prev)->is_thread = 1;
    }

    *prev = current;

    ConvertToThreaded(root->right, prev);
}

// ������ ���� Ʈ�� ����
ThreadNode* GenerateThreadTree(int inputData[], int size) {
    TreeNode* bstRoot = GenerateBinaryTree(inputData, size);
    ThreadNode* prev = NULL;
    ConvertToThreaded(bstRoot, &prev);
    free_binary_tree(bstRoot);  // ���� Ʈ�� �޸� ����
    return prev;
}

// ������ ���� Ʈ�� ���� ��ȸ
void ThreadTreeInOrder(ThreadNode* root) {
    ThreadNode* current = root;
    while (current != NULL) {
        while (current->left != NULL) {
            current = current->left;
        }
        printf("%d ", current->data);

        while (current->is_thread && current->right != NULL) {
            current = current->right;
            printf("%d ", current->data);
        }
        current = current->right;
    }
}

// ���� Ʈ�� �޸� ����
void free_binary_tree(TreeNode* root) {
    if (root == NULL) return;
    free_binary_tree(root->left);
    free_binary_tree(root->right);
    free(root);
}

// ������ ���� Ʈ�� �޸� ����
void free_thread_tree(ThreadNode* root) {
    if (root == NULL) return;
    free_thread_tree(root->left);
    if (!root->is_thread) free_thread_tree(root->right);
    free(root);
}

// ���� �Լ�
int main() {
    int inputData[] = { 4, 1, 9, 13, 15, 3, 6, 14, 7, 10, 12, 2, 5, 8, 11 };
    int size = sizeof(inputData) / sizeof(inputData[0]);

    TreeNode* root = GenerateBinaryTree(inputData, size);
    printf("Binary Tree In-order Traversal: ");
    BinaryTreeInOrder(root);
    printf("\n");

    ThreadNode* troot = GenerateThreadTree(inputData, size);
    printf("Threaded Tree In-order Traversal: ");
    ThreadTreeInOrder(troot);
    printf("\n");

    free_binary_tree(root);  // ���� Ʈ�� �޸� ����
    free_thread_tree(troot);  // ������ ���� Ʈ�� �޸� ����

    return 0;
}
