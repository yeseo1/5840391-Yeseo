#ifndef QUICKSORT_H
#define QUICKSORT_H

#define SIZE 100

// 전역 변수 선언
extern int comparisonCount;
extern int moveCount;

// 함수 프로토타입 선언
void generateRandomArray(int array[]);
void printArray(int array[], int size);
void doQuickSort(int array[], int low, int high);

#endif // QUICKSORT_H
