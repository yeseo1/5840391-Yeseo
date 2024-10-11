#pragma once
#define MAX_SIZE 100

typedef struct TreeNode {
    int data;
    struct TreeNode* left;
    struct TreeNode* right;
} TreeNode;

typedef struct ThreadNode {
    int data;
    struct ThreadNode* left;
    struct ThreadNode* right;
    int is_thread;  // ���������� ���θ� ��Ÿ��
} ThreadNode;

extern void free_binary_tree(TreeNode* root);
extern void free_thread_tree(ThreadNode* root);
