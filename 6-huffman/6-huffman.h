#pragma once
#ifndef HUFFMAN_H
#define HUFFMAN_H

typedef struct Node {
    char character;
    int frequency;
    struct Node* left, * right;
} Node;

void GenerateHuffmanCodes(char characters[], int frequencies[], int size);
Node* buildHuffmanTree(char characters[], int frequencies[], int size);
void printCodes(Node* root, int arr[], int top);
void printHeap(int arr[], int size);
void freeTree(Node* root);

#endif // HUFFMAN_H
