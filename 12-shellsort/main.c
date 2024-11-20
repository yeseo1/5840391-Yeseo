// main.c
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "shellsort.h"

#define ARRAY_SIZE 100

int main() {
    srand(time(0)); // 난수 생성을 위해 현재 시간을 시드로 설정
    int array[ARRAY_SIZE];
    int comparisonCount, moveCount;

    // Shell Sort (n/2) 과정
    printf("Shell Sort (n/2):\n");
    generateRandomNumbers(array, ARRAY_SIZE);

    doShellSortWithSteps(array, ARRAY_SIZE, 2, &comparisonCount, &moveCount);
    printf("Sorted Shell array (gap = 2):\n");
    printShellArray(array, ARRAY_SIZE, ARRAY_SIZE);
    printf("\n");
    printf("Shell Sort (n/2) - Comparisons: %d, Moves: %d\n\n", comparisonCount, moveCount);

    // Shell Sort (n/3) 과정
    printf("Shell Sort (n/3):\n");
    generateRandomNumbers(array, ARRAY_SIZE);

    doShellSortWithSteps(array, ARRAY_SIZE, 3, &comparisonCount, &moveCount);
    printf("Sorted Shell array (gap = 3): ");
    printShellArray(array, ARRAY_SIZE, ARRAY_SIZE);
    printf("\n");
    printf("Shell Sort (n/3) - Comparisons: %d, Moves: %d\n\n", comparisonCount, moveCount);

    // Insertion Sort (보너스)
    printf("Insertion Sort:\n");
    generateRandomNumbers(array, ARRAY_SIZE);

    doInsertionSort(array, ARRAY_SIZE, &comparisonCount, &moveCount);
    printf("Sorted Insertion array: ");
    printArray(array, ARRAY_SIZE, ARRAY_SIZE);
    printf("\n");
    printf("Insertion Sort - Comparisons: %d, Moves: %d\n", comparisonCount, moveCount);

    return 0;
}
