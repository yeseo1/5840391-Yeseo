#ifndef MAX_HEAP_TREE_H
#define MAX_HEAP_TREE_H

#include <stdio.h>
#include <stdlib.h>

typedef struct TreeNode {
    int data;
    struct TreeNode* left;
    struct TreeNode* right;
} TreeNode;

// 함수 선언
TreeNode* createNode(int data);
TreeNode* getLastNode(TreeNode* root);
TreeNode* findParent(TreeNode* root, TreeNode* node);
void printPreOrder(TreeNode* root);
void insertMaxHeapTree(TreeNode** root, int data, int* moveCount, int silent);
void deleteMaxHeapTree(TreeNode** root, int* moveCount);
void printLevelOrder(TreeNode* root);
void freeTree(TreeNode* root);
void runUserInterface(TreeNode* root);
TreeNode* generateMaxHeapTree(int inputData[], int size);

#endif // MAX_HEAP_TREE_H
