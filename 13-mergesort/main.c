#include <stdio.h>
#include <stdlib.h>
#include "mergesort.h"

int comparisonCount = 0; // �� Ƚ��
int moveCount = 0;       // �̵� Ƚ��

int main() {
    int array[SIZE];
    double totalComparisons = 0, totalMoves = 0;

    for (int i = 0; i < 20; i++) {
        generateRandomArray(array); // ���� ������ ����
        comparisonCount = 0;
        moveCount = 0;

        if (i == 0) {
            printf("Merge Sort Run\n");
            doMergeSort(array); // ù ��° ���࿡�� ���� ���� ���
            printf("Result\n");
            printArray(array, SIZE);
        }
        else {
            break;
        }

        totalComparisons += comparisonCount;
        totalMoves += moveCount;
    }

    printf("\nAverage Comparisons: %.2f\n", totalComparisons / 20.0);
    printf("Average Moves: %.2f\n", totalMoves / 20.0);

    return 0;
}
