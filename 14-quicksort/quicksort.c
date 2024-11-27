#include "QuickSort.h"
#include <stdio.h>
#include <stdlib.h>

int comparisonCount = 0;
int moveCount = 0;

// 랜덤 배열 생성
void generateRandomArray(int array[]) {
    for (int i = 0; i < SIZE; i++) {
        array[i] = rand() % 1000; // 0-999 범위
    }
}

// 배열 출력
void printArray(int array[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
}

// 배열의 특정 구간(40~60 위치) 출력
void printSubArray(int array[], int start, int end) {
    for (int i = start; i < end; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
}

// 파티션 함수
int partition(int array[], int low, int high) {
    int pivot = array[high];
    int i = low - 1;

    for (int j = low; j < high; j++) {
        comparisonCount++;
        if (array[j] <= pivot) {
            i++;
            int temp = array[i];
            array[i] = array[j];
            array[j] = temp;
            moveCount += 3;
        }
    }

    int temp = array[i + 1];
    array[i + 1] = array[high];
    array[high] = temp;
    moveCount += 3;

    return i + 1;
}

// 반복적 퀵 정렬
void doQuickSort(int array[], int low, int high) {
    int stack[SIZE];
    int top = -1;

    stack[++top] = low;
    stack[++top] = high;

    int rounds = 0; // 정렬 단계 추적

    while (top >= 0) {
        high = stack[top--];
        low = stack[top--];

        int p = partition(array, low, high);

        // 정렬 과정 출력: 같은 상태를 반복하지 않도록
        if (rounds % 10 == 0) {
            printSubArray(array, 40, 60);
        }
        rounds++;

        if (p - 1 > low) {
            stack[++top] = low;
            stack[++top] = p - 1;
        }
        if (p + 1 < high) {
            stack[++top] = p + 1;
            stack[++top] = high;
        }
    }
}
