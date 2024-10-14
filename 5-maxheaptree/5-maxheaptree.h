#pragma once
#ifndef MAX_HEAP_H
#define MAX_HEAP_H

// 노드 구조체 정의
typedef struct TreeNode {
    int data;
    struct TreeNode* left;
    struct TreeNode* right;
} TreeNode;

// 함수 선언
TreeNode* createNode(int data);
void insertMaxHeapTree(TreeNode** root, int data, int* moveCount);
void deleteMaxHeapTree(TreeNode** root, int* moveCount);
void printLevelOrder(TreeNode* root);
void freeTree(TreeNode* root);
void runUserInterface(TreeNode* root);
TreeNode* generateMaxHeapTree(int inputData[], int size);

#endif // MAX_HEAP_H