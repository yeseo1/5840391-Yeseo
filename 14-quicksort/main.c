#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "QuickSort.h"

int main() {
    srand(time(NULL));
    int array[SIZE];
    int totalComparisons = 0, totalMoveCount = 0;

    for (int i = 0; i < 20; i++) {
        generateRandomArray(array);
        comparisonCount = 0;
        moveCount = 0;

        if (i == 0) {
            printf("Quick Sort Run\n");

            // �� ���� ���� �� �߰� ���� ���
            doQuickSort(array, 0, SIZE - 1);

            // ���� ���� ��� ���
            printf("\nResult:\n");
            printArray(array, SIZE);
        }
        else {
            break;
        }

        // �� �� �̵� Ƚ�� ����
        totalComparisons += comparisonCount;
        totalMoveCount += moveCount;
    }

    // ��� �� Ƚ�� �� �̵� Ƚ�� ���
    printf("\nAverage Comparisons: %.2f\n", totalComparisons / 20.0);
    printf("Average Moves: %.2f\n", totalMoveCount / 20.0);

    return 0;
}
