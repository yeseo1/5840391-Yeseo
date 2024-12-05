#ifndef SEARCH_H
#define SEARCH_H

#define SIZE 10000

void generateRandomArray(int* array);
void quickSort(int* array, int low, int high);
int partition(int* array, int low, int high);
void printArray(int* array);
float getAverageBinarySearchCompareCount(int* array);
float getAverageInterpolationSearchCompareCount(int* array);
int binarySearch(int* array, int target, int* compareCount);
int interpolationSearch(int* array, int target, int* compareCount);

#endif // SEARCH_H
