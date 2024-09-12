#include <stdio.h>
#include <stdlib.h>

// 이진 트리 노드 구조체
typedef struct TreeNode {
    int data;
    struct TreeNode* left;
    struct TreeNode* right;
} TreeNode;

// 스택 노드 구조체
typedef struct StackNode {
    TreeNode* treeNode;
    struct StackNode* next;
} StackNode;

// 스택 구조체
typedef struct Stack {
    StackNode* top;
} Stack;

// 스택 초기화
void initStack(Stack* stack) {
    stack->top = NULL;
}

// 스택에 노드 추가
void push(Stack* stack, TreeNode* node) {
    StackNode* newNode = (StackNode*)malloc(sizeof(StackNode));
    newNode->treeNode = node;
    newNode->next = stack->top;
    stack->top = newNode;
    printf("push(%d) ", node->data);
}

// 스택에서 노드 제거
TreeNode* pop(Stack* stack) {
    if (stack->top == NULL) return NULL;
    StackNode* temp = stack->top;
    TreeNode* node = temp->treeNode;
    stack->top = temp->next;
    printf("pop(%d) ", node->data); // 수정된 부분
    free(temp);
    return node;
}

// 스택이 비어있는지 확인
int isStackEmpty(Stack* stack) {
    return stack->top == NULL;
}

// 이진 트리 노드 생성
TreeNode* CreateNode(int data) {
    TreeNode* newNode = (TreeNode*)malloc(sizeof(TreeNode));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// 노드 추가
void PlaceNode(TreeNode* node, int direction, int data) {
    if (direction == 0) {
        node->left = CreateNode(data);
    }
    else {
        node->right = CreateNode(data);
    }
}

// 이진 트리 생성
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

// 전위 순회
void LinkPreOrder(TreeNode* root) {
    Stack stack;
    initStack(&stack);
    push(&stack, root);

    while (!isStackEmpty(&stack)) {
        TreeNode* node = pop(&stack);
        if (node != NULL) {
            Visit(node->data);
            if (node->right != NULL) push(&stack, node->right);
            if (node->left != NULL) push(&stack, node->left);
        }
    }
}

// 중위 순회
void LinkInOrder(TreeNode* root) {
    Stack stack;
    initStack(&stack);
    TreeNode* current = root;

    while (current != NULL || !isStackEmpty(&stack)) {
        while (current != NULL) {
            push(&stack, current);
            current = current->left;
        }
        current = pop(&stack);
        Visit(current->data);
        current = current->right;
    }
}

// 후위 순회
void LinkPostOrder(TreeNode* root) {
    Stack stack1, stack2;
    initStack(&stack1);
    initStack(&stack2);
    push(&stack1, root);

    while (!isStackEmpty(&stack1)) {
        TreeNode* node = pop(&stack1);
        push(&stack2, node);
        if (node->left != NULL) push(&stack1, node->left);
        if (node->right != NULL) push(&stack1, node->right);
    }

    while (!isStackEmpty(&stack2)) {
        TreeNode* node = pop(&stack2);
        Visit(node->data);
    }
}

// 방문 함수
void Visit(int data) {
    printf("visit(%d) ", data);
}

// 각 순회 방식 출력
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
    GenerateLinkTree(root);

    LinkOrders(root);

    return 0;
}
