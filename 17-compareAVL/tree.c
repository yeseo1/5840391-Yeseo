#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "tree.h"

// 전역 변수 정의
int compareCount = 0;  // 탐색 시 비교 횟수를 누적하는 변수
int searchCount = 0;   // 탐색 연산 횟수를 누적하는 변수

// 노드 생성 함수
Node* createNode(int key) {
    Node* node = (Node*)malloc(sizeof(Node));  // 새로운 노드를 동적으로 생성
    node->key = key;  // 노드의 키 값 설정
    node->left = node->right = NULL;  // 좌우 자식 노드는 NULL로 초기화
    node->height = 1;  // AVL 트리를 위한 높이 초기화 (초기에는 1)
    return node;  // 생성된 노드 반환
}

// --- BST 관련 함수 ---

// 이진 탐색 트리에 새로운 노드 삽입
Node* bstInsert(Node* root, int key) {
    if (root == NULL) return createNode(key);  // 빈 노드에 삽입
    if (key < root->key)  // 삽입할 값이 현재 노드의 값보다 작으면 왼쪽 자식으로
        root->left = bstInsert(root->left, key);
    else if (key > root->key)  // 삽입할 값이 현재 노드의 값보다 크면 오른쪽 자식으로
        root->right = bstInsert(root->right, key);
    return root;  // 삽입 후 루트 반환
}

// 이진 탐색 트리에서 노드 삭제
Node* bstDelete(Node* root, int key) {
    if (root == NULL) return root;  // 트리가 비어있으면 그대로 반환
    if (key < root->key)  // 삭제할 값이 현재 노드의 값보다 작으면 왼쪽 서브트리로
        root->left = bstDelete(root->left, key);
    else if (key > root->key)  // 삭제할 값이 현재 노드의 값보다 크면 오른쪽 서브트리로
        root->right = bstDelete(root->right, key);
    else {  // 삭제할 노드를 찾았을 때
        if (root->left == NULL || root->right == NULL) {  // 자식이 하나 또는 없을 때
            Node* temp = root->left ? root->left : root->right;  // 자식이 하나만 있을 경우 그 자식을 반환
            free(root);  // 노드 메모리 해제
            return temp;  // 자식 노드를 반환
        }
        // 두 자식이 모두 있을 때: 후속 순회하여 오른쪽 자식 중 가장 작은 값으로 교체
        Node* temp = root->right;
        while (temp->left != NULL) temp = temp->left;
        root->key = temp->key;  // 오른쪽 서브트리에서 가장 작은 값으로 교체
        root->right = bstDelete(root->right, temp->key);  // 교체 후 삭제
    }
    return root;
}

// 이진 탐색 트리에서 특정 키를 탐색하며 비교 횟수 누적
Node* bstSearch(Node* root, int key, int* compareCount) {
    (*compareCount)++;  // 비교 횟수 증가
    if (root == NULL || root->key == key) return root;  // 노드를 찾거나 트리가 비었을 때 종료
    if (key < root->key)  // 탐색할 값이 현재 노드의 값보다 작으면 왼쪽 자식으로
        return bstSearch(root->left, key, compareCount);
    return bstSearch(root->right, key, compareCount);  // 크면 오른쪽 자식으로
}

// --- AVL 관련 함수 ---

// AVL 트리에서 노드의 높이 계산
int getHeight(Node* node) {
    return node ? node->height : 0;  // 노드가 NULL이면 0, 아니면 노드의 높이 반환
}

// AVL 트리에서 균형 인덱스 계산 (좌우 서브트리의 높이 차)
int getBalance(Node* node) {
    return node ? getHeight(node->left) - getHeight(node->right) : 0;  // 왼쪽 서브트리의 높이 - 오른쪽 서브트리의 높이
}

// AVL 트리에서 오른쪽 회전
Node* rightRotate(Node* y) {
    Node* x = y->left;
    Node* T2 = x->right;
    x->right = y;
    y->left = T2;
    // 높이 업데이트
    y->height = 1 + ((getHeight(y->left) > getHeight(y->right)) ? getHeight(y->left) : getHeight(y->right));
    x->height = 1 + ((getHeight(x->left) > getHeight(x->right)) ? getHeight(x->left) : getHeight(x->right));
    return x;  // 회전 후 새 루트 반환
}

