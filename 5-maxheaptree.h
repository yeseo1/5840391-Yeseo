#pragma once
#ifndef MAX_HEAP_TREE_H
#define MAX_HEAP_TREE_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// 트리 노드 구조체 정의
typedef struct TreeNode {
    int value;
    struct TreeNode* left;
    struct TreeNode* right;
} TreeNode;

// 함수 선언
TreeNode* createNode(int value);
TreeNode* insertMaxHeapTree(TreeNode* root, int value);
void printLevelOrder(TreeNode* root, int level);
int treeHeight(TreeNode* node);
void printHeapTree(TreeNode* root);
void printHeapInOrder(TreeNode* root);
void runUserInterface(TreeNode* root);
void freeTree(TreeNode* root);
TreeNode* generateMaxHeapTree(int inputData[], int size);

#endif // MAX_HEAP_TREE_H
