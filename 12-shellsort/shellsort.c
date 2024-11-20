// shellsort.c
#include <stdio.h>
#include <stdlib.h>
#include "shellsort.h"

// ������ �����ϴ� �Լ�
void generateRandomNumbers(int* array, int size) {
    for (int i = 0; i < size; i++) {
        array[i] = rand() % 1000; // 0~999 ������ ����
    }
}

void printArray(int* array, int size, int printCount) {
    for (int i = 0; i < printCount && i < size; i++) {
        printf("%d ", array[i]);
    }
    printf("...\n");
}

void printShellArray(int* array, int size, int printCount) {
    for (int i = 0; i < printCount && i < size; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
}

// �� ���� �Լ� (���� ��� ����)
void doShellSortWithSteps(int* array, int size, int gapFactor, int* comparisonCount, int* moveCount) {
    *comparisonCount = 0;
    *moveCount = 0;
    int gap = (gapFactor == 2) ? size / 2 : size / 3;

    while (gap > 0) {
        printf("Sorting with gap = %d:\n", gap);
        for (int i = gap; i < size; i++) {
            int temp = array[i];
            (*moveCount)++;
            int j;
            for (j = i; j >= gap && ++(*comparisonCount) && array[j - gap] > temp; j -= gap) {
                array[j] = array[j - gap];
                (*moveCount)++;
            }
            array[j] = temp;
            (*moveCount)++;
        }
        printArray(array, size, 20);
        gap = (gapFactor == 2) ? gap / 2 : gap / 3;
        printf("\n");
    }
}

// ���� ���� �Լ� (���ʽ�)
void doInsertionSort(int* array, int size, int* comparisonCount, int* moveCount) {
    *comparisonCount = 0;
    *moveCount = 0;

    for (int i = 1; i < size; i++) {
        int temp = array[i];
        (*moveCount)++;
        int j = i - 1;
        while (j >= 0 && ++(*comparisonCount) && array[j] > temp) {
            array[j + 1] = array[j];
            (*moveCount)++;
            j--;
        }
        array[j + 1] = temp;
        (*moveCount)++;
    }
}
