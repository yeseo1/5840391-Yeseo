#ifndef SORT_BY_HEAP_H
#define SORT_BY_HEAP_H

void BuildMaxHeapAndSort(int inputData[], int n);
void BuildMaxHeap(int inputData[], int n);
void swap(int* a, int* b);
void resortHeap(int inputData[], int n, int i);

#endif // SORT_BY_HEAP_H