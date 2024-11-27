#include <stdio.h>
#include <stdlib.h>
#include "mergesort.h"

// 랜덤 배열 생성
void generateRandomArray(int array[]) {
    for (int i = 0; i < SIZE; i++) {
        array[i] = rand() % 1000; // 0 ~ 999 범위의 랜덤 값
    }
}

// 병합 함수
void merge(int array[], int left, int mid, int right) {
    int temp[SIZE];
    int i = left, j = mid + 1, k = left;

    // 병합 과정
    while (i <= mid && j <= right) {
        comparisonCount++;
        if (array[i] <= array[j]) {
            temp[k++] = array[i++];
        }
        else {
            temp[k++] = array[j++];
        }
        moveCount++;
    }

    while (i <= mid) {
        temp[k++] = array[i++];
        moveCount++;
    }

    while (j <= right) {
        temp[k++] = array[j++];
        moveCount++;
    }

    for (i = left; i <= right; i++) {
        array[i] = temp[i];
        moveCount++;
    }
}

// 반복적 합병정렬
void doMergeSort(int array[]) {
    int width, left, mid, right;
    int round = 0;

    for (width = 1; width < SIZE; width *= 2) {
        for (left = 0; left < SIZE - width; left += 2 * width) {
            mid = left + width - 1;
            right = (left + 2 * width - 1 < SIZE) ? left + 2 * width - 1 : SIZE - 1;
            merge(array, left, mid, right);
        }

        // 병합 과정 출력 (10번마다)
        if (round % 10 == 0) {
            // 처음 10개 값
            for (int i = 0; i < 10; i++) printf("%3d ", array[i]);
            printf("| ");
            // 중앙-1 ~ 중앙+10 값
            for (int i = SIZE / 2 - 1; i < SIZE / 2 + 10; i++) printf("%3d ", array[i]);
            printf("\n\n");
        }
    }
}

// 배열 출력
void printArray(int array[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%3d ", array[i]);
        if ((i + 1) % 10 == 0) printf("\n");
    }
}
