#include <stdio.h>
#include "6-sortbyheap.h"

// 최대 힙을 구성하는 함수
void BuildMaxHeap(int inputData[], int n) {
    for (int i = n / 2 - 1; i >= 0; i--) {
        resortHeap(inputData, n, i);
    }
}

// 힙 정렬 함수
void BuildMaxHeapAndSort(int inputData[], int n) {
    BuildMaxHeap(inputData, n);

    for (int i = n - 1; i > 0; i--) {
        swap(&inputData[0], &inputData[i]);
        resortHeap(inputData, i, 0);

        // 힙 재정렬 후 상태 출력
        for (int j = 0; j < i; j++) {
            printf("%d ", inputData[j]);
        }
        printf("\n");
    }
}

// 힙을 재정렬하는 함수
void resortHeap(int inputData[], int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && inputData[left] > inputData[largest]) {
        largest = left;
    }
    if (right < n && inputData[right] > inputData[largest]) {
        largest = right;
    }
    if (largest != i) {
        swap(&inputData[i], &inputData[largest]);
        resortHeap(inputData, n, largest);
    }
}

// 두 값을 교환하는 함수
void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}
