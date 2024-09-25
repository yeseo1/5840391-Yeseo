#include <stdio.h>
#include <stdlib.h>

// 트리 노드 구조체 정의
typedef struct TreeNode {
    int data;
    struct TreeNode* left;
    struct TreeNode* right;
} TreeNode;

// 큐 구현 (BFS를 위한 큐 자료구조)
typedef struct QueueNode {
    TreeNode* treeNode;
    struct QueueNode* next;
} QueueNode;

typedef struct {
    QueueNode* front;
    QueueNode* rear;
} Queue;

void initQueue(Queue* q) {
    q->front = q->rear = NULL;
}

int isEmpty(Queue* q) {
    return q->front == NULL;
}

void push(Queue* q, TreeNode* treeNode) {
    QueueNode* newNode = (QueueNode*)malloc(sizeof(QueueNode));
    newNode->treeNode = treeNode;
    newNode->next = NULL;
    if (q->rear) {
        q->rear->next = newNode;
    }
    else {
        q->front = newNode;
    }
    q->rear = newNode;
}

TreeNode* pop(Queue* q) {
    if (isEmpty(q)) {
        return NULL;
    }
    QueueNode* temp = q->front;
    TreeNode* treeNode = temp->treeNode;
    q->front = q->front->next;
    if (q->front == NULL) {
        q->rear = NULL;
    }
    free(temp);
    return treeNode;
}

// 노드를 배치하는 함수
void PlaceNode(TreeNode* node, int direction, int data) {
    TreeNode* newNode = (TreeNode*)malloc(sizeof(TreeNode));
    newNode->data = data;
    newNode->left = newNode->right = NULL;

    if (direction == 0) {
        node->left = newNode;
    }
    else if (direction == 1) {
        node->right = newNode;
    }
}

// 트리 생성 함수
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

// 트리의 모든 노드 값을 더하는 함수
int GetSumOfNodes(TreeNode* root) {
    if (!root) return 0;

    int sum = 0;
    Queue q;
    initQueue(&q);
    push(&q, root);

    while (!isEmpty(&q)) {
        TreeNode* node = pop(&q);
        sum += node->data;

        if (node->left) push(&q, node->left);
        if (node->right) push(&q, node->right);
    }

    return sum;
}

// 트리의 전체 노드 수를 구하는 함수
int GetNumberOfNodes(TreeNode* root) {
    if (!root) return 0;

    int count = 0;
    Queue q;
    initQueue(&q);
    push(&q, root);

    while (!isEmpty(&q)) {
        TreeNode* node = pop(&q);
        count++;

        if (node->left) push(&q, node->left);
        if (node->right) push(&q, node->right);
    }

    return count;
}

// 트리의 높이를 구하는 함수
int GetHeightOfTree(TreeNode* root) {
    if (!root) return 0;

    int height = 0;
    Queue q;
    initQueue(&q);
    push(&q, root);

    while (!isEmpty(&q)) {
        int levelSize = 0;
        Queue tempQueue;
        initQueue(&tempQueue);

        while (!isEmpty(&q)) {
            TreeNode* node = pop(&q);
            if (node->left) push(&tempQueue, node->left);
            if (node->right) push(&tempQueue, node->right);
            levelSize++;
        }

        if (levelSize > 0) height++;

        q = tempQueue;  // Move to the next level
    }

    return height;
}

// 트리의 단말 노드(리프 노드) 수를 구하는 함수
int GetNumberOfLeafNodes(TreeNode* root) {
    if (!root) return 0;

    int leafCount = 0;
    Queue q;
    initQueue(&q);
    push(&q, root);

    while (!isEmpty(&q)) {
        TreeNode* node = pop(&q);

        if (!node->left && !node->right) {
            leafCount++;
        }

        if (node->left) push(&q, node->left);
        if (node->right) push(&q, node->right);
    }

    return leafCount;
}

int main() {
    TreeNode* root = (TreeNode*)malloc(sizeof(TreeNode));
    root->data = 1;
    root->left = root->right = NULL;

    // 트리 생성
    GenerateLinkTree(root);

    // 결과 출력
    printf("Sum of nodes: %d\n", GetSumOfNodes(root));
    printf("Number of nodes: %d\n", GetNumberOfNodes(root));
    printf("Height of Tree: %d\n", GetHeightOfTree(root));
    printf("Number of leaf nodes: %d\n", GetNumberOfLeafNodes(root));

    return 0;
}