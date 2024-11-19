// sorting.c
#include "sorting.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// ���� ������ ���� �Լ�
void generateRandomData(int arr[]) {
    for (int i = 0; i < SIZE; i++) {
        arr[i] = rand() % 1000;  // 0���� 999 ������ ���� ����
    }
}

// ���� ���� �Լ� (10~20 ������ ���)
void selectionSort(int arr[]) {
    int i, j, minIdx, temp;
    printf("Selection Sort:\n");
    for (i = 0; i < SIZE - 1; i++) {
        minIdx = i;
        for (j = i + 1; j < SIZE; j++) {
            if (arr[j] < arr[minIdx]) {
                minIdx = j;
            }
        }
        // ��� ��ȯ
        temp = arr[i];
        arr[i] = arr[minIdx];
        arr[minIdx] = temp;

        // 10���� Ȧ�� ���븸
        if (i % 10 == 0 && i % 20 == 10) {
            printf("Step %d: ", i);
            for (int k = 0; k < SIZE; k++) {
                printf("%d ", arr[k]);
            }
            printf("\n\n");
        }

        // ������ �ܰ� (99��° �ܰ�)�� ���
        if (i == SIZE - 2) {
            printf("Step %d: ", i + 1); // 99��°�� i + 1
            for (int k = 0; k < SIZE; k++) {
                printf("%d ", arr[k]);
            }
            printf("\n\n\n");
        }
    }
}

// ���� ���� �Լ� (20ȸ ����, ��� �� Ƚ�� ���)
void insertionSort(int arr[]) {
    int totalComparisons = 0;
    int comparisons;

    for (int run = 0; run < 20; run++) {
        comparisons = 0;
        for (int i = 1; i < SIZE; i++) {
            int key = arr[i];
            int j = i - 1;
            while (j >= 0 && arr[j] > key) {
                arr[j + 1] = arr[j];
                j--;
                comparisons++;
            }
            arr[j + 1] = key;
        }
        totalComparisons += comparisons;
    }

    printf("Insertion Sort Compare Average: %d\n", totalComparisons / 20);

    printf("Insertion Sort Result: \n");
    int j = 0;
    for (j = 0; j < SIZE; j++) {
        printf("%d ", arr[j]);
    }
    printf("\n\n");
}

// ���� ���� �Լ� (20ȸ ����, ��� �̵� Ƚ�� ���)
void bubbleSort(int arr[]) {
    int totalMoves = 0;
    int moves;

    for (int run = 0; run < 20; run++) {
        moves = 0;
        for (int i = 0; i < SIZE - 1; i++) {
            for (int j = 0; j < SIZE - i - 1; j++) {
                if (arr[j] > arr[j + 1]) {
                    // ��� ��ȯ
                    int temp = arr[j];
                    arr[j] = arr[j + 1];
                    arr[j + 1] = temp;
                    moves += 3;  // �� ��ȯ�� 3ȸ �̵����� ���
                }
            }
        }
        totalMoves += moves;
    }

    printf("Bubble Sort Move Average: %d\n", totalMoves / 20);

    printf("Bubble Sort Result: \n");
    int j = 0;
    for (j = 0; j < SIZE; j++) {
        printf("%d ", arr[j]);
    }
    printf("\n");
}
