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

            // 퀵 정렬 수행 및 중간 상태 출력
            doQuickSort(array, 0, SIZE - 1);

            // 최종 정렬 결과 출력
            printf("\nResult:\n");
            printArray(array, SIZE);
        }
        else {
            break;
        }

        // 비교 및 이동 횟수 누적
        totalComparisons += comparisonCount;
        totalMoveCount += moveCount;
    }

    // 평균 비교 횟수 및 이동 횟수 출력
    printf("\nAverage Comparisons: %.2f\n", totalComparisons / 20.0);
    printf("Average Moves: %.2f\n", totalMoveCount / 20.0);

    return 0;
}
