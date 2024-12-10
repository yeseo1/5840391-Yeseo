#ifndef TREE_H
#define TREE_H

typedef struct Node {
    int key;
    struct Node* left, * right;
    int height; // AVL Ʈ���� ���� ���� ����
} Node;

// ���� ���� ����
extern int compareCount;
extern int searchCount;

// BST ���� �Լ�
Node* bstInsert(Node* root, int key);
Node* bstDelete(Node* root, int key);
Node* bstSearch(Node* root, int key, int* compareCount);

// AVL Ʈ�� ���� �Լ�
Node* avlInsert(Node* root, int key);
Node* avlDelete(Node* root, int key);
Node* avlSearch(Node* root, int key, int* compareCount);

// ��ƿ��Ƽ �Լ�
void doBinaryBatch(Node* root);
void doAVLBatch(Node* root);
void freeTree(Node* root);
void printTree(Node* root, int level);

#endif
