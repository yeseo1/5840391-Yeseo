#include <stdio.h>
#include <stdlib.h>

// 트리 노드를 위한 구조체 정의 (링크 기반 트리)
typedef struct TreeNode {
    int data;
    struct TreeNode* left;
    struct TreeNode* right;
} TreeNode;

// 배열 기반 트리 생성
void GenerateArrayTree(int* tree) {
    int list[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15 };  // 트리 노드 값

    for (int i = 0; i < 15; i++) {
        tree[i] = list[i];
    }

    // 배열 기반 트리 출력
    printf("Array-based Tree: ");
    for (int i = 0; i < 15; i++) {
        printf("%d ", tree[i]);
    }
    printf("\n\n");  // 출력 후 한 줄 띄우기
}

// 전위 순회 (Pre-order) - 배열 기반
void arraypreorder(int* tree, int index) {
    if (index >= 15) return;
    printf("%d ", tree[index]);
    arraypreorder(tree, 2 * index + 1);
    arraypreorder(tree, 2 * index + 2);
}

// 중위 순회 (In-order) - 배열 기반
void arrayinorder(int* tree, int index) {
    if (index >= 15) return;
    arrayinorder(tree, 2 * index + 1);
    printf("%d ", tree[index]);
    arrayinorder(tree, 2 * index + 2);
}

// 후위 순회 (Post-order) - 배열 기반
void arraypostorder(int* tree, int index) {
    if (index >= 15) return;
    arraypostorder(tree, 2 * index + 1);
    arraypostorder(tree, 2 * index + 2);
    printf("%d ", tree[index]);
}

// 배열 기반 트리 순회 호출
void arrayorders(int* tree) {
    printf("Array Pre-order: ");
    arraypreorder(tree, 0);
    printf("\n");

    printf("Array In-order: ");
    arrayinorder(tree, 0);
    printf("\n");

    printf("Array Post-order: ");
    arraypostorder(tree, 0);
    printf("\n\n");  // 순회 결과 출력 후 한 줄 띄우기
}

// 노드 생성 함수 (링크 기반 트리)
TreeNode* createNode(int data) {
    TreeNode* newNode = (TreeNode*)malloc(sizeof(TreeNode));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// 노드를 해당 위치에 배치하는 함수
void placenode(TreeNode* node, int direction, TreeNode* newNode) {
    if (direction == 0) {
        node->left = newNode;
    }
    else {
        node->right = newNode;
    }
}

// 링크 기반 트리 생성
TreeNode* GenerateLinkTree() {
    TreeNode* root = createNode(1);
    placenode(root, 0, createNode(2));  // 왼쪽 자식
    placenode(root, 1, createNode(3));  // 오른쪽 자식

    // 2의 자식
    placenode(root->left, 0, createNode(4));
    placenode(root->left, 1, createNode(5));

    // 3의 자식
    placenode(root->right, 0, createNode(6));
    placenode(root->right, 1, createNode(7));

    // 4의 자식
    placenode(root->left->left, 0, createNode(8));
    placenode(root->left->left, 1, createNode(9));

    // 5의 자식
    placenode(root->left->right, 0, createNode(10));
    placenode(root->left->right, 1, createNode(11));

    // 6의 자식
    placenode(root->right->left, 0, createNode(12));
    placenode(root->right->left, 1, createNode(13));

    // 7의 자식
    placenode(root->right->right, 0, createNode(14));
    placenode(root->right->right, 1, createNode(15));

    return root;
}

// 전위 순회 (Pre-order) - 링크 기반
void linkpreorder(TreeNode* node) {
    if (node == NULL) return;
    printf("%d ", node->data);
    linkpreorder(node->left);
    linkpreorder(node->right);
}

// 중위 순회 (In-order) - 링크 기반
void linkinorder(TreeNode* node) {
    if (node == NULL) return;
    linkinorder(node->left);
    printf("%d ", node->data);
    linkinorder(node->right);
}

// 후위 순회 (Post-order) - 링크 기반
void linkpostorder(TreeNode* node) {
    if (node == NULL) return;
    linkpostorder(node->left);
    linkpostorder(node->right);
    printf("%d ", node->data);
}

// 링크 기반 트리 순회 호출
void linkorders(TreeNode* root) {
    printf("Link Pre-order: ");
    linkpreorder(root);
    printf("\n");

    printf("Link In-order: ");
    linkinorder(root);
    printf("\n");

    printf("Link Post-order: ");
    linkpostorder(root);
    printf("\n\n");  // 순회 결과 출력 후 한 줄 띄우기
}

int main() {
    int arr[15];

    // 배열 기반 트리 생성 및 순회
    GenerateArrayTree(arr);
    arrayorders(arr);

    // 링크 기반 트리 생성 및 순회
    TreeNode* root = GenerateLinkTree();
    linkorders(root);

    return 0;
}