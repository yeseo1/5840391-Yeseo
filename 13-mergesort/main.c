#include <stdio.h>
#include <stdlib.h>
#include "mergesort.h"

int comparisonCount = 0; // 비교 횟수
int moveCount = 0;       // 이동 횟수

int main() {
    int array[SIZE];
    double totalComparisons = 0, totalMoves = 0;

    for (int i = 0; i < 20; i++) {
        generateRandomArray(array); // 랜덤 데이터 생성
        comparisonCount = 0;
        moveCount = 0;

        if (i == 0) {
            printf("Merge Sort Run\n");
            doMergeSort(array); // 첫 번째 실행에서 정렬 과정 출력
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
