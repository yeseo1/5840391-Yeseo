#ifndef QUICKSORT_H
#define QUICKSORT_H

#define SIZE 100

// ���� ���� ����
extern int comparisonCount;
extern int moveCount;

// �Լ� ������Ÿ�� ����
void generateRandomArray(int array[]);
void printArray(int array[], int size);
void doQuickSort(int array[], int low, int high);

#endif // QUICKSORT_H
