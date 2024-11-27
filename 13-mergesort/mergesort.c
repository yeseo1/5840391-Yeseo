#include <stdio.h>
#include <stdlib.h>
#include "mergesort.h"

// ���� �迭 ����
void generateRandomArray(int array[]) {
    for (int i = 0; i < SIZE; i++) {
        array[i] = rand() % 1000; // 0 ~ 999 ������ ���� ��
    }
}

// ���� �Լ�
void merge(int array[], int left, int mid, int right) {
    int temp[SIZE];
    int i = left, j = mid + 1, k = left;

    // ���� ����
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

// �ݺ��� �պ�����
void doMergeSort(int array[]) {
    int width, left, mid, right;
    int round = 0;

    for (width = 1; width < SIZE; width *= 2) {
        for (left = 0; left < SIZE - width; left += 2 * width) {
            mid = left + width - 1;
            right = (left + 2 * width - 1 < SIZE) ? left + 2 * width - 1 : SIZE - 1;
            merge(array, left, mid, right);
        }

        // ���� ���� ��� (10������)
        if (round % 10 == 0) {
            // ó�� 10�� ��
            for (int i = 0; i < 10; i++) printf("%3d ", array[i]);
            printf("| ");
            // �߾�-1 ~ �߾�+10 ��
            for (int i = SIZE / 2 - 1; i < SIZE / 2 + 10; i++) printf("%3d ", array[i]);
            printf("\n\n");
        }
    }
}

// �迭 ���
void printArray(int array[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%3d ", array[i]);
        if ((i + 1) % 10 == 0) printf("\n");
    }
}
