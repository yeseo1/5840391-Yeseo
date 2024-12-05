#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "search.h"

// 배열에 임의의 숫자 생성
void generateRandomArray(int* array) {
    for (int i = 0; i < SIZE; i++) {
        array[i] = rand() % 10000;
    }
}

// Quick Sort 구현
void quickSort(int* array, int low, int high) {
    if (low < high) {
        int pivot = partition(array, low, high);
        quickSort(array, low, pivot - 1);
        quickSort(array, pivot + 1, high);
    }
}

// Quick Sort의 Partition 함수
int partition(int* array, int low, int high) {
    int pivot = array[high];
    int i = low - 1;
    for (int j = low; j < high; j++) {
        if (array[j] <= pivot) {
            i++;
            int temp = array[i];
            array[i] = array[j];
            array[j] = temp;
        }
    }
    int temp = array[i + 1];
    array[i + 1] = array[high];
    array[high] = temp;
    return i + 1;
}

// 배열 출력
void printArray(int* array) {
    printf("Array Sorting Result:\n");
    for (int i = 0; i < 20; i++)
        printf("%4d ", array[i]);
    printf("\n");
    for (int i = SIZE - 20; i < SIZE; i++)
        printf("%4d ", array[i]);
    printf("\n\n");
}

// Binary Search
int binarySearch(int* array, int target, int* compareCount) {
    int left = 0, right = SIZE - 1;
    *compareCount = 0;
    while (left <= right) {
        (*compareCount)++;
        int mid = left + (right - left) / 2;
        if (array[mid] == target) {
            return mid;
        }
        else if (array[mid] < target) {
            left = mid + 1;
        }
        else {
            right = mid - 1;
        }
    }
    return -1;
}

// Interpolation Search
int interpolationSearch(int* array, int target, int* compareCount) {
    int left = 0, right = SIZE - 1;
    *compareCount = 0;
    while (left <= right && target >= array[left] && target <= array[right]) {
        (*compareCount)++;
        int pos = left + ((double)(right - left) / (array[right] - array[left]) * (target - array[left]));
        if (array[pos] == target) {
            return pos;
        }
        else if (array[pos] < target) {
            left = pos + 1;
        }
        else {
            right = pos - 1;
        }
    }
    return -1;
}

// Binary Search 평균 비교 횟수 계산
float getAverageBinarySearchCompareCount(int* array) {
    int totalCompareCount = 0;
    for (int i = 0; i < 1000; i++) {
        int target = array[rand() % SIZE];
        int compareCount;
        binarySearch(array, target, &compareCount);
        totalCompareCount += compareCount;
    }
    return (float)totalCompareCount / 1000;
}

// Interpolation Search 평균 비교 횟수 계산
float getAverageInterpolationSearchCompareCount(int* array) {
    int totalCompareCount = 0;
    for (int i = 0; i < 1000; i++) {
        int target = array[rand() % SIZE];
        int compareCount;
        interpolationSearch(array, target, &compareCount);
        totalCompareCount += compareCount;
    }
    return (float)totalCompareCount / 1000;
}
