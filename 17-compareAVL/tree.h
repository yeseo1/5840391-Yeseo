#ifndef TREE_H
#define TREE_H

typedef struct Node {
    int key;
    struct Node* left, * right;
    int height; // AVL 트리를 위한 높이 정보
} Node;

// 전역 변수 선언
extern int compareCount;
extern int searchCount;

// BST 관련 함수
Node* bstInsert(Node* root, int key);
Node* bstDelete(Node* root, int key);
Node* bstSearch(Node* root, int key, int* compareCount);

// AVL 트리 관련 함수
Node* avlInsert(Node* root, int key);
Node* avlDelete(Node* root, int key);
Node* avlSearch(Node* root, int key, int* compareCount);

// 유틸리티 함수
void doBinaryBatch(Node* root);
void doAVLBatch(Node* root);
void freeTree(Node* root);
void printTree(Node* root, int level);

#endif
