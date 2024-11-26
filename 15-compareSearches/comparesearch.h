#pragma once
#ifndef COMPARESEARCH_H
#define COMPARESEARCH_H

#define SIZE 1000

extern int compareCount;

void generateRandomArray(int array[]);
void printArray(int* array);
float getAverageLinearSearchCompareCount(int array[]);
void getQuickSortCompareCount(int array[]);
float getAverageBinarySearchCompareCount(int array[]);

#endif
