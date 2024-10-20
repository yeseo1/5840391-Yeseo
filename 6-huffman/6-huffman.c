#include <stdio.h>
#include <stdlib.h>
#include "6-huffman.h"

Node* createNode(char character, int frequency) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (!newNode) {
        fprintf(stderr, "Memory allocation failed for node\n");
        exit(EXIT_FAILURE);
    }
    newNode->character = character;
    newNode->frequency = frequency;
    newNode->left = newNode->right = NULL;
    return newNode;
}

Node* extractMin(Node* nodes[], int* size) {
    int minIndex = 0;
    for (int i = 1; i < *size; i++) {
        if (nodes[i]->frequency < nodes[minIndex]->frequency) {
            minIndex = i;
        }
    }
    Node* minNode = nodes[minIndex];
    nodes[minIndex] = nodes[--(*size)];
    return minNode;
}

Node* buildHuffmanTree(char characters[], int frequencies[], int size) {
    Node* nodes[100];
    int nodeCount = size;

    for (int i = 0; i < size; i++) {
        nodes[i] = createNode(characters[i], frequencies[i]);
    }

    while (nodeCount > 1) {
        Node* left = extractMin(nodes, &nodeCount);
        Node* right = extractMin(nodes, &nodeCount);

        Node* combinedNode = createNode('\0', left->frequency + right->frequency);
        combinedNode->left = left;
        combinedNode->right = right;

        nodes[nodeCount++] = combinedNode;

        // 빈도 수 출력
        printHeap(frequencies, nodeCount);
        printf("// %d + %d -> %d\n", left->frequency, right->frequency, combinedNode->frequency);
    }

    return nodes[0];
}

void printHeap(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void GenerateHuffmanCodes(char characters[], int frequencies[], int size) {
    Node* root = buildHuffmanTree(characters, frequencies, size);
    if (root == NULL) {
        fprintf(stderr, "Failed to build Huffman Tree\n");
        return;
    }

    int* arr = (int*)malloc(size * sizeof(int));
    if (arr == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        return;
    }

    int top = 0;
    printf("\nHuffman Codes:\n");
    printCodes(root, arr, top);
    free(arr);
    freeTree(root); // 트리 메모리 해제
}

void printCodes(Node* root, int arr[], int top) {
    if (root->left) {
        arr[top] = 0;
        printCodes(root->left, arr, top + 1);
    }

    if (root->right) {
        arr[top] = 1;
        printCodes(root->right, arr, top + 1);
    }

    if (!(root->left) && !(root->right)) {
        printf("%c: ", root->character);
        for (int i = 0; i < top; i++) {
            printf("%d", arr[i]);
        }
        printf("\n");
    }
}

void freeTree(Node* root) {
    if (root) {
        freeTree(root->left);
        freeTree(root->right);
        free(root);
    }
}
