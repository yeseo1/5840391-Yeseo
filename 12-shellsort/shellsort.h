// shellsort.h
#ifndef SHELLSORT_H
#define SHELLSORT_H

void generateRandomNumbers(int* array, int size);
void doShellSortWithSteps(int* array, int size, int gapFactor, int* comparisonCount, int* moveCount);
void doInsertionSort(int* array, int size, int* comparisonCount, int* moveCount);
void printArray(int* array, int size, int printCount);

#endif // SHELLSORT_H
