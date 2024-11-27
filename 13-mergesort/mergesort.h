#ifndef MERGESORT_H
#define MERGESORT_H

#define SIZE 100

extern int comparisonCount;
extern int moveCount;

void generateRandomArray(int array[]);
void doMergeSort(int array[]);
void printArray(int array[], int size);

#endif
