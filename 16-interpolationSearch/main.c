#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "search.h"

#define SIZE 10000

int main(int argc, char* argv[]) {
    srand(time(NULL));
    int array[SIZE];
    generateRandomArray(array);

    quickSort(array, 0, SIZE - 1);
    printArray(array);

    printf("Average Compare Count of Binary Search: %.2f\n",
        getAverageBinarySearchCompareCount(array));

    printf("Average Compare Count of Interpolation Search: %.2f\n",
        getAverageInterpolationSearchCompareCount(array));

    return 0;
}
