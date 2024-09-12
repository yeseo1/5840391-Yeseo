#include <stdio.h>
#include <stdlib.h>

typedef struct TreeNode {
    int data;
    struct TreeNode* left;
    struct TreeNode* right;
} TreeNode;

TreeNode* CreateNode(int data) {
    TreeNode* newNode = (TreeNode*)malloc(sizeof(TreeNode));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

void PlaceNode(TreeNode* node, int direction, int data) {
    if (direction == 0) {
        node->left = CreateNode(data);
    }
    else {
        node->right = CreateNode(data);
    }
}

void GenerateLinkTree(TreeNode* root) {
    PlaceNode(root, 0, 2);
    PlaceNode(root, 1, 3);

    PlaceNode(root->left, 0, 4);
    PlaceNode(root->left, 1, 5);
    PlaceNode(root->right, 0, 6);
    PlaceNode(root->right, 1, 7);

    PlaceNode(root->left->left, 0, 8);
    PlaceNode(root->left->left, 1, 9);
    PlaceNode(root->left->right, 0, 10);
    PlaceNode(root->left->right, 1, 11);
    PlaceNode(root->right->left, 0, 12);
    PlaceNode(root->right->left, 1, 13);
    PlaceNode(root->right->right, 0, 14);
    PlaceNode(root->right->right, 1, 15);
}

void Push(int data) {
    printf("push(%d) ", data);
}

void Pop(int data) {
    printf("pop(%d) ", data);
}

void Visit(int data) {
    printf("visit(%d) ", data);
}

void LinkPreOrder(TreeNode* root) {
    if (root == NULL) return;
    Push(root->data);
    LinkPreOrder(root->left);
    LinkPreOrder(root->right);
}

void LinkInOrder(TreeNode* root) {
    if (root == NULL) return;
    LinkInOrder(root->left);
    Push(root->data);
    Pop(root->data);
    Visit(root->data);
    LinkInOrder(root->right);
}

void LinkPostOrder(TreeNode* root) {
    if (root == NULL) return;
    LinkPostOrder(root->left);
    LinkPostOrder(root->right);
    Push(root->data);
    Pop(root->data);
}

void LinkOrders(TreeNode* root) {
    printf("LinkedPreOrder: ");
    LinkPreOrder(root);
    printf("\n");

    printf("LinkedInOrder: ");
    LinkInOrder(root);
    printf("\n");

    printf("LinkedPostOrder: ");
    LinkPostOrder(root);
    printf("\n");
}

int main() {
    TreeNode* root = CreateNode(1);
    root->data = 1;

    GenerateLinkTree(root);

    LinkOrders(root);

    return 0;
}