#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "tree.h"

// ���� ���� ����
int compareCount = 0;
int searchCount = 0;

// ��� ���� �Լ�
Node* createNode(int key) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->key = key;
    node->left = node->right = NULL;
    node->height = 1; // AVL Ʈ���� ���� ���� �ʱ�ȭ
    return node;
}

// --- BST ���� �Լ� ---
Node* bstInsert(Node* root, int key) {
    if (root == NULL) return createNode(key);
    if (key < root->key)
        root->left = bstInsert(root->left, key);
    else if (key > root->key)
        root->right = bstInsert(root->right, key);
    return root;
}

Node* bstDelete(Node* root, int key) {
    if (root == NULL) return root;
    if (key < root->key)
        root->left = bstDelete(root->left, key);
    else if (key > root->key)
        root->right = bstDelete(root->right, key);
    else {
        if (root->left == NULL || root->right == NULL) {
            Node* temp = root->left ? root->left : root->right;
            free(root);
            return temp;
        }
        Node* temp = root->right;
        while (temp->left != NULL) temp = temp->left;
        root->key = temp->key;
        root->right = bstDelete(root->right, temp->key);
    }
    return root;
}

Node* bstSearch(Node* root, int key, int* compareCount) {
    (*compareCount)++;
    if (root == NULL || root->key == key) return root;
    if (key < root->key)
        return bstSearch(root->left, key, compareCount);
    return bstSearch(root->right, key, compareCount);
}

// --- AVL ���� �Լ� ---
int getHeight(Node* node) {
    return node ? node->height : 0;
}

int getBalance(Node* node) {
    return node ? getHeight(node->left) - getHeight(node->right) : 0;
}

Node* rightRotate(Node* y) {
    Node* x = y->left;
    Node* T2 = x->right;
    x->right = y;
    y->left = T2;
    y->height = 1 + ((getHeight(y->left) > getHeight(y->right)) ? getHeight(y->left) : getHeight(y->right));
    x->height = 1 + ((getHeight(x->left) > getHeight(x->right)) ? getHeight(x->left) : getHeight(x->right));
    return x;
}

Node* leftRotate(Node* x) {
    Node* y = x->right;
    Node* T2 = y->left;
    y->left = x;
    x->right = T2;
    x->height = 1 + ((getHeight(x->left) > getHeight(x->right)) ? getHeight(x->left) : getHeight(x->right));
    y->height = 1 + ((getHeight(y->left) > getHeight(y->right)) ? getHeight(y->left) : getHeight(y->right));
    return y;
}

Node* avlInsert(Node* root, int key) {
    if (root == NULL) return createNode(key);
    if (key < root->key)
        root->left = avlInsert(root->left, key);
    else if (key > root->key)
        root->right = avlInsert(root->right, key);
    else
        return root;

    root->height = 1 + ((getHeight(root->left) > getHeight(root->right)) ? getHeight(root->left) : getHeight(root->right));

    int balance = getBalance(root);
    if (balance > 1 && key < root->left->key)
        return rightRotate(root);
    if (balance < -1 && key > root->right->key)
        return leftRotate(root);
    if (balance > 1 && key > root->left->key) {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }
    if (balance < -1 && key < root->right->key) {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }
    return root;
}

Node* avlDelete(Node* root, int key) {
    if (root == NULL) return root;

    if (key < root->key)
        root->left = avlDelete(root->left, key);
    else if (key > root->key)
        root->right = avlDelete(root->right, key);
    else {
        if (root->left == NULL || root->right == NULL) {
            Node* temp = root->left ? root->left : root->right;
            free(root);
            return temp;
        }
        Node* temp = root->right;
        while (temp->left != NULL) temp = temp->left;
        root->key = temp->key;
        root->right = avlDelete(root->right, temp->key);
    }

    root->height = 1 + ((getHeight(root->left) > getHeight(root->right)) ?
        getHeight(root->left) : getHeight(root->right));

    int balance = getBalance(root);
    if (balance > 1 && getBalance(root->left) >= 0)
        return rightRotate(root);
    if (balance > 1 && getBalance(root->left) < 0) {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }
    if (balance < -1 && getBalance(root->right) <= 0)
        return leftRotate(root);
    if (balance < -1 && getBalance(root->right) > 0) {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }

    return root;
}

Node* avlSearch(Node* root, int key, int* compareCount) {
    (*compareCount)++;
    if (root == NULL || root->key == key) return root;
    if (key < root->key)
        return avlSearch(root->left, key, compareCount);
    return avlSearch(root->right, key, compareCount);
}

// --- Batch �۾� ---
void doBinaryBatch(Node* root) {
    for (int i = 0; i < 2000; i++) {
        int A = rand() % 10; // Ž�� ���� ����
        int B = rand() % 1000;
        if (A < 5) { // Ž�� ���� ����: 50%
            bstSearch(root, B, &compareCount);
            searchCount++;
        }
        else if (A < 8) { // ���� ���� ����: 30%
            root = bstInsert(root, B);
        }
        else { // ���� ���� ����: 20%
            root = bstDelete(root, B);
        }
    }
}

void doAVLBatch(Node* root) {
    for (int i = 0; i < 2000; i++) {
        int A = rand() % 10; // Ž�� ���� ����
        int B = rand() % 1000;
        if (A < 5) { // Ž�� ���� ����: 50%
            avlSearch(root, B, &compareCount);
            searchCount++;
        }
        else if (A < 8) { // ���� ���� ����: 30%
            root = avlInsert(root, B);
        }
        else { // ���� ���� ����: 20%
            root = avlDelete(root, B);
        }
    }
}

void freeTree(Node* root) {
    if (root == NULL) return;
    freeTree(root->left);
    freeTree(root->right);
    free(root);
}

void printTree(Node* root, int level) {
    if (root == NULL) return;
    printTree(root->right, level + 1);
    for (int i = 0; i < level; i++) printf("\t");
    printf("%d\n", root->key);
    printTree(root->left, level + 1);
}