// AVL 트리에서 왼쪽 회전
Node* leftRotate(Node* x) {
    Node* y = x->right;
    Node* T2 = y->left;
    y->left = x;
    x->right = T2;
    // 높이 업데이트
    x->height = 1 + ((getHeight(x->left) > getHeight(x->right)) ? getHeight(x->left) : getHeight(x->right));
    y->height = 1 + ((getHeight(y->left) > getHeight(y->right)) ? getHeight(y->left) : getHeight(y->right));
    return y;  // 회전 후 새 루트 반환
}

// AVL 트리에서 노드 삽입
Node* avlInsert(Node* root, int key) {
    if (root == NULL) return createNode(key);  // 트리가 비었으면 새 노드 삽입
    if (key < root->key)
        root->left = avlInsert(root->left, key);
    else if (key > root->key)
        root->right = avlInsert(root->right, key);
    else
        return root;  // 중복된 키는 삽입하지 않음

    // 높이 업데이트
    root->height = 1 + ((getHeight(root->left) > getHeight(root->right)) ? getHeight(root->left) : getHeight(root->right));

    // 균형 상태 확인
    int balance = getBalance(root);
    if (balance > 1 && key < root->left->key)
        return rightRotate(root);  // 좌측 회전
    if (balance < -1 && key > root->right->key)
        return leftRotate(root);  // 우측 회전
    if (balance > 1 && key > root->left->key) {
        root->left = leftRotate(root->left);  // 좌측 회전 후 우측 회전
        return rightRotate(root);
    }
    if (balance < -1 && key < root->right->key) {
        root->right = rightRotate(root->right);  // 우측 회전 후 좌측 회전
        return leftRotate(root);
    }

    return root;
}

// AVL 트리에서 노드 삭제
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

    root->height = 1 + ((getHeight(root->left) > getHeight(root->right)) ? getHeight(root->left) : getHeight(root->right));

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

// AVL 트리에서 특정 키를 탐색하며 비교 횟수 누적
Node* avlSearch(Node* root, int key, int* compareCount) {
    (*compareCount)++;  // 비교 횟수 증가
    if (root == NULL || root->key == key) return root;
    if (key < root->key)
        return avlSearch(root->left, key, compareCount);
    return avlSearch(root->right, key, compareCount);
}

// --- Batch 작업 ---
// 이진 탐색 트리에서 2000번의 작업을 수행
void doBinaryBatch(Node* root) {
    for (int i = 0; i < 2000; i++) {
        int A = rand() % 10; // 0~9 사이 난수 발생
        int B = rand() % 1000;

        if (A < 5) {  // 탐색 연산 비율: 50%
            bstSearch(root, B, &compareCount);
            searchCount++;
        }
        else if (A < 8) {  // 삽입 연산 비율: 30%
            root = bstInsert(root, B);
        }
        else {  // 삭제 연산 비율: 20%
            root = bstDelete(root, B);
        }
    }
}

// AVL 트리에서 2000번의 작업을 수행
void doAVLBatch(Node* root) {
    for (int i = 0; i < 2000; i++) {
        int A = rand() % 10; // 0~9 사이 난수 발생
        int B = rand() % 1000;

        if (A < 5) {  // 탐색 연산 비율: 50%
            avlSearch(root, B, &compareCount);
            searchCount++;
        }
        else if (A < 8) {  // 삽입 연산 비율: 30%
            root = avlInsert(root, B);
        }
        else {  // 삭제 연산 비율: 20%
            root = avlDelete(root, B);
        }
    }
}

// 트리 메모리 해제 함수
void freeTree(Node* root) {
    if (root == NULL) return;
    freeTree(root->left);
    freeTree(root->right);
    free(root);
}

// 트리 구조를 출력하는 디버깅용 함수
void printTree(Node* root, int level) {
    if (root == NULL) return;
    printTree(root->right, level + 1);
    for (int i = 0; i < level; i++) printf("\t");
    printf("%d\n", root->key);
    printTree(root->left, level + 1);
}
